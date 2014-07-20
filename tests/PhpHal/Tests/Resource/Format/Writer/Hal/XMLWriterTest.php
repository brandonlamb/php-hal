<?php

namespace PhpHal\Tests\Resource\Format\Writer\Hal;

use PhpHal\Tests\Resource\Format\Writer\WriterTest;

class XMLWriterTest extends WriterTest
{
    protected $mime = 'application/hal+xml';
    protected $class = 'PhpHal\Format\Writer\Hal\XmlWriter';
    protected $toNonPretty = 'Writer/Hal/XMLWriterNonPretty.xml';
    protected $toPretty = 'Writer/Hal/XMLWriterPretty.xml';
}
