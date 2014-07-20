<?php

namespace Phal\Format;

use Phal\Resource;

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
