<?php

namespace PhpHal\Format\Writer\Hal;

use PhpHal\Format\Writer\AbstractJsonWriter;
use PhpHal\Resource;

class JsonWriter extends AbstractJsonWriter
{
    const CONTENT_TYPE = 'application/vnd.siren+json';

    protected function resourceToArray(Resource $resource)
    {
        $data = [];

        $this->transformDataAndMetadata($data, $resource);
        $this->transformResources($data, $resource);
        $this->transformLinks($data, $resource);
        $this->transformLinkedResources($data, $resource);

        return $data;
    }

    protected function transformDataAndMetadata(array &$data, Resource $resource)
    {
        $data['class'] = null;
        if ($key = $resource->getRepositoryKey()) {
            $data['class'] = explode('/', $key);
        }

        if ($title = $resource->getTitle()) {
            $data['title'] = $title;
        }

        $data['properties'] = $resource->getData();
    }

    protected function transformLinks(array &$data, Resource $resource)
    {
        if ($self = $resource->getSelfLink()) {
            $data['links'][] = [
                'rel' => 'self',
                'href' => $self->getHref()
            ];
        }

        foreach ($resource->getAllLinks() as $rel => $links) {
            if (!is_array($links)) {
                $links = [$links];
            }

            foreach ($links as &$link) {
                $data['links'][] = [
                    'rel' => $rel,
                    'href' => $link->getHref()
                ];
            }
        }
    }

    protected function transformLinkedResources(array &$data, Resource $resource)
    {
        $embeddedLinks = $this->getHrefsFromEntities($data);

        foreach ($resource->getAllLinkedResources() as $rel => $linkedResources) {
            if (!is_array($linkedResources)) {
                $linkedResources = [$linkedResources];
            }

            foreach ($linkedResources as &$linked) {
                $link = $linked->getSelfLink()->getHref();
                if (isset($embeddedLinks[$link])) {
                    continue;
                }

                $data['entities'][] = [
                    'rel' => $rel,
                    'href' => $link
                ];
            }
        }
    }

    private function getHrefsFromEntities(array $data)
    {
        $embeddedLinks = [];
        if (isset($data['entities'])) {
            foreach ($data['entities'] as &$entity) {
                if (isset($entity['href'])) {
                    $embeddedLinks[$entity['href']] = true;
                }
            }
        }

        return $embeddedLinks;
    }

    protected function transformResources(array &$data, Resource $resource)
    {
        foreach ($resource->getAllResources() as $rel => $resources) {
            if (!is_array($resources)) {
                $resources = [$resources];
            }

            foreach ($resources as &$resource) {
                $data['entities'][] = $this->doTransformResource($data, $rel, $resource);
            }
        }
    }

    protected function doTransformResource(array &$array, $rel, Resource $resource)
    {
        $data = $this->resourceToArray($resource);
        if (!$data['class']) {
            $data['class'] = array_merge($array['class'], [$rel]);
        }

        $metadata = [];
        $metadata['rel'] = $rel;

        if ($resource->getUri()) {
            $metadata['href'] = $resource->getSelfLink()->getHref();
        }

        return array_merge($metadata, $data);
    }
}
