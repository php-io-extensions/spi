namespace Spi;

class SPIWrite
{
    public static function wrMode(int fd, int value) -> int
    {
        return spi_wr_mode(fd, value);
    }

    public static function wrMode32(int fd, int value) -> int
    {
        return spi_wr_mode32(fd, value);
    }

    public static function wrMaxSpeedHz(int fd, int value) -> int
    {
        return spi_wr_max_speed_hz(fd, value);
    }

    public static function wrBitsPerWord(int fd, int value) -> int
    {
        return spi_wr_bits_per_word(fd, value);
    }

    public static function wrLsbFirst(int fd, int value) -> int
    {
        return spi_wr_lsb_first(fd, value);
    }

    /**
     * Half-duplex write - Uses standard write() syscall
     * CS toggles after this operation
     * Returns number of bytes written
     */
    public static function write(int fd, var payload) -> int
    {
        string data = payload;
        return spi_write(fd, data);
    }

    public static function message(int fd, var tx) -> array
    {
        string payload = tx;
        var result;
        let result = spi_message(fd, payload);
        return result;
    }
}
