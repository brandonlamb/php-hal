<?php

namespace PhpHal\Tests;

use PhpHal\Mocks\Mapper;
use Mockery as m;

class TestCase extends \PHPUnit_Framework_TestCase
{
    const IRRELEVANT_KEY = 'X';
    const IRRELEVANT_HREF = 'XX';

    protected function createPhpHalMock()
    {
        return m::mock('PhpHal\\PhpHal');
    }

    protected function createMapperMock()
    {
        return m::mock('PhpHal\\Mapper');
    }

    protected function createHubMock()
    {
        return m::mock('PhpHal\\Hub');
    }

    protected function createLinkMock()
    {
        return m::mock('PhpHal\\Link');
    }

    protected function createFinderMock()
    {
        return m::mock('PhpHal\\Repository,PhpHal\\Repository\\Finder');
    }

    protected function createGetterMock()
    {
        return m::mock('PhpHal\\Repository,PhpHal\\Repository\\Getter');
    }

    protected function createDeleterMock()
    {
        return m::mock('PhpHal\\Repository,PhpHal\\Repository\\Deleter');
    }

    protected function createPutterMock()
    {
        return m::mock('PhpHal\\Repository,PhpHal\\Repository\\Putter');
    }

    protected function createPosterMock()
    {
        return m::mock('PhpHal\\Repository,PhpHal\\Repository\\Poster');
    }

    protected function createPatcherMock()
    {
        return m::mock('PhpHal\\Repository,PhpHal\\Repository\\Patcher');
    }

    protected function createRepositoryMock()
    {
        return m::mock('PhpHal\\Repository');
    }

    protected function createMethodMock()
    {
        return m::mock('PhpHal\\Processor\\Wrapper\\Authenticator\\Method');
    }

    protected function createResourceMock($mockMethods = true)
    {
        $resource = m::mock('PhpHal\\Resource');

        if ($mockMethods) {
            $resource->shouldReceive('getCache')->andReturn(null);
            $resource->shouldReceive('getId')->andReturn(null);
            $resource->shouldReceive('getLastUpdate')->andReturn(null);
        }

        return $resource;
    }

    protected function createProcessorMock()
    {
        return m::mock('PhpHal\\Processor');
    }

    protected function createFormatterMock()
    {
        $formatter = m::mock('PhpHal\\Format\\Writer');
        $formatter->shouldReceive('getContentType')->andReturn('foo/bar');

        return $formatter;
    }

    protected function createParametersMock()
    {
        $parameters = m::mock('PhpHal\\Messages\\Parameters');
        $parameters->shouldReceive('getIterator');

        return $parameters;
    }

    protected function createWrapperMock()
    {
        return m::mock('PhpHal\\Processor\\Wrapper\\ExceptionHandler');
    }

    protected function createRequestMockSimple()
    {
        return m::mock('PhpHal\\Messages\\Request');
    }

    protected function createResponseMock()
    {
        return m::mock('PhpHal\\Messages\\Response');
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
