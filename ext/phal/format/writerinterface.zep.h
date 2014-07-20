
extern zend_class_entry *phal_format_writerinterface_ce;

ZEPHIR_INIT_CLASS(Phal_Format_WriterInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phal_format_writerinterface___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, pretty)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phal_format_writerinterface_execute, 0, 0, 1)
	ZEND_ARG_INFO(0, resource)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phal_format_writerinterface_method_entry) {
	PHP_ABSTRACT_ME(Phal_Format_WriterInterface, __construct, arginfo_phal_format_writerinterface___construct)
	PHP_ABSTRACT_ME(Phal_Format_WriterInterface, execute, arginfo_phal_format_writerinterface_execute)
	PHP_ABSTRACT_ME(Phal_Format_WriterInterface, getContentType, NULL)
  PHP_FE_END
};
