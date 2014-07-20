
namespace Phal\Format;

abstract class AbstractReader
{
    /**
     * Execute parsing
     *
     * @param string input
     * @return mixed
     */
    abstract public function execute(string! input);

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
