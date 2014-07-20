
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/concat.h"
#include "kernel/memory.h"
#include "kernel/object.h"
#include "kernel/fcall.h"


ZEPHIR_INIT_CLASS(Phal_Format_AbstractReader) {

	ZEPHIR_REGISTER_CLASS(Phal\\Format, AbstractReader, phal, format_abstractreader, phal_format_abstractreader_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	return SUCCESS;

}

/**
 * Execute parsing
 *
 * @param string input
 * @return mixed
 */
PHP_METHOD(Phal_Format_AbstractReader, execute) {

}

/**
 * Return the content type string for the resource
 *
 * @return string
 */
PHP_METHOD(Phal_Format_AbstractReader, getContentType) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_2 = NULL;
	zval *_0, *_1;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	zephir_get_called_class(_0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_1);
	ZEPHIR_CONCAT_VS(_1, _0, "::CONTENT_TYPE");
	ZEPHIR_RETURN_CALL_FUNCTION("constant", &_2, _1);
	zephir_check_call_status();
	RETURN_MM();

}

