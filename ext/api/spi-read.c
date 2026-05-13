#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_ext.h"
#include "spi-read.h"

#include <linux/spi/spidev.h>
#include <stdint.h>
#include <sys/ioctl.h>
#include <unistd.h>

zend_long spi_rd_mode(zval *fd)
{
    uint8_t value = 0;
    int     result = ioctl((int) Z_LVAL_P(fd), SPI_IOC_RD_MODE, &value);

    return (result < 0) ? -1 : (zend_long) value;
}

zend_long spi_rd_mode32(zval *fd)
{
    uint32_t value = 0;
    int      result = ioctl((int) Z_LVAL_P(fd), SPI_IOC_RD_MODE32, &value);

    return (result < 0) ? -1 : (zend_long) value;
}

zend_long spi_rd_max_speed_hz(zval *fd)
{
    uint32_t value = 0;
    int      result = ioctl((int) Z_LVAL_P(fd), SPI_IOC_RD_MAX_SPEED_HZ, &value);

    return (result < 0) ? -1 : (zend_long) value;
}

zend_long spi_rd_bits_per_word(zval *fd)
{
    uint8_t value = 0;
    int     result = ioctl((int) Z_LVAL_P(fd), SPI_IOC_RD_BITS_PER_WORD, &value);

    return (result < 0) ? -1 : (zend_long) value;
}

zend_long spi_rd_lsb_first(zval *fd)
{
    uint8_t value = 0;
    int     result = ioctl((int) Z_LVAL_P(fd), SPI_IOC_RD_LSB_FIRST, &value);

    return (result < 0) ? -1 : (zend_long) value;
}

void spi_read(zval *return_value, zval *fd, zval *num_bytes)
{
    size_t  num_read = (size_t) Z_LVAL_P(num_bytes);
    char   *buffer = emalloc(num_read + 1);
    ssize_t bytes_read = read((int) Z_LVAL_P(fd), buffer, num_read);

    if (bytes_read < 0) {
        efree(buffer);
        ZVAL_EMPTY_STRING(return_value);
    } else {
        buffer[bytes_read] = '\0';
        ZVAL_STRINGL(return_value, buffer, (size_t) bytes_read);
        efree(buffer);
    }
}
