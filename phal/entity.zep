
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
    protected resources;
    protected linkedResources;
    protected links;
    protected data;
    protected lastUpdate;
    protected cache;
    protected writer;

    /**
     * Constructor
     */
    public function __construct()
    {
        let this->resources = [];
        let this->linkedResources = [];
        let this->links = [];
        let this->data = [];
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

    public function setUri(var uri) -> <\Phal\Entity>
    {
        let this->uri = uri;
        return this;
    }

    public function getUri()
    {
        return this->uri;
    }

    public function setData(array data) -> <\Phal\Entity>
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

    public function setLinks(string! rel, array links) -> <\Phal\Entity>
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

    public function linkResource(string! rel, <\Phal\Entity> $resource) -> <\Phal\Entity>
    {
        this->throwExceptionIfNotLinkableResouce($resource);
        let this->linkedResources[rel] = $resource;
        return this;
    }

    public function linkResources(string! rel, array resources)
    {
        var $resource;

        for $resource in resources {
            this->throwExceptionIfNotLinkableResouce($resource);
        }

        let this->linkedResources[rel] = resources;

        return this;
    }

    protected function throwExceptionIfNotLinkableResouce(<\Phal\Entity> $resource)
    {
        var link;

        let link = $resource->getSelfLink();

        if !link {
            throw new InvalidArgumentException("This resource not contains a valid URI");
        }
    }

    public function expandLinkedResourcesTree(array path) -> void
    {
        var rel, $resource, resources;

        if count(path) == 1 {
            this->expandLinkedResources(end(path));
            return;
        }

        let rel = array_shift(path);
        this->expandLinkedResources(rel);

        let resources = this->getResources(rel);
        if !resources {
            return;
        }

        if typeof resources != "array" {
            let resources = [resources];
        }

        for $resource in resources {
            $resource->expandLinkedResourcesTree(path);
        }
    }

    public function expandLinkedResources(string! rel) -> void
    {
        var resources;

        let resources = this->getLinkedResources(rel);
        if !resources {
            return;
        }

        if typeof resources != "array" {
            this->addResource(rel, resources);
        } else {
            this->addResources(rel, resources);
        }
    }

    public function getAllLinkedResources() -> array
    {
        return this->linkedResources;
    }

    public function getLinkedResources(rel) -> array | null
    {
        var $resource;
        if fetch $resource, this->linkedResources[rel] {
            return $resource;
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

    public function addResource(string! rel, <\Phal\Entity> $resource) -> <\Phal\Entity>
    {
        let this->resources[rel] = $resource;
        return this;
    }

    public function addResources(string! rel, array resources)
    {
        var $resource;

        for $resource in resources {
            if !($resource instanceof \Phal\Entity) {
                throw new InvalidArgumentException("Invalid array, must be []Entity");
            }
        }

        let this->resources[rel] = resources;

        return this;
    }

    public function getAllResources() -> array
    {
        return this->resources;
    }

    public function getResources(string! rel)
    {
        var $resource;
        if fetch $resource, this->resources[rel] {
            return $resource;
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
