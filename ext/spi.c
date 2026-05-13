
/* This file was generated automatically by Zephir do not modify it! */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <php.h>

#include "php_ext.h"
#include "spi.h"

#include <ext/standard/info.h>

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/globals.h"
#include "kernel/main.h"
#include "kernel/fcall.h"
#include "kernel/memory.h"



zend_class_entry *spi_spiread_ce;
zend_class_entry *spi_spiwrite_ce;

ZEND_DECLARE_MODULE_GLOBALS(spi)

PHP_INI_BEGIN()
	
PHP_INI_END()

static PHP_MINIT_FUNCTION(spi)
{
	REGISTER_INI_ENTRIES();
	zephir_module_init();
	ZEPHIR_INIT(Spi_SPIRead);
	ZEPHIR_INIT(Spi_SPIWrite);
	
	return SUCCESS;
}

#ifndef ZEPHIR_RELEASE
static PHP_MSHUTDOWN_FUNCTION(spi)
{
	
	zephir_deinitialize_memory();
	UNREGISTER_INI_ENTRIES();
	return SUCCESS;
}
#endif

/**
 * Initialize globals on each request or each thread started
 */
static void php_zephir_init_globals(zend_spi_globals *spi_globals)
{
	spi_globals->initialized = 0;

	/* Cache Enabled */
	spi_globals->cache_enabled = 1;

	/* Recursive Lock */
	spi_globals->recursive_lock = 0;

	/* Static cache */
	memset(spi_globals->scache, '\0', sizeof(zephir_fcall_cache_entry*) * ZEPHIR_MAX_CACHE_SLOTS);

	
	
}

/**
 * Initialize globals only on each thread started
 */
static void php_zephir_init_module_globals(zend_spi_globals *spi_globals)
{
	
}

static PHP_RINIT_FUNCTION(spi)
{
	zend_spi_globals *spi_globals_ptr;
	spi_globals_ptr = ZEPHIR_VGLOBAL;

	php_zephir_init_globals(spi_globals_ptr);
	zephir_initialize_memory(spi_globals_ptr);

	
	return SUCCESS;
}

static PHP_RSHUTDOWN_FUNCTION(spi)
{
	
	zephir_deinitialize_memory();
	return SUCCESS;
}



static PHP_MINFO_FUNCTION(spi)
{
	php_info_print_box_start(0);
	php_printf("%s", PHP_SPI_DESCRIPTION);
	php_info_print_box_end();

	php_info_print_table_start();
	php_info_print_table_header(2, PHP_SPI_NAME, "enabled");
	php_info_print_table_row(2, "Author", PHP_SPI_AUTHOR);
	php_info_print_table_row(2, "Version", PHP_SPI_VERSION);
	php_info_print_table_row(2, "Build Date", __DATE__ " " __TIME__ );
	php_info_print_table_row(2, "Powered by Zephir", "Version " PHP_SPI_ZEPVERSION);
	php_info_print_table_end();
	
	DISPLAY_INI_ENTRIES();
}

static PHP_GINIT_FUNCTION(spi)
{
#if defined(COMPILE_DL_SPI) && defined(ZTS)
	ZEND_TSRMLS_CACHE_UPDATE();
#endif

	php_zephir_init_globals(spi_globals);
	php_zephir_init_module_globals(spi_globals);
}

static PHP_GSHUTDOWN_FUNCTION(spi)
{
	
}


zend_function_entry php_spi_functions[] = {
	ZEND_FE_END

};

static const zend_module_dep php_spi_deps[] = {
	
	ZEND_MOD_END
};

zend_module_entry spi_module_entry = {
	STANDARD_MODULE_HEADER_EX,
	NULL,
	php_spi_deps,
	PHP_SPI_EXTNAME,
	php_spi_functions,
	PHP_MINIT(spi),
#ifndef ZEPHIR_RELEASE
	PHP_MSHUTDOWN(spi),
#else
	NULL,
#endif
	PHP_RINIT(spi),
	PHP_RSHUTDOWN(spi),
	PHP_MINFO(spi),
	PHP_SPI_VERSION,
	ZEND_MODULE_GLOBALS(spi),
	PHP_GINIT(spi),
	PHP_GSHUTDOWN(spi),
#ifdef ZEPHIR_POST_REQUEST
	PHP_PRSHUTDOWN(spi),
#else
	NULL,
#endif
	STANDARD_MODULE_PROPERTIES_EX
};

/* implement standard "stub" routine to introduce ourselves to Zend */
#ifdef COMPILE_DL_SPI
# ifdef ZTS
ZEND_TSRMLS_CACHE_DEFINE()
# endif
ZEND_GET_MODULE(spi)
#endif
