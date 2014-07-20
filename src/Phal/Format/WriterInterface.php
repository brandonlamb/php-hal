<?php

namespace Phal\Format;

use Phal\Resource;

interface WriterInterface
{
    /**
     * Constructor
     *
     * @param boolean pretty
     */
    public function __construct($pretty = false);

    /**
     * Execute parsing
     *
     * @param \Phal\Resource $resource
     * @return mixed
     */
    public function execute(Resource $resource);

    /**
     * Return the content type string for the resource
     *
     * @return string
     */
    public function getContentType();
}
