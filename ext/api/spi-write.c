#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_ext.h"
#include "spi-write.h"

#include <linux/spi/spidev.h>
#include <stdint.h>
#include <string.h>
#include <sys/ioctl.h>
#include <unistd.h>

zend_long spi_wr_mode(zval *fd, zval *value)
{
    uint8_t mode = (uint8_t) Z_LVAL_P(value);
    int     result = ioctl((int) Z_LVAL_P(fd), SPI_IOC_WR_MODE, &mode);

    return (zend_long) result;
}

zend_long spi_wr_mode32(zval *fd, zval *value)
{
    uint32_t mode = (uint32_t) Z_LVAL_P(value);
    int      result = ioctl((int) Z_LVAL_P(fd), SPI_IOC_WR_MODE32, &mode);

    return (zend_long) result;
}

zend_long spi_wr_max_speed_hz(zval *fd, zval *value)
{
    uint32_t speed = (uint32_t) Z_LVAL_P(value);
    int      result = ioctl((int) Z_LVAL_P(fd), SPI_IOC_WR_MAX_SPEED_HZ, &speed);

    return (zend_long) result;
}

zend_long spi_wr_bits_per_word(zval *fd, zval *value)
{
    uint8_t bits = (uint8_t) Z_LVAL_P(value);
    int     result = ioctl((int) Z_LVAL_P(fd), SPI_IOC_WR_BITS_PER_WORD, &bits);

    return (zend_long) result;
}

zend_long spi_wr_lsb_first(zval *fd, zval *value)
{
    uint8_t lsb_first = (uint8_t) Z_LVAL_P(value);
    int     result = ioctl((int) Z_LVAL_P(fd), SPI_IOC_WR_LSB_FIRST, &lsb_first);

    return (zend_long) result;
}

zend_long spi_write(zval *fd, zval *payload)
{
    return (zend_long) write(
        (int)            Z_LVAL_P(fd),
        (const uint8_t *) Z_STRVAL_P(payload),
        (size_t)         Z_STRLEN_P(payload)
    );
}

void spi_message(zval *return_value, zval *fd, zval *tx)
{
    size_t tx_len = (size_t) Z_STRLEN_P(tx);
    char  *rx = emalloc(tx_len + 1);
    struct spi_ioc_transfer transfer;
    int result;

    memset(rx, 0, tx_len + 1);
    memset(&transfer, 0, sizeof(struct spi_ioc_transfer));

    transfer.tx_buf = (unsigned long) Z_STRVAL_P(tx);
    transfer.rx_buf = (unsigned long) rx;
    transfer.len = (uint32_t) tx_len;

    result = ioctl((int) Z_LVAL_P(fd), SPI_IOC_MESSAGE(1), &transfer);

    array_init(return_value);
    add_assoc_long(return_value, "success", (zend_long) result);

    if (result >= 0) {
        add_assoc_stringl(return_value, "data", rx, tx_len);
    } else {
        add_assoc_string(return_value, "data", "");
    }

    efree(rx);
}
