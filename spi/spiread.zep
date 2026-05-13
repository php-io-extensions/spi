namespace Spi;
class SPIRead
{
    public static function rdMode(int fd) -> int
    {
        return spi_rd_mode(fd);
    }

    public static function rdMode32(int fd) -> int
    {
        return spi_rd_mode32(fd);
    }

    public static function rdMaxSpeedHz(int fd) -> int
    {
        return spi_rd_max_speed_hz(fd);
    }

    public static function rdBitsPerWord(int fd) -> int
    {
        return spi_rd_bits_per_word(fd);
    }

    public static function rdLsbFirst(int fd) -> int
    {
        return spi_rd_lsb_first(fd);
    }

    public static function read(int fd, int num_bytes) -> string
    {
        var buffer;
        let buffer = spi_read(fd, num_bytes);

        return buffer;
    }
}
