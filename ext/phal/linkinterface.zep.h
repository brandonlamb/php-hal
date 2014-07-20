
extern zend_class_entry *phal_linkinterface_ce;

ZEPHIR_INIT_CLASS(Phal_LinkInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phal_linkinterface___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, href)
	ZEND_ARG_INFO(0, templated)
	ZEND_ARG_INFO(0, type)
	ZEND_ARG_INFO(0, deprecation)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, profile)
	ZEND_ARG_INFO(0, title)
	ZEND_ARG_INFO(0, hreflang)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phal_linkinterface_sethref, 0, 0, 1)
	ZEND_ARG_INFO(0, href)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phal_linkinterface_settemplated, 0, 0, 1)
	ZEND_ARG_INFO(0, templated)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phal_linkinterface_settype, 0, 0, 1)
	ZEND_ARG_INFO(0, type)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phal_linkinterface_setdeprecation, 0, 0, 1)
	ZEND_ARG_INFO(0, deprecation)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phal_linkinterface_setname, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phal_linkinterface_setprofile, 0, 0, 1)
	ZEND_ARG_INFO(0, profile)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phal_linkinterface_settitle, 0, 0, 1)
	ZEND_ARG_INFO(0, title)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phal_linkinterface_sethreflang, 0, 0, 1)
	ZEND_ARG_INFO(0, hreflang)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phal_linkinterface_method_entry) {
	PHP_ABSTRACT_ME(Phal_LinkInterface, __construct, arginfo_phal_linkinterface___construct)
	PHP_ABSTRACT_ME(Phal_LinkInterface, setHref, arginfo_phal_linkinterface_sethref)
	PHP_ABSTRACT_ME(Phal_LinkInterface, getHref, NULL)
	PHP_ABSTRACT_ME(Phal_LinkInterface, setTemplated, arginfo_phal_linkinterface_settemplated)
	PHP_ABSTRACT_ME(Phal_LinkInterface, getTemplated, NULL)
	PHP_ABSTRACT_ME(Phal_LinkInterface, setType, arginfo_phal_linkinterface_settype)
	PHP_ABSTRACT_ME(Phal_LinkInterface, getType, NULL)
	PHP_ABSTRACT_ME(Phal_LinkInterface, setDeprecation, arginfo_phal_linkinterface_setdeprecation)
	PHP_ABSTRACT_ME(Phal_LinkInterface, getDeprecation, NULL)
	PHP_ABSTRACT_ME(Phal_LinkInterface, setName, arginfo_phal_linkinterface_setname)
	PHP_ABSTRACT_ME(Phal_LinkInterface, getName, NULL)
	PHP_ABSTRACT_ME(Phal_LinkInterface, setProfile, arginfo_phal_linkinterface_setprofile)
	PHP_ABSTRACT_ME(Phal_LinkInterface, getProfile, NULL)
	PHP_ABSTRACT_ME(Phal_LinkInterface, setTitle, arginfo_phal_linkinterface_settitle)
	PHP_ABSTRACT_ME(Phal_LinkInterface, getTitle, NULL)
	PHP_ABSTRACT_ME(Phal_LinkInterface, setHreflang, arginfo_phal_linkinterface_sethreflang)
	PHP_ABSTRACT_ME(Phal_LinkInterface, getHreflang, NULL)
	PHP_ABSTRACT_ME(Phal_LinkInterface, getAttributes, NULL)
	PHP_ABSTRACT_ME(Phal_LinkInterface, toArray, NULL)
	PHP_ABSTRACT_ME(Phal_LinkInterface, __toString, NULL)
  PHP_FE_END
};
