
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
#include "api/spi-write.h"
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/object.h"
#include "kernel/string.h"


ZEPHIR_INIT_CLASS(Spi_SPIWrite)
{
	ZEPHIR_REGISTER_CLASS(Spi, SPIWrite, spi, spiwrite, spi_spiwrite_method_entry, 0);

	return SUCCESS;
}

PHP_METHOD(Spi_SPIWrite, wrMode)
{
	zval *fd_param = NULL, *value_param = NULL, _0, _1;
	zend_long fd, value;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(fd)
		Z_PARAM_LONG(value)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &fd_param, &value_param);
	ZVAL_LONG(&_0, fd);
	ZVAL_LONG(&_1, value);
	RETURN_LONG(spi_wr_mode(&_0, &_1));
}

PHP_METHOD(Spi_SPIWrite, wrMode32)
{
	zval *fd_param = NULL, *value_param = NULL, _0, _1;
	zend_long fd, value;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(fd)
		Z_PARAM_LONG(value)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &fd_param, &value_param);
	ZVAL_LONG(&_0, fd);
	ZVAL_LONG(&_1, value);
	RETURN_LONG(spi_wr_mode32(&_0, &_1));
}

PHP_METHOD(Spi_SPIWrite, wrMaxSpeedHz)
{
	zval *fd_param = NULL, *value_param = NULL, _0, _1;
	zend_long fd, value;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(fd)
		Z_PARAM_LONG(value)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &fd_param, &value_param);
	ZVAL_LONG(&_0, fd);
	ZVAL_LONG(&_1, value);
	RETURN_LONG(spi_wr_max_speed_hz(&_0, &_1));
}

PHP_METHOD(Spi_SPIWrite, wrBitsPerWord)
{
	zval *fd_param = NULL, *value_param = NULL, _0, _1;
	zend_long fd, value;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(fd)
		Z_PARAM_LONG(value)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &fd_param, &value_param);
	ZVAL_LONG(&_0, fd);
	ZVAL_LONG(&_1, value);
	RETURN_LONG(spi_wr_bits_per_word(&_0, &_1));
}

PHP_METHOD(Spi_SPIWrite, wrLsbFirst)
{
	zval *fd_param = NULL, *value_param = NULL, _0, _1;
	zend_long fd, value;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(fd)
		Z_PARAM_LONG(value)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &fd_param, &value_param);
	ZVAL_LONG(&_0, fd);
	ZVAL_LONG(&_1, value);
	RETURN_LONG(spi_wr_lsb_first(&_0, &_1));
}

/**
 * Half-duplex write - Uses standard write() syscall
 * CS toggles after this operation
 * Returns number of bytes written
 */
PHP_METHOD(Spi_SPIWrite, write)
{
	zval data;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *fd_param = NULL, *payload = NULL, payload_sub, _0;
	zend_long fd;

	ZVAL_UNDEF(&payload_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&data);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(fd)
		Z_PARAM_ZVAL(payload)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 2, 0, &fd_param, &payload);
	zephir_get_strval(&data, payload);
	ZVAL_LONG(&_0, fd);
	RETURN_MM_LONG(spi_write(&_0, &data));
}

PHP_METHOD(Spi_SPIWrite, message)
{
	zval payload;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *fd_param = NULL, *tx = NULL, tx_sub, result, _0;
	zend_long fd;

	ZVAL_UNDEF(&tx_sub);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&payload);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(fd)
		Z_PARAM_ZVAL(tx)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 2, 0, &fd_param, &tx);
	zephir_get_strval(&payload, tx);
	ZVAL_LONG(&_0, fd);
	ZEPHIR_INIT_VAR(&result);
	spi_message(&result, &_0, &payload);
	RETURN_CCTOR(&result);
}

