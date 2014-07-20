
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
#include "kernel/object.h"
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/concat.h"
#include "kernel/fcall.h"


ZEPHIR_INIT_CLASS(Phal_Format_AbstractWriter) {

	ZEPHIR_REGISTER_CLASS(Phal\\Format, AbstractWriter, phal, format_abstractwriter, phal_format_abstractwriter_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	/**
	 * @var boolean
	 */
	zend_declare_property_null(phal_format_abstractwriter_ce, SL("pretty"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_class_constant_string(phal_format_abstractwriter_ce, SL("CONTENT_TYPE_ANY"), "*/*" TSRMLS_CC);

	return SUCCESS;

}

/**
 * Constructor
 *
 * @param boolean pretty
 */
PHP_METHOD(Phal_Format_AbstractWriter, __construct) {

	zval *pretty_param = NULL;
	zend_bool pretty;

	zephir_fetch_params(0, 0, 1, &pretty_param);

	if (!pretty_param) {
		pretty = 0;
	} else {
		pretty = zephir_get_boolval(pretty_param);
	}


	zephir_update_property_this(this_ptr, SL("pretty"), pretty ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false) TSRMLS_CC);

}

/**
 * Execute parsing
 *
 * @param \Phal\Entity $resource
 * @return mixed
 */
PHP_METHOD(Phal_Format_AbstractWriter, execute) {

}

/**
 * Return the content type string for the resource
 *
 * @return string
 */
PHP_METHOD(Phal_Format_AbstractWriter, getContentType) {

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

