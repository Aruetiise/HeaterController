#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <fcntl.h>
#include <linux/spi/spidev.h>
#include <sys/ioctl.h>
#include <unistd.h>

int main()
{
    int spi_fd;
    const char* spi_dev = "/dev/spidev0.0";
    int spi_mode = SPI_MODE_0;
    int spi_bits_per_word = 8;
    int spi_speed_hz = 1000000;

    // Open the SPI device file
    spi_fd = open(spi_dev, O_RDWR);
    if (spi_fd < 0) {
        perror("Failed to open SPI device");
        return EXIT_FAILURE;
    }

    // Configure the SPI mode
    if (ioctl(spi_fd, SPI_IOC_WR_MODE, &spi_mode) == -1) {
        perror("Failed to set SPI mode");
        return EXIT_FAILURE;
    }

    // Configure the SPI bits per word
    if (ioctl(spi_fd, SPI_IOC_WR_BITS_PER_WORD, &spi_bits_per_word) == -1) {
        perror("Failed to set SPI bits per word");
        return EXIT_FAILURE;
    }

    // Configure the SPI speed
    if (ioctl(spi_fd, SPI_IOC_WR_MAX_SPEED_HZ, &spi_speed_hz) == -1) {
        perror("Failed to set SPI speed");
        return EXIT_FAILURE;
    }

    // Write some data to the SPI device
    unsigned char tx_buf[] = {0x01, 0x02, 0x03, 0x04};
    unsigned char rx_buf[sizeof(tx_buf)] = {0};
    struct spi_ioc_transfer spi_xfer = {
            .tx_buf = (unsigned long)tx_buf,
            .rx_buf = (unsigned long)rx_buf,
            .len = sizeof(tx_buf),
            .delay_usecs = 0,
            .speed_hz = spi_speed_hz,
            .bits_per_word = spi_bits_per_word,
    };
    if (ioctl(spi_fd, SPI_IOC_MESSAGE(1), &spi_xfer) == -1) {
        perror("Failed to write SPI data");
        return EXIT_FAILURE;
    }

    // Print the received data
    printf("Received data:");
    for (int i = 0; i < sizeof(rx_buf); i++) {
        printf(" %02X", rx_buf[i]);
    }
    printf("\n");

    // Close the SPI device file
    close(spi_fd);

    return EXIT_SUCCESS;
}
