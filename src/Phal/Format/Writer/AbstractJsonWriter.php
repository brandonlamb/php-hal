<?php

namespace Phal\Format\Writer;

use Phal\Format\AbstractWriter;
use Phal\Format\WriterInterface;
use Phal\Resource;

abstract class AbstractJsonWriter extends AbstractWriter implements WriterInterface
{
    /**
     * Parse resource to array
     *
     * @param \Phal\Resource $resource
     * @return array
     */
    abstract protected function resourceToArray(Resource $resource);

    /**
     * Execute parsing
     *
     * @param \Phal\Resource $resource
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
