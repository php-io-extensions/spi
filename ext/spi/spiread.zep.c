
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
#include "api/spi-read.h"
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/object.h"
#include "kernel/string.h"


ZEPHIR_INIT_CLASS(Spi_SPIRead)
{
	ZEPHIR_REGISTER_CLASS(Spi, SPIRead, spi, spiread, spi_spiread_method_entry, 0);

	return SUCCESS;
}

PHP_METHOD(Spi_SPIRead, rdMode)
{
	zval *fd_param = NULL, _0;
	zend_long fd;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(fd)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &fd_param);
	ZVAL_LONG(&_0, fd);
	RETURN_LONG(spi_rd_mode(&_0));
}

PHP_METHOD(Spi_SPIRead, rdMode32)
{
	zval *fd_param = NULL, _0;
	zend_long fd;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(fd)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &fd_param);
	ZVAL_LONG(&_0, fd);
	RETURN_LONG(spi_rd_mode32(&_0));
}

PHP_METHOD(Spi_SPIRead, rdMaxSpeedHz)
{
	zval *fd_param = NULL, _0;
	zend_long fd;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(fd)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &fd_param);
	ZVAL_LONG(&_0, fd);
	RETURN_LONG(spi_rd_max_speed_hz(&_0));
}

PHP_METHOD(Spi_SPIRead, rdBitsPerWord)
{
	zval *fd_param = NULL, _0;
	zend_long fd;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(fd)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &fd_param);
	ZVAL_LONG(&_0, fd);
	RETURN_LONG(spi_rd_bits_per_word(&_0));
}

PHP_METHOD(Spi_SPIRead, rdLsbFirst)
{
	zval *fd_param = NULL, _0;
	zend_long fd;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(fd)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &fd_param);
	ZVAL_LONG(&_0, fd);
	RETURN_LONG(spi_rd_lsb_first(&_0));
}

PHP_METHOD(Spi_SPIRead, read)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *fd_param = NULL, *num_bytes_param = NULL, buffer, _0, _1;
	zend_long fd, num_bytes;

	ZVAL_UNDEF(&buffer);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(fd)
		Z_PARAM_LONG(num_bytes)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 2, 0, &fd_param, &num_bytes_param);
	ZVAL_LONG(&_0, fd);
	ZVAL_LONG(&_1, num_bytes);
	ZEPHIR_INIT_VAR(&buffer);
	spi_read(&buffer, &_0, &_1);
	RETURN_CCTOR(&buffer);
}

