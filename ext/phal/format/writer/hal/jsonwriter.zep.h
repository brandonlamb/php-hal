
extern zend_class_entry *phal_format_writer_hal_jsonwriter_ce;

ZEPHIR_INIT_CLASS(Phal_Format_Writer_Hal_JsonWriter);

PHP_METHOD(Phal_Format_Writer_Hal_JsonWriter, resourceToArray);
PHP_METHOD(Phal_Format_Writer_Hal_JsonWriter, transformLinks);
PHP_METHOD(Phal_Format_Writer_Hal_JsonWriter, transformLinkedResources);
PHP_METHOD(Phal_Format_Writer_Hal_JsonWriter, transformResources);
PHP_METHOD(Phal_Format_Writer_Hal_JsonWriter, doTransformSingleResource);
PHP_METHOD(Phal_Format_Writer_Hal_JsonWriter, doTransformResource);
PHP_METHOD(Phal_Format_Writer_Hal_JsonWriter, doTransformResources);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phal_format_writer_hal_jsonwriter_resourcetoarray, 0, 0, 1)
	ZEND_ARG_INFO(0, resource)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phal_format_writer_hal_jsonwriter_transformlinks, 0, 0, 1)
	ZEND_ARG_INFO(0, resource)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phal_format_writer_hal_jsonwriter_transformlinkedresources, 0, 0, 1)
	ZEND_ARG_INFO(0, resource)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phal_format_writer_hal_jsonwriter_transformresources, 0, 0, 1)
	ZEND_ARG_INFO(0, resource)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phal_format_writer_hal_jsonwriter_dotransformsingleresource, 0, 0, 2)
	ZEND_ARG_INFO(0, rel)
	ZEND_ARG_INFO(0, resource)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phal_format_writer_hal_jsonwriter_dotransformresource, 0, 0, 2)
	ZEND_ARG_INFO(0, rel)
	ZEND_ARG_INFO(0, resource)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phal_format_writer_hal_jsonwriter_dotransformresources, 0, 0, 2)
	ZEND_ARG_INFO(0, rel)
	ZEND_ARG_INFO(0, resources)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phal_format_writer_hal_jsonwriter_method_entry) {
	PHP_ME(Phal_Format_Writer_Hal_JsonWriter, resourceToArray, arginfo_phal_format_writer_hal_jsonwriter_resourcetoarray, ZEND_ACC_PROTECTED)
	PHP_ME(Phal_Format_Writer_Hal_JsonWriter, transformLinks, arginfo_phal_format_writer_hal_jsonwriter_transformlinks, ZEND_ACC_PROTECTED)
	PHP_ME(Phal_Format_Writer_Hal_JsonWriter, transformLinkedResources, arginfo_phal_format_writer_hal_jsonwriter_transformlinkedresources, ZEND_ACC_PROTECTED)
	PHP_ME(Phal_Format_Writer_Hal_JsonWriter, transformResources, arginfo_phal_format_writer_hal_jsonwriter_transformresources, ZEND_ACC_PROTECTED)
	PHP_ME(Phal_Format_Writer_Hal_JsonWriter, doTransformSingleResource, arginfo_phal_format_writer_hal_jsonwriter_dotransformsingleresource, ZEND_ACC_PRIVATE)
	PHP_ME(Phal_Format_Writer_Hal_JsonWriter, doTransformResource, arginfo_phal_format_writer_hal_jsonwriter_dotransformresource, ZEND_ACC_PRIVATE)
	PHP_ME(Phal_Format_Writer_Hal_JsonWriter, doTransformResources, arginfo_phal_format_writer_hal_jsonwriter_dotransformresources, ZEND_ACC_PRIVATE)
  PHP_FE_END
};
