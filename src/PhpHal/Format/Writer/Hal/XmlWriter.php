<?php

namespace PhpHal\Format\Writer\Hal;

use PhpHal\Format\Writer\AbstractXmlWriter;
use PhpHal\Resource;
use PhpHal\Link;
use XMLWriter as BasicXmlWriter;

class XmlWriter extends AbstractXmlWriter
{
    const CONTENT_TYPE = 'application/hal+xml';

    protected function resourceToArray(BasicXmlWriter $writer, Resource $resource, $rel = null)
    {
        $writer->startElement('resource');
        if ($rel) {
            $this->addAttribute($writer, 'rel', $rel);
        }

        if ($self = $resource->getSelfLink()) {
            $this->addAttribute($writer, 'href', $self->getHref());
        }

        $this->transformLinks($writer, $resource);
        $this->transformData($writer, $resource);
        $this->transformResources($writer, $resource);
        $this->transformLinkedResources($writer, $resource);

        $writer->endElement();
    }

    protected function transformLinks(BasicXmlWriter $writer, Resource $resource)
    {
        foreach ($resource->getAllLinks() as $rel => $links) {
            if (!is_array($links)) {
                $links = [$links];
            }

            foreach ($links as &$link) {
                $this->doTransformLink($writer, $rel, $link);
            }
        }
    }

    protected function transformLinkedResources(BasicXmlWriter $writer, Resource $resource)
    {
        foreach ($resource->getAllLinkedResources() as $rel => $resources) {
            if (!is_array($resources)) {
                $resources = [$resources];
            }

            foreach ($resources as &$resource) {
                $this->doTransformLink($writer, $rel, $resource->getSelfLink());
            }
        }
    }

    private function doTransformLink(BasicXmlWriter $writer, $rel, Link $link)
    {
        $writer->startElement('link');
        $this->addAttribute($writer, 'rel', $rel);

        foreach ($link->toArray() as $name => $value) {
            $this->addAttribute($writer, $name, $value);
        }

        $writer->endElement();
    }

    private function addAttribute(BasicXmlWriter $writer, $name, $value)
    {
        return $writer->writeAttribute($name, $value);
    }

    protected function transformData(BasicXmlWriter $writer, Resource $resource)
    {
        foreach ($resource->getData() as $name => $value) {
            $this->addValue($writer, $name, $value);
        }

        return;
    }

    private function addValue(BasicXmlWriter $writer, $name, $value)
    {
        if (!is_array($value)) {
            return $this->doWriteString($writer, $name, $value);
        }

        reset($value);
        if (is_numeric(key($value))) {
            return $this->doWriteArray($writer, $name, $value);
        } else {
            return $this->doWriteAssocArray($writer, $name, $value);
        }
    }

    private function doWriteString(BasicXmlWriter $writer, $name, $value)
    {
        $writer->writeElement($name, $value);
    }

    private function doWriteArray(BasicXmlWriter $writer, $name, array $data)
    {
        foreach ($data as &$childValue) {
            $this->addValue($writer, $name, $childValue);
        }
    }

    private function doWriteAssocArray(BasicXmlWriter $writer, $name, array $data)
    {
        $writer->startElement($name);
        foreach ($data as $childName => $childValue) {
            $this->addValue($writer, $childName, $childValue);
        }
        $writer->endElement();
    }

    protected function transformResources(BasicXmlWriter $writer, Resource $resource)
    {
        foreach ($resource->getAllResources() as $rel => $resources) {
            if (!is_array($resources)) {
                $resources = [$resources];
            }

            foreach ($resources as &$resource) {
                $this->resourceToArray($writer, $resource, $rel);
            }
        }
    }
}
