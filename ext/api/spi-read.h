#ifndef PHP_SPI_READ_API_H
#define PHP_SPI_READ_API_H

#include "php.h"

zend_long spi_rd_mode(zval *fd);
zend_long spi_rd_mode32(zval *fd);
zend_long spi_rd_max_speed_hz(zval *fd);
zend_long spi_rd_bits_per_word(zval *fd);
zend_long spi_rd_lsb_first(zval *fd);
void      spi_read(zval *return_value, zval *fd, zval *num_bytes);

#endif /* PHP_SPI_READ_API_H */
