
namespace Phal;

class Link implements LinkInterface
{
    /**
     * @var string
     */
    protected href;

    /**
     * @var bool
     */
    protected templated;

    /**
     * @var string
     */
    protected type;

    /**
     * @var string
     */
    protected deprecation;

    /**
     * @var string
     */
    protected name;

    /**
     * @var string
     */
    protected profile;

    /**
     * @var string
     */
    protected title;

    /**
     * @var string
     */
    protected hreflang;

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
    )
    {
        let this->href = href;
        let this->templated = templated;
        let this->type = type;
        let this->deprecation = deprecation;
        let this->name = name;
        let this->profile = profile;
        let this->title = title;
        let this->hreflang = hreflang;
    }

    /**
     * Set href
     *
     * @param string href
     * @return \Phal\LinkInterfaceInterface
     */
    public function setHref(string! href) -> <\Phal\LinkInterface>
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
     * @return \Phal\LinkInterface
     */
    public function setTemplated(boolean templated) -> <\Phal\LinkInterface>
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
     * @return \Phal\LinkInterface
     */
    public function setType(string! type) -> <\Phal\LinkInterface>
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
     * @return \Phal\LinkInterface
     */
    public function setDeprecation(string! deprecation) -> <\Phal\LinkInterface>
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
     * @return \Phal\LinkInterface
     */
    public function setName(string! name) -> <\Phal\LinkInterface>
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
     * @return \Phal\LinkInterface
     */
    public function setProfile(string! profile) -> <\Phal\LinkInterface>
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
     * @return \Phal\LinkInterface
     */
    public function setTitle(string! title) -> <\Phal\LinkInterface>
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
     * @return \Phal\LinkInterface
     */
    public function setHreflang(string! hreflang) -> <\Phal\LinkInterface>
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
        array data = [];

        if this->href != "" {
            let data["href"] = this->href;
        }

        if this->templated {
            let data["templated"] = true;
        }

        if this->type != "" {
            let data["type"] = this->type;
        }

        if this->deprecation != "" {
            let data["deprecation"] = this->deprecation;
        }

        if this->name != "" {
            let data["name"] = this->name;
        }

        if this->profile != "" {
            let data["profile"] = this->profile;
        }

        if this->title != "" {
            let data["title"] = this->title;
        }

        if this->hreflang != "" {
            let data["hreflang"] = this->hreflang;
        }

        return data;
    }

    /**
     * Return serialized string
     *
     * @return string
     */
    public function __toString() -> string
    {
        return this->{"getHref"}();
    }
}
