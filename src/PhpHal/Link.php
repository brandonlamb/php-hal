<?php

namespace PhpHal;

class Link implements LinkInterface
{
    /**
     * @var string
     */
    protected $href;

    /**
     * @var bool
     */
    protected $templated;

    /**
     * @var string
     */
    protected $type;

    /**
     * @var string
     */
    protected $deprecation;

    /**
     * @var string
     */
    protected $name;

    /**
     * @var string
     */
    protected $profile;

    /**
     * @var string
     */
    protected $title;

    /**
     * @var string
     */
    protected $hreflang;

    /**
     * Constructor
     *
     * @param string $href
     * @param bool $templated
     * @param string $type
     * @param string $deprecation
     * @param string $name
     * @param string $profile
     * @param string $title
     * @param string $hreflang
     */
    public function __construct(
        $href = null,
        $templated = false,
        $type = null,
        $deprecation = null,
        $name = null,
        $profile = null,
        $title = null,
        $hreflang = null
    )
    {
        $this->href = $href;
        $this->templated = $templated;
        $this->type = $type;
        $this->deprecation = $deprecation;
        $this->name = $name;
        $this->profile = $profile;
        $this->title = $title;
        $this->hreflang = $hreflang;
    }

    /**
     * Set href
     *
     * @param string $href
     * @return \PhpHal\LinkInterfaceInterface
     */
    public function setHref($href)
    {
        $this->href = (string) $href;
        return $this;
    }

    /**
     * Get href
     *
     * @return string
     */
    public function getHref()
    {
        return (string) $this->href;
    }

    /**
     * Set templated
     *
     * @param boolean $templated
     * @return \PhpHal\LinkInterface
     */
    public function setTemplated($templated)
    {
        $this->templated = (bool) $templated;
        return $this;
    }

    /**
     * Get templated
     *
     * @return boolean
     */
    public function isTemplated()
    {
        return (bool) $this->templated;
    }

    /**
     * Set type
     *
     * @param string $type
     * @return \PhpHal\LinkInterface
     */
    public function setType($type)
    {
        $this->type = (string) $type;
        return $this;
    }

    /**
     * Get type
     *
     * @return string
     */
    public function getType()
    {
        return (string) $this->type;
    }

    /**
     * Set deprecation
     *
     * @param string $deprecation
     * @return \PhpHal\LinkInterface
     */
    public function setDeprecation($deprecation)
    {
        $this->deprecation = (string) $deprecation;
        return $this;
    }

    /**
     * Get deprecation
     *
     * @return string
     */
    public function getDeprecation()
    {
        return (string) $this->deprecation;
    }

    /**
     * Set name
     *
     * @param string $name
     * @return \PhpHal\LinkInterface
     */
    public function setName($name)
    {
        $this->name = (string) $name;
        return $this;
    }

    /**
     * Get name
     *
     * @return string
     */
    public function getName()
    {
        return (string) $this->name;
    }

    /**
     * Set profile
     *
     * @param string $profile
     * @return \PhpHal\LinkInterface
     */
    public function setProfile($profile)
    {
        $this->profile = (string) $profile;
        return $this;
    }

    /**
     * Get profile
     *
     * @return string
     */
    public function getProfile()
    {
        return (string) $this->profile;
    }

    /**
     * Set title
     *
     * @param string $title
     * @return \PhpHal\LinkInterface
     */
    public function setTitle($title)
    {
        $this->title = (string) $title;
        return $this;
    }

    /**
     * Get title
     *
     * @return string
     */
    public function getTitle()
    {
        return (string) $this->title;
    }

    /**
     * Set hreflang
     *
     * @param string $hreflang
     * @return \PhpHal\LinkInterface
     */
    public function setHreflang($hreflang)
    {
        $this->hreflang = (string) $hreflang;
        return $this;
    }

    /**
     * Get hreflang
     *
     * @return string
     */
    public function getHreflang()
    {
        return (string) $this->hreflang;
    }

    /**
     * Get link attributes
     *
     * @return array
     */
    public function getAttributes()
    {
        $attr = get_object_vars($this);
        unset($attr['href']);
        return array_filter($attr);
    }

    /**
     * Serialize link to array
     *
     * @return array
     */
    public function toArray()
    {
        $data = [];

        isset($this->href) && $data['href'] = $this->href;
        $this->templated && $data['templated'] = true;
        isset($this->type) && $data['type'] = $this->type;
        isset($this->deprecation) && $data['deprecation'] = $this->deprecation;
        isset($this->name) && $data['name'] = $this->name;
        isset($this->profile) && $data['profile'] = $this->profile;
        isset($this->title) && $data['title'] = $this->title;
        isset($this->hreflang) && $data['hreflang'] = $this->hreflang;

        return $data;
    }

    /**
     * Return serialized string
     *
     * @return string
     */
    public function __toString()
    {
        return $this->getHref();
    }
}
