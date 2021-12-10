//Demo File für M5Stamp Pico ESP32
/*
 * This Sketch tries to show some Text on an eink Display. It only works with an Addon Board.
 * You may add an SD Card Reader as well on the rem
 */

//Check here your Version and Pinnings
  #define TTGOT5 1 //neded to indicate the E-INK Library a different pinning
  #define E_INK_PIN_SPI_BUSY 23//19
  #define E_INK_PIN_SPI_RST  22//21
  #define E_INK_PIN_SPI_DC   21//22
  #define E_INK_PIN_SPI_CS   19
  #define E_INK_PIN_SPI_DIN  17
  #define E_INK_PIN_SPI_SCK  18 
  #define E_INK_PIN_SPI_MISO -1//n/A

#include <SPI.h>

#include <GxEPD.h> // https://github.com/ZinggJM/GxEPD

// select the display class to use, only one

//#include <GxGDE0213B1/GxGDE0213B1.h> // 2.13" b/w 
//#include <GxGDEH0213B72/GxGDEH0213B72.h>  // 2.13" b/w new panel 
#include <GxGDEH0213B73/GxGDEH0213B73.h>  // 2.13" b/w newer panel b/w, new replacement for GDE0213B1, GDEH0213B72



// FreeFonts from Adafruit_GFX
#include <Fonts/FreeMonoBold9pt7b.h>
#include <Fonts/FreeMonoBold12pt7b.h>
#include <Fonts/FreeMonoBold18pt7b.h>
#include <Fonts/FreeMonoBold24pt7b.h>

#include <GxIO/GxIO_SPI/GxIO_SPI.h>
#include <GxIO/GxIO.h>


  
  
// eink SPI pin definitions:
SPIClass einkSPI(HSPI);
GxIO_Class io(einkSPI, /*CS=5*/ E_INK_PIN_SPI_CS, /*DC=*/ E_INK_PIN_SPI_DC, /*RST=*/ E_INK_PIN_SPI_RST); // arbitrary selection of 17, 16
//GxIO_Class io(SPIg, /*CS=5*/ E_INK_PIN_SPI_CS, /*DC=*/ E_INK_PIN_SPI_DC, /*RST=*/ E_INK_PIN_SPI_RST); // arbitrary selection of 17, 16
GxEPD_Class display(io, /*RST=*/ E_INK_PIN_SPI_RST, /*BUSY=*/ E_INK_PIN_SPI_BUSY); // arbitrary selection of (16), 4



String payload = "42";
const unsigned TX_INTERVAL = 10;
#define DISP_INTERVAL 30000
int port = 1;
int sec_A;
int sec_B;
int verbunden_indicator = 0;
float temp;
float pressure;
float humidity;


void setup()
{
  Serial.begin(115200);
  Serial.println();
  Serial.println("setup");
  einkSPI.begin(E_INK_PIN_SPI_SCK,E_INK_PIN_SPI_MISO,E_INK_PIN_SPI_DIN,E_INK_PIN_SPI_CS);//reMapping of SPI Pins
  display.init(115200); // enable diagnostic output on Serial 
  SPI.end(); //released SPI PINS
  sec_A = millis(); 
   Serial.println("Display setup done");
}

void loop()
{
  drawCornerTest();
  
  if ((sec_A - sec_B) > DISP_INTERVAL) {
      //BME_Test();
      payload ="";
      sec_B = millis();
      if (port < 4){
        port++;
        showFont("FreeMonoBold12pt7b", &FreeMonoBold12pt7b);  
      }
      else{
        port = 1;
        showFont("FreeMonoBold9pt7b", &FreeMonoBold9pt7b);
      }
  }
    sec_A = millis();    
}

void showFont(const char name[], const GFXfont* f)
{
  display.fillScreen(GxEPD_WHITE);
  display.setTextColor(GxEPD_BLACK);
  display.setFont(f);
  display.setCursor(0, 0);
  display.println();
  display.println("Status:");
  display.println("Sec:");
  display.println(sec_B/1000);
  display.println("Ende");
  display.update();
  delay(5000);
}


void drawCornerTest()
{
  display.drawCornerTest();
  delay(5000);
  uint8_t rotation = display.getRotation();
  for (uint16_t r = 0; r < 4; r++)
  {
    display.setRotation(r);
    display.fillScreen(GxEPD_WHITE);
    display.fillRect(0, 0, 8, 8, GxEPD_BLACK);
    display.fillRect(display.width() - 18, 0, 16, 16, GxEPD_BLACK);
    display.fillRect(display.width() - 25, display.height() - 25, 24, 24, GxEPD_BLACK);
    display.fillRect(0, display.height() - 33, 32, 32, GxEPD_BLACK);
    display.update();
    delay(5000);
  }
  display.setRotation(rotation); // restore
}
