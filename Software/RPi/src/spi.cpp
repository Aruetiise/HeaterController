#include "spi.h"
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <stdint.h>
#include <stddef.h>

SpiDevice::SpiDevice(const char* dev, uint8_t mode, uint8_t bitsPerWord, uint32_t speed) :
        m_mode(mode), m_bitsPerWord(bitsPerWord), m_speed(speed)
{
    // Open the SPI device file
    m_fd = open(dev, O_RDWR);
    if (m_fd < 0) {
        perror("Failed to open SPI device");
        exit(EXIT_FAILURE);
    }

    // Configure the SPI mode
    if (ioctl(m_fd, SPI_IOC_WR_MODE, &m_mode) == -1) {
        perror("Failed to set SPI mode");
        exit(EXIT_FAILURE);
    }

    // Configure the SPI bits per word
    if (ioctl(m_fd, SPI_IOC_WR_BITS_PER_WORD, &m_bitsPerWord) == -1) {
        perror("Failed to set SPI bits per word");
        exit(EXIT_FAILURE);
    }

    // Configure the SPI speed
    if (ioctl(m_fd, SPI_IOC_WR_MAX_SPEED_HZ, &m_speed) == -1) {
        perror("Failed to set SPI speed");
        exit(EXIT_FAILURE);
    }

    // Initialize the SPI transfer structure
    memset(&m_transfer, 0, sizeof(m_transfer));
    m_transfer.delay_usecs = 0;
    m_transfer.speed_hz = m_speed;
    m_transfer.bits_per_word = m_bitsPerWord;
}

SpiDevice::~SpiDevice()
{
    close(m_fd);
}

bool SpiDevice::write(const uint8_t* data, size_t length)
{
    m_transfer.tx_buf = (unsigned long)data;
    m_transfer.rx_buf = 0;
    m_transfer.len = length;

    if (ioctl(m_fd, SPI_IOC_MESSAGE(1), &m_transfer) == -1) {
        perror("Failed to write SPI data");
        return false;
    }

    return true;
}

bool SpiDevice::read(uint8_t* data, size_t length)
{
    m_transfer.tx_buf = 0;
    m_transfer.rx_buf = (unsigned long)data;
    m_transfer.len = length;

    if (ioctl(m_fd, SPI_IOC_MESSAGE(1), &m_transfer) == -1) {
        perror("Failed to read SPI data");
        return false;
    }

    return true;
}

bool SpiDevice::transfer(const uint8_t* txData, uint8_t* rxData, size_t length)
{
    m_transfer.tx_buf = (unsigned long)txData;
    m_transfer.rx_buf = (unsigned long)rxData;
    m_transfer.len = length;

    if (ioctl(m_fd, SPI_IOC_MESSAGE(1), &m_transfer) == -1) {
        perror("Failed to transfer SPI data");
        return false;
    }

    return true;
}
