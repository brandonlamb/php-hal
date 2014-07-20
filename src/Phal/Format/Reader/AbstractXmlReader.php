<?php

use Phal\Format\AbstractReader;
use Phal\Format\ReaderInterface;
use XMLReader;

abstract class AbstractXmlReader extends AbstractReader implements ReaderInterface
{
    /**
     * Parse array of data into resource
     *
     * @param array $data
     * @return \Phal\Resource
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
        $reader = new XMLReader();
        $reader->xml($input);
        $data = $this->xmlToArray($reader);

        return $this->arrayToResource($data);
    }

    protected function xmlToArray(XMLReader $xml)
    {
        $data = [];

        $i = 0;
        while ($xml->read()) {
            if ($xml->nodeType == XMLReader::END_ELEMENT) {
                break;
            }

            if ($xml->nodeType === XMLReader::ELEMENT && !$xml->isEmptyElement) {
                $data[$i]['name'] = $xml->name;
                $data[$i]['values'] = $this->xmlToArray($xml);
                $data[$i]['attributes'] = $this->getAttributesFromNode($xml);
                $i++;
            } elseif ($xml->isEmptyElement) {
                $data[$i]['name'] = $xml->name;
                $data[$i]['values'] = null;
                $data[$i]['attributes'] = $this->getAttributesFromNode($xml);
                $i++;
            } elseif($xml->nodeType == XMLReader::TEXT) {
                $data = $xml->value;
            }
        }

        return $data;
    }

    private function getAttributesFromNode(XMLReader $xml)
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
