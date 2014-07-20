
#ifdef HAVE_CONFIG_H
#include "../ext_config.h"
#endif

#include <php.h>
#include "../php_ext.h"
#include "../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


ZEPHIR_INIT_CLASS(Phal_LinkInterface) {

	ZEPHIR_REGISTER_INTERFACE(Phal, LinkInterface, phal, linkinterface, phal_linkinterface_method_entry);

	return SUCCESS;

}

/**
 * Constructor
 *
 * @param string href
 */
ZEPHIR_DOC_METHOD(Phal_LinkInterface, __construct);

/**
 * Set href
 *
 * @param string href
 * @return \Phal\LinkInterface
 */
ZEPHIR_DOC_METHOD(Phal_LinkInterface, setHref);

/**
 * Get href
 *
 * @return string
 */
ZEPHIR_DOC_METHOD(Phal_LinkInterface, getHref);

/**
 * Set templated
 *
 * @param boolean templated
 * @return \Phal\LinkInterface
 */
ZEPHIR_DOC_METHOD(Phal_LinkInterface, setTemplated);

/**
 * Get templated
 *
 * @return boolean
 */
ZEPHIR_DOC_METHOD(Phal_LinkInterface, getTemplated);

/**
 * Set type
 *
 * @param string type
 * @return \Phal\LinkInterface
 */
ZEPHIR_DOC_METHOD(Phal_LinkInterface, setType);

/**
 * Get type
 *
 * @return string
 */
ZEPHIR_DOC_METHOD(Phal_LinkInterface, getType);

/**
 * Set deprecation
 *
 * @param string deprecation
 * @return \Phal\LinkInterface
 */
ZEPHIR_DOC_METHOD(Phal_LinkInterface, setDeprecation);

/**
 * Get deprecation
 *
 * @return string
 */
ZEPHIR_DOC_METHOD(Phal_LinkInterface, getDeprecation);

/**
 * Set name
 *
 * @param string name
 * @return \Phal\LinkInterface
 */
ZEPHIR_DOC_METHOD(Phal_LinkInterface, setName);

/**
 * Get name
 *
 * @return string
 */
ZEPHIR_DOC_METHOD(Phal_LinkInterface, getName);

/**
 * Set profile
 *
 * @param string profile
 * @return \Phal\LinkInterface
 */
ZEPHIR_DOC_METHOD(Phal_LinkInterface, setProfile);

/**
 * Get profile
 *
 * @return string
 */
ZEPHIR_DOC_METHOD(Phal_LinkInterface, getProfile);

/**
 * Set name
 *
 * @param string name
 * @return \Phal\LinkInterface
 */
ZEPHIR_DOC_METHOD(Phal_LinkInterface, setTitle);

/**
 * Get title
 *
 * @return string
 */
ZEPHIR_DOC_METHOD(Phal_LinkInterface, getTitle);

/**
 * Set hreflang
 *
 * @param string hreflang
 * @return \Phal\LinkInterface
 */
ZEPHIR_DOC_METHOD(Phal_LinkInterface, setHreflang);

/**
 * Get hreflang
 *
 * @return string
 */
ZEPHIR_DOC_METHOD(Phal_LinkInterface, getHreflang);

/**
 * Get link attributes
 *
 * @return array
 */
ZEPHIR_DOC_METHOD(Phal_LinkInterface, getAttributes);

/**
 * Serialize link to array
 *
 * @return array
 */
ZEPHIR_DOC_METHOD(Phal_LinkInterface, toArray);

/**
 * Return serialized string
 *
 * @return string
 */
ZEPHIR_DOC_METHOD(Phal_LinkInterface, __toString);

