
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


ZEPHIR_INIT_CLASS(Phal_Format_ReaderInterface) {

	ZEPHIR_REGISTER_INTERFACE(Phal\\Format, ReaderInterface, phal, format_readerinterface, phal_format_readerinterface_method_entry);

	return SUCCESS;

}

/**
 * Execute parsing
 *
 * @param string input
 * @return mixed
 */
ZEPHIR_DOC_METHOD(Phal_Format_ReaderInterface, execute);

/**
 * Return the content type string for the resource
 *
 * @return string
 */
ZEPHIR_DOC_METHOD(Phal_Format_ReaderInterface, getContentType);

