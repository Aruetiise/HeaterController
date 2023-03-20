//
// Created by Julius on 18.03.2023.
//

#include "Models/HeatingTimeslot.h"
#include <iostream>
#include <Adafruit_GFX.h>
#include <Adafruit_ST7735.h>

// Pin definitions for your setup
#define TFT_CS   24
#define TFT_RST  18
#define TFT_DC   16

// Create display object
Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_RST);

void setup() {
    // Initialize display
    tft.initR(INITR_BLACKTAB);
    // Set rotation
    tft.setRotation(1);
}

void loop() {
    // Set line color to white
    uint16_t color = ST7735_WHITE;
    // Draw line from (10,10) to (50,50)
    tft.drawLine(10, 10, 50, 50, color);
}

int main(int argc, char* argv[]) {
    std::cout << "Hello, world!" << std::endl;
    HeatingTimeslot slot;
    std::cout << "Duration " << slot.getDuration().getHour() << ":" << slot.getDuration().getMinute() << std::endl;
    setup();
    loop();
    return 0;
}