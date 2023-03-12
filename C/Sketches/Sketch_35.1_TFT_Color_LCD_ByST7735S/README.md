## SPI TFT Color LCD ST7735S on Freenove ESP32-S3-WROOM CAM board

* YouTube demo  
[<img src="https://img.youtube.com/vi/1S3dxJ9Wgxw/maxresdefault.jpg" alt="ESP32 SPI IPS Color LCD ST7735S tutorial" title="ESP32 SPI IPS Color LCD ST7735S tutorial" width="320" height="180"> YouTube https://youtu.be/1S3dxJ9Wgxw](https://youtu.be/1S3dxJ9Wgxw)
(This movie is ESP32-WROVER)  

* Hardware  
[Freenove ESP32-S3-WROOM CAM board](https://www.amazon.co.jp/dp/B0BMQB2MG1/ref=nosim?tag=freewing-22)  
[0.96 inch TFT Display IPS LCD ST7735S 3.3V 160x80 SPI Interface](https://www.amazon.co.jp/dp/B07S728JV4/ref=nosim?tag=freewing-22)  
  
* Base Source Code  
[moononournation / Arduino_GFX](https://github.com/moononournation/Arduino_GFX)  
examples/HelloWorld/HelloWorld.ino  
  
* Wiring  
```
//  LCD - ESP32  
//  GND - GND  
//  VCC - +3.3V  
//  SCL - GPIO 3  
//  SDA - GPIO 14  
//  RES - GPIO 45  
//  DC  - GPIO 46  
//  CS  - GPIO 47  
//  BLK/LED - GPIO 2  
```
```
#define GFX_BL 2

// ESP32-S3 SPI patch
#if CONFIG_IDF_TARGET_ESP32S2 || CONFIG_IDF_TARGET_ESP32S3
  #define VSPI FSPI
#endif

Arduino_DataBus *bus = new Arduino_ESP32SPI(
  46 /* DC */, 
  47 /* CS */,
  3 /* SCK */,
  14 /* MOSI */,
  GFX_NOT_DEFINED /* MISO */,
  VSPI /* spi_num */);

Arduino_GFX *gfx = new Arduino_ST7735(
  bus,
  45 /* RST */,
  3 /* rotation */,
  true /* IPS */,
  80 /* width */, 160 /* height */,
  26 /* col offset 1 */, 1 /* row offset 1 */,
  26 /* col offset 2 */, 1 /* row offset 2 */);
```

* Breadboard Wiring  
![Sketch_35.1_TFT_Color_LCD_ByST7735S.png](https://user-images.githubusercontent.com/16265606/224536378-2cda6c75-0c9a-4ca4-8895-7d75354f0754.png)  
