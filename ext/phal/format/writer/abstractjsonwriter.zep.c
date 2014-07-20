
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
#include "kernel/object.h"
#include "kernel/exception.h"
#include "kernel/operators.h"
#include "kernel/string.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"


ZEPHIR_INIT_CLASS(Phal_Format_Writer_AbstractJsonWriter) {

	ZEPHIR_REGISTER_CLASS_EX(Phal\\Format\\Writer, AbstractJsonWriter, phal, format_writer_abstractjsonwriter, phal_format_abstractwriter_ce, phal_format_writer_abstractjsonwriter_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	zend_class_implements(phal_format_writer_abstractjsonwriter_ce TSRMLS_CC, 1, phal_format_writerinterface_ce);
	return SUCCESS;

}

/**
 * Execute parsing
 *
 * @param \Phal\Entity $resource
 * @return array
 */
PHP_METHOD(Phal_Format_Writer_AbstractJsonWriter, resourceToArray) {

}

/**
 * Execute parsing
 *
 * @param \Phal\Entity $resource
 * @return mixed
 */
PHP_METHOD(Phal_Format_Writer_AbstractJsonWriter, execute) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *resource, *_0, *_1 = NULL, _2 = zval_used_for_init;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &resource);



	if (!(zephir_instance_of_ev(resource, phal_entity_ce TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Parameter 'resource' must be an instance of 'Phal\\Entity'", "", 0);
		return;
	}
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("pretty"), PH_NOISY_CC);
	if (unlikely(!zephir_is_true(_0))) {
		ZEPHIR_CALL_METHOD(&_1, this_ptr, "resourcetoarray", NULL, resource);
		zephir_check_call_status();
		ZEPHIR_SINIT_VAR(_2);
		ZVAL_LONG(&_2, 64);
		zephir_json_encode(return_value, &(return_value), _1, zephir_get_intval(&_2)  TSRMLS_CC);
		RETURN_MM();
	}
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "resourcetoarray", NULL, resource);
	zephir_check_call_status();
	ZEPHIR_SINIT_NVAR(_2);
	ZVAL_LONG(&_2, (64 | 128));
	zephir_json_encode(return_value, &(return_value), _1, zephir_get_intval(&_2)  TSRMLS_CC);
	RETURN_MM();

}

