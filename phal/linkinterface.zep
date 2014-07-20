
namespace Phal;

interface LinkInterface
{
    /**
     * Constructor
     *
     * @param string href
     */
    public function __construct(
        string! href = null,
        boolean! templated = false,
        string! type = null,
        string! deprecation = null,
        string! name = null,
        string! profile = null,
        string! title = null,
        string! hreflang = null
    );

    /**
     * Set href
     *
     * @param string href
     * @return \Phal\LinkInterface
     */
    public function setHref(string! href) -> <\Phal\LinkInterface>;

    /**
     * Get href
     *
     * @return string
     */
    public function getHref() -> string;

    /**
     * Set templated
     *
     * @param boolean templated
     * @return \Phal\LinkInterface
     */
    public function setTemplated(boolean templated) -> <\Phal\LinkInterface>;

    /**
     * Get templated
     *
     * @return boolean
     */
    public function getTemplated() -> boolean;

    /**
     * Set type
     *
     * @param string type
     * @return \Phal\LinkInterface
     */
    public function setType(string! type) -> <\Phal\LinkInterface>;

    /**
     * Get type
     *
     * @return string
     */
    public function getType() -> string;

    /**
     * Set deprecation
     *
     * @param string deprecation
     * @return \Phal\LinkInterface
     */
    public function setDeprecation(string! deprecation) -> <\Phal\LinkInterface>;

    /**
     * Get deprecation
     *
     * @return string
     */
    public function getDeprecation() -> string;

    /**
     * Set name
     *
     * @param string name
     * @return \Phal\LinkInterface
     */
    public function setName(string! name) -> <\Phal\LinkInterface>;

    /**
     * Get name
     *
     * @return string
     */
    public function getName() -> string;

    /**
     * Set profile
     *
     * @param string profile
     * @return \Phal\LinkInterface
     */
    public function setProfile(string! profile) -> <\Phal\LinkInterface>;

    /**
     * Get profile
     *
     * @return string
     */
    public function getProfile() -> string;

    /**
     * Set name
     *
     * @param string name
     * @return \Phal\LinkInterface
     */
    public function setTitle(string! title) -> <\Phal\LinkInterface>;

    /**
     * Get title
     *
     * @return string
     */
    public function getTitle() -> string;

    /**
     * Set hreflang
     *
     * @param string hreflang
     * @return \Phal\LinkInterface
     */
    public function setHreflang(string! hreflang) -> <\Phal\LinkInterface>;

    /**
     * Get hreflang
     *
     * @return string
     */
    public function getHreflang() -> string;

    /**
     * Get link attributes
     *
     * @return array
     */
    public function getAttributes() -> array;

    /**
     * Serialize link to array
     *
     * @return array
     */
    public function toArray() -> array;

    /**
     * Return serialized string
     *
     * @return string
     */
    public function __toString() -> string;
}
