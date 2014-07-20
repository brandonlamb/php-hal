<?php

namespace PhpHal\Format;

use PhpHal\Resource;

abstract class AbstractWriter
{
    const CONTENT_TYPE_ANY = '*/*';

    /**
     * @var boolean
     */
    protected $pretty;

    /**
     * Constructor
     *
     * @param boolean pretty
     */
    public function __construct($pretty = false)
    {
        $this->pretty = (bool) $pretty;
    }

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
