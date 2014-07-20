
namespace Phal\Format\Reader\Hal;

use Phal\Format\Reader\AbstractJsonReader;
use Phal\Entity;
use Phal\Link;

class JsonReader extends AbstractJsonReader
{
    const CONTENT_TYPE = "application/hal+json";

    const RESOURCE_KEY_LINKS = "_links";
    const RESOURCE_KEY_EMBEDDED = "_embedded";
    const RESOURCE_LINK_SELF = "self";

    const LINK_KEY_HREF = "href";
    const LINK_KEY_TEMPLATED = "templated";
    const LINK_KEY_TYPE = "type";
    const LINK_KEY_DEPRECATION = "deprecation";
    const LINK_KEY_NAME = "name";
    const LINK_KEY_PROFILE = "profile";
    const LINK_KEY_TITLE = "title";
    const LINK_KEY_HREFLANG = "hreflang";

    protected function arrayToResource(var data) -> <\Phal\Entity>
    {
        if typeof data != "array" {
            throw new \InvalidArgumentException("data must be array");
        }
        return this->doTransformEmbedded(data);
    }

    /**
     * @param \Phal\Entity
     * @param array data
     * @return void
     */
    protected function transformMetadata(<\Phal\Entity> $resource, var data) -> void
    {
        var key;

        if typeof data != "array" {
            throw new \InvalidArgumentException("data must be array");
        }

        if fetch key, data[self::RESOURCE_KEY_LINKS] {
            this->transformLinks($resource, key);
        }

        if fetch key, data[self::RESOURCE_KEY_EMBEDDED] {
            this->transformEmbeddeds($resource, key);
        }
    }

    /**
     *
     * @param \Phal\Entity $resource
     * @param array linksByRel
     * @return void
     */
    protected function transformLinks(<\Phal\Entity> $resource, var linksByRel) -> void
    {
        var rel, data, link, links;

        if typeof linksByRel != "array" {
            throw new \InvalidArgumentException("linksByRel must be array");
        }

        for rel, data in linksByRel {
            if rel == self::RESOURCE_LINK_SELF {
                this->transformSelfLink($resource, data);
                continue;
            }

            if this->isAssocArray(data) {
                let link = this->doTransformLink(data);
                $resource->setLink(rel, link);
            } else {
                let links = this->doTransformLinks(data);
                $resource->setLinks(rel, links);
            }
        }
    }

    /**
     * @param \Phal\Entity
     * @param array data
     * @return void
     */
    protected function transformSelfLink(<\Phal\Entity> $resource, var data) -> void
    {
        var key;

        if typeof data != "array" {
            throw new \InvalidArgumentException("data must be array");
        }

        if fetch key, data[self::LINK_KEY_HREF] {
            $resource->setURI(key);
        }

        if fetch key, data[self::LINK_KEY_TITLE] {
            $resource->setTitle(key);
        }
    }

    /**
     * @param data
     * @return array
     */
    protected function doTransformLinks(var data) -> array
    {
        var link, links;

        if typeof data != "array" {
            throw new \InvalidArgumentException("data must be array");
        }

        let links = [];
        for link in data {
            let links[] = this->doTransformLink(link);
        }

        return links;
    }

    /**
     * @param array data
     * @return \Phal\Link
     */
    protected function doTransformLink(array data) -> <\Phal\Link>
    {
        var link, key;

        let link = new Link();

        if fetch key, data[self::LINK_KEY_HREF] {
            link->setHref(key);
        }

        if fetch key, data[self::LINK_KEY_TEMPLATED] {
            link->setTemplated(key);
        }

        if fetch key, data[self::LINK_KEY_TYPE] {
            link->setType(key);
        }

        if fetch key, data[self::LINK_KEY_DEPRECATION] {
            link->setDeprecation(key);
        }

        if fetch key, data[self::LINK_KEY_NAME] {
            link->setName(key);
        }

        if fetch key, data[self::LINK_KEY_PROFILE] {
            link->setProfile(key);
        }

        if fetch key, data[self::LINK_KEY_TITLE] {
            link->setTitle(key);
        }

        if fetch key, data[self::LINK_KEY_HREFLANG] {
            link->setHreflang(key);
        }

        return link;
    }

    /**
     * @param \Phal\Entity $resource
     * @param array embeddedByRel
     * @return void
     */
    protected function transformEmbeddeds(<\Phal\Entity> $resource, var embeddedsByRel) -> void
    {
        var rel, data, embedded, embeddeds;

        if typeof embeddedsByRel != "array" {
            throw new \InvalidArgumentException("embeddedsByRel must be array");
        }

        for rel, data in embeddedsByRel {
            if this->isAssocArray(data) {
                let embedded = this->doTransformEmbedded(data);
                $resource->addResource(rel, embedded);
            } else {
                let embeddeds = this->doTransformEmbeddeds(data);
                $resource->addResources(rel, embeddeds);
            }
        }
    }

    /**
     * Transform each embedded entity, return transformed array
     *
     * @param array data
     * @return array
     */
    protected function doTransformEmbeddeds(var data) -> array
    {
        var embedded, embeddeds;

        if typeof data != "array" {
            throw new \InvalidArgumentException("data must be array");
        }

        let  embeddeds = [];
        for embedded in data {
            let embeddeds[] = this->doTransformEmbedded(embedded);
        }

        return embeddeds;
    }

    /**
     * @param array data
     * @return \Phal\Entity
     */
    protected function doTransformEmbedded(var data) -> <\Phal\Entity>
    {
        var $resource, key, value;

        if typeof data != "array" {
            throw new \InvalidArgumentException("data must be array");
        }

        let $resource = new Entity();

        for key, value in data {
            if substr(key, 0, 1) !== "_" {
                $resource->addData(key, value);
            }
        }

        this->transformMetadata($resource, data);

        return $resource;
    }

    /**
     * Determine if data is associative array
     *
     * @param mixed data
     * @return boolean
     */
    private function isAssocArray(var data) -> boolean
    {
        return array_keys(data) !== range(0, count(data) - 1);
    }
}
