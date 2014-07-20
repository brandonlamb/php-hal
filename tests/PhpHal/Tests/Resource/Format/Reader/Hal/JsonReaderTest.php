<?php

namespace PhpHal\Tests\Resource\Format\Reader\Hal;

use PhpHal\Tests\Resource\Format\Reader\ReaderTest;

class JsonReaderTest extends ReaderTest
{
    protected $mime = 'application/hal+json';
    protected $reader = '\\PhpHal\\Format\\Reader\\Hal\\JsonReader';
    protected $writer = '\\PhpHal\\Format\\Writer\\Hal\\JsonWriter';
    protected $from = 'Reader/Hal/JsonReader.json';
}
