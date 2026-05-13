
/* This file was generated automatically by Zephir do not modify it! */

#ifndef PHP_SPI_H
#define PHP_SPI_H 1

#ifdef PHP_WIN32
#define ZEPHIR_RELEASE 1
#endif

#include "kernel/globals.h"

#define PHP_SPI_NAME        "spi"
#define PHP_SPI_VERSION     "0.1.7"
#define PHP_SPI_EXTNAME     "spi"
#define PHP_SPI_AUTHOR      "Project Saturn Studios, LLC"
#define PHP_SPI_ZEPVERSION  "0.19.0-$Id$"
#define PHP_SPI_DESCRIPTION "PHP-Controllable SPI Extension"



ZEND_BEGIN_MODULE_GLOBALS(spi)

	int initialized;

	/** Function cache */
	HashTable *fcache;

	zephir_fcall_cache_entry *scache[ZEPHIR_MAX_CACHE_SLOTS];

	/* Cache enabled */
	unsigned int cache_enabled;

	/* Max recursion control */
	unsigned int recursive_lock;

	
ZEND_END_MODULE_GLOBALS(spi)

#ifdef ZTS
#include "TSRM.h"
#endif

ZEND_EXTERN_MODULE_GLOBALS(spi)

#ifdef ZTS
	#define ZEPHIR_GLOBAL(v) ZEND_MODULE_GLOBALS_ACCESSOR(spi, v)
#else
	#define ZEPHIR_GLOBAL(v) (spi_globals.v)
#endif

#ifdef ZTS
	ZEND_TSRMLS_CACHE_EXTERN()
	#define ZEPHIR_VGLOBAL ((zend_spi_globals *) (*((void ***) tsrm_get_ls_cache()))[TSRM_UNSHUFFLE_RSRC_ID(spi_globals_id)])
#else
	#define ZEPHIR_VGLOBAL &(spi_globals)
#endif

#define ZEPHIR_API ZEND_API

#define zephir_globals_def spi_globals
#define zend_zephir_globals_def zend_spi_globals

extern zend_module_entry spi_module_entry;
#define phpext_spi_ptr &spi_module_entry

#endif
