<?php

namespace Phal\Tests\Resource\Format\Reader\Hal;

use Phal\Tests\Resource\Format\Reader\ReaderTest;

class XMLReaderTest extends ReaderTest
{
    protected $mime = 'application/hal+xml';
    protected $reader = '\\Phal\\Format\\Reader\\Hal\\XmlReader';
    protected $writer = '\\Phal\\Format\\Writer\\Hal\\XmlWriter';
    protected $from = 'Reader/Hal/XMLReader.xml';
}
