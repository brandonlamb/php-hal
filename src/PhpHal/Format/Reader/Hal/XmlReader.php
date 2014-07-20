<?php

namespace PhpHal\Format\Reader\Hal;

use PhpHal\Format\Reader\AbstractXmlReader;
use PhpHal\Resource;
use PhpHal\Link;
use UnexpectedValueException;

class XmlReader extends AbstractXmlReader
{
    const CONTENT_TYPE = 'application/hal+xml';

    const RESOURCE_NAME = 'resource';
    const LINK_NAME = 'link';
    const LINK_KEY_REL = 'rel';

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
        if (count($data) !== 1 || !$this->nodeIsResource(end($data))) {
            throw new UnexpectedValueException('Expencted only one resource node');
        }
        return $this->transformEmbedded(end($data));
    }

    private function nodeIsResource(array $data)
    {
        return $data['name'] === self::RESOURCE_NAME;
    }

    private function nodeIsLink(array $data)
    {
        return $data['name'] === self::LINK_NAME;
    }

    protected function transformLink(array $node)
    {
        $link = new Link();
        $data = $node['attributes'];

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

    protected function transformEmbedded(array $data)
    {
        $resource = new Resource();
        isset($data['attributes'][self::LINK_KEY_HREF]) && $resource->setURI($data['attributes'][self::LINK_KEY_HREF]);
        isset($data['attributes'][self::LINK_KEY_TITLE]) && $resource->setTitle($data['attributes'][self::LINK_KEY_TITLE]);

        $embeddeds = [];
        $links = [];
        $data2 = [];

        foreach ($data['values'] as &$node) {
            if ($this->nodeIsResource($node)) {
                $embeddeds[$node['attributes']['rel']][] = $this->transformEmbedded($node);
            } elseif ($this->nodeIsLink($node)) {
                $links[$node['attributes']['rel']][] = $this->transformLink($node);
            } else {
                if (is_array($node['values'])) {
                    $toSave = [];
                    foreach ($node['values'] as &$value) {
                        $toSave[$value['name']][] = $value['values'];
                    }
                } else {
                    $toSave = $node['values'];
                }

                $data2[$node['name']][] = $toSave;
            }
        }

        $resource->setData($data2);

        foreach ($links as $rel => $link) {
            $resource->setLinks($rel, $link);
        }

        foreach ($embeddeds as $rel => $embedded) {
            $resource->addResources($rel, $embedded);
        }

        return $resource;
    }

    private function isAssocArray($data)
    {
        return array_keys($data) !== range(0, count($data) - 1);
    }
}
