
extern zend_class_entry *phal_format_writer_abstractjsonwriter_ce;

ZEPHIR_INIT_CLASS(Phal_Format_Writer_AbstractJsonWriter);

PHP_METHOD(Phal_Format_Writer_AbstractJsonWriter, resourceToArray);
PHP_METHOD(Phal_Format_Writer_AbstractJsonWriter, execute);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phal_format_writer_abstractjsonwriter_resourcetoarray, 0, 0, 1)
	ZEND_ARG_INFO(0, resource)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phal_format_writer_abstractjsonwriter_execute, 0, 0, 1)
	ZEND_ARG_INFO(0, resource)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phal_format_writer_abstractjsonwriter_method_entry) {
	PHP_ME(Phal_Format_Writer_AbstractJsonWriter, resourceToArray, arginfo_phal_format_writer_abstractjsonwriter_resourcetoarray, ZEND_ACC_ABSTRACT|ZEND_ACC_PROTECTED)
	PHP_ME(Phal_Format_Writer_AbstractJsonWriter, execute, arginfo_phal_format_writer_abstractjsonwriter_execute, ZEND_ACC_PUBLIC)
  PHP_FE_END
};
