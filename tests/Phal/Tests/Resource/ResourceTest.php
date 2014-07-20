<?php

namespace Phal\Tests;

use Phal\Resource;
use Phal\Link;
use Mockery as m;
use DateTime;

class ResourceTest extends TestCase
{
    public function setUp()
    {
        $this->resource = new Resource();
    }

    public function testSetId()
    {
        $id = 'foo';

        $this->assertSame($this->resource, $this->resource->setId($id));
        $this->assertSame($id, $this->resource->getId());
    }

    public function testSetRepositoryKey()
    {
        $key = 'foo';

        $this->assertSame($this->resource, $this->resource->setRepositoryKey($key));
        $this->assertSame($key, $this->resource->getRepositoryKey());
    }

    public function testSetTitle()
    {
        $title = 'foo';

        $this->assertSame($this->resource, $this->resource->setTitle($title));
        $this->assertSame($title, $this->resource->getTitle());
    }

    public function testSetLink()
    {
        $link = $this->createLinkMock();
        $this->resource->setLink('foo', $link);

        $links = $this->resource->getAllLinks();
        $this->assertSame($link, $links['foo']);
    }

    public function testSetLinks()
    {
        $linksExpected = [
            $this->createLinkMock(),
            $this->createLinkMock()
        ];

        $this->resource->setLinks('foo', $linksExpected);

        $links = $this->resource->getAllLinks();
        $this->assertSame($linksExpected, $links['foo']);
    }

    /**
     * @expectedException InvalidArgumentException
     */
    public function testSetLinksInvalid()
    {
        $linksExpected = [
            $this->createLinkMock(),
            'foo'
        ];

        $this->resource->setLinks('foo', $linksExpected);
    }

    public function testGetLink()
    {
        $link = $this->createLinkMock();
        $this->resource->setLink('foo', $link);

        $links = $this->resource->getLinks('foo');
        $this->assertSame($link, $links);

        $this->assertNull($this->resource->getLinks('bar'));
    }

    public function testLinkResource()
    {
        $linkedResource = new Resource($this->repository);
        $linkedResource->setURI('foo');

        $this->resource->linkResource('foo', $linkedResource);

        $links = $this->resource->getLinkedResources('foo');
        $this->assertSame($linkedResource, $links);

        $this->assertNull($this->resource->getLinkedResources('bar'));
    }

    public function testLinkResources()
    {
        $linkedResourceA = new Resource($this->repository);
        $linkedResourceA->setURI('foo');

        $linkedResourceB = new Resource($this->repository);
        $linkedResourceB->setURI('bar');

        $this->resource->linkResources('foo', [
            $linkedResourceA,
            $linkedResourceB
        ]);

        $links = $this->resource->getLinkedResources('foo');
        $this->assertSame([
            $linkedResourceA,
            $linkedResourceB
        ], $links);

        $this->assertNull($this->resource->getLinkedResources('bar'));
    }

    /**
     * @expectedException InvalidArgumentException
     */
    public function testSetResourcesInvalid()
    {
        $linkedResourceB = new Resource($this->repository);

        $this->resource->linkResources('foo', [
            $linkedResourceB
        ]);
    }

    public function testExpandLinkedResourcesOne()
    {
        $linkedResource = new Resource($this->repository);
        $linkedResource->setURI('foo');

        $this->resource->linkResource('foo', $linkedResource);
        $this->assertCount(0, $this->resource->getAllResources());

        $this->resource->expandLinkedResources('bar');
        $this->assertCount(0, $this->resource->getAllResources());

        $this->resource->expandLinkedResources('foo');
        $this->assertSame(
            $linkedResource,
            $this->resource->getResources('foo')
        );
    }

    public function testExpandLinkedResourcesMany()
    {
        $linkedResourceA = new Resource($this->repository);
        $linkedResourceA->setURI('foo');

        $linkedResourceB = new Resource($this->repository);
        $linkedResourceB->setURI('bar');

        $this->resource->linkResources('foo', [
            $linkedResourceA,
            $linkedResourceB
        ]);

        $this->assertCount(0, $this->resource->getAllResources());

        $this->resource->expandLinkedResources('foo');
        $this->assertSame(
            [$linkedResourceA, $linkedResourceB],
            $this->resource->getResources('foo')
        );
    }

    public function testExpandLinkedResourcesTreeOneLevel()
    {
        $linkedResource = new Resource($this->repository);
        $linkedResource->setURI('foo');

        $this->resource->linkResource('foo', $linkedResource);
        $this->assertCount(0, $this->resource->getAllResources());

        $this->resource->expandLinkedResourcesTree(['foo']);
        $this->assertSame(
            $linkedResource,
            $this->resource->getResources('foo')
        );
    }

    public function testExpandLinkedResourcesTreeTwoLevel()
    {
        $linkedLevel1Resource = new Resource($this->repository);
        $linkedLevel1Resource->setURI('foo');

        $linkedLevel2Resource = new Resource($this->repository);
        $linkedLevel2Resource->linkResource('bar', $linkedLevel1Resource);

        $this->resource->addResource('foo', $linkedLevel2Resource);
        $this->assertCount(0, $linkedLevel2Resource->getAllResources());

        $this->resource->expandLinkedResourcesTree(['foo', 'bar']);
        $this->assertSame(
            $linkedLevel1Resource,
            $linkedLevel2Resource->getResources('bar')
        );
    }

    public function testExpandLinkedResourcesTreeTwoLevelLinked()
    {
        $linkedLevel1Resource = new Resource($this->repository);
        $linkedLevel1Resource->setURI('foo');

        $linkedLevel2Resource = new Resource($this->repository);
        $linkedLevel2Resource->setURI('foo');
        $linkedLevel2Resource->linkResource('bar', $linkedLevel1Resource);

        $this->resource->linkResource('foo', $linkedLevel2Resource);
        $this->assertCount(0, $linkedLevel2Resource->getAllResources());

        $this->resource->expandLinkedResourcesTree(['foo', 'bar']);
        $this->assertSame(
            $linkedLevel1Resource,
            $linkedLevel2Resource->getResources('bar')
        );
    }

    public function testExpandLinkedResourcesTreeThreeLevelLinked()
    {
        $linkedLevel1Resource = new Resource($this->repository);
        $linkedLevel1Resource->setURI('foo');

        $linkedLevel2Resource = new Resource($this->repository);
        $linkedLevel2Resource->setURI('foo');
        $linkedLevel2Resource->linkResource('bar', $linkedLevel1Resource);

        $linkedPhalResource = new Resource($this->repository);
        $linkedPhalResource->setURI('foo');
        $linkedPhalResource->linkResource('qux', $linkedLevel2Resource);

        $this->resource->linkResource('foo', $linkedPhalResource);
        $this->assertCount(0, $linkedLevel2Resource->getAllResources());

        $this->resource->expandLinkedResourcesTree(['foo', 'qux', 'bar']);
        $this->assertSame(
            $linkedLevel1Resource,
            $linkedLevel2Resource->getResources('bar')
        );
    }

    public function testExpandLinkedResourcesTreeNotExists()
    {
        $this->resource->expandLinkedResourcesTree(['foo', 'bar']);
        $this->assertNull($this->resource->getResources('bar'));
    }

    /**
     * @expectedException InvalidArgumentException
     */
    public function testLinkResourceInvalid()
    {
        $linkedResource = new Resource($this->repository);

        $this->resource->linkResource('foo', $linkedResource);
        $links = $this->resource->getAllLinks();
        $this->assertInstanceOf('Phal\Link', $links['foo'][0]);
        $this->assertSame('foo', $links['foo'][0]->getHref());
    }

    public function testAddResource()
    {
        $resource = new Resource($this->repository);

        $this->resource->addResource('foo', $resource);
        $resources = $this->resource->getAllResources();
        $this->assertSame($resource, $resources['foo']);
    }

    public function testAddResources()
    {
        $resourceA = new Resource($this->repository);
        $resourceB = new Resource($this->repository);

        $this->resource->addResources('foo', [
            $resourceA,
            $resourceB
        ]);

        $resources = $this->resource->getAllResources();
        $this->assertSame([$resourceA, $resourceB], $resources['foo']);
    }

    /**
     * @expectedException \InvalidArgumentException
     */
    public function testAddResourcesInvalid()
    {
        $resourceA = new Resource($this->repository);
        $resourceB = new Resource($this->repository);

        $this->resource->addResources('foo', [
            $resourceA,
            'root'
        ]);

        $resources = $this->resource->getAllResources();
        $this->assertSame([$resourceA, $resourceB], $resources['foo']);
    }

    public function testGetResource()
    {
        $resource = new Resource($this->repository);

        $this->resource->addResource('foo', $resource);
        $resources = $this->resource->getResources('foo');
        $this->assertSame($resource, $resources);

        $this->assertNull($this->resource->getResources('bar'));
    }

    public function testSetData()
    {
        $this->assertSame($this->resource, $this->resource->setData(['foo' => 'bar']));
        $this->assertSame(['foo' => 'bar'], $this->resource->getData());
    }

    public function testAddData()
    {
        $this->assertSame($this->resource, $this->resource->addData('foo', 'bar'));
        $this->assertSame(['foo' => 'bar'], $this->resource->getData());
    }

    public function testSetURI()
    {
        $uri = 'foo';

        $this->assertSame($this->resource, $this->resource->setURI($uri));
        $this->assertSame($uri, $this->resource->getURI());
    }

    public function testSetLastUpdate()
    {
        $date = new DateTime();

        $this->assertSame($this->resource, $this->resource->setLastUpdate($date));
        $this->assertSame($date, $this->resource->getLastUpdate());
    }

    public function testSetCache()
    {
        $cache = 10;

        $this->assertSame($this->resource, $this->resource->setCache($cache));
        $this->assertSame($cache, $this->resource->getCache());
    }

    public function testGetSelfLinkNoUri()
    {
        $this->assertNull($this->resource->getSelfLink());
    }

    public function testGetSelfLink()
    {
        $this->resource->setId('qux');
        $this->resource->setUri('foo');
        $this->resource->setTitle('bar');

        $link = $this->resource->getSelfLink();

        $this->assertSame('foo', $link->getHref());
        $this->assertSame('qux', $link->getName());
        $this->assertSame('bar', $link->getTitle());
    }

    public function testSetFormatWriter()
    {
        $formatter = m::mock('Phal\Format\Writer');

        $this->assertSame($this->resource, $this->resource->setFormatWriter($formatter));
        $this->assertSame($formatter, $this->resource->getFormatWriter());
    }

    public function testToString()
    {
        $this->assertSame('', (string) $this->resource);

        $formatter = m::mock('Phal\Format\Writer');
        $formatter->shouldReceive('execute')
            ->with($this->resource)->once()->andReturn('bar');

        $this->resource->setFormatWriter($formatter);

        $this->assertSame('bar', (string) $this->resource);
    }
}
