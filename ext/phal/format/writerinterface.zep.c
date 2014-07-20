
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


ZEPHIR_INIT_CLASS(Phal_Format_WriterInterface) {

	ZEPHIR_REGISTER_INTERFACE(Phal\\Format, WriterInterface, phal, format_writerinterface, phal_format_writerinterface_method_entry);

	return SUCCESS;

}

/**
 * Constructor
 *
 * @param boolean pretty
 */
ZEPHIR_DOC_METHOD(Phal_Format_WriterInterface, __construct);

/**
 * Execute parsing
 *
 * @param \Phal\Entity $resource
 * @return mixed
 */
ZEPHIR_DOC_METHOD(Phal_Format_WriterInterface, execute);

/**
 * Return the content type string for the resource
 *
 * @return string
 */
ZEPHIR_DOC_METHOD(Phal_Format_WriterInterface, getContentType);

