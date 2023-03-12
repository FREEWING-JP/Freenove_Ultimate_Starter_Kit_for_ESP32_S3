// moononournation / Arduino_GFX
// https://github.com/moononournation/Arduino_GFX/blob/master/examples/HelloWorld/HelloWorld.ino

/*******************************************************************************
 * Start of Arduino_GFX setting
 * 
 * Arduino_GFX try to find the settings depends on selected board in Arduino IDE
 * Or you can define the display dev kit not in the board list
 * Defalult pin list for non display dev kit:
 * Arduino Nano, Micro and more: CS:  9, DC:  8, RST:  7, BL:  6, SCK: 13, MOSI: 11, MISO: 12
 * ESP32 various dev board     : CS:  5, DC: 27, RST: 33, BL: 22, SCK: 18, MOSI: 23, MISO: nil
 * ESP32-C3 various dev board  : CS:  7, DC:  2, RST:  1, BL:  3, SCK:  4, MOSI:  6, MISO: nil
 * ESP32-S2 various dev board  : CS: 34, DC: 38, RST: 33, BL: 21, SCK: 36, MOSI: 35, MISO: nil
 * ESP32-S3 various dev board  : CS: 40, DC: 41, RST: 42, BL: 48, SCK: 36, MOSI: 35, MISO: nil
 * ESP8266 various dev board   : CS: 15, DC:  4, RST:  2, BL:  5, SCK: 14, MOSI: 13, MISO: 12
 * Raspberry Pi Pico dev board : CS: 17, DC: 27, RST: 26, BL: 28, SCK: 18, MOSI: 19, MISO: 16
 * RTL8720 BW16 old patch core : CS: 18, DC: 17, RST:  2, BL: 23, SCK: 19, MOSI: 21, MISO: 20
 * RTL8720_BW16 Official core  : CS:  9, DC:  8, RST:  6, BL:  3, SCK: 10, MOSI: 12, MISO: 11
 * RTL8722 dev board           : CS: 18, DC: 17, RST: 22, BL: 23, SCK: 13, MOSI: 11, MISO: 12
 * RTL8722_mini dev board      : CS: 12, DC: 14, RST: 15, BL: 13, SCK: 11, MOSI:  9, MISO: 10
 * Seeeduino XIAO dev board    : CS:  3, DC:  2, RST:  1, BL:  0, SCK:  8, MOSI: 10, MISO:  9
 * Teensy 4.1 dev board        : CS: 39, DC: 41, RST: 40, BL: 22, SCK: 13, MOSI: 11, MISO: 12
 ******************************************************************************/
#include <Arduino_GFX_Library.h>

// Freenove ESP32-WROVER CAM board ON BOARD LED GPIO 2
#define GFX_BL 2 // default backlight pin, you may replace DF_GFX_BL to actual backlight pin

// Freenove ESP32-S3-WROOM CAM board
// https://www.amazon.co.jp/dp/B0BMQB2MG1/ref=nosim?tag=freewing-22
// 0.96 inch TFT Display IPS LCD ST7735S 3.3V 160x80 SPI Interface
// https://www.amazon.co.jp/dp/B07S728JV4/ref=nosim?tag=freewing-22
//  LCD - ESP32
//  GND - GND
//  VCC - +3.3V
//  SCL - GPIO 3
//  SDA - GPIO 14
//  RES - GPIO 45
//  DC  - GPIO 46
//  CS  - GPIO 47
//  BLK/LED - GPIO 2

// ESP32-S3 SPI patch
// error: 'VSPI' was not declared in this scope
#if CONFIG_IDF_TARGET_ESP32S2 || CONFIG_IDF_TARGET_ESP32S3
  #define VSPI FSPI
#endif

/* More dev device declaration: https://github.com/moononournation/Arduino_GFX/wiki/Dev-Device-Declaration */
#if defined(DISPLAY_DEV_KIT)
Arduino_GFX *gfx = create_default_Arduino_GFX();
#else /* !defined(DISPLAY_DEV_KIT) */

/* More data bus class: https://github.com/moononournation/Arduino_GFX/wiki/Data-Bus-Class */
// Arduino_DataBus *bus = create_default_Arduino_DataBus();
// ESP32 - SPI
// https://github.com/moononournation/Arduino_GFX/wiki/Data-Bus-Class#esp32
Arduino_DataBus *bus = new Arduino_ESP32SPI(
  46 /* DC */, 
  47 /* CS */,
  3 /* SCK */,
  14 /* MOSI */,
  GFX_NOT_DEFINED /* MISO */,
  VSPI /* spi_num */);

/* More display class: https://github.com/moononournation/Arduino_GFX/wiki/Display-Class */
// Arduino_GFX *gfx = new Arduino_ILI9341(bus, DF_GFX_RST, 0 /* rotation */, false /* IPS */);
// ST7735 LCD - 0.96" IPS LCD 80x160
// https://github.com/moononournation/Arduino_GFX/wiki/Display-Class#st7735-lcd
Arduino_GFX *gfx = new Arduino_ST7735(
  bus,
  45 /* RST */,
  3 /* rotation */,
  true /* IPS */,
  80 /* width */, 160 /* height */,
  26 /* col offset 1 */, 1 /* row offset 1 */,
  26 /* col offset 2 */, 1 /* row offset 2 */);

#endif /* !defined(DISPLAY_DEV_KIT) */
/*******************************************************************************
 * End of Arduino_GFX setting
 ******************************************************************************/

void setup(void)
{
    gfx->begin();
    delay(1000); // 1 seconds
    gfx->fillScreen(RED);
    delay(1000); // 1 seconds
    gfx->fillScreen(GREEN);
    delay(1000); // 1 seconds
    gfx->fillScreen(BLUE);
    delay(1000); // 1 seconds
    gfx->fillScreen(WHITE);
    delay(1000); // 1 seconds

    gfx->fillScreen(BLACK);
    delay(1000); // 1 seconds

#ifdef GFX_BL
    pinMode(GFX_BL, OUTPUT);
    digitalWrite(GFX_BL, HIGH);
#endif

    gfx->setCursor(10, 10);
    gfx->setTextColor(RED);
    gfx->println("Hello World!");

    delay(5000); // 5 seconds
}

void loop()
{
    gfx->setCursor(random(gfx->width()), random(gfx->height()));
    gfx->setTextColor(random(0xffff), random(0xffff));
    gfx->setTextSize(random(6) /* x scale */, random(6) /* y scale */, random(2) /* pixel_margin */);
    gfx->println("Hello World!");

    delay(200); // 0.2 second
}
