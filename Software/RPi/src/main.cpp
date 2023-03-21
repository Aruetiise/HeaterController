#include "spi.h"
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <unistd.h>
#include <stdint.h>
#include <stddef.h>

// ST7735 initialization sequence
const uint8_t initSequence[] = {
        0x01, 0x80, 0x78, 0x20, 0x01, 0x05, 0x11, 0x0a, 0xb1, 0x00, 0x06, 0x3a,
        0x3a, 0x0a, 0x02, 0x0c, 0x01, 0x2a, 0x00, 0x02, 0x7f, 0x00, 0x2b, 0x00,
        0x02, 0x9f, 0x00, 0x36, 0xc8, 0x00, 0x29, 0x00, 0x2c, 0x00, 0x00
};

// Define the SPI device for the ST7735 display
SpiDevice spi("/dev/spidev0.0", SPI_MODE_0, 8, 1000000);

// Write a command to the ST7735 display
void writeCommand(uint8_t cmd)
{
    uint8_t buffer[] = { 0x00, cmd };
    spi.write(buffer, sizeof(buffer));
}

// Write data to the ST7735 display
void writeData(const uint8_t* data, size_t length)
{
    uint8_t buffer[length + 1];
    buffer[0] = 0x01;   // Data mode
    memcpy(&buffer[1], data, length);
    spi.write(buffer, sizeof(buffer));
}

int main()
{
    // Initialize the ST7735 display
    for (size_t i = 0; i < sizeof(initSequence); i++) {
        writeCommand(initSequence[i]);
        usleep(100);
    }

    // Fill the entire screen with blue color
    uint16_t buffer[80 * 160];
    memset(buffer, 0xF800, sizeof(buffer));   // Red color
    for (size_t i = 0; i < 80 * 160; i += 512) {
        writeData((const uint8_t*)&buffer[i], 512);
    }

    return 0;
}
