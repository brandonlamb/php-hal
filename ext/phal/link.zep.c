
#ifdef HAVE_CONFIG_H
#include "../ext_config.h"
#endif

#include <php.h>
#include "../php_ext.h"
#include "../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/object.h"
#include "kernel/memory.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/operators.h"
#include "kernel/fcall.h"
#include "kernel/array.h"


ZEPHIR_INIT_CLASS(Phal_Link) {

	ZEPHIR_REGISTER_CLASS(Phal, Link, phal, link, phal_link_method_entry, 0);

	/**
	 * @var string
	 */
	zend_declare_property_null(phal_link_ce, SL("href"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * @var bool
	 */
	zend_declare_property_null(phal_link_ce, SL("templated"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * @var string
	 */
	zend_declare_property_null(phal_link_ce, SL("type"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * @var string
	 */
	zend_declare_property_null(phal_link_ce, SL("deprecation"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * @var string
	 */
	zend_declare_property_null(phal_link_ce, SL("name"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * @var string
	 */
	zend_declare_property_null(phal_link_ce, SL("profile"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * @var string
	 */
	zend_declare_property_null(phal_link_ce, SL("title"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * @var string
	 */
	zend_declare_property_null(phal_link_ce, SL("hreflang"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(phal_link_ce TSRMLS_CC, 1, phal_linkinterface_ce);
	return SUCCESS;

}

/**
 * Constructor
 *
 * @param string href
 */
PHP_METHOD(Phal_Link, __construct) {

	zend_bool templated;
	zval *href_param = NULL, *templated_param = NULL, *type_param = NULL, *deprecation_param = NULL, *name_param = NULL, *profile_param = NULL, *title_param = NULL, *hreflang_param = NULL;
	zval *href = NULL, *type = NULL, *deprecation = NULL, *name = NULL, *profile = NULL, *title = NULL, *hreflang = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 8, &href_param, &templated_param, &type_param, &deprecation_param, &name_param, &profile_param, &title_param, &hreflang_param);

	if (!href_param) {
		ZEPHIR_INIT_VAR(href);
		ZVAL_EMPTY_STRING(href);
	} else {
	if (unlikely(Z_TYPE_P(href_param) != IS_STRING && Z_TYPE_P(href_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'href' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (unlikely(Z_TYPE_P(href_param) == IS_STRING)) {
		href = href_param;
	} else {
		ZEPHIR_INIT_VAR(href);
		ZVAL_EMPTY_STRING(href);
	}
	}
	if (!templated_param) {
		templated = 0;
	} else {
	if (unlikely(Z_TYPE_P(templated_param) != IS_BOOL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'templated' must be a bool") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	templated = Z_BVAL_P(templated_param);
	}
	if (!type_param) {
		ZEPHIR_INIT_VAR(type);
		ZVAL_EMPTY_STRING(type);
	} else {
	if (unlikely(Z_TYPE_P(type_param) != IS_STRING && Z_TYPE_P(type_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'type' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (unlikely(Z_TYPE_P(type_param) == IS_STRING)) {
		type = type_param;
	} else {
		ZEPHIR_INIT_VAR(type);
		ZVAL_EMPTY_STRING(type);
	}
	}
	if (!deprecation_param) {
		ZEPHIR_INIT_VAR(deprecation);
		ZVAL_EMPTY_STRING(deprecation);
	} else {
	if (unlikely(Z_TYPE_P(deprecation_param) != IS_STRING && Z_TYPE_P(deprecation_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'deprecation' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (unlikely(Z_TYPE_P(deprecation_param) == IS_STRING)) {
		deprecation = deprecation_param;
	} else {
		ZEPHIR_INIT_VAR(deprecation);
		ZVAL_EMPTY_STRING(deprecation);
	}
	}
	if (!name_param) {
		ZEPHIR_INIT_VAR(name);
		ZVAL_EMPTY_STRING(name);
	} else {
	if (unlikely(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (unlikely(Z_TYPE_P(name_param) == IS_STRING)) {
		name = name_param;
	} else {
		ZEPHIR_INIT_VAR(name);
		ZVAL_EMPTY_STRING(name);
	}
	}
	if (!profile_param) {
		ZEPHIR_INIT_VAR(profile);
		ZVAL_EMPTY_STRING(profile);
	} else {
	if (unlikely(Z_TYPE_P(profile_param) != IS_STRING && Z_TYPE_P(profile_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'profile' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (unlikely(Z_TYPE_P(profile_param) == IS_STRING)) {
		profile = profile_param;
	} else {
		ZEPHIR_INIT_VAR(profile);
		ZVAL_EMPTY_STRING(profile);
	}
	}
	if (!title_param) {
		ZEPHIR_INIT_VAR(title);
		ZVAL_EMPTY_STRING(title);
	} else {
	if (unlikely(Z_TYPE_P(title_param) != IS_STRING && Z_TYPE_P(title_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'title' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (unlikely(Z_TYPE_P(title_param) == IS_STRING)) {
		title = title_param;
	} else {
		ZEPHIR_INIT_VAR(title);
		ZVAL_EMPTY_STRING(title);
	}
	}
	if (!hreflang_param) {
		ZEPHIR_INIT_VAR(hreflang);
		ZVAL_EMPTY_STRING(hreflang);
	} else {
	if (unlikely(Z_TYPE_P(hreflang_param) != IS_STRING && Z_TYPE_P(hreflang_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'hreflang' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (unlikely(Z_TYPE_P(hreflang_param) == IS_STRING)) {
		hreflang = hreflang_param;
	} else {
		ZEPHIR_INIT_VAR(hreflang);
		ZVAL_EMPTY_STRING(hreflang);
	}
	}


	zephir_update_property_this(this_ptr, SL("href"), href TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("templated"), templated ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("type"), type TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("deprecation"), deprecation TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("name"), name TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("profile"), profile TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("title"), title TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("hreflang"), hreflang TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Set href
 *
 * @param string href
 * @return \Phal\LinkInterfaceInterface
 */
PHP_METHOD(Phal_Link, setHref) {

	zval *href_param = NULL;
	zval *href = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &href_param);

	if (unlikely(Z_TYPE_P(href_param) != IS_STRING && Z_TYPE_P(href_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'href' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (unlikely(Z_TYPE_P(href_param) == IS_STRING)) {
		href = href_param;
	} else {
		ZEPHIR_INIT_VAR(href);
		ZVAL_EMPTY_STRING(href);
	}


	zephir_update_property_this(this_ptr, SL("href"), href TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Get href
 *
 * @return string
 */
PHP_METHOD(Phal_Link, getHref) {


	RETURN_MEMBER(this_ptr, "href");

}

/**
 * Set templated
 *
 * @param boolean templated
 * @return \Phal\LinkInterface
 */
PHP_METHOD(Phal_Link, setTemplated) {

	zval *templated_param = NULL;
	zend_bool templated;

	zephir_fetch_params(0, 1, 0, &templated_param);

	templated = zephir_get_boolval(templated_param);


	zephir_update_property_this(this_ptr, SL("templated"), templated ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
	RETURN_THISW();

}

/**
 * Get templated
 *
 * @return boolean
 */
PHP_METHOD(Phal_Link, getTemplated) {


	RETURN_MEMBER(this_ptr, "templated");

}

/**
 * Set type
 *
 * @param string type
 * @return \Phal\LinkInterface
 */
PHP_METHOD(Phal_Link, setType) {

	zval *type_param = NULL;
	zval *type = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &type_param);

	if (unlikely(Z_TYPE_P(type_param) != IS_STRING && Z_TYPE_P(type_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'type' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (unlikely(Z_TYPE_P(type_param) == IS_STRING)) {
		type = type_param;
	} else {
		ZEPHIR_INIT_VAR(type);
		ZVAL_EMPTY_STRING(type);
	}


	zephir_update_property_this(this_ptr, SL("type"), type TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Get type
 *
 * @return string
 */
PHP_METHOD(Phal_Link, getType) {


	RETURN_MEMBER(this_ptr, "type");

}

/**
 * Set deprecation
 *
 * @param string deprecation
 * @return \Phal\LinkInterface
 */
PHP_METHOD(Phal_Link, setDeprecation) {

	zval *deprecation_param = NULL;
	zval *deprecation = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &deprecation_param);

	if (unlikely(Z_TYPE_P(deprecation_param) != IS_STRING && Z_TYPE_P(deprecation_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'deprecation' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (unlikely(Z_TYPE_P(deprecation_param) == IS_STRING)) {
		deprecation = deprecation_param;
	} else {
		ZEPHIR_INIT_VAR(deprecation);
		ZVAL_EMPTY_STRING(deprecation);
	}


	zephir_update_property_this(this_ptr, SL("deprecation"), deprecation TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Get deprecation
 *
 * @return string
 */
PHP_METHOD(Phal_Link, getDeprecation) {


	RETURN_MEMBER(this_ptr, "deprecation");

}

/**
 * Set name
 *
 * @param string name
 * @return \Phal\LinkInterface
 */
PHP_METHOD(Phal_Link, setName) {

	zval *name_param = NULL;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	if (unlikely(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (unlikely(Z_TYPE_P(name_param) == IS_STRING)) {
		name = name_param;
	} else {
		ZEPHIR_INIT_VAR(name);
		ZVAL_EMPTY_STRING(name);
	}


	zephir_update_property_this(this_ptr, SL("name"), name TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Get name
 *
 * @return string
 */
PHP_METHOD(Phal_Link, getName) {


	RETURN_MEMBER(this_ptr, "name");

}

/**
 * Set profile
 *
 * @param string profile
 * @return \Phal\LinkInterface
 */
PHP_METHOD(Phal_Link, setProfile) {

	zval *profile_param = NULL;
	zval *profile = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &profile_param);

	if (unlikely(Z_TYPE_P(profile_param) != IS_STRING && Z_TYPE_P(profile_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'profile' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (unlikely(Z_TYPE_P(profile_param) == IS_STRING)) {
		profile = profile_param;
	} else {
		ZEPHIR_INIT_VAR(profile);
		ZVAL_EMPTY_STRING(profile);
	}


	zephir_update_property_this(this_ptr, SL("profile"), profile TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Get profile
 *
 * @return string
 */
PHP_METHOD(Phal_Link, getProfile) {


	RETURN_MEMBER(this_ptr, "profile");

}

/**
 * Set name
 *
 * @param string name
 * @return \Phal\LinkInterface
 */
PHP_METHOD(Phal_Link, setTitle) {

	zval *title_param = NULL;
	zval *title = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &title_param);

	if (unlikely(Z_TYPE_P(title_param) != IS_STRING && Z_TYPE_P(title_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'title' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (unlikely(Z_TYPE_P(title_param) == IS_STRING)) {
		title = title_param;
	} else {
		ZEPHIR_INIT_VAR(title);
		ZVAL_EMPTY_STRING(title);
	}


	zephir_update_property_this(this_ptr, SL("title"), title TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Get title
 *
 * @return string
 */
PHP_METHOD(Phal_Link, getTitle) {


	RETURN_MEMBER(this_ptr, "title");

}

/**
 * Set hreflang
 *
 * @param string hreflang
 * @return \Phal\LinkInterface
 */
PHP_METHOD(Phal_Link, setHreflang) {

	zval *hreflang_param = NULL;
	zval *hreflang = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &hreflang_param);

	if (unlikely(Z_TYPE_P(hreflang_param) != IS_STRING && Z_TYPE_P(hreflang_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'hreflang' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (unlikely(Z_TYPE_P(hreflang_param) == IS_STRING)) {
		hreflang = hreflang_param;
	} else {
		ZEPHIR_INIT_VAR(hreflang);
		ZVAL_EMPTY_STRING(hreflang);
	}


	zephir_update_property_this(this_ptr, SL("hreflang"), hreflang TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Get hreflang
 *
 * @return string
 */
PHP_METHOD(Phal_Link, getHreflang) {


	RETURN_MEMBER(this_ptr, "hreflang");

}

/**
 * Get link attributes
 *
 * @return array
 */
PHP_METHOD(Phal_Link, getAttributes) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_0 = NULL, *_1 = NULL;
	zval *attr = NULL;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_FUNCTION(&attr, "get_object_vars", &_0, this_ptr);
	zephir_check_call_status();
	zephir_array_unset_string(&attr, SS("href"), PH_SEPARATE);
	ZEPHIR_RETURN_CALL_FUNCTION("array_filter", &_1, attr);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Serialize link to array
 *
 * @return array
 */
PHP_METHOD(Phal_Link, toArray) {

	zval *_0, *_1, *_2;
	zval *data;

	ZEPHIR_MM_GROW();
	ZEPHIR_INIT_VAR(data);
	array_init(data);

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("href"), PH_NOISY_CC);
	if (!ZEPHIR_IS_STRING(_0, "")) {
		_1 = zephir_fetch_nproperty_this(this_ptr, SL("href"), PH_NOISY_CC);
		zephir_array_update_string(&data, SL("href"), &_1, PH_COPY | PH_SEPARATE);
	}
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("templated"), PH_NOISY_CC);
	if (zephir_is_true(_1)) {
		zephir_array_update_string(&data, SL("templated"), &ZEPHIR_GLOBAL(global_true), PH_COPY | PH_SEPARATE);
	}
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("type"), PH_NOISY_CC);
	if (!ZEPHIR_IS_STRING(_1, "")) {
		_2 = zephir_fetch_nproperty_this(this_ptr, SL("type"), PH_NOISY_CC);
		zephir_array_update_string(&data, SL("type"), &_2, PH_COPY | PH_SEPARATE);
	}
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("deprecation"), PH_NOISY_CC);
	if (!ZEPHIR_IS_STRING(_1, "")) {
		_2 = zephir_fetch_nproperty_this(this_ptr, SL("deprecation"), PH_NOISY_CC);
		zephir_array_update_string(&data, SL("deprecation"), &_2, PH_COPY | PH_SEPARATE);
	}
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("name"), PH_NOISY_CC);
	if (!ZEPHIR_IS_STRING(_1, "")) {
		_2 = zephir_fetch_nproperty_this(this_ptr, SL("name"), PH_NOISY_CC);
		zephir_array_update_string(&data, SL("name"), &_2, PH_COPY | PH_SEPARATE);
	}
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("profile"), PH_NOISY_CC);
	if (!ZEPHIR_IS_STRING(_1, "")) {
		_2 = zephir_fetch_nproperty_this(this_ptr, SL("profile"), PH_NOISY_CC);
		zephir_array_update_string(&data, SL("profile"), &_2, PH_COPY | PH_SEPARATE);
	}
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("title"), PH_NOISY_CC);
	if (!ZEPHIR_IS_STRING(_1, "")) {
		_2 = zephir_fetch_nproperty_this(this_ptr, SL("title"), PH_NOISY_CC);
		zephir_array_update_string(&data, SL("title"), &_2, PH_COPY | PH_SEPARATE);
	}
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("hreflang"), PH_NOISY_CC);
	if (!ZEPHIR_IS_STRING(_1, "")) {
		_2 = zephir_fetch_nproperty_this(this_ptr, SL("hreflang"), PH_NOISY_CC);
		zephir_array_update_string(&data, SL("hreflang"), &_2, PH_COPY | PH_SEPARATE);
	}
	RETURN_CTOR(data);

}

/**
 * Return serialized string
 *
 * @return string
 */
PHP_METHOD(Phal_Link, __toString) {

	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "gethref", NULL);
	zephir_check_call_status();
	RETURN_MM();

}

