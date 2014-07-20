
extern zend_class_entry *phal_format_readerinterface_ce;

ZEPHIR_INIT_CLASS(Phal_Format_ReaderInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phal_format_readerinterface_execute, 0, 0, 1)
	ZEND_ARG_INFO(0, input)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phal_format_readerinterface_method_entry) {
	PHP_ABSTRACT_ME(Phal_Format_ReaderInterface, execute, arginfo_phal_format_readerinterface_execute)
	PHP_ABSTRACT_ME(Phal_Format_ReaderInterface, getContentType, NULL)
  PHP_FE_END
};
