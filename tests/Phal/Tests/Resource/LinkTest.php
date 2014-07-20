<?php
/*
 * This file is part of the Phal package.
 *
 * (c) Máximo Cuadros <maximo@yunait.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

namespace Phal\Tests;
use Phal\Link;

class LinkTest extends TestCase
{
    public function testConstructor()
    {
        $href = '/test';

        $link = new Link($href);
        $this->assertSame($href, $link->getHref());
    }

    public function testConstructorEmpty()
    {
        $link = new Link();
        $this->assertEmpty($link->getHref());
    }

    public function testSetAndGetHref()
    {
        $href = 'foo';

        $link = new Link();
        $this->assertSame($link, $link->setHref($href));
        $this->assertSame($href, $link->getHref());
        $this->assertSame($href, (string) $link);
    }

    public function testSetAndGetName()
    {
        $name = 'foo';

        $link = new Link();
        $this->assertSame($link, $link->setName($name));
        $this->assertSame($name, $link->getName());
    }

    public function testSetAndGetLang()
    {
        $lang = 'foo';

        $link = new Link();
        $this->assertSame($link, $link->setHreflang($lang));
        $this->assertSame($lang, $link->getHreflang());
    }

    public function testSetAndGetTitle()
    {
        $title = 'foo';

        $link = new Link();
        $this->assertSame($link, $link->setTitle($title));
        $this->assertSame($title, $link->getTitle());
    }

    public function testIsTemplatedAndSetTemplated()
    {
        $templated = true;

        $link = new Link();
        $this->assertSame($link, $link->setTemplated($templated));
        $this->assertSame($templated, $link->isTemplated());
    }

    public function testGetAttributes()
    {
        $expected = [
            'templated' => true,
            'name' => 'foo',
            'title' => 'qux',
            'hreflang' => 'bar',
        ];

        $link = new Link();
        $link->setName($expected['name']);
        $link->setHreflang($expected['hreflang']);
        $link->setTitle($expected['title']);
        $link->setTemplated($expected['templated']);

        $this->assertSame($expected, $link->getAttributes());
    }

    public function testToArray()
    {
        $expected = [
            'href' => 'fux',
            'templated' => true,
            'name' => 'foo',
            'title' => 'qux',
            'hreflang' => 'bar',
        ];

        $link = new Link($expected['href']);
        $link->setName($expected['name']);
        $link->setHreflang($expected['hreflang']);
        $link->setTitle($expected['title']);
        $link->setTemplated($expected['templated']);

        $this->assertSame($expected, $link->toArray());
    }

    public function testGetAttributesEmpty()
    {
        $expected = [];

        $link = new Link();
        $this->assertSame($expected, $link->getAttributes());
    }
}
