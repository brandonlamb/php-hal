<?php

namespace Phal\Format\Reader;

use Phal\Format\AbstractReader;
use Phal\Format\ReaderInterface;

abstract class AbstractJsonReader extends AbstractReader implements ReaderInterface
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
        return $this->arrayToResource(json_decode($input, true));
    }
}
