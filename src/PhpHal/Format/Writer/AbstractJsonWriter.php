<?php

namespace PhpHal\Format\Writer;

use PhpHal\Format\AbstractWriter;
use PhpHal\Format\WriterInterface;
use PhpHal\Resource;

abstract class AbstractJsonWriter extends AbstractWriter implements WriterInterface
{
    /**
     * Parse resource to array
     *
     * @param \PhpHal\Resource $resource
     * @return array
     */
    abstract protected function resourceToArray(Resource $resource);

    /**
     * Execute parsing
     *
     * @param \PhpHal\Resource $resource
     * @return mixed
     */
    public function execute(Resource $resource)
    {
        if (!$this->pretty) {
            return json_encode($this->resourceToArray($resource), \JSON_UNESCAPED_SLASHES);
        }
        return json_encode($this->resourceToArray($resource), \JSON_UNESCAPED_SLASHES | \JSON_PRETTY_PRINT);
    }
}
