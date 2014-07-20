
namespace Phal\Format;

interface WriterInterface
{
    /**
     * Constructor
     *
     * @param boolean pretty
     */
    public function __construct(boolean pretty = false);

    /**
     * Execute parsing
     *
     * @param \Phal\Entity $resource
     * @return mixed
     */
    public function execute(<\Phal\Entity> $resource);

    /**
     * Return the content type string for the resource
     *
     * @return string
     */
    public function getContentType() -> string;
}
