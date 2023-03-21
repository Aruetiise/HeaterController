#ifndef SPI_H
#define SPI_H

#include <linux/spi/spidev.h>

class SpiDevice {
public:
    SpiDevice(const char* dev, uint8_t mode = SPI_MODE_0, uint8_t bitsPerWord = 8, uint32_t speed = 1000000);
    ~SpiDevice();

    bool write(const uint8_t* data, size_t length);
    bool read(uint8_t* data, size_t length);
    bool transfer(const uint8_t* txData, uint8_t* rxData, size_t length);

private:
    int m_fd;
    uint8_t m_mode;
    uint8_t m_bitsPerWord;
    uint32_t m_speed;
    struct spi_ioc_transfer m_transfer;
};

#endif // SPI_H
