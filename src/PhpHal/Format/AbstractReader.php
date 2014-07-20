<?php

namespace PhpHal\Format;

use PhpHal\Resource;

abstract class AbstractReader
{
    /**
     * Return the content type string for the resource
     *
     * @return string
     */
    public function getContentType()
    {
        return static::CONTENT_TYPE;
    }
}
