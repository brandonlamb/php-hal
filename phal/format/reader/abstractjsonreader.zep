
namespace Phal\Format\Reader;

use Phal\Format\AbstractReader;
use Phal\Format\ReaderInterface;

abstract class AbstractJsonReader extends AbstractReader implements ReaderInterface
{
    /**
     * Parse array of data into resource
     *
     * @param array data
     * @return mixed
     */
    abstract protected function arrayToResource(var data);

    /**
     * Execute parsing
     *
     * @param string input
     * @return mixed
     */
    public function execute(string! input)
    {
        var data;
        let data = json_decode(input, true);
        return this->arrayToResource(data);
    }
}
