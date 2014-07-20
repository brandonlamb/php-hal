
extern zend_class_entry *phal_format_reader_jsonreader_ce;

ZEPHIR_INIT_CLASS(Phal_Format_Reader_JsonReader);

PHP_METHOD(Phal_Format_Reader_JsonReader, arrayToResource);
PHP_METHOD(Phal_Format_Reader_JsonReader, execute);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phal_format_reader_jsonreader_arraytoresource, 0, 0, 1)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phal_format_reader_jsonreader_execute, 0, 0, 1)
	ZEND_ARG_INFO(0, input)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phal_format_reader_jsonreader_method_entry) {
	PHP_ME(Phal_Format_Reader_JsonReader, arrayToResource, arginfo_phal_format_reader_jsonreader_arraytoresource, ZEND_ACC_ABSTRACT|ZEND_ACC_PROTECTED)
	PHP_ME(Phal_Format_Reader_JsonReader, execute, arginfo_phal_format_reader_jsonreader_execute, ZEND_ACC_PUBLIC)
  PHP_FE_END
};
