# SPI

[![PHP][badge-php]][php]
[![Zephir][badge-zephir]][zephir-install]
[![Platform][badge-platform]][linux]

PHP-controllable Linux SPI extension built with Zephir.

The SPI extension allows PHP to communicate with SPI devices on Linux by configuring a `spidev` file descriptor and performing read, write, and full-duplex transfer operations. Useful for sensors, DACs, ADCs, displays, EEPROMs, and other peripherals connected over SPI.

```shell
git clone https://github.com/DeptOfScrapyardRobotics/SPI
cd SPI
bash install.sh
```

## Requirements

- PHP 8.3+ with development headers (`php-dev` / `php-devel`)
- [Zephir][zephir-install] 0.19+
- [FD extension][fd-repo] — provides raw integer file descriptors via `Fd\FD::open()`
- Linux with SPI userspace support (`/dev/spidevB.C`)
- `spidev` kernel support enabled

## Installation

Install Zephir if you haven't already:

```shell
composer global require phalcon/zephir
```

Install the [FD extension][fd-repo] first. SPI methods in this extension expect a raw integer file descriptor, which PHP's normal stream APIs do not provide:

```shell
git clone https://github.com/DeptOfScrapyardRobotics/FD
cd FD && bash install.sh
```

Make sure the `spidev` device exists on your system:

```shell
ls /dev/spidev*
```

Then clone and build this extension:

```shell
git clone https://github.com/DeptOfScrapyardRobotics/SPI
cd SPI
bash install.sh
```

`install.sh` handles the full workflow: clean → build → copy `.so` → write `30-spi.ini` into detected `conf.d` directories → verify `php -m` → reload php-fpm if present.

To use a specific Zephir binary:

```shell
ZEPHIR_BIN=/path/to/zephir bash install.sh
```

## API

All methods are static. File descriptors are plain integers. Use the [FD extension][fd-repo] to open and close them.

```php
use Fd\FD;
use Spi\SPIRead;
use Spi\SPIWrite;

$fd = FD::open('/dev/spidev0.0', 2); // O_RDWR = 2
// ... use $fd with SPIRead and SPIWrite methods ...
FD::close($fd);
```

### `Spi\SPIWrite`

Configuration setters and transfer methods for an SPI file descriptor.

---

#### `wrMode(int $fd, int $value): int`

Writes the 8-bit SPI mode flags using `SPI_IOC_WR_MODE`. Returns `0` on success, `-1` on failure.

---

#### `wrMode32(int $fd, int $value): int`

Writes the 32-bit SPI mode flags using `SPI_IOC_WR_MODE32`. Returns `0` on success, `-1` on failure.

---

#### `wrMaxSpeedHz(int $fd, int $value): int`

Sets the SPI clock speed in Hz. Returns `0` on success, `-1` on failure.

---

#### `wrBitsPerWord(int $fd, int $value): int`

Sets bits per word, commonly `8`. Returns `0` on success, `-1` on failure.

---

#### `wrLsbFirst(int $fd, int $value): int`

Sets bit order. Use `0` for MSB-first and `1` for LSB-first. Returns `0` on success, `-1` on failure.

---

#### `write(int $fd, string $payload): int`

Performs a half-duplex write using the standard `write(2)` syscall. Returns the number of bytes written, or `-1` on failure.

---

#### `message(int $fd, string $tx): array`

Performs a single full-duplex SPI transfer using `SPI_IOC_MESSAGE(1)`.

Returns an associative array:

| Key | Type | Description |
|-----|------|-------------|
| `success` | `int` | `ioctl()` return value; negative means failure |
| `data` | `string` | Bytes received during the transfer |

The number of bytes received matches the length of `$tx`. If your device needs clock pulses to return data, include dummy bytes in `$tx`.

---

### `Spi\SPIRead`

Configuration getters and half-duplex read operations for an SPI file descriptor.

---

#### `rdMode(int $fd): int`

Reads the current 8-bit SPI mode via `SPI_IOC_RD_MODE`. Returns the mode value, or `-1` on failure.

---

#### `rdMode32(int $fd): int`

Reads the current 32-bit SPI mode via `SPI_IOC_RD_MODE32`. Returns the mode value, or `-1` on failure.

---

#### `rdMaxSpeedHz(int $fd): int`

Reads the configured SPI clock speed in Hz. Returns the value, or `-1` on failure.

---

#### `rdBitsPerWord(int $fd): int`

Reads the configured bits-per-word value. Returns the value, or `-1` on failure.

---

#### `rdLsbFirst(int $fd): int`

Reads the configured bit order. Returns `0` for MSB-first, `1` for LSB-first, or `-1` on failure.

---

#### `read(int $fd, int $num_bytes): string`

Performs a half-duplex read using the standard `read(2)` syscall. Returns the bytes read as a binary string, or `""` on failure.

## Usage

```php
use Fd\FD;
use Spi\SPIRead;
use Spi\SPIWrite;
```

Common mode values:

| Mode | Value |
|------|-------|
| `SPI_MODE_0` | `0` |
| `SPI_MODE_1` | `1` |
| `SPI_MODE_2` | `2` |
| `SPI_MODE_3` | `3` |

---

### Configure a device

```php
$fd = FD::open('/dev/spidev0.0', 2); // O_RDWR

SPIWrite::wrMode($fd, 0);            // SPI mode 0
SPIWrite::wrMaxSpeedHz($fd, 500000); // 500 kHz
SPIWrite::wrBitsPerWord($fd, 8);
SPIWrite::wrLsbFirst($fd, 0);        // MSB first

echo "Mode: " . SPIRead::rdMode($fd) . PHP_EOL;
echo "Speed: " . SPIRead::rdMaxSpeedHz($fd) . PHP_EOL;

FD::close($fd);
```

---

### Half-duplex write

```php
$fd = FD::open('/dev/spidev0.0', 2);

SPIWrite::wrMode($fd, 0);
SPIWrite::wrMaxSpeedHz($fd, 1000000);
SPIWrite::wrBitsPerWord($fd, 8);

$written = SPIWrite::write($fd, "\x9A\xBC\xDE");
echo "Bytes written: {$written}\n";

FD::close($fd);
```

---

### Half-duplex read

```php
$fd = FD::open('/dev/spidev0.0', 2);

SPIWrite::wrMode($fd, 0);
SPIWrite::wrMaxSpeedHz($fd, 1000000);
SPIWrite::wrBitsPerWord($fd, 8);

$data = SPIRead::read($fd, 4);
echo bin2hex($data) . PHP_EOL;

FD::close($fd);
```

---

### Full-duplex transfer

```php
$fd = FD::open('/dev/spidev0.0', 2);

SPIWrite::wrMode($fd, 0);
SPIWrite::wrMaxSpeedHz($fd, 1000000);
SPIWrite::wrBitsPerWord($fd, 8);

$result = SPIWrite::message($fd, "\x9F\x00\x00\x00");

if ($result['success'] >= 0) {
    echo "RX: " . bin2hex($result['data']) . PHP_EOL;
}

FD::close($fd);
```

---

### Query current configuration

```php
$fd = FD::open('/dev/spidev0.0', 2);

echo "Mode: " . SPIRead::rdMode($fd) . PHP_EOL;
echo "Mode32: " . SPIRead::rdMode32($fd) . PHP_EOL;
echo "Max speed: " . SPIRead::rdMaxSpeedHz($fd) . PHP_EOL;
echo "Bits/word: " . SPIRead::rdBitsPerWord($fd) . PHP_EOL;
echo "LSB first: " . SPIRead::rdLsbFirst($fd) . PHP_EOL;

FD::close($fd);
```

## Notes

- This extension operates on Linux `spidev` device files such as `/dev/spidev0.0`.
- `message()` performs a single transfer whose RX length matches the TX length.
- Some SPI devices do not support plain `read()` and instead require command bytes or dummy bytes through `message()`.
- This extension does not open device files itself; use the [FD extension][fd-repo] for that.

## License

Copyright © Project Saturn Studios, LLC. All rights reserved.

[badge-php]: https://img.shields.io/badge/php-%3E%3D8.3-blue
[badge-zephir]: https://img.shields.io/badge/zephir-0.19%2B-orange
[badge-platform]: https://img.shields.io/badge/platform-linux-lightgrey
[php]: https://www.php.net
[zephir-install]: https://docs.zephir-lang.com/latest/en/installation
[linux]: https://www.kernel.org
[fd-repo]: https://github.com/DeptOfScrapyardRobotics/FD
