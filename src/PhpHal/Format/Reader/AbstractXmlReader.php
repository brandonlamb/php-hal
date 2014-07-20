<?php

namespace PhpHal\Format\Reader;

use PhpHal\Format\AbstractReader;
use PhpHal\Format\ReaderInterface;
use XMLReader as BasicXmlReader;

abstract class AbstractXmlReader extends AbstractReader implements ReaderInterface
{
    /**
     * Parse array of data into resource
     *
     * @param array $data
     * @return \PhpHal\Resource
     */
    abstract protected function arrayToResource(array $data);

    /**
     * Execute parsing
     *
     * @param string $input
     * @return mixed
     */
    public function execute($input)
    {
        $reader = new BasicXmlReader();
        $reader->xml($input);
        $data = $this->xmlToArray($reader);

        return $this->arrayToResource($data);
    }

    /**
     * Parse xml object into array
     *
     * @param \XMLReader $xml
     * @return array
     */
    protected function xmlToArray(BasicXmlReader $xml)
    {
        $data = [];

        $i = 0;
        while ($xml->read()) {
            if ($xml->nodeType == BasicXmlReader::END_ELEMENT) {
                break;
            }

            if ($xml->nodeType === BasicXmlReader::ELEMENT && !$xml->isEmptyElement) {
                $data[$i]['name'] = $xml->name;
                $data[$i]['values'] = $this->xmlToArray($xml);
                $data[$i]['attributes'] = $this->getAttributesFromNode($xml);
                $i++;
            } elseif ($xml->isEmptyElement) {
                $data[$i]['name'] = $xml->name;
                $data[$i]['values'] = null;
                $data[$i]['attributes'] = $this->getAttributesFromNode($xml);
                $i++;
            } elseif($xml->nodeType == BasicXmlReader::TEXT) {
                $data = $xml->value;
            }
        }

        return $data;
    }

    private function getAttributesFromNode(BasicXmlReader $xml)
    {
        if (!$xml->hasAttributes) {
            return null;
        }

        $attributes = [];
        while ($xml->moveToNextAttribute()) {
            $attributes[$xml->name] = $xml->value;
        }

        return $attributes;
    }
}
