<?php

namespace Phal\Tests\Resource\Format\Reader\Hal;

use Phal\Tests\Resource\Format\Reader\ReaderTest;

class JsonReaderTest extends ReaderTest
{
    protected $mime = 'application/hal+json';
    protected $reader = '\\Phal\\Format\\Reader\\Hal\\JsonReader';
    protected $writer = '\\Phal\\Format\\Writer\\Hal\\JsonWriter';
    protected $from = 'Reader/Hal/JsonReader.json';
}
