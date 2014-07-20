
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/memory.h"
#include "kernel/string.h"
#include "kernel/operators.h"
#include "kernel/fcall.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"


ZEPHIR_INIT_CLASS(Phal_Format_Reader_JsonReader) {

	ZEPHIR_REGISTER_CLASS_EX(Phal\\Format\\Reader, JsonReader, phal, format_reader_jsonreader, phal_format_abstractreader_ce, phal_format_reader_jsonreader_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	return SUCCESS;

}

/**
 * Parse array of data into resource
 *
 * @param array data
 * @return mixed
 */
PHP_METHOD(Phal_Format_Reader_JsonReader, arrayToResource) {

}

/**
 * Execute parsing
 *
 * @param string input
 * @return mixed
 */
PHP_METHOD(Phal_Format_Reader_JsonReader, execute) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *input_param = NULL, *data;
	zval *input = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &input_param);

	if (unlikely(Z_TYPE_P(input_param) != IS_STRING && Z_TYPE_P(input_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'input' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (unlikely(Z_TYPE_P(input_param) == IS_STRING)) {
		input = input_param;
	} else {
		ZEPHIR_INIT_VAR(input);
		ZVAL_EMPTY_STRING(input);
	}


	ZEPHIR_INIT_VAR(data);
	zephir_json_decode(data, &(data), input, zephir_get_intval(ZEPHIR_GLOBAL(global_true))  TSRMLS_CC);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "arraytoresource", NULL, data);
	zephir_check_call_status();
	RETURN_MM();

}

