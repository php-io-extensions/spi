<?php

namespace Spi;

class SPIWrite
{


    /**
     * @param int $fd
     * @param int $value
     * @return int
     */
    public static function wrMode(int $fd, int $value): int
    {
    }

    /**
     * @param int $fd
     * @param int $value
     * @return int
     */
    public static function wrMode32(int $fd, int $value): int
    {
    }

    /**
     * @param int $fd
     * @param int $value
     * @return int
     */
    public static function wrMaxSpeedHz(int $fd, int $value): int
    {
    }

    /**
     * @param int $fd
     * @param int $value
     * @return int
     */
    public static function wrBitsPerWord(int $fd, int $value): int
    {
    }

    /**
     * @param int $fd
     * @param int $value
     * @return int
     */
    public static function wrLsbFirst(int $fd, int $value): int
    {
    }

    /**
     * Half-duplex write - Uses standard write() syscall
     * CS toggles after this operation
     * Returns number of bytes written
     *
     * @param int $fd
     * @param string $payload
     * @return int
     */
    public static function write(int $fd, string $payload): int
    {
    }

    /**
     * @param int $fd
     * @param string $tx
     * @return array
     */
    public static function message(int $fd, string $tx): array
    {
    }
}
