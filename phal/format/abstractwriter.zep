
namespace Phal\Format;

use Phal\Entity;

abstract class AbstractWriter
{
    const CONTENT_TYPE_ANY = "*/*";

    /**
     * @var boolean
     */
    protected pretty;

    /**
     * Constructor
     *
     * @param boolean pretty
     */
    public function __construct(boolean pretty = false)
    {
        let this->pretty = pretty;
    }

    /**
     * Execute parsing
     *
     * @param \Phal\Entity $resource
     * @return mixed
     */
    abstract public function execute(<\Phal\Entity> $resource);

    /**
     * Return the content type string for the resource
     *
     * @return string
     */
    public function getContentType() -> string
    {
        return constant(get_called_class() . "::CONTENT_TYPE");
    }
}
