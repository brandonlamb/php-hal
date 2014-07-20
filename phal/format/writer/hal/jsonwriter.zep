
namespace Phal\Format\Writer\Hal;

use Phal\Format\Writer\AbstractJsonWriter;
use Phal\Entity;

class JsonWriter extends AbstractJsonWriter
{
    const CONTENT_TYPE = "application/hal+json";

    /**
     * @var array
     */
    private data;

    /**
     * @var array
     */
    private embedded;

    /**
     * Execute parsing
     *
     * @param \Phal\Entity $resource
     * @return array
     */
    protected function resourceToArray(<\Phal\Entity> $resource) -> array
    {
        let this->data = $resource->getData();
        this->transformResources($resource);
        this->transformLinks($resource);
        this->transformLinkedResources($resource);

        return this->data;
    }

    protected function transformLinks(<\Phal\Entity> $resource) -> void
    {
        var selfLink, rel, link, links;

        let selfLink = $resource->getSelfLink();
        if selfLink {
            let this->data["_links"]["self"] = selfLink->toArray();
        }

        for rel, links in $resource->getAllLinks() {
            if typeof links != "array" {
                let this->data["_links"][rel] = links->toArray();
            } else {
                for link in links {
                    let this->data["_links"][rel][] = link->toArray();
                }
            }
        }
    }

    protected function transformLinkedResources(<\Phal\Entity> $resource) -> void
    {
        var rel, link, links;

        for rel, links in $resource->getAllLinkedResources() {
            if typeof links != "array" {
                let this->data["_links"][rel] = links->getSelfLink()->toArray();
            } else {
                for link in links {
                    let this->data["_links"][rel][] = link->getSelfLink()->toArray();
                }
            }
        }
    }

    protected function transformResources(<\Phal\Entity> $resource) -> void
    {
        var rel, resources;

        let this->embedded = [];

        for rel, resources in $resource->getAllResources() {
            if resources instanceof \Phal\Entity {
                this->doTransformSingleResource(rel, resources);
            } else {
                this->doTransformResources(rel, resources);
            }
        }

        if count(this->embedded) > 0 {
            let this->data["_embedded"] = this->embedded;
        }
    }

    private function doTransformSingleResource(var rel, <\Phal\Entity> $resource) -> void
    {
        if !$resource->getUri() {
            let this->data[rel] = this->resourceToArray($resource);
        } else {
            let this->embedded[rel] = this->resourceToArray($resource);
        }
    }

    private function doTransformResource(var rel, <\Phal\Entity> $resource) -> void
    {
        if (!$resource->getUri()) {
            let this->data[rel][] = this->resourceToArray($resource);
        } else {
            let this->embedded[rel][] = this->resourceToArray($resource);
        }
    }

    private function doTransformResources(var rel, var resources) -> void
    {
        var $resource;

        if typeof resources != "array" {
            throw new \InvalidArgumentException("resources must be array");
        }

        for $resource in resources {
            this->doTransformResource(rel, $resource);
        }
    }
}
