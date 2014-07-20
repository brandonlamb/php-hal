
namespace Phal;

use Phal\Link;
use Phal\Format\Writer;
use RuntimeException;
use InvalidArgumentException;

class Entity
{
    protected id;
    protected title;
    protected key;
    protected relation;
    protected uri;
    protected entities;
    protected linkedResources;
    protected links;
    protected data;
    protected lastUpdate;
    protected cache;
    protected writer;

    /**
     * Constructor
     */
    public function __construct(string! uri = null)
    {
        let this->entities = [];
        let this->linkedResources = [];
        let this->links = [];
        let this->data = [];

        if typeof uri != "null" {
            this->setUri(uri);
        }
    }

    public function setId(var id)
    {
        let this->id = id;
        return this;
    }

    public function getId()
    {
        return this->id;
    }

    public function setRepositoryKey($key) -> <\Phal\Entity>
    {
        let this->key = key;
        return this;
    }

    public function getRepositoryKey()
    {
        return this->key;
    }

    public function setTitle(var title) -> <\Phal\Entity>
    {
        let this->title = title;
        return this;
    }

    public function getTitle()
    {
        return this->title;
    }

    public function setUri(string! uri) -> <\Phal\Entity>
    {
        let this->uri = uri;
        return this;
    }

    public function getUri()
    {
        return this->uri;
    }

    public function setData(var data) -> <\Phal\Entity>
    {
        let this->data = data;
        return this;
    }

    public function addData(string! key, var value) -> <\Phal\Entity>
    {
        let this->data[key] = value;
        return this;
    }

    public function getData() -> array
    {
        return this->data;
    }

    public function setLink(string! rel, <\Phal\Link> link) -> <\Phal\Entity>
    {
        let this->links[rel] = link;
        return this;
    }

    public function setLinks(string! rel, var links) -> <\Phal\Entity>
    {
        var link;

        for link in links {
            if !(link instanceof \Phal\Link) {
                throw new InvalidArgumentException("Invalid array, must be []Link");
            }
        }

        let this->links[rel] = links;

        return this;
    }

    public function linkResource(string! rel, <\Phal\Entity> entity) -> <\Phal\Entity>
    {
        this->throwExceptionIfNotLinkableResouce(entity);
        let this->linkedResources[rel] = entity;
        return this;
    }

    public function linkResources(string! rel, var entities)
    {
        var entity;

        for entity in entities {
            this->throwExceptionIfNotLinkableResouce(entity);
        }

        let this->linkedResources[rel] = entities;

        return this;
    }

    protected function throwExceptionIfNotLinkableResouce(<\Phal\Entity> entity)
    {
        var link;

        let link = entity->getSelfLink();

        if !link {
            throw new InvalidArgumentException("This resource not contains a valid URI");
        }
    }

    public function expandLinkedResourcesTree(var path) -> void
    {
        var rel, entity, entities;

        if count(path) == 1 {
            this->expandLinkedResources(end(path));
            return;
        }

        let rel = array_shift(path);
        this->expandLinkedResources(rel);

        let entities = this->getResources(rel);
        if !entities {
            return;
        }

        if typeof entities != "array" {
            let entities = [entities];
        }

        for entity in entities {
            entity->expandLinkedResourcesTree(path);
        }
    }

    public function expandLinkedResources(string! rel) -> void
    {
        var entities;

        let entities = this->getLinkedResources(rel);
        if !entities {
            return;
        }

        if typeof entities != "array" {
            this->addResource(rel, entities);
        } else {
            this->addResources(rel, entities);
        }
    }

    public function getAllLinkedResources() -> array
    {
        return this->linkedResources;
    }

    public function getLinkedResources(rel) -> array | null
    {
        var entity;
        if fetch entity, this->linkedResources[rel] {
            return entity;
        }
        return null;
    }

    public function getAllLinks() -> array
    {
        return this->links;
    }

    public function getLinks(rel)
    {
        var link;
        if fetch link, this->links[rel] {
            return link;
        }

        return null;
    }

    public function addResource(string! rel, <\Phal\Entity> entity, boolean! multi = true) -> <\Phal\Entity>
    {
        if unlikely !multi {
            // Set single resource
            let this->entities[rel] = entity;
        } else {
            // Adding a resource to a collection, make sure rel is an array
            if unlikely !isset this->entities[rel] {
                let this->entities[rel] = [];
                let this->entities[rel][] = entity;
            } else {
                let this->entities[rel][] = entity;
            }
        }

        return this;
    }

    public function addResources(string! rel, var entities, boolean! overwrite = false)
    {
        var entity;
        if unlikely overwrite {
            let this->entities[rel] = [];
        }
        for entity in entities {
            this->addResource(rel, entity, true);
        }
        return this;
    }

    public function getAllResources() -> array
    {
        return this->entities;
    }

    public function getResources(string! rel)
    {
        var entity;
        if fetch entity, this->entities[rel] {
            return entity;
        }
        return null;
    }

    public function getSelfLink() -> <\Phal\Link> | null
    {
        var link;

        if !this->uri {
            return null;
        }

        let link = new Link(this->getURI());
        link->setTitle(this->getTitle());
        link->setName(this->getId());

        return link;
    }

    public function setLastUpdate(<\DateTime> date) -> <\Phal\Entity>
    {
        let this->lastUpdate = date;
        return this;
    }

    public function getLastUpdate() -> <\DateTime> | null
    {
        return this->lastUpdate;
    }

    public function setCache(int secs) -> <\Phal\Entity>
    {
        let this->cache = secs;
        return this;
    }

    public function getCache() -> int
    {
        return this->cache;
    }

    public function setFormatWriter(<\Phal\Format\AbstractWriter> writer) -> <\Phal\Entity>
    {
        let this->writer = writer;
        return this;
    }

    public function getFormatWriter() -> <\Phal\Format\AbstractWriter> | null
    {
        return this->writer;
    }

    public function __toString() -> string
    {
        if !this->writer {
            return "";
        }
        return this->writer->execute(this);
    }
}
