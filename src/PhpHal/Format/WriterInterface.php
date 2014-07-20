<?php

namespace PhpHal\Format;

use PhpHal\Resource;

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
     * @param \PhpHal\Resource $resource
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
