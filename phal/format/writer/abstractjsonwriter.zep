
namespace Phal\Format\Writer;

use Phal\Format\AbstractWriter;
use Phal\Format\WriterInterface;

abstract class AbstractJsonWriter extends AbstractWriter implements WriterInterface
{
    /**
     * Execute parsing
     *
     * @param \Phal\Entity $resource
     * @return array
     */
    abstract protected function resourceToArray(<\Phal\Entity> $resource) -> array;

    /**
     * Execute parsing
     *
     * @param \Phal\Entity $resource
     * @return mixed
     */
    public function execute(<\Phal\Entity> $resource) -> string
    {
        if unlikely !this->pretty {
            return json_encode(this->resourceToArray($resource), JSON_UNESCAPED_SLASHES);
        }
        return json_encode(this->resourceToArray($resource), JSON_UNESCAPED_SLASHES | JSON_PRETTY_PRINT);
    }
}
