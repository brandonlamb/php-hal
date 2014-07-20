
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
#include "kernel/object.h"
#include "kernel/exception.h"
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "kernel/array.h"
#include "kernel/operators.h"
#include "kernel/hash.h"


ZEPHIR_INIT_CLASS(Phal_Format_Writer_Hal_JsonWriter) {

	ZEPHIR_REGISTER_CLASS_EX(Phal\\Format\\Writer\\Hal, JsonWriter, phal, format_writer_hal_jsonwriter, phal_format_writer_abstractjsonwriter_ce, phal_format_writer_hal_jsonwriter_method_entry, 0);

	zend_declare_class_constant_string(phal_format_writer_hal_jsonwriter_ce, SL("CONTENT_TYPE"), "application/hal+json" TSRMLS_CC);

	return SUCCESS;

}

/**
 * Execute parsing
 *
 * @param \Phal\Entity entity
 * @return array
 */
PHP_METHOD(Phal_Format_Writer_Hal_JsonWriter, resourceToArray) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *entity, *data = NULL, *links = NULL, *embedded = NULL, *_0 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &entity);



	if (!(zephir_instance_of_ev(entity, phal_entity_ce TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Parameter 'entity' must be an instance of 'Phal\\Entity'", "", 0);
		return;
	}
	ZEPHIR_CALL_METHOD(&data, entity, "getdata",  NULL);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(links);
	array_init(links);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "transformlinks", NULL, links, entity);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(links, _0);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "transformlinkedresources", NULL, links, entity);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(links, _0);
	if (zephir_fast_count_int(links TSRMLS_CC) > 0) {
		zephir_array_update_string(&data, SL("_links"), &links, PH_COPY | PH_SEPARATE);
	}
	ZEPHIR_CALL_METHOD(&embedded, this_ptr, "transformresources", NULL, entity);
	zephir_check_call_status();
	if (zephir_fast_count_int(embedded TSRMLS_CC) > 0) {
		zephir_array_update_string(&data, SL("_embedded"), &embedded, PH_COPY | PH_SEPARATE);
	}
	RETURN_CCTOR(data);

}

/**
 * Transform links to array
 *
 * @param array data
 * @param \Phal\Entity entity
 * @return array
 */
PHP_METHOD(Phal_Format_Writer_Hal_JsonWriter, transformLinks) {

	HashTable *_2, *_6;
	HashPosition _1, _5;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *data, *entity, *selfLink = NULL, *rel = NULL, *link = NULL, *links = NULL, *_0 = NULL, **_3, *_4 = NULL, **_7;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &data, &entity);

	ZEPHIR_SEPARATE_PARAM(data);


	if (!(zephir_instance_of_ev(entity, phal_entity_ce TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Parameter 'entity' must be an instance of 'Phal\\Entity'", "", 0);
		return;
	}
	ZEPHIR_CALL_METHOD(&selfLink, entity, "getselflink",  NULL);
	zephir_check_call_status();
	if (zephir_is_true(selfLink)) {
		ZEPHIR_CALL_METHOD(&_0, selfLink, "toarray",  NULL);
		zephir_check_call_status();
		zephir_array_update_string(&data, SL("self"), &_0, PH_COPY | PH_SEPARATE);
	}
	ZEPHIR_CALL_METHOD(&_0, entity, "getalllinks",  NULL);
	zephir_check_call_status();
	zephir_is_iterable(_0, &_2, &_1, 0, 0);
	for (
	  ; zephir_hash_get_current_data_ex(_2, (void**) &_3, &_1) == SUCCESS
	  ; zephir_hash_move_forward_ex(_2, &_1)
	) {
		ZEPHIR_GET_HMKEY(rel, _2, _1);
		ZEPHIR_GET_HVALUE(links, _3);
		if (Z_TYPE_P(links) != IS_ARRAY) {
			ZEPHIR_CALL_METHOD(&_4, links, "toarray",  NULL);
			zephir_check_call_status();
			zephir_array_update_zval(&data, rel, &_4, PH_COPY | PH_SEPARATE);
		} else {
			zephir_is_iterable(links, &_6, &_5, 0, 0);
			for (
			  ; zephir_hash_get_current_data_ex(_6, (void**) &_7, &_5) == SUCCESS
			  ; zephir_hash_move_forward_ex(_6, &_5)
			) {
				ZEPHIR_GET_HVALUE(link, _7);
				ZEPHIR_CALL_METHOD(&_4, link, "toarray",  NULL);
				zephir_check_call_status();
				zephir_array_update_multi(&data, &_4 TSRMLS_CC, SL("za"), 2, rel);
			}
		}
	}
	RETURN_CCTOR(data);

}

PHP_METHOD(Phal_Format_Writer_Hal_JsonWriter, transformLinkedResources) {

	HashTable *_2, *_7;
	HashPosition _1, _6;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *data, *entity, *rel = NULL, *link = NULL, *links = NULL, *_0 = NULL, **_3, *_4 = NULL, *_5 = NULL, **_8;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &data, &entity);

	ZEPHIR_SEPARATE_PARAM(data);


	if (!(zephir_instance_of_ev(entity, phal_entity_ce TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Parameter 'entity' must be an instance of 'Phal\\Entity'", "", 0);
		return;
	}
	if (Z_TYPE_P(data) != IS_ARRAY) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "data must be array", "phal/format/writer/hal/jsonwriter.zep", 75);
		return;
	}
	ZEPHIR_CALL_METHOD(&_0, entity, "getalllinkedresources",  NULL);
	zephir_check_call_status();
	zephir_is_iterable(_0, &_2, &_1, 0, 0);
	for (
	  ; zephir_hash_get_current_data_ex(_2, (void**) &_3, &_1) == SUCCESS
	  ; zephir_hash_move_forward_ex(_2, &_1)
	) {
		ZEPHIR_GET_HMKEY(rel, _2, _1);
		ZEPHIR_GET_HVALUE(links, _3);
		if (Z_TYPE_P(links) != IS_ARRAY) {
			ZEPHIR_CALL_METHOD(&_4, links, "getselflink",  NULL);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&_5, _4, "toarray",  NULL);
			zephir_check_call_status();
			zephir_array_update_zval(&data, rel, &_5, PH_COPY | PH_SEPARATE);
		} else {
			zephir_is_iterable(links, &_7, &_6, 0, 0);
			for (
			  ; zephir_hash_get_current_data_ex(_7, (void**) &_8, &_6) == SUCCESS
			  ; zephir_hash_move_forward_ex(_7, &_6)
			) {
				ZEPHIR_GET_HVALUE(link, _8);
				ZEPHIR_CALL_METHOD(&_4, link, "getselflink",  NULL);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&_5, _4, "toarray",  NULL);
				zephir_check_call_status();
				zephir_array_update_multi(&data, &_5 TSRMLS_CC, SL("za"), 2, rel);
			}
		}
	}
	RETURN_CCTOR(data);

}

PHP_METHOD(Phal_Format_Writer_Hal_JsonWriter, transformResources) {

	HashTable *_2, *_5;
	HashPosition _1, _4;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *entity, *embedded, *rel = NULL, *subEntity = NULL, *subEntity2 = NULL, *_0 = NULL, **_3, **_6, *_7 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &entity);



	if (!(zephir_instance_of_ev(entity, phal_entity_ce TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Parameter 'entity' must be an instance of 'Phal\\Entity'", "", 0);
		return;
	}
	ZEPHIR_INIT_VAR(embedded);
	array_init(embedded);
	ZEPHIR_CALL_METHOD(&_0, entity, "getallresources",  NULL);
	zephir_check_call_status();
	zephir_is_iterable(_0, &_2, &_1, 0, 0);
	for (
	  ; zephir_hash_get_current_data_ex(_2, (void**) &_3, &_1) == SUCCESS
	  ; zephir_hash_move_forward_ex(_2, &_1)
	) {
		ZEPHIR_GET_HMKEY(rel, _2, _1);
		ZEPHIR_GET_HVALUE(subEntity, _3);
		if (Z_TYPE_P(subEntity) != IS_OBJECT) {
			zephir_is_iterable(subEntity, &_5, &_4, 0, 0);
			for (
			  ; zephir_hash_get_current_data_ex(_5, (void**) &_6, &_4) == SUCCESS
			  ; zephir_hash_move_forward_ex(_5, &_4)
			) {
				ZEPHIR_GET_HVALUE(subEntity2, _6);
				ZEPHIR_CALL_METHOD(&_7, this_ptr, "resourcetoarray", NULL, subEntity2);
				zephir_check_call_status();
				zephir_array_update_multi(&embedded, &_7 TSRMLS_CC, SL("za"), 2, rel);
			}
		} else {
			if (zephir_instance_of_ev(subEntity, phal_entity_ce TSRMLS_CC)) {
				ZEPHIR_CALL_METHOD(&_7, this_ptr, "resourcetoarray", NULL, entity);
				zephir_check_call_status();
				zephir_array_update_zval(&embedded, rel, &_7, PH_COPY | PH_SEPARATE);
			}
		}
	}
	RETURN_CCTOR(embedded);

}

