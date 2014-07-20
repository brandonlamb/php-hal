<?php

namespace Phal\Tests;

use Phal\Mocks\Mapper;
use Mockery as m;

class TestCase extends \PHPUnit_Framework_TestCase
{
    const IRRELEVANT_KEY = 'X';
    const IRRELEVANT_HREF = 'XX';

    protected function createPhalMock()
    {
        return m::mock('Phal\\Phal');
    }

    protected function createMapperMock()
    {
        return m::mock('Phal\\Mapper');
    }

    protected function createHubMock()
    {
        return m::mock('Phal\\Hub');
    }

    protected function createLinkMock()
    {
        return m::mock('Phal\\Link');
    }

    protected function createFinderMock()
    {
        return m::mock('Phal\\Repository,Phal\\Repository\\Finder');
    }

    protected function createGetterMock()
    {
        return m::mock('Phal\\Repository,Phal\\Repository\\Getter');
    }

    protected function createDeleterMock()
    {
        return m::mock('Phal\\Repository,Phal\\Repository\\Deleter');
    }

    protected function createPutterMock()
    {
        return m::mock('Phal\\Repository,Phal\\Repository\\Putter');
    }

    protected function createPosterMock()
    {
        return m::mock('Phal\\Repository,Phal\\Repository\\Poster');
    }

    protected function createPatcherMock()
    {
        return m::mock('Phal\\Repository,Phal\\Repository\\Patcher');
    }

    protected function createRepositoryMock()
    {
        return m::mock('Phal\\Repository');
    }

    protected function createMethodMock()
    {
        return m::mock('Phal\\Processor\\Wrapper\\Authenticator\\Method');
    }

    protected function createResourceMock($mockMethods = true)
    {
        $resource = m::mock('Phal\\Resource');

        if ($mockMethods) {
            $resource->shouldReceive('getCache')->andReturn(null);
            $resource->shouldReceive('getId')->andReturn(null);
            $resource->shouldReceive('getLastUpdate')->andReturn(null);
        }

        return $resource;
    }

    protected function createProcessorMock()
    {
        return m::mock('Phal\\Processor');
    }

    protected function createFormatterMock()
    {
        $formatter = m::mock('Phal\\Format\\Writer');
        $formatter->shouldReceive('getContentType')->andReturn('foo/bar');

        return $formatter;
    }

    protected function createParametersMock()
    {
        $parameters = m::mock('Phal\\Messages\\Parameters');
        $parameters->shouldReceive('getIterator');

        return $parameters;
    }

    protected function createWrapperMock()
    {
        return m::mock('Phal\\Processor\\Wrapper\\ExceptionHandler');
    }

    protected function createRequestMockSimple()
    {
        return m::mock('Phal\\Messages\\Request');
    }

    protected function createResponseMock()
    {
        return m::mock('Phal\\Messages\\Response');
    }

    protected function createRequestMock(
        $attributes = null, $filters = null, $formatter = null,
        $repository = null, $content = null, $key = self::IRRELEVANT_KEY
    ) {
        $request = $this->createRequestMockSimple();
        if ($key) {
            $request->shouldReceive('getKey')
                ->withNoArgs()->once()->andReturn($key);
        }

        if ($attributes) {
            $request->shouldReceive('getAttributes')
                ->withNoArgs()->once()->andReturn($attributes);
        }

        if ($filters) {
            $request->shouldReceive('getFilters')
                ->withNoArgs()->once()->andReturn($filters);
        }

        if ($content) {
            $request->shouldReceive('getContent')
                ->withNoArgs()->once()->andReturn($content);
        }

        if ($formatter) {
            $request->shouldReceive('getFormatter')
                ->withNoArgs()->once()->andReturn($formatter);
        }

        return $request;
    }
}
