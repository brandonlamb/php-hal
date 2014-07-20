php-hal
=======

PHP library for representing HAL resources for REST API

[![Build
Status](https://travis-ci.org/brandonlamb/php-hal.png?branch=master)](https://travis-ci.org/brandonlamb/php-hal)
[![Latest Stable Version](https://poser.pugx.org/brandonlamb/php-hal/v/stable.png)](https://packagist.org/packages/brandonlamb/php-hal)
[![Total Downloads](https://poser.pugx.org/brandonlamb/php-hal/downloads.png)](https://packagist.org/packages/brandonlamb/php-hal)

PhpHal [![Build Status](https://travis-ci.org/level3php/resource.png?branch=master)](https://travis-ci.org/level3php/resource)
==============================

PhpHal is a library for representing and consuming resources in different [hypermedia](http://en.wikipedia.org/wiki/Hypermedia)
formats.

A resource in a [HATEOAS API] (http://en.wikipedia.org/wiki/HATEOAS) must describe its own capabilities
and interconnections, which is the third level of [Three Levels of the REST Maturity Model](http://www.infoq.com/news/2010/03/RESTLevels)

### Why Hypermedia?

As you can read in the prologue of [Designing Hypermedia APIs](http://www.designinghypermediaapis.com/) book:

>Hypermedia APIs embrace the principles that make the web great: flexibility, standardization, and loose coupling
to any given service. They take into account the principles of systems design [enumerated by Roy Fielding in his thesis](http://www.ics.uci.edu/~fielding/pubs/dissertation/top.htm),
but with a little less sytems theory jargon.

>Hypermedia designs scale better, are more easily changed and promote decoupling and encapsulation, with all the
benefits those things bring. On the downside, it is not necessarily the most latency-tolerant design, and caches
can get stale if you're not careful. It may not be as efficient on an individual request level as other designs.

>-- [Steve Klabnik](http://www.steveklabnik.com/)

### Which Hypermedia specification should I use?

Hypermedia is being defined these days. Only the best APIs implement Hypermedia. Currently there is no de
facto standard, so you must choose between the differents specifications.

PhpHal currenly implements or is planned to implement these specifications:
* [HAL](http://stateless.co/hal_specification.html): This is the most common and active. It has a JSON and a XML version.
* [Siren](https://github.com/kevinswiber/siren): Currently being defined. It implements some useful things like actions, classes, etc.
* [Collection+JSON](http://amundsen.com/media-types/collection/): This is fully designed to be a CRUD oriented API.


Requirements
------------

* PHP 5.4.x

Installation
------------

The recommended way to install PhpHal is [through composer](http://getcomposer.org).
You can see [the package information on Packagist.](https://packagist.org/packages/brandonlamb/php-hal)

```JSON
{
    "require": {
        "brandonlamb/php-hal": "dev-master"
    }
}
```


Examples
--------

### Writer

#### Basic Resource with Link as ```application/hal+json```

```php
use PhpHal\Link;
use PhpHal\Resource;
use PhpHal\Format\Writer\Hal;

$resource = new Resource();
$resource->setURI('/foo');
$resource->setLink('foo', new Link('/bar'));
$resource->setData([
    'foo' => 'bar',
    'baz' => 'qux'
]);

$writer = new Hal\JsonWriter(true);
echo $writer->execute($resource);
```

```js
{
    "foo": "bar",
    "baz": "qux",
    "_links": {
        "self": {
            "href": "/foo"
        },
        "foo": {
            "href": "/bar"
        }
    }
}
```

#### Resource with embedded resources as ```aapplication/vnd.siren+json```

```php
use PhpHal\Link;
use PhpHal\Resource;
use PhpHal\Format\Writer\Siren;

$resource = new Resource();
$resource->setRepositoryKey('index');
$resource->setURI('/index?page=2');
$resource->setLink('prev', new Link('/index?page=1'));
$resource->setLink('next', new Link('/index?page=3'));
$resource->addData('count', 5);

$subresource = [];
foreach (range(1, 5) as $value) {
    $subresource = new Resource();
    $subresource->addData('value', $value);

    $subresources[] = $subresource;
}

$resource->addResources('subresources', $subresources);

$writer = new Siren\JsonWriter(true);
echo $writer->execute($resource);
```

```json
{
    "class": [
        "index"
    ],
    "properties": {
        "count": 5
    },
    "entities": [
        {
            "rel": "subresources",
            "class": [
                "index",
                "subresources"
            ],
            "properties": {
                "value": 1
            }
        },
        ...
        {
            "rel": "subresources",
            "class": [
                "index",
                "subresources"
            ],
            "properties": {
                "value": 5
            }
        }
    ],
    "links": [
        {
            "rel": "self",
            "href": "/index?page=2"
        },
        {
            "rel": "prev",
            "href": "/index?page=1"
        },
        {
            "rel": "next",
            "href": "/index?page=3"
        }
    ]
}
```

#### Resource with linked resource as ```application/hal+xml```

```php
use PhpHal\Link;
use PhpHal\Resource;
use PhpHal\Format\Writer\Hal;

$author = new Resource();
$author->setURI('/john-doe');
$author->setTitle('John Doe');

$article = new Resource();
$article->setURI('/lorem-ipsum');
$article->addData('description', 'Lorem ipsum dolor sit amet ...');
$article->linkResource('author', $author);

$writer = new Hal\XmlWriter(true);
echo $writer->execute($article);
```

```xml
<?xml version="1.0"?>
<resource href="/lorem-ipsum">
  <description>Lorem ipsum dolor sit amet ...</description>
  <link rel="author" href="/john-doe" title="John Doe"/>
</resource>
```
### Reader

#### Basic Resource with Link as ```application/hal+json```

```php
use PhpHal\Format\Reader\Hal;

$json = '{"foo":"bar","baz":"qux","_links":{"self":{"href":"/foo"},"foo":{"href":"/bar"}}}';

$reader = new Hal\JsonReader();
$resource = $reader->execute($json);
print_r($resource);
```

```php
PhpHal\Resource Object
(
    [uri:protected] => /foo
    [links:protected] => Array
        (
            [foo] => PhpHal\Link Object
                (
                    [href:protected] => /bar
                )

        )

    [data:protected] => Array
        (
            [foo] => bar
            [baz] => qux
        )

)
```

Tests
-----

Tests are in the `tests` folder.
To run them, you need PHPUnit.
Example:

    $ phpunit --configuration phpunit.xml.dist


License
-------

MIT, see [LICENSE](LICENSE)
