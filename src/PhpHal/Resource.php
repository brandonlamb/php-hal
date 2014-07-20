<?php

namespace PhpHal;

use PhpHal\Link;
use PhpHal\Format\Writer;
use RuntimeException;
use InvalidArgumentException;
use DateTime;

class Resource
{
    protected $id;
    protected $title;
    protected $key;
    protected $uri;
    protected $resources = [];
    protected $linkedResources = [];
    protected $links = [];
    protected $data = [];
    protected $lastUpdate;
    protected $cache;
    protected $writer;

    public function setId($id)
    {
        $this->id = $id;
        return $this;
    }

    public function getId()
    {
        return $this->id;
    }

    public function setRepositoryKey($key)
    {
        $this->key = (string) $key;
        return $this;
    }

    public function getRepositoryKey()
    {
        return (string) $this->key;
    }

    public function setTitle($title)
    {
        $this->title = (string) $title;
        return $this;
    }

    public function getTitle()
    {
        return (string) $this->title;
    }

    public function setUri($uri)
    {
        $this->uri = (string) $uri;
        return $this;
    }

    public function getURI()
    {
        return (string) $this->uri;
    }

    public function setData(array $data)
    {
        $this->data = $data;
        return $this;
    }

    public function addData($key, $value)
    {
        $this->data[(string) $key] = $value;
        return $this;
    }

    public function getData()
    {
        return $this->data;
    }

    public function setLink($rel, Link $link)
    {
        $this->links[(string) $rel] = $link;
        return $this;
    }

    public function setLinks($rel, array $links)
    {
        foreach ($links as &$link) {
            if (!$link instanceof Link) {
                throw new InvalidArgumentException('Invalid array, must be []Link');
            }
        }

        $this->links[(string) $rel] = $links;

        return $this;
    }

    public function linkResource($rel, Resource $resource)
    {
        $this->throwExceptionIfNotLinkableResouce($resource);
        $this->linkedResources[(string) $rel] = $resource;
        return $this;
    }

    public function linkResources($rel, array $resources)
    {
        foreach ($resources as &$resource) {
            $this->throwExceptionIfNotLinkableResouce($resource);
        }
        $this->linkedResources[(string) $rel] = $resources;
        return $this;
    }

    protected function throwExceptionIfNotLinkableResouce(Resource $resource)
    {
        $link = $resource->getSelfLink();
        if (!$link) {
            throw new InvalidArgumentException('This resource not contains a valid URI');
        }
    }

    public function expandLinkedResourcesTree(array $path)
    {
        if (count($path) == 1) {
            return $this->expandLinkedResources(end($path));
        }

        $rel = (string) array_shift($path);
        $this->expandLinkedResources($rel);

        $resources = $this->getResources($rel);
        if (!$resources) {
            return;
        }

        if (!is_array($resources)) {
            $resources = [$resources];
        }

        foreach ($resources as &$resource) {
            $resource->expandLinkedResourcesTree($path);
        }
    }

    public function expandLinkedResources($rel)
    {
        $rel = (string) $rel;

        $resources = $this->getLinkedResources($rel);
        if (!$resources) {
            return;
        }

        if (!is_array($resources)) {
            $this->addResource($rel, $resources);
        } else {
            $this->addResources($rel, $resources);
        }
    }

    public function getAllLinkedResources()
    {
        return $this->linkedResources;
    }

    public function getLinkedResources($rel)
    {
        $rel = (string) $rel;
        if (!isset($this->linkedResources[$rel])) {
            return null;
        }
        return $this->linkedResources[$rel];
    }

    public function getAllLinks()
    {
        return $this->links;
    }

    public function getLinks($rel)
    {
        $rel = (string) $rel;
        if (isset($this->links[$rel])) {
            return $this->links[$rel];
        }

        return null;
    }

    public function addResource($rel, Resource $resource, $multi = false)
    {
        $rel = (string) $rel;

        if (!$multi) {
            $this->resources[$rel] = $resource;
        } else {
            if (!isset($this->resources[$rel])) {
                $this->resources[$rel] = [$resource];
            } else {
                $this->resources[$rel][] = $resource;
            }
        }
        return $this;
    }

    public function addResources($rel, array $resources, $overwrite = false)
    {
        $rel = (string) $rel;

        foreach ($resources as &$resource) {
            if (!$resource instanceof Resource) {
                throw new \InvalidArgumentException('Invalid array, must be []Resource');
            }
        }

        if ($overwrite) {
            $this->resources[$rel] = $resources;
        } else {
            if (isset($this->resources[$rel])) {
                $this->resources[$rel] = array_merge($this->resources[$rel], $resources);
            } else {
                $this->resources[$rel] = $resources;
            }
        }

        return $this;
    }

    public function getAllResources()
    {
        return $this->resources;
    }

    public function getResources($rel)
    {
        $rel = (string) $rel;
        if (isset($this->resources[$rel])) {
            return $this->resources[$rel];
        }
        return null;
    }

    public function getSelfLink()
    {
        if (!$this->uri) {
            return null;
        }

        $link = new Link($this->getURI());

        if ($title = $this->getTitle()) {
            $link->setTitle($title);
        }

        if ($name = $this->getId()) {
            $link->setName($name);
        }

        return $link;
    }

    public function setLastUpdate(DateTime $date)
    {
        $this->lastUpdate = $date;
        return $this;
    }

    public function getLastUpdate()
    {
        return $this->lastUpdate;
    }

    public function setCache($secs)
    {
        $this->cache = (int) $secs;
        return $this;
    }

    public function getCache()
    {
        return (int) $this->cache;
    }

    public function setFormatWriter(Writer $writer)
    {
        $this->writer = $writer;
        return $this;
    }

    public function getFormatWriter()
    {
        return $this->writer;
    }

    public function __toString()
    {
        if (!$this->writer) {
            return '';
        }
        return $this->writer->execute($this);
    }
}
