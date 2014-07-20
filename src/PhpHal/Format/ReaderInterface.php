<?php

namespace PhpHal\Format;

interface ReaderInterface
{
    /**
     * Execute parsing
     *
     * @param string $input
     * @return mixed
     */
    public function execute($input);

    /**
     * Return the content type string for the resource
     *
     * @return string
     */
    public function getContentType();
}
