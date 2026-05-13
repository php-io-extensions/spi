
extern zend_class_entry *spi_spiread_ce;

ZEPHIR_INIT_CLASS(Spi_SPIRead);

PHP_METHOD(Spi_SPIRead, rdMode);
PHP_METHOD(Spi_SPIRead, rdMode32);
PHP_METHOD(Spi_SPIRead, rdMaxSpeedHz);
PHP_METHOD(Spi_SPIRead, rdBitsPerWord);
PHP_METHOD(Spi_SPIRead, rdLsbFirst);
PHP_METHOD(Spi_SPIRead, read);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_spi_spiread_rdmode, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, fd, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_spi_spiread_rdmode32, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, fd, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_spi_spiread_rdmaxspeedhz, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, fd, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_spi_spiread_rdbitsperword, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, fd, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_spi_spiread_rdlsbfirst, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, fd, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_spi_spiread_read, 0, 2, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, fd, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, num_bytes, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(spi_spiread_method_entry) {
	PHP_ME(Spi_SPIRead, rdMode, arginfo_spi_spiread_rdmode, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Spi_SPIRead, rdMode32, arginfo_spi_spiread_rdmode32, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Spi_SPIRead, rdMaxSpeedHz, arginfo_spi_spiread_rdmaxspeedhz, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Spi_SPIRead, rdBitsPerWord, arginfo_spi_spiread_rdbitsperword, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Spi_SPIRead, rdLsbFirst, arginfo_spi_spiread_rdlsbfirst, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Spi_SPIRead, read, arginfo_spi_spiread_read, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
