
extern zend_class_entry *phal_format_writer_hal_jsonwriter_ce;

ZEPHIR_INIT_CLASS(Phal_Format_Writer_Hal_JsonWriter);

PHP_METHOD(Phal_Format_Writer_Hal_JsonWriter, resourceToArray);
PHP_METHOD(Phal_Format_Writer_Hal_JsonWriter, transformLinks);
PHP_METHOD(Phal_Format_Writer_Hal_JsonWriter, transformLinkedResources);
PHP_METHOD(Phal_Format_Writer_Hal_JsonWriter, transformResources);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phal_format_writer_hal_jsonwriter_resourcetoarray, 0, 0, 1)
	ZEND_ARG_INFO(0, entity)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phal_format_writer_hal_jsonwriter_transformlinks, 0, 0, 2)
	ZEND_ARG_INFO(0, data)
	ZEND_ARG_INFO(0, entity)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phal_format_writer_hal_jsonwriter_transformlinkedresources, 0, 0, 2)
	ZEND_ARG_INFO(0, data)
	ZEND_ARG_INFO(0, entity)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phal_format_writer_hal_jsonwriter_transformresources, 0, 0, 1)
	ZEND_ARG_INFO(0, entity)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phal_format_writer_hal_jsonwriter_method_entry) {
	PHP_ME(Phal_Format_Writer_Hal_JsonWriter, resourceToArray, arginfo_phal_format_writer_hal_jsonwriter_resourcetoarray, ZEND_ACC_PROTECTED)
	PHP_ME(Phal_Format_Writer_Hal_JsonWriter, transformLinks, arginfo_phal_format_writer_hal_jsonwriter_transformlinks, ZEND_ACC_PROTECTED)
	PHP_ME(Phal_Format_Writer_Hal_JsonWriter, transformLinkedResources, arginfo_phal_format_writer_hal_jsonwriter_transformlinkedresources, ZEND_ACC_PROTECTED)
	PHP_ME(Phal_Format_Writer_Hal_JsonWriter, transformResources, arginfo_phal_format_writer_hal_jsonwriter_transformresources, ZEND_ACC_PROTECTED)
  PHP_FE_END
};
