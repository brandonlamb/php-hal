
extern zend_class_entry *phal_format_abstractreader_ce;

ZEPHIR_INIT_CLASS(Phal_Format_AbstractReader);

PHP_METHOD(Phal_Format_AbstractReader, execute);
PHP_METHOD(Phal_Format_AbstractReader, getContentType);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phal_format_abstractreader_execute, 0, 0, 1)
	ZEND_ARG_INFO(0, input)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phal_format_abstractreader_method_entry) {
	PHP_ME(Phal_Format_AbstractReader, execute, arginfo_phal_format_abstractreader_execute, ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	PHP_ME(Phal_Format_AbstractReader, getContentType, NULL, ZEND_ACC_PUBLIC)
  PHP_FE_END
};
