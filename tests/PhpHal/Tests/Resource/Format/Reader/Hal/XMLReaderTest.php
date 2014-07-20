<?php

namespace PhpHal\Tests\Resource\Format\Reader\Hal;

use PhpHal\Tests\Resource\Format\Reader\ReaderTest;

class XMLReaderTest extends ReaderTest
{
    protected $mime = 'application/hal+xml';
    protected $reader = '\\PhpHal\\Format\\Reader\\Hal\\XmlReader';
    protected $writer = '\\PhpHal\\Format\\Writer\\Hal\\XmlWriter';
    protected $from = 'Reader/Hal/XMLReader.xml';
}
