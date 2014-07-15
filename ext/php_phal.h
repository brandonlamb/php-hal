
/* This file was generated automatically by Zephir do not modify it! */

#ifndef PHP_PHAL_H
#define PHP_PHAL_H 1

#define ZEPHIR_RELEASE 1

#include "kernel/globals.h"

#define PHP_PHAL_NAME        "phal"
#define PHP_PHAL_VERSION     "0.0.1"
#define PHP_PHAL_EXTNAME     "phal"
#define PHP_PHAL_AUTHOR      ""
#define PHP_PHAL_ZEPVERSION  "0.4.2a"
#define PHP_PHAL_DESCRIPTION ""



ZEND_BEGIN_MODULE_GLOBALS(phal)

	/* Memory */
	zephir_memory_entry *start_memory; /**< The first preallocated frame */
	zephir_memory_entry *end_memory; /**< The last preallocate frame */
	zephir_memory_entry *active_memory; /**< The current memory frame */

	/* Virtual Symbol Tables */
	zephir_symbol_table *active_symbol_table;

	/** Function cache */
	HashTable *fcache;

	/* Max recursion control */
	unsigned int recursive_lock;

	/* Global constants */
	zval *global_true;
	zval *global_false;
	zval *global_null;
	
ZEND_END_MODULE_GLOBALS(phal)

#ifdef ZTS
#include "TSRM.h"
#endif

ZEND_EXTERN_MODULE_GLOBALS(phal)

#ifdef ZTS
	#define ZEPHIR_GLOBAL(v) TSRMG(phal_globals_id, zend_phal_globals *, v)
#else
	#define ZEPHIR_GLOBAL(v) (phal_globals.v)
#endif

#ifdef ZTS
	#define ZEPHIR_VGLOBAL ((zend_phal_globals *) (*((void ***) tsrm_ls))[TSRM_UNSHUFFLE_RSRC_ID(phal_globals_id)])
#else
	#define ZEPHIR_VGLOBAL &(phal_globals)
#endif

#define zephir_globals_def phal_globals
#define zend_zephir_globals_def zend_phal_globals

extern zend_module_entry phal_module_entry;
#define phpext_phal_ptr &phal_module_entry

#endif
