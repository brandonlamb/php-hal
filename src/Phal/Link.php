<?php

namespace Phal;

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
     * @return \Phal\LinkInterfaceInterface
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
     * @return \Phal\LinkInterface
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
    public function getTemplated()
    {
        return (bool) $this->templated;
    }

    /**
     * Set type
     *
     * @param string $type
     * @return \Phal\LinkInterface
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
     * @return \Phal\LinkInterface
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
     * @return \Phal\LinkInterface
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
     * @return \Phal\LinkInterface
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
     * @return \Phal\LinkInterface
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
     * @return \Phal\LinkInterface
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

        if ($this->href !== '') {
            $data['href'] = $this->href;
        }

        if ($this->templated) {
            $data['templated'] = true;
        }

        if ($this->type !== '') {
            $data['type'] = $this->type;
        }

        if ($this->deprecation !== '') {
            $data['deprecation'] = $this->deprecation;
        }

        if ($this->name !== '') {
            $data['name'] = $this->name;
        }

        if ($this->profile !== '') {
            $data['profile'] = $this->profile;
        }

        if ($this->title !== '') {
            $data['title'] = $this->title;
        }

        if ($this->hreflang !== '') {
            $data['hreflang'] = $this->hreflang;
        }

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
