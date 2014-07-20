<?php

namespace Phal\Tests\Resource\Format\Writer\Hal;

use Phal\Tests\Resource\Format\Writer\WriterTest;

class XMLWriterTest extends WriterTest
{
    protected $mime = 'application/hal+xml';
    protected $class = 'Phal\Format\Writer\Hal\XmlWriter';
    protected $toNonPretty = 'Writer/Hal/XMLWriterNonPretty.xml';
    protected $toPretty = 'Writer/Hal/XMLWriterPretty.xml';
}
