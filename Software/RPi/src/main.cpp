//
// Created by Julius on 18.03.2023.
//

#include "Models/HeatingTimeslot.h"
#include <iostream>
#include <wiringPi.h>
#include <wiringPiSPI.h>

int main(int argc, char* argv[]) {
    std::cout << "Hello, world!" << std::endl;
    HeatingTimeslot slot;
    std::cout << "Duration " << slot.getDuration().getHour() << ":" << slot.getDuration().getMinute() << std::endl;

    wiringPiSPISetup(0, 1000000);  // Configure the SPI interface with a clock speed of 1MHz

    unsigned char data[] = {0x01, 0x02, 0x03, 0x04};
    wiringPiSPIDataRW(0, data, sizeof(data));  // Write the data to the device
    return 0;
}