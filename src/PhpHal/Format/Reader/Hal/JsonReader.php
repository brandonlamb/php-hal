<?php

namespace PhpHal\Format\Reader\Hal;

use PhpHal\Format\Reader\AbstractJsonReader;
use PhpHal\Resource;
use PhpHal\Link;

class JsonReader extends AbstractJsonReader
{
    const CONTENT_TYPE = 'application/hal+json';

    const RESOURCE_KEY_LINKS = '_links';
    const RESOURCE_KEY_EMBEDDED = '_embedded';
    const RESOURCE_LINK_SELF = 'self';

    const LINK_KEY_HREF = 'href';
    const LINK_KEY_TEMPLATED = 'templated';
    const LINK_KEY_TYPE = 'type';
    const LINK_KEY_DEPRECATION = 'deprecation';
    const LINK_KEY_NAME = 'name';
    const LINK_KEY_PROFILE = 'profile';
    const LINK_KEY_TITLE = 'title';
    const LINK_KEY_HREFLANG = 'hreflang';

    protected function arrayToResource(array $data)
    {
        return $this->doTransformEmbedded($data);
    }

    protected function transformMetadata(Resource $resource, array $data)
    {
        isset($data[self::RESOURCE_KEY_LINKS]) && $this->transformLinks($resource, $data[self::RESOURCE_KEY_LINKS]);
        isset($data[self::RESOURCE_KEY_EMBEDDED]) && $this->transformEmbeddeds($resource, $data[self::RESOURCE_KEY_EMBEDDED]);
    }

    protected function transformLinks(Resource $resource, array $linksByRel)
    {
        foreach ($linksByRel as $rel => $data) {
            if ($rel == self::RESOURCE_LINK_SELF) {
                $this->transformSelfLink($resource, $data);
                continue;
            }

            if ($this->isAssocArray($data)) {
                $link = $this->doTransformLink($data);
                $resource->setLink($rel, $link);
            } else {
                $links = $this->doTransformLinks($data);
                $resource->setLinks($rel, $links);
            }
        }
    }

    protected function transformSelfLink(Resource $resource, array $data)
    {
        isset($data[self::LINK_KEY_HREF]) && $resource->setURI($data[self::LINK_KEY_HREF]);
        isset($data[self::LINK_KEY_TITLE]) && $resource->setTitle($data[self::LINK_KEY_TITLE]);
    }

    protected function doTransformLinks(array $data)
    {
        $links = [];
        foreach ($data as &$link) {
            $links[] = $this->doTransformLink($link);
        }
        return $links;
    }

    protected function doTransformLink(array $data)
    {
        $link = new Link();
        isset($data[self::LINK_KEY_HREF]) && $link->setHref($data[self::LINK_KEY_HREF]);
        isset($data[self::LINK_KEY_TEMPLATED]) && $link->setTemplated($data[self::LINK_KEY_TEMPLATED]);
        isset($data[self::LINK_KEY_TYPE]) && $link->setType($data[self::LINK_KEY_TYPE]);
        isset($data[self::LINK_KEY_DEPRECATION]) && $link->setDeprecation($data[self::LINK_KEY_DEPRECATION]);
        isset($data[self::LINK_KEY_NAME]) && $link->setName($data[self::LINK_KEY_NAME]);
        isset($data[self::LINK_KEY_PROFILE]) && $link->setProfile($data[self::LINK_KEY_PROFILE]);
        isset($data[self::LINK_KEY_TITLE]) && $link->setTitle($data[self::LINK_KEY_TITLE]);
        isset($data[self::LINK_KEY_HREFLANG]) && $link->setHreflang($data[self::LINK_KEY_HREFLANG]);

        return $link;
    }

    protected function transformEmbeddeds(Resource $resource, array $embeddedsByRel)
    {
        foreach ($embeddedsByRel as $rel => $data) {
            if ($this->isAssocArray($data)) {
                $embedded = $this->doTransformEmbedded($data);
                $resource->addResource($rel, $embedded);
            } else {
                $embeddeds = $this->doTransformEmbeddeds($data);
                $resource->addResources($rel, $embeddeds);
            }
        }
    }

    protected function doTransformEmbeddeds(array $data)
    {
        $embeddeds = [];
        foreach ($data as &$embedded) {
            $embeddeds[] = $this->doTransformEmbedded($embedded);
        }
        return $embeddeds;
    }

    protected function doTransformEmbedded(array $data)
    {
        $resource = new Resource();
        foreach ($data as $key => $value) {
            if (substr($key, 0, 1) !== '_') {
                $resource->addData($key, $value);
            }
        }
        $this->transformMetadata($resource, $data);
        return $resource;
    }

    private function isAssocArray($data)
    {
        return array_keys($data) !== range(0, count($data) - 1);
    }
}
