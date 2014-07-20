<?php

namespace Phal\Format\Writer;

use Phal\Format\AbstractWriter;
use Phal\Format\WriterInterface;
use Phal\Resource;
use XMLWriter as BasicXmlWriter;

abstract class AbstractXmlWriter extends AbstractWriter implements WriterInterface
{
    /**
     * Parse resource into array
     *
     * @param \XMLWriter $writer
     * @param \Phal\Resource $resource
     * @param string $rel
     * @return array
     */
    abstract protected function resourceToArray(BasicXmlWriter $writer, Resource $resource, $rel = null);

    /**
     * Execute parsing
     *
     * @param \Phal\Resource $resource
     * @return mixed
     */
    public function execute(Resource $resource)
    {
        $writer = new BasicXmlWriter;
        $writer->openMemory();
        $writer->setIndentString('  ');
        $writer->setIndent($this->pretty);
        $writer->startDocument('1.0');

        $this->resourceToArray($writer, $resource);

        return $writer->outputMemory();
    }
}
