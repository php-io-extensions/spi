#ifndef PHP_SPI_WRITE_API_H
#define PHP_SPI_WRITE_API_H

#include "php.h"

zend_long spi_wr_mode(zval *fd, zval *value);
zend_long spi_wr_mode32(zval *fd, zval *value);
zend_long spi_wr_max_speed_hz(zval *fd, zval *value);
zend_long spi_wr_bits_per_word(zval *fd, zval *value);
zend_long spi_wr_lsb_first(zval *fd, zval *value);
zend_long spi_write(zval *fd, zval *payload);
void      spi_message(zval *return_value, zval *fd, zval *tx);

#endif /* PHP_SPI_WRITE_API_H */
