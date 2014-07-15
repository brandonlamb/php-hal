
namespace Phal;

class Link
{
    /**
     * @var string
     */
    protected href = "";

    /**
     * @var bool
     */
    protected templated = false;

    /**
     * @var string
     */
    protected type = "";

    /**
     * @var string
     */
    protected deprecation = "";

    /**
     * @var string
     */
    protected name = "";

    /**
     * @var string
     */
    protected profile = "";

    /**
     * @var string
     */
    protected title = "";

    /**
     * @var string
     */
    protected hreflang = "";

    /**
     * Constructor
     *
     * @param string href
     */
    public function __construct(string! href = "")
    {
        let this->href = href;
    }

    /**
     * Set href
     *
     * @param string href
     * @return \Phal\Link
     */
    public function setHref(string! href) -> <\Phal\Link>
    {
        let this->href = href;
        return this;
    }

    /**
     * Get href
     *
     * @return string
     */
    public function getHref() -> string
    {
        return this->href;
    }

    /**
     * Set templated
     *
     * @param boolean templated
     * @return \Phal\Link
     */
    public function setTemplated(boolean templated) -> <\Phal\Link>
    {
        let this->templated = templated;
        return this;
    }

    /**
     * Get templated
     *
     * @return boolean
     */
    public function getTemplated() -> boolean
    {
        return this->templated;
    }

    /**
     * Set type
     *
     * @param string type
     * @return \Phal\Link
     */
    public function setType(string! type) -> <\Phal\Link>
    {
        let this->type = type;
        return this;
    }

    /**
     * Get type
     *
     * @return string
     */
    public function getType() -> string
    {
        return this->type;
    }

    /**
     * Set deprecation
     *
     * @param string deprecation
     * @return \Phal\Link
     */
    public function setDeprecation(string! deprecation) -> <\Phal\Link>
    {
        let this->deprecation = deprecation;
        return this;
    }

    /**
     * Get deprecation
     *
     * @return string
     */
    public function getDeprecation() -> string
    {
        return this->deprecation;
    }

    /**
     * Set name
     *
     * @param string name
     * @return \Phal\Link
     */
    public function setName(string! name) -> <\Phal\Link>
    {
        let this->name = name;
        return this;
    }

    /**
     * Get name
     *
     * @return string
     */
    public function getName() -> string
    {
        return this->name;
    }

    /**
     * Set profile
     *
     * @param string profile
     * @return \Phal\Link
     */
    public function setProfile(string! profile) -> <\Phal\Link>
    {
        let this->profile = profile;
        return this;
    }

    /**
     * Get profile
     *
     * @return string
     */
    public function getProfile() -> string
    {
        return this->profile;
    }

    /**
     * Set name
     *
     * @param string name
     * @return \Phal\Link
     */
    public function setTitle(string! title) -> <\Phal\Link>
    {
        let this->title = title;
        return this;
    }

    /**
     * Get title
     *
     * @return string
     */
    public function getTitle() -> string
    {
        return this->title;
    }

    /**
     * Set hreflang
     *
     * @param string hreflang
     * @return \Phal\Link
     */
    public function setHreflang(string! hreflang) -> <\Phal\Link>
    {
        let this->hreflang = hreflang;
        return this;
    }

    /**
     * Get hreflang
     *
     * @return string
     */
    public function getHreflang() -> string
    {
        return this->hreflang;
    }

    /**
     * Get link attributes
     *
     * @return array
     */
    public function getAttributes() -> array
    {
        var attr;
        let attr = get_object_vars(this);
        unset attr["href"];

        return array_filter(attr);
    }

    /**
     * Serialize link to array
     *
     * @return array
     */
    public function toArray() -> array
    {
        return array_filter(get_object_vars(this), [this, "filterArray"]);
    }

    public function __toString() -> string
    {
        return this->{"getHref"}();
    }

    /**
     * Filter method for array_filter
     *
     * @param mixed value
     * @return boolean
     */
    public function filterArray(var value) -> boolean
    {
        return value !== null;
    }
}
