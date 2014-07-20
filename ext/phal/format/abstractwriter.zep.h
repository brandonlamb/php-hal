
extern zend_class_entry *phal_format_abstractwriter_ce;

ZEPHIR_INIT_CLASS(Phal_Format_AbstractWriter);

PHP_METHOD(Phal_Format_AbstractWriter, __construct);
PHP_METHOD(Phal_Format_AbstractWriter, execute);
PHP_METHOD(Phal_Format_AbstractWriter, getContentType);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phal_format_abstractwriter___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, pretty)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phal_format_abstractwriter_execute, 0, 0, 1)
	ZEND_ARG_INFO(0, resource)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phal_format_abstractwriter_method_entry) {
	PHP_ME(Phal_Format_AbstractWriter, __construct, arginfo_phal_format_abstractwriter___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phal_Format_AbstractWriter, execute, arginfo_phal_format_abstractwriter_execute, ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	PHP_ME(Phal_Format_AbstractWriter, getContentType, NULL, ZEND_ACC_PUBLIC)
  PHP_FE_END
};
