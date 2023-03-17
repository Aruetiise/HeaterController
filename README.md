# HeaterController
Heater controller with RPi 

<b>Hardware</b>
<ul>
  <li><a href="https://cdn.shopify.com/s/files/1/1509/1638/files/1_77_Zoll_SPI_TFT_Display_Datenblatt_AZ-Delivery_Vertriebs_GmbH_0eab71a3-f0c9-42af-8089-d8e6f689e9dc.pdf?v=1606166813" rel="noopener" target="_blank" >1,77 Zoll 128x160 Pixel SPI TFT-Display</a></li>
  <li><a href="https://www.amazon.de/Treibermodul-Dual-Hochleistungs-Switching-Einstellung-Elektronische/dp/B0BBVCD85Q/" rel="noopener" target="_blank" >MOSFET Treibermodul 5V-36V 15A</a></li>
</ul>

<b>Initialization and Configuration Methods</b>

Adafruit_ST7735(T_CS cs, T_DC dc, T_RST rst) - Constructor for initializing the display with the specified chip select (CS), data/command (DC), and reset (RST) pins.
```cpp
void initR(INITR_t option); // Initializes the display with the specified INITR_t option (ST7735_INITR_BLACKTAB, ST7735_INITR_GREENTAB, or ST7735_INITR_REDTAB).
void setRotation(uint8_t m); // Sets the rotation of the display to the specified value (0, 1, 2, or 3).
void invertDisplay(boolean i); // Inverts the display if the argument is true.
```

<b>Drawing and Pixel Manipulation Methods</b>
```cpp
void drawPixel(int16_t x, int16_t y, uint16_t color); // Draws a single pixel at the specified x and y coordinates with the specified color.
void drawFastVLine(int16_t x, int16_t y, int16_t h, uint16_t color); // Draws a vertical line with the specified height and color starting at the specified x and y coordinates.
void drawFastHLine(int16_t x, int16_t y, int16_t w, uint16_t color); // Draws a horizontal line with the specified width and color starting at the specified x and y coordinates.
void fillRect(int16_t x, int16_t y, int16_t w, int16_t h, uint16_t color); // Fills a rectangle with the specified width, height, and color starting at the specified x and y coordinates.
void fillScreen(uint16_t color); // Fills the entire screen with the specified color.
void drawBitmap(int16_t x, int16_t y, const uint8_t *bitmap, int16_t w, int16_t h, uint16_t color); // Draws a bitmap with the specified width, height, and color at the specified x and y coordinates.
```
<b>Text and Font Methods</b>
```cpp
void setCursor(int16_t x, int16_t y); // Sets the cursor position for text output to the specified x and y coordinates.
void setTextColor(uint16_t color); // Sets the text color to the specified color.
void setTextColor(uint16_t fgcolor, uint16_t bgcolor); // Sets the text color and background color to the specified colors.
void setTextSize(uint8_t size); // Sets the text size to the specified value.
void setTextWrap(boolean wrap); // Enables or disables text wrapping.
void print(const char *str); // Prints a null-terminated string to the screen at the current cursor position.
void print(const __FlashStringHelper *str); // Prints a string from flash memory to the screen at the current cursor position.
void print(char c); // Prints a single character to the screen at the current cursor position.
```
<b>Low-Level SPI Methods</b>
```cpp
void writecommand(uint8_t c); // Sends a command byte to the display.
void writedata(uint8_t d); // Sends a data byte to the display.
void writedata16(uint16_t d); //- Sends a 16-bit data word to the display.
void writedata16(uint16_t *d, uint32_t num); // Sends an array of 16-bit data words to the display.
```
Note that this is not an exhaustive list of every method
