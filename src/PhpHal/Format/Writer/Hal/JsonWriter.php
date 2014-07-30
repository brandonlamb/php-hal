<?php

namespace PhpHal\Format\Writer\Hal;

use PhpHal\Format\Writer\AbstractJsonWriter;
use PhpHal\Resource;

class JsonWriter extends AbstractJsonWriter
{
    const CONTENT_TYPE = 'application/hal+json';

    protected function resourceToArray(Resource $resource)
    {
        $data = $resource->getData();

        $this->transformResources($data, $resource);
        $this->transformLinks($data, $resource);
        $this->transformLinkedResources($data, $resource);

        return $data;
    }

    protected function transformLinks(&$data, Resource $resource)
    {
        if ($self = $resource->getSelfLink()) {
            $data['_links']['self'] = $self->toArray();
        }

        foreach ($resource->getAllLinks() as $rel => $links) {
            if (!is_array($links)) {
                $data['_links'][$rel] = $links->toArray();
            } else {
                foreach ($links as &$link) {
                    $data['_links'][$rel][] = $link->toArray();
                }
            }
        }
    }

    protected function transformLinkedResources(&$data, Resource $resource)
    {
        foreach ($resource->getAllLinkedResources() as $rel => $links) {
            if (!is_array($links)) {
                $data['_links'][$rel] = $links->getSelfLink()->toArray();
            } else {
                foreach ($links as &$link) {
                    $data['_links'][$rel][] = $link->getSelfLink()->toArray();
                }
            }
        }
    }

    protected function transformResources(&$data, Resource $resource)
    {
        $embedded = [];
        foreach ($resource->getAllResources() as $rel => $resources) {
            if ($resources instanceof Resource) {
                $this->doTransformSingleResource($data, $embedded, $rel, $resources);
            } else {
                $this->doTransformResources($data, $embedded, $rel, $resources);
            }
        }

        if ($embedded) {
            $data['_embedded'] = $embedded;
        }
    }

    private function doTransformSingleResource(&$data, &$embedded, $rel, Resource $resource)
    {
        if (!$resource->getUri()) {
            $data[$rel] = $this->resourceToArray($resource);
        } else {
            $embedded[$rel] = $this->resourceToArray($resource);
        }
    }

    private function doTransformResource(&$data, &$embedded, $rel, Resource $resource)
    {
        if (!$resource->getUri()) {
            $data[$rel][] = $this->resourceToArray($resource);
        } else {
            $embedded[$rel][] = $this->resourceToArray($resource);
        }
    }

    private function doTransformResources(&$data, &$embedded, $rel, array $resources)
    {
        // Set embedded rel to an empty array to force sending rel: []
        if (count($resources) === 0) {
            $embedded[$rel] = [];
            return;
        }

        foreach ($resources as &$resource) {
            $this->doTransformResource($data, $embedded, $rel, $resource);
        }
    }
}
