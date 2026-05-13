
extern zend_class_entry *spi_spiwrite_ce;

ZEPHIR_INIT_CLASS(Spi_SPIWrite);

PHP_METHOD(Spi_SPIWrite, wrMode);
PHP_METHOD(Spi_SPIWrite, wrMode32);
PHP_METHOD(Spi_SPIWrite, wrMaxSpeedHz);
PHP_METHOD(Spi_SPIWrite, wrBitsPerWord);
PHP_METHOD(Spi_SPIWrite, wrLsbFirst);
PHP_METHOD(Spi_SPIWrite, write);
PHP_METHOD(Spi_SPIWrite, message);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_spi_spiwrite_wrmode, 0, 2, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, fd, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, value, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_spi_spiwrite_wrmode32, 0, 2, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, fd, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, value, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_spi_spiwrite_wrmaxspeedhz, 0, 2, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, fd, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, value, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_spi_spiwrite_wrbitsperword, 0, 2, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, fd, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, value, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_spi_spiwrite_wrlsbfirst, 0, 2, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, fd, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, value, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_spi_spiwrite_write, 0, 2, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, fd, IS_LONG, 0)
	ZEND_ARG_INFO(0, payload)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_spi_spiwrite_message, 0, 2, IS_ARRAY, 0)
	ZEND_ARG_TYPE_INFO(0, fd, IS_LONG, 0)
	ZEND_ARG_INFO(0, tx)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(spi_spiwrite_method_entry) {
	PHP_ME(Spi_SPIWrite, wrMode, arginfo_spi_spiwrite_wrmode, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Spi_SPIWrite, wrMode32, arginfo_spi_spiwrite_wrmode32, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Spi_SPIWrite, wrMaxSpeedHz, arginfo_spi_spiwrite_wrmaxspeedhz, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Spi_SPIWrite, wrBitsPerWord, arginfo_spi_spiwrite_wrbitsperword, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Spi_SPIWrite, wrLsbFirst, arginfo_spi_spiwrite_wrlsbfirst, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Spi_SPIWrite, write, arginfo_spi_spiwrite_write, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Spi_SPIWrite, message, arginfo_spi_spiwrite_message, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
