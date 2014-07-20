
#ifdef HAVE_CONFIG_H
#include "../../../../ext_config.h"
#endif

#include <php.h>
#include "../../../../php_ext.h"
#include "../../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/exception.h"
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "kernel/object.h"
#include "kernel/array.h"
#include "kernel/hash.h"
#include "kernel/operators.h"


ZEPHIR_INIT_CLASS(Phal_Format_Reader_Hal_JsonReader) {

	ZEPHIR_REGISTER_CLASS_EX(Phal\\Format\\Reader\\Hal, JsonReader, phal, format_reader_hal_jsonreader, phal_format_reader_abstractjsonreader_ce, phal_format_reader_hal_jsonreader_method_entry, 0);

	zend_declare_class_constant_string(phal_format_reader_hal_jsonreader_ce, SL("CONTENT_TYPE"), "application/hal+json" TSRMLS_CC);

	zend_declare_class_constant_string(phal_format_reader_hal_jsonreader_ce, SL("RESOURCE_KEY_LINKS"), "_links" TSRMLS_CC);

	zend_declare_class_constant_string(phal_format_reader_hal_jsonreader_ce, SL("RESOURCE_KEY_EMBEDDED"), "_embedded" TSRMLS_CC);

	zend_declare_class_constant_string(phal_format_reader_hal_jsonreader_ce, SL("RESOURCE_LINK_SELF"), "self" TSRMLS_CC);

	zend_declare_class_constant_string(phal_format_reader_hal_jsonreader_ce, SL("LINK_KEY_HREF"), "href" TSRMLS_CC);

	zend_declare_class_constant_string(phal_format_reader_hal_jsonreader_ce, SL("LINK_KEY_TEMPLATED"), "templated" TSRMLS_CC);

	zend_declare_class_constant_string(phal_format_reader_hal_jsonreader_ce, SL("LINK_KEY_TYPE"), "type" TSRMLS_CC);

	zend_declare_class_constant_string(phal_format_reader_hal_jsonreader_ce, SL("LINK_KEY_DEPRECATION"), "deprecation" TSRMLS_CC);

	zend_declare_class_constant_string(phal_format_reader_hal_jsonreader_ce, SL("LINK_KEY_NAME"), "name" TSRMLS_CC);

	zend_declare_class_constant_string(phal_format_reader_hal_jsonreader_ce, SL("LINK_KEY_PROFILE"), "profile" TSRMLS_CC);

	zend_declare_class_constant_string(phal_format_reader_hal_jsonreader_ce, SL("LINK_KEY_TITLE"), "title" TSRMLS_CC);

	zend_declare_class_constant_string(phal_format_reader_hal_jsonreader_ce, SL("LINK_KEY_HREFLANG"), "hreflang" TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Phal_Format_Reader_Hal_JsonReader, arrayToResource) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *data;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &data);



	if (Z_TYPE_P(data) != IS_ARRAY) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "data must be array", "phal/format/reader/hal/jsonreader.zep", 28);
		return;
	}
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "dotransformembedded", NULL, data);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * @param \Phal\Entity
 * @param array data
 * @return void
 */
PHP_METHOD(Phal_Format_Reader_Hal_JsonReader, transformMetadata) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *resource, *data, *key = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &resource, &data);



	if (!(zephir_instance_of_ev(resource, phal_entity_ce TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Parameter 'resource' must be an instance of 'Phal\\Entity'", "", 0);
		return;
	}
	if (Z_TYPE_P(data) != IS_ARRAY) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "data must be array", "phal/format/reader/hal/jsonreader.zep", 43);
		return;
	}
	ZEPHIR_OBS_VAR(key);
	if (zephir_array_isset_string_fetch(&key, data, SS("_links"), 0 TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "transformlinks", NULL, resource, key);
		zephir_check_call_status();
	}
	ZEPHIR_OBS_NVAR(key);
	if (zephir_array_isset_string_fetch(&key, data, SS("_embedded"), 0 TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "transformembeddeds", NULL, resource, key);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}

/**
 *
 * @param \Phal\Entity $resource
 * @param array linksByRel
 * @return void
 */
PHP_METHOD(Phal_Format_Reader_Hal_JsonReader, transformLinks) {

	zephir_fcall_cache_entry *_4 = NULL, *_5 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	HashTable *_1;
	HashPosition _0;
	zval *resource, *linksByRel, *rel = NULL, *data = NULL, *link = NULL, *links = NULL, **_2, *_3 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &resource, &linksByRel);



	if (!(zephir_instance_of_ev(resource, phal_entity_ce TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Parameter 'resource' must be an instance of 'Phal\\Entity'", "", 0);
		return;
	}
	if (Z_TYPE_P(linksByRel) != IS_ARRAY) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "linksByRel must be array", "phal/format/reader/hal/jsonreader.zep", 66);
		return;
	}
	zephir_is_iterable(linksByRel, &_1, &_0, 0, 0);
	for (
	  ; zephir_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
	  ; zephir_hash_move_forward_ex(_1, &_0)
	) {
		ZEPHIR_GET_HMKEY(rel, _1, _0);
		ZEPHIR_GET_HVALUE(data, _2);
		if (ZEPHIR_IS_STRING(rel, "self")) {
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "transformselflink", NULL, resource, data);
			zephir_check_call_status();
			continue;
		}
		ZEPHIR_CALL_METHOD(&_3, this_ptr, "isassocarray", NULL, data);
		zephir_check_call_status();
		if (zephir_is_true(_3)) {
			ZEPHIR_CALL_METHOD(&link, this_ptr, "dotransformlink", NULL, data);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, resource, "setlink", &_4, rel, link);
			zephir_check_call_status();
		} else {
			ZEPHIR_CALL_METHOD(&links, this_ptr, "dotransformlinks", NULL, data);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, resource, "setlinks", &_5, rel, links);
			zephir_check_call_status();
		}
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * @param \Phal\Entity
 * @param array data
 * @return void
 */
PHP_METHOD(Phal_Format_Reader_Hal_JsonReader, transformSelfLink) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *resource, *data, *key = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &resource, &data);



	if (!(zephir_instance_of_ev(resource, phal_entity_ce TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Parameter 'resource' must be an instance of 'Phal\\Entity'", "", 0);
		return;
	}
	if (Z_TYPE_P(data) != IS_ARRAY) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "data must be array", "phal/format/reader/hal/jsonreader.zep", 95);
		return;
	}
	ZEPHIR_OBS_VAR(key);
	if (zephir_array_isset_string_fetch(&key, data, SS("href"), 0 TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(NULL, resource, "seturi", NULL, key);
		zephir_check_call_status();
	}
	ZEPHIR_OBS_NVAR(key);
	if (zephir_array_isset_string_fetch(&key, data, SS("title"), 0 TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(NULL, resource, "settitle", NULL, key);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * @param data
 * @return array
 */
PHP_METHOD(Phal_Format_Reader_Hal_JsonReader, doTransformLinks) {

	int ZEPHIR_LAST_CALL_STATUS;
	HashTable *_1;
	HashPosition _0;
	zval *data, *link = NULL, *links, **_2, *_3 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &data);



	if (Z_TYPE_P(data) != IS_ARRAY) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "data must be array", "phal/format/reader/hal/jsonreader.zep", 116);
		return;
	}
	ZEPHIR_INIT_VAR(links);
	array_init(links);
	zephir_is_iterable(data, &_1, &_0, 0, 0);
	for (
	  ; zephir_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
	  ; zephir_hash_move_forward_ex(_1, &_0)
	) {
		ZEPHIR_GET_HVALUE(link, _2);
		ZEPHIR_CALL_METHOD(&_3, this_ptr, "dotransformlink", NULL, link);
		zephir_check_call_status();
		zephir_array_append(&links, _3, PH_SEPARATE);
	}
	RETURN_CCTOR(links);

}

/**
 * @param array data
 * @return \Phal\Link
 */
PHP_METHOD(Phal_Format_Reader_Hal_JsonReader, doTransformLink) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *data_param = NULL, *link, *key = NULL;
	zval *data = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &data_param);

	zephir_get_arrval(data, data_param);


	ZEPHIR_INIT_VAR(link);
	object_init_ex(link, phal_link_ce);
	ZEPHIR_CALL_METHOD(NULL, link, "__construct", NULL);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(key);
	if (zephir_array_isset_string_fetch(&key, data, SS("href"), 0 TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(NULL, link, "sethref", NULL, key);
		zephir_check_call_status();
	}
	ZEPHIR_OBS_NVAR(key);
	if (zephir_array_isset_string_fetch(&key, data, SS("templated"), 0 TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(NULL, link, "settemplated", NULL, key);
		zephir_check_call_status();
	}
	ZEPHIR_OBS_NVAR(key);
	if (zephir_array_isset_string_fetch(&key, data, SS("type"), 0 TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(NULL, link, "settype", NULL, key);
		zephir_check_call_status();
	}
	ZEPHIR_OBS_NVAR(key);
	if (zephir_array_isset_string_fetch(&key, data, SS("deprecation"), 0 TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(NULL, link, "setdeprecation", NULL, key);
		zephir_check_call_status();
	}
	ZEPHIR_OBS_NVAR(key);
	if (zephir_array_isset_string_fetch(&key, data, SS("name"), 0 TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(NULL, link, "setname", NULL, key);
		zephir_check_call_status();
	}
	ZEPHIR_OBS_NVAR(key);
	if (zephir_array_isset_string_fetch(&key, data, SS("profile"), 0 TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(NULL, link, "setprofile", NULL, key);
		zephir_check_call_status();
	}
	ZEPHIR_OBS_NVAR(key);
	if (zephir_array_isset_string_fetch(&key, data, SS("title"), 0 TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(NULL, link, "settitle", NULL, key);
		zephir_check_call_status();
	}
	ZEPHIR_OBS_NVAR(key);
	if (zephir_array_isset_string_fetch(&key, data, SS("hreflang"), 0 TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(NULL, link, "sethreflang", NULL, key);
		zephir_check_call_status();
	}
	RETURN_CCTOR(link);

}

/**
 * @param \Phal\Entity $resource
 * @param array embeddedByRel
 * @return void
 */
PHP_METHOD(Phal_Format_Reader_Hal_JsonReader, transformEmbeddeds) {

	zephir_fcall_cache_entry *_4 = NULL, *_5 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	HashTable *_1;
	HashPosition _0;
	zval *resource, *embeddedsByRel, *rel = NULL, *data = NULL, *embedded = NULL, *embeddeds = NULL, **_2, *_3 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &resource, &embeddedsByRel);



	if (!(zephir_instance_of_ev(resource, phal_entity_ce TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Parameter 'resource' must be an instance of 'Phal\\Entity'", "", 0);
		return;
	}
	if (Z_TYPE_P(embeddedsByRel) != IS_ARRAY) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "embeddedsByRel must be array", "phal/format/reader/hal/jsonreader.zep", 182);
		return;
	}
	zephir_is_iterable(embeddedsByRel, &_1, &_0, 0, 0);
	for (
	  ; zephir_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
	  ; zephir_hash_move_forward_ex(_1, &_0)
	) {
		ZEPHIR_GET_HMKEY(rel, _1, _0);
		ZEPHIR_GET_HVALUE(data, _2);
		ZEPHIR_CALL_METHOD(&_3, this_ptr, "isassocarray", NULL, data);
		zephir_check_call_status();
		if (zephir_is_true(_3)) {
			ZEPHIR_CALL_METHOD(&embedded, this_ptr, "dotransformembedded", NULL, data);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, resource, "addresource", &_4, rel, embedded);
			zephir_check_call_status();
		} else {
			ZEPHIR_CALL_METHOD(&embeddeds, this_ptr, "dotransformembeddeds", NULL, data);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, resource, "addresources", &_5, rel, embeddeds);
			zephir_check_call_status();
		}
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Transform each embedded entity, return transformed array
 *
 * @param array data
 * @return array
 */
PHP_METHOD(Phal_Format_Reader_Hal_JsonReader, doTransformEmbeddeds) {

	int ZEPHIR_LAST_CALL_STATUS;
	HashTable *_1;
	HashPosition _0;
	zval *data, *embedded = NULL, *embeddeds, **_2, *_3 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &data);



	if (Z_TYPE_P(data) != IS_ARRAY) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "data must be array", "phal/format/reader/hal/jsonreader.zep", 207);
		return;
	}
	ZEPHIR_INIT_VAR(embeddeds);
	array_init(embeddeds);
	zephir_is_iterable(data, &_1, &_0, 0, 0);
	for (
	  ; zephir_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
	  ; zephir_hash_move_forward_ex(_1, &_0)
	) {
		ZEPHIR_GET_HVALUE(embedded, _2);
		ZEPHIR_CALL_METHOD(&_3, this_ptr, "dotransformembedded", NULL, embedded);
		zephir_check_call_status();
		zephir_array_append(&embeddeds, _3, PH_SEPARATE);
	}
	RETURN_CCTOR(embeddeds);

}

/**
 * @param array data
 * @return \Phal\Entity
 */
PHP_METHOD(Phal_Format_Reader_Hal_JsonReader, doTransformEmbedded) {

	zephir_fcall_cache_entry *_7 = NULL;
	zephir_nts_static zephir_fcall_cache_entry *_6 = NULL;
	HashTable *_1;
	HashPosition _0;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *data, *resource, *key = NULL, *value = NULL, **_2, _3 = zval_used_for_init, _4 = zval_used_for_init, *_5 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &data);



	if (Z_TYPE_P(data) != IS_ARRAY) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "data must be array", "phal/format/reader/hal/jsonreader.zep", 227);
		return;
	}
	ZEPHIR_INIT_VAR(resource);
	object_init_ex(resource, phal_entity_ce);
	ZEPHIR_CALL_METHOD(NULL, resource, "__construct", NULL);
	zephir_check_call_status();
	zephir_is_iterable(data, &_1, &_0, 0, 0);
	for (
	  ; zephir_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
	  ; zephir_hash_move_forward_ex(_1, &_0)
	) {
		ZEPHIR_GET_HMKEY(key, _1, _0);
		ZEPHIR_GET_HVALUE(value, _2);
		ZEPHIR_SINIT_NVAR(_3);
		ZVAL_LONG(&_3, 0);
		ZEPHIR_SINIT_NVAR(_4);
		ZVAL_LONG(&_4, 1);
		ZEPHIR_CALL_FUNCTION(&_5, "substr", &_6, key, &_3, &_4);
		zephir_check_call_status();
		if (!ZEPHIR_IS_STRING_IDENTICAL(_5, "_")) {
			ZEPHIR_CALL_METHOD(NULL, resource, "adddata", &_7, key, value);
			zephir_check_call_status();
		}
	}
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "transformmetadata", NULL, resource, data);
	zephir_check_call_status();
	RETURN_CCTOR(resource);

}

/**
 * Determine if data is associative array
 *
 * @param mixed data
 * @return boolean
 */
PHP_METHOD(Phal_Format_Reader_Hal_JsonReader, isAssocArray) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_4 = NULL;
	zval *data, *_0, _1, _2, *_3 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &data);



	ZEPHIR_INIT_VAR(_0);
	zephir_array_keys(_0, data TSRMLS_CC);
	ZEPHIR_SINIT_VAR(_1);
	ZVAL_LONG(&_1, 0);
	ZEPHIR_SINIT_VAR(_2);
	ZVAL_LONG(&_2, (zephir_fast_count_int(data TSRMLS_CC) - 1));
	ZEPHIR_CALL_FUNCTION(&_3, "range", &_4, &_1, &_2);
	zephir_check_call_status();
	RETURN_MM_BOOL(!ZEPHIR_IS_IDENTICAL(_0, _3));

}

