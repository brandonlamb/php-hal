
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
#include "kernel/memory.h"
#include "kernel/object.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/operators.h"
#include "kernel/hash.h"
#include "kernel/fcall.h"
#include "kernel/array.h"


ZEPHIR_INIT_CLASS(Phal_Entity) {

	ZEPHIR_REGISTER_CLASS(Phal, Entity, phal, entity, phal_entity_method_entry, 0);

	zend_declare_property_null(phal_entity_ce, SL("id"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phal_entity_ce, SL("title"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phal_entity_ce, SL("key"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phal_entity_ce, SL("uri"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phal_entity_ce, SL("entities"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phal_entity_ce, SL("linkedResources"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phal_entity_ce, SL("links"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phal_entity_ce, SL("data"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phal_entity_ce, SL("lastUpdate"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phal_entity_ce, SL("cache"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phal_entity_ce, SL("writer"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

/**
 * Constructor
 */
PHP_METHOD(Phal_Entity, __construct) {

	zval *_0, *_1, *_2, *_3;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	array_init(_0);
	zephir_update_property_this(this_ptr, SL("entities"), _0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_1);
	array_init(_1);
	zephir_update_property_this(this_ptr, SL("linkedResources"), _1 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_2);
	array_init(_2);
	zephir_update_property_this(this_ptr, SL("links"), _2 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_3);
	array_init(_3);
	zephir_update_property_this(this_ptr, SL("data"), _3 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Phal_Entity, setId) {

	zval *id;

	zephir_fetch_params(0, 1, 0, &id);



	zephir_update_property_this(this_ptr, SL("id"), id TSRMLS_CC);
	RETURN_THISW();

}

PHP_METHOD(Phal_Entity, getId) {


	RETURN_MEMBER(this_ptr, "id");

}

PHP_METHOD(Phal_Entity, setRepositoryKey) {

	zval *key_param = NULL;
	zval *key = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &key_param);

	if (unlikely(Z_TYPE_P(key_param) != IS_STRING && Z_TYPE_P(key_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'key' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (unlikely(Z_TYPE_P(key_param) == IS_STRING)) {
		key = key_param;
	} else {
		ZEPHIR_INIT_VAR(key);
		ZVAL_EMPTY_STRING(key);
	}


	zephir_update_property_this(this_ptr, SL("key"), key TSRMLS_CC);
	RETURN_THIS();

}

PHP_METHOD(Phal_Entity, getRepositoryKey) {


	RETURN_MEMBER(this_ptr, "key");

}

PHP_METHOD(Phal_Entity, setTitle) {

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

PHP_METHOD(Phal_Entity, getTitle) {


	RETURN_MEMBER(this_ptr, "title");

}

PHP_METHOD(Phal_Entity, setUri) {

	zval *uri_param = NULL;
	zval *uri = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &uri_param);

	if (unlikely(Z_TYPE_P(uri_param) != IS_STRING && Z_TYPE_P(uri_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'uri' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (unlikely(Z_TYPE_P(uri_param) == IS_STRING)) {
		uri = uri_param;
	} else {
		ZEPHIR_INIT_VAR(uri);
		ZVAL_EMPTY_STRING(uri);
	}


	zephir_update_property_this(this_ptr, SL("uri"), uri TSRMLS_CC);
	RETURN_THIS();

}

PHP_METHOD(Phal_Entity, getUri) {


	RETURN_MEMBER(this_ptr, "uri");

}

PHP_METHOD(Phal_Entity, setData) {

	zval *data_param = NULL;
	zval *data = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &data_param);

	zephir_get_arrval(data, data_param);


	zephir_update_property_this(this_ptr, SL("data"), data TSRMLS_CC);
	RETURN_THIS();

}

PHP_METHOD(Phal_Entity, addData) {

	zval *key_param = NULL, *value;
	zval *key = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &key_param, &value);

	if (unlikely(Z_TYPE_P(key_param) != IS_STRING && Z_TYPE_P(key_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'key' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (unlikely(Z_TYPE_P(key_param) == IS_STRING)) {
		key = key_param;
	} else {
		ZEPHIR_INIT_VAR(key);
		ZVAL_EMPTY_STRING(key);
	}


	zephir_update_property_array(this_ptr, SL("data"), key, value TSRMLS_CC);
	RETURN_THIS();

}

PHP_METHOD(Phal_Entity, getData) {


	RETURN_MEMBER(this_ptr, "data");

}

PHP_METHOD(Phal_Entity, setLink) {

	zval *rel_param = NULL, *link;
	zval *rel = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &rel_param, &link);

	if (unlikely(Z_TYPE_P(rel_param) != IS_STRING && Z_TYPE_P(rel_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'rel' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (unlikely(Z_TYPE_P(rel_param) == IS_STRING)) {
		rel = rel_param;
	} else {
		ZEPHIR_INIT_VAR(rel);
		ZVAL_EMPTY_STRING(rel);
	}


	if (!(zephir_instance_of_ev(link, phal_link_ce TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Parameter 'link' must be an instance of 'Phal\\Link'", "", 0);
		return;
	}
	zephir_update_property_array(this_ptr, SL("links"), rel, link TSRMLS_CC);
	RETURN_THIS();

}

PHP_METHOD(Phal_Entity, setLinks) {

	HashTable *_1;
	HashPosition _0;
	zval *rel_param = NULL, *links, *link = NULL, **_2;
	zval *rel = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &rel_param, &links);

	if (unlikely(Z_TYPE_P(rel_param) != IS_STRING && Z_TYPE_P(rel_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'rel' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (unlikely(Z_TYPE_P(rel_param) == IS_STRING)) {
		rel = rel_param;
	} else {
		ZEPHIR_INIT_VAR(rel);
		ZVAL_EMPTY_STRING(rel);
	}


	zephir_is_iterable(links, &_1, &_0, 0, 0);
	for (
	  ; zephir_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
	  ; zephir_hash_move_forward_ex(_1, &_0)
	) {
		ZEPHIR_GET_HVALUE(link, _2);
		if (!(zephir_instance_of_ev(link, phal_link_ce TSRMLS_CC))) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Invalid array, must be []Link", "phal/entity.zep", 108);
			return;
		}
	}
	zephir_update_property_array(this_ptr, SL("links"), rel, links TSRMLS_CC);
	RETURN_THIS();

}

PHP_METHOD(Phal_Entity, linkResource) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *rel_param = NULL, *entity;
	zval *rel = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &rel_param, &entity);

	if (unlikely(Z_TYPE_P(rel_param) != IS_STRING && Z_TYPE_P(rel_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'rel' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (unlikely(Z_TYPE_P(rel_param) == IS_STRING)) {
		rel = rel_param;
	} else {
		ZEPHIR_INIT_VAR(rel);
		ZVAL_EMPTY_STRING(rel);
	}


	if (!(zephir_instance_of_ev(entity, phal_entity_ce TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Parameter 'entity' must be an instance of 'Phal\\Entity'", "", 0);
		return;
	}
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "throwexceptionifnotlinkableresouce", NULL, entity);
	zephir_check_call_status();
	zephir_update_property_array(this_ptr, SL("linkedResources"), rel, entity TSRMLS_CC);
	RETURN_THIS();

}

PHP_METHOD(Phal_Entity, linkResources) {

	int ZEPHIR_LAST_CALL_STATUS;
	HashTable *_1;
	HashPosition _0;
	zval *rel_param = NULL, *entities, *entity = NULL, **_2;
	zval *rel = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &rel_param, &entities);

	if (unlikely(Z_TYPE_P(rel_param) != IS_STRING && Z_TYPE_P(rel_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'rel' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (unlikely(Z_TYPE_P(rel_param) == IS_STRING)) {
		rel = rel_param;
	} else {
		ZEPHIR_INIT_VAR(rel);
		ZVAL_EMPTY_STRING(rel);
	}


	zephir_is_iterable(entities, &_1, &_0, 0, 0);
	for (
	  ; zephir_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
	  ; zephir_hash_move_forward_ex(_1, &_0)
	) {
		ZEPHIR_GET_HVALUE(entity, _2);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "throwexceptionifnotlinkableresouce", NULL, entity);
		zephir_check_call_status();
	}
	zephir_update_property_array(this_ptr, SL("linkedResources"), rel, entities TSRMLS_CC);
	RETURN_THIS();

}

PHP_METHOD(Phal_Entity, throwExceptionIfNotLinkableResouce) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *entity, *link = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &entity);



	if (!(zephir_instance_of_ev(entity, phal_entity_ce TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Parameter 'entity' must be an instance of 'Phal\\Entity'", "", 0);
		return;
	}
	ZEPHIR_CALL_METHOD(&link, entity, "getselflink",  NULL);
	zephir_check_call_status();
	if (!(zephir_is_true(link))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "This resource not contains a valid URI", "phal/entity.zep", 144);
		return;
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Phal_Entity, expandLinkedResourcesTree) {

	HashTable *_4;
	HashPosition _3;
	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_1 = NULL, *_2 = NULL;
	zval *path, *rel = NULL, *entity = NULL, *entities = NULL, *_0 = NULL, **_5;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &path);



	if (zephir_fast_count_int(path TSRMLS_CC) == 1) {
		Z_SET_ISREF_P(path);
		ZEPHIR_CALL_FUNCTION(&_0, "end", &_1, path);
		Z_UNSET_ISREF_P(path);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "expandlinkedresources", NULL, _0);
		zephir_check_call_status();
		RETURN_MM_NULL();
	}
	Z_SET_ISREF_P(path);
	ZEPHIR_CALL_FUNCTION(&rel, "array_shift", &_2, path);
	Z_UNSET_ISREF_P(path);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "expandlinkedresources", NULL, rel);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&entities, this_ptr, "getresources", NULL, rel);
	zephir_check_call_status();
	if (!(zephir_is_true(entities))) {
		RETURN_MM_NULL();
	}
	if (Z_TYPE_P(entities) != IS_ARRAY) {
		ZEPHIR_INIT_BNVAR(entities);
		array_init_size(entities, 2);
		zephir_array_fast_append(entities, entities);
	}
	zephir_is_iterable(entities, &_4, &_3, 0, 0);
	for (
	  ; zephir_hash_get_current_data_ex(_4, (void**) &_5, &_3) == SUCCESS
	  ; zephir_hash_move_forward_ex(_4, &_3)
	) {
		ZEPHIR_GET_HVALUE(entity, _5);
		ZEPHIR_CALL_METHOD(NULL, entity, "expandlinkedresourcestree", NULL, path);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Phal_Entity, expandLinkedResources) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *rel_param = NULL, *entities = NULL;
	zval *rel = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &rel_param);

	if (unlikely(Z_TYPE_P(rel_param) != IS_STRING && Z_TYPE_P(rel_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'rel' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (unlikely(Z_TYPE_P(rel_param) == IS_STRING)) {
		rel = rel_param;
	} else {
		ZEPHIR_INIT_VAR(rel);
		ZVAL_EMPTY_STRING(rel);
	}


	ZEPHIR_CALL_METHOD(&entities, this_ptr, "getlinkedresources", NULL, rel);
	zephir_check_call_status();
	if (!(zephir_is_true(entities))) {
		RETURN_MM_NULL();
	}
	if (Z_TYPE_P(entities) != IS_ARRAY) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "addresource", NULL, rel, entities);
		zephir_check_call_status();
	} else {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "addresources", NULL, rel, entities);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Phal_Entity, getAllLinkedResources) {


	RETURN_MEMBER(this_ptr, "linkedResources");

}

PHP_METHOD(Phal_Entity, getLinkedResources) {

	zval *rel, *entity, *_0;

	zephir_fetch_params(0, 1, 0, &rel);



	_0 = zephir_fetch_nproperty_this(this_ptr, SL("linkedResources"), PH_NOISY_CC);
	if (zephir_array_isset_fetch(&entity, _0, rel, 1 TSRMLS_CC)) {
		RETURN_CTORW(entity);
	}
	RETURN_NULL();

}

PHP_METHOD(Phal_Entity, getAllLinks) {


	RETURN_MEMBER(this_ptr, "links");

}

PHP_METHOD(Phal_Entity, getLinks) {

	zval *rel, *link, *_0;

	zephir_fetch_params(0, 1, 0, &rel);



	_0 = zephir_fetch_nproperty_this(this_ptr, SL("links"), PH_NOISY_CC);
	if (zephir_array_isset_fetch(&link, _0, rel, 1 TSRMLS_CC)) {
		RETURN_CTORW(link);
	}
	RETURN_NULL();

}

PHP_METHOD(Phal_Entity, addResource) {

	zend_bool multi;
	zval *rel_param = NULL, *entity, *multi_param = NULL, *_0, *_1;
	zval *rel = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &rel_param, &entity, &multi_param);

	if (unlikely(Z_TYPE_P(rel_param) != IS_STRING && Z_TYPE_P(rel_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'rel' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (unlikely(Z_TYPE_P(rel_param) == IS_STRING)) {
		rel = rel_param;
	} else {
		ZEPHIR_INIT_VAR(rel);
		ZVAL_EMPTY_STRING(rel);
	}
	if (!multi_param) {
		multi = 1;
	} else {
	if (unlikely(Z_TYPE_P(multi_param) != IS_BOOL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'multi' must be a bool") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	multi = Z_BVAL_P(multi_param);
	}


	if (!(zephir_instance_of_ev(entity, phal_entity_ce TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Parameter 'entity' must be an instance of 'Phal\\Entity'", "", 0);
		return;
	}
	if (unlikely(!multi)) {
		zephir_update_property_array(this_ptr, SL("entities"), rel, entity TSRMLS_CC);
	} else {
		_0 = zephir_fetch_nproperty_this(this_ptr, SL("entities"), PH_NOISY_CC);
		if (unlikely(!zephir_array_isset(_0, rel))) {
			ZEPHIR_INIT_VAR(_1);
			array_init(_1);
			zephir_update_property_array(this_ptr, SL("entities"), rel, _1 TSRMLS_CC);
		}
		zephir_update_property_array_multi(this_ptr, SL("entities"), &entity TSRMLS_CC, SL("za"), 1, rel);
	}
	RETURN_THIS();

}

PHP_METHOD(Phal_Entity, addResources) {

	int ZEPHIR_LAST_CALL_STATUS;
	HashTable *_1, *_4;
	HashPosition _0, _3;
	zend_bool overwrite;
	zval *rel_param = NULL, *entities, *overwrite_param = NULL, *entity = NULL, **_2, **_5;
	zval *rel = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &rel_param, &entities, &overwrite_param);

	if (unlikely(Z_TYPE_P(rel_param) != IS_STRING && Z_TYPE_P(rel_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'rel' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (unlikely(Z_TYPE_P(rel_param) == IS_STRING)) {
		rel = rel_param;
	} else {
		ZEPHIR_INIT_VAR(rel);
		ZVAL_EMPTY_STRING(rel);
	}
	if (!overwrite_param) {
		overwrite = 0;
	} else {
	if (unlikely(Z_TYPE_P(overwrite_param) != IS_BOOL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'overwrite' must be a bool") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	overwrite = Z_BVAL_P(overwrite_param);
	}


	if (unlikely(overwrite)) {
		zephir_is_iterable(entities, &_1, &_0, 0, 0);
		for (
		  ; zephir_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
		  ; zephir_hash_move_forward_ex(_1, &_0)
		) {
			ZEPHIR_GET_HVALUE(entity, _2);
			if (!(zephir_instance_of_ev(entity, phal_entity_ce TSRMLS_CC))) {
				ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "entity must be a \\Phal\\Entity", "phal/entity.zep", 241);
				return;
			}
		}
		zephir_update_property_array(this_ptr, SL("entities"), rel, entities TSRMLS_CC);
		RETURN_THIS();
	}
	zephir_is_iterable(entities, &_4, &_3, 0, 0);
	for (
	  ; zephir_hash_get_current_data_ex(_4, (void**) &_5, &_3) == SUCCESS
	  ; zephir_hash_move_forward_ex(_4, &_3)
	) {
		ZEPHIR_GET_HVALUE(entity, _5);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "addresource", NULL, rel, entity, ZEPHIR_GLOBAL(global_true));
		zephir_check_call_status();
	}
	RETURN_THIS();

}

PHP_METHOD(Phal_Entity, getAllResources) {


	RETURN_MEMBER(this_ptr, "entities");

}

PHP_METHOD(Phal_Entity, getResources) {

	zval *rel_param = NULL, *entity, *_0;
	zval *rel = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &rel_param);

	if (unlikely(Z_TYPE_P(rel_param) != IS_STRING && Z_TYPE_P(rel_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'rel' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (unlikely(Z_TYPE_P(rel_param) == IS_STRING)) {
		rel = rel_param;
	} else {
		ZEPHIR_INIT_VAR(rel);
		ZVAL_EMPTY_STRING(rel);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("entities"), PH_NOISY_CC);
	if (zephir_array_isset_fetch(&entity, _0, rel, 1 TSRMLS_CC)) {
		RETURN_CTOR(entity);
	}
	RETURN_MM_NULL();

}

PHP_METHOD(Phal_Entity, getSelfLink) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *link, *_0, *_1 = NULL, *_2 = NULL, *_3 = NULL;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("uri"), PH_NOISY_CC);
	if (!(zephir_is_true(_0))) {
		RETURN_MM_NULL();
	}
	ZEPHIR_INIT_VAR(link);
	object_init_ex(link, phal_link_ce);
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "geturi",  NULL);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, link, "__construct", NULL, _1);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_2, this_ptr, "gettitle",  NULL);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, link, "settitle", NULL, _2);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_3, this_ptr, "getid",  NULL);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, link, "setname", NULL, _3);
	zephir_check_call_status();
	RETURN_CCTOR(link);

}

PHP_METHOD(Phal_Entity, setLastUpdate) {

	zval *date;

	zephir_fetch_params(0, 1, 0, &date);



	if (!(zephir_is_instance_of(date, SL("DateTime") TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STRW(spl_ce_InvalidArgumentException, "Parameter 'date' must be an instance of 'DateTime'", "", 0);
		return;
	}
	zephir_update_property_this(this_ptr, SL("lastUpdate"), date TSRMLS_CC);
	RETURN_THISW();

}

PHP_METHOD(Phal_Entity, getLastUpdate) {


	RETURN_MEMBER(this_ptr, "lastUpdate");

}

PHP_METHOD(Phal_Entity, setCache) {

	zval *secs_param = NULL, *_0;
	int secs;

	zephir_fetch_params(0, 1, 0, &secs_param);

	secs = zephir_get_intval(secs_param);


	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(_0, secs);
	zephir_update_property_this(this_ptr, SL("cache"), _0 TSRMLS_CC);
	RETURN_THISW();

}

PHP_METHOD(Phal_Entity, getCache) {


	RETURN_MEMBER(this_ptr, "cache");

}

PHP_METHOD(Phal_Entity, setFormatWriter) {

	zval *writer;

	zephir_fetch_params(0, 1, 0, &writer);



	if (!(zephir_instance_of_ev(writer, phal_format_abstractwriter_ce TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STRW(spl_ce_InvalidArgumentException, "Parameter 'writer' must be an instance of 'Phal\\Format\\AbstractWriter'", "", 0);
		return;
	}
	zephir_update_property_this(this_ptr, SL("writer"), writer TSRMLS_CC);
	RETURN_THISW();

}

PHP_METHOD(Phal_Entity, getFormatWriter) {


	RETURN_MEMBER(this_ptr, "writer");

}

PHP_METHOD(Phal_Entity, __toString) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0, *_1;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("writer"), PH_NOISY_CC);
	if (!(zephir_is_true(_0))) {
		RETURN_MM_STRING("", 1);
	}
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("writer"), PH_NOISY_CC);
	ZEPHIR_RETURN_CALL_METHOD(_1, "execute", NULL, this_ptr);
	zephir_check_call_status();
	RETURN_MM();

}

