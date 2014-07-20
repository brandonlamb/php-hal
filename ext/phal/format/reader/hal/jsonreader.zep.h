
extern zend_class_entry *phal_format_reader_hal_jsonreader_ce;

ZEPHIR_INIT_CLASS(Phal_Format_Reader_Hal_JsonReader);

PHP_METHOD(Phal_Format_Reader_Hal_JsonReader, arrayToResource);
PHP_METHOD(Phal_Format_Reader_Hal_JsonReader, transformMetadata);
PHP_METHOD(Phal_Format_Reader_Hal_JsonReader, transformLinks);
PHP_METHOD(Phal_Format_Reader_Hal_JsonReader, transformSelfLink);
PHP_METHOD(Phal_Format_Reader_Hal_JsonReader, doTransformLinks);
PHP_METHOD(Phal_Format_Reader_Hal_JsonReader, doTransformLink);
PHP_METHOD(Phal_Format_Reader_Hal_JsonReader, transformEmbeddeds);
PHP_METHOD(Phal_Format_Reader_Hal_JsonReader, doTransformEmbeddeds);
PHP_METHOD(Phal_Format_Reader_Hal_JsonReader, doTransformEmbedded);
PHP_METHOD(Phal_Format_Reader_Hal_JsonReader, isAssocArray);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phal_format_reader_hal_jsonreader_arraytoresource, 0, 0, 1)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phal_format_reader_hal_jsonreader_transformmetadata, 0, 0, 2)
	ZEND_ARG_INFO(0, resource)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phal_format_reader_hal_jsonreader_transformlinks, 0, 0, 2)
	ZEND_ARG_INFO(0, resource)
	ZEND_ARG_INFO(0, linksByRel)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phal_format_reader_hal_jsonreader_transformselflink, 0, 0, 2)
	ZEND_ARG_INFO(0, resource)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phal_format_reader_hal_jsonreader_dotransformlinks, 0, 0, 1)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phal_format_reader_hal_jsonreader_dotransformlink, 0, 0, 1)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phal_format_reader_hal_jsonreader_transformembeddeds, 0, 0, 2)
	ZEND_ARG_INFO(0, resource)
	ZEND_ARG_INFO(0, embeddedsByRel)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phal_format_reader_hal_jsonreader_dotransformembeddeds, 0, 0, 1)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phal_format_reader_hal_jsonreader_dotransformembedded, 0, 0, 1)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phal_format_reader_hal_jsonreader_isassocarray, 0, 0, 1)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phal_format_reader_hal_jsonreader_method_entry) {
	PHP_ME(Phal_Format_Reader_Hal_JsonReader, arrayToResource, arginfo_phal_format_reader_hal_jsonreader_arraytoresource, ZEND_ACC_PROTECTED)
	PHP_ME(Phal_Format_Reader_Hal_JsonReader, transformMetadata, arginfo_phal_format_reader_hal_jsonreader_transformmetadata, ZEND_ACC_PROTECTED)
	PHP_ME(Phal_Format_Reader_Hal_JsonReader, transformLinks, arginfo_phal_format_reader_hal_jsonreader_transformlinks, ZEND_ACC_PROTECTED)
	PHP_ME(Phal_Format_Reader_Hal_JsonReader, transformSelfLink, arginfo_phal_format_reader_hal_jsonreader_transformselflink, ZEND_ACC_PROTECTED)
	PHP_ME(Phal_Format_Reader_Hal_JsonReader, doTransformLinks, arginfo_phal_format_reader_hal_jsonreader_dotransformlinks, ZEND_ACC_PROTECTED)
	PHP_ME(Phal_Format_Reader_Hal_JsonReader, doTransformLink, arginfo_phal_format_reader_hal_jsonreader_dotransformlink, ZEND_ACC_PROTECTED)
	PHP_ME(Phal_Format_Reader_Hal_JsonReader, transformEmbeddeds, arginfo_phal_format_reader_hal_jsonreader_transformembeddeds, ZEND_ACC_PROTECTED)
	PHP_ME(Phal_Format_Reader_Hal_JsonReader, doTransformEmbeddeds, arginfo_phal_format_reader_hal_jsonreader_dotransformembeddeds, ZEND_ACC_PROTECTED)
	PHP_ME(Phal_Format_Reader_Hal_JsonReader, doTransformEmbedded, arginfo_phal_format_reader_hal_jsonreader_dotransformembedded, ZEND_ACC_PROTECTED)
	PHP_ME(Phal_Format_Reader_Hal_JsonReader, isAssocArray, arginfo_phal_format_reader_hal_jsonreader_isassocarray, ZEND_ACC_PRIVATE)
  PHP_FE_END
};
