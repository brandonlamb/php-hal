<?php

namespace PhpHal\Format\Reader;

use PhpHal\Format\AbstractReader;
use PhpHal\Format\ReaderInterface;

abstract class AbstractJsonReader extends AbstractReader implements ReaderInterface
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
        return $this->arrayToResource(json_decode($input, true));
    }
}
