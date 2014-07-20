
namespace Phal\Format\Writer\Hal;

use Phal\Format\Writer\AbstractJsonWriter;
use Phal\Entity;

class JsonWriter extends AbstractJsonWriter
{
    const CONTENT_TYPE = "application/hal+json";

    /**
     * Execute parsing
     *
     * @param \Phal\Entity entity
     * @return array
     */
    protected function resourceToArray(<\Phal\Entity> entity) -> array
    {
        var data, links, embedded;

        // Get entity data
        let data = entity->getData();

        // Parse entity links
        let links = [];
        let links = this->transformLinks(links, entity);
        let links = this->transformLinkedResources(links, entity);
        if count(links) > 0 {
            let data["_links"] = links;
        }

        // Parse embedded resources
        let embedded = this->transformResources(entity);
        if count(embedded) > 0 {
            let data["_embedded"] = embedded;
        }

        return data;
    }

    /**
     * Transform links to array
     *
     * @param array data
     * @param \Phal\Entity entity
     * @return array
     */
    protected function transformLinks(var data, <\Phal\Entity> entity) -> array
    {
        var selfLink, rel, link, links;

        let selfLink = entity->getSelfLink();
        if selfLink {
            let data["self"] = selfLink->toArray();
        }

        for rel, links in entity->getAllLinks() {
            if typeof links != "array" {
                let data[rel] = links->toArray();
            } else {
                for link in links {
                    let data[rel][] = link->toArray();
                }
            }
        }

        return data;
    }

    protected function transformLinkedResources(var data, <\Phal\Entity> entity) -> array
    {
        var rel, link, links;

        if typeof data != "array" {
            throw new \InvalidArgumentException("data must be array");
        }

        for rel, links in entity->getAllLinkedResources() {
            if typeof links != "array" {
                let data[rel] = links->getSelfLink()->toArray();
            } else {
                for link in links {
                    let data[rel][] = link->getSelfLink()->toArray();
                }
            }
        }

        return data;
    }

    protected function transformResources(<\Phal\Entity> entity) -> array
    {
        var embedded, rel, subEntity, subEntity2;

        let embedded = [];

        for rel, subEntity in entity->getAllResources() {
            if typeof subEntity != "object" {
                // Collection of resources
                for subEntity2 in subEntity {
                    let embedded[rel][] = this->resourceToArray(subEntity2);
                }
            } else {
                // Single resource
                if subEntity instanceof \Phal\Entity {
                    let embedded[rel] = this->resourceToArray(entity);
                }
            }
        }

        return embedded;
    }
}
