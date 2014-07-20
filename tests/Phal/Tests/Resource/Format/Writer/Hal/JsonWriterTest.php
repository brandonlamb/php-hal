<?php

namespace Phal\Tests\Resource\Format\Writer\Hal;

use Phal\Tests\Resource\Format\Writer\WriterTest;

class JsonWriterTest extends WriterTest
{
    protected $mime = 'application/hal+json';
    protected $class = '\\Phal\\Format\\Writer\\Hal\\JsonWriter';
    protected $toNonPretty = 'Writer/Hal/JsonWriterNonPretty.json';
    protected $toPretty = 'Writer/Hal/JsonWriterPretty.json';
}
