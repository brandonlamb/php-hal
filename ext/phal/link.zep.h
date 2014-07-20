
extern zend_class_entry *phal_link_ce;

ZEPHIR_INIT_CLASS(Phal_Link);

PHP_METHOD(Phal_Link, __construct);
PHP_METHOD(Phal_Link, setHref);
PHP_METHOD(Phal_Link, getHref);
PHP_METHOD(Phal_Link, setTemplated);
PHP_METHOD(Phal_Link, getTemplated);
PHP_METHOD(Phal_Link, setType);
PHP_METHOD(Phal_Link, getType);
PHP_METHOD(Phal_Link, setDeprecation);
PHP_METHOD(Phal_Link, getDeprecation);
PHP_METHOD(Phal_Link, setName);
PHP_METHOD(Phal_Link, getName);
PHP_METHOD(Phal_Link, setProfile);
PHP_METHOD(Phal_Link, getProfile);
PHP_METHOD(Phal_Link, setTitle);
PHP_METHOD(Phal_Link, getTitle);
PHP_METHOD(Phal_Link, setHreflang);
PHP_METHOD(Phal_Link, getHreflang);
PHP_METHOD(Phal_Link, getAttributes);
PHP_METHOD(Phal_Link, toArray);
PHP_METHOD(Phal_Link, __toString);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phal_link___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, href)
	ZEND_ARG_INFO(0, templated)
	ZEND_ARG_INFO(0, type)
	ZEND_ARG_INFO(0, deprecation)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, profile)
	ZEND_ARG_INFO(0, title)
	ZEND_ARG_INFO(0, hreflang)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phal_link_sethref, 0, 0, 1)
	ZEND_ARG_INFO(0, href)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phal_link_settemplated, 0, 0, 1)
	ZEND_ARG_INFO(0, templated)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phal_link_settype, 0, 0, 1)
	ZEND_ARG_INFO(0, type)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phal_link_setdeprecation, 0, 0, 1)
	ZEND_ARG_INFO(0, deprecation)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phal_link_setname, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phal_link_setprofile, 0, 0, 1)
	ZEND_ARG_INFO(0, profile)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phal_link_settitle, 0, 0, 1)
	ZEND_ARG_INFO(0, title)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phal_link_sethreflang, 0, 0, 1)
	ZEND_ARG_INFO(0, hreflang)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phal_link_method_entry) {
	PHP_ME(Phal_Link, __construct, arginfo_phal_link___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phal_Link, setHref, arginfo_phal_link_sethref, ZEND_ACC_PUBLIC)
	PHP_ME(Phal_Link, getHref, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phal_Link, setTemplated, arginfo_phal_link_settemplated, ZEND_ACC_PUBLIC)
	PHP_ME(Phal_Link, getTemplated, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phal_Link, setType, arginfo_phal_link_settype, ZEND_ACC_PUBLIC)
	PHP_ME(Phal_Link, getType, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phal_Link, setDeprecation, arginfo_phal_link_setdeprecation, ZEND_ACC_PUBLIC)
	PHP_ME(Phal_Link, getDeprecation, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phal_Link, setName, arginfo_phal_link_setname, ZEND_ACC_PUBLIC)
	PHP_ME(Phal_Link, getName, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phal_Link, setProfile, arginfo_phal_link_setprofile, ZEND_ACC_PUBLIC)
	PHP_ME(Phal_Link, getProfile, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phal_Link, setTitle, arginfo_phal_link_settitle, ZEND_ACC_PUBLIC)
	PHP_ME(Phal_Link, getTitle, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phal_Link, setHreflang, arginfo_phal_link_sethreflang, ZEND_ACC_PUBLIC)
	PHP_ME(Phal_Link, getHreflang, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phal_Link, getAttributes, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phal_Link, toArray, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phal_Link, __toString, NULL, ZEND_ACC_PUBLIC)
  PHP_FE_END
};
