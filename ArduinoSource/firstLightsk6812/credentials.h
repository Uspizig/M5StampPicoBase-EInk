#define mySSID "wallyweb"
#define myPASSWORD "fs4burgberg"
#define thingspeak_server "api.thingspeak.com"
#define thingspeak_api_key "xxxxxxxxxxxxxx"


#define rotary1

#ifdef rotary1
    //ESP32 PICO Base Board
    //#define mqtt_client_on
	  #define ANZAHL_LEDS 1 
    #define RGB_LED_DATA_PIN 0
    #define WS2812_LEDS
    #define RXD2 35
    #define TXD2 33
    
    #define ROTARY_ENCODER_A_PIN 26
    #define ROTARY_ENCODER_B_PIN 12
    #define ROTARY_ENCODER_BUTTON_PIN 21
    #define LED_PIN 22
    
    #define BUTTON_DISABLED 0
    #define BUTTON_ENABLED 1
    #define timeSeconds 500
    #define updaterate_leds 2000
    #define max_counter 255
    #define min_counter 0
#endif

#ifdef rotary2
  #define mqtt_client_on
  #define ANZAHL_LEDS 1
  #define RGB_LED_DATA_PIN 25
  #define WS2812_LEDS
  #define RXD2 35
  #define TXD2 33
 
  #define ROTARY_ENCODER_A_PIN 26
  #define ROTARY_ENCODER_B_PIN 12
  #define ROTARY_ENCODER_BUTTON_PIN 21
  #define LED_PIN 22
  
  #define BUTTON_DISABLED 0
  #define BUTTON_ENABLED 1
  #define timeSeconds 500
  #define updaterate_leds 2000
  #define max_counter 255
  #define min_counter 0
#endif

#ifdef rotary3
//TTGO Base Board
  #define mqtt_client_on
  #define ANZAHL_LEDS 8
  #define RGB_LED_DATA_PIN 2
  #define SK6812_LEDS
  //#define WS2812_LEDS
  #define RXD2 35
  #define TXD2 33
 
  #define ROTARY_ENCODER_A_PIN 26
  #define ROTARY_ENCODER_B_PIN 12
  #define ROTARY_ENCODER_BUTTON_PIN 21
  #define LED_PIN 22
  
  #define BUTTON_DISABLED 0
  #define BUTTON_ENABLED 1
  #define timeSeconds 500
  #define updaterate_leds 2000
  #define max_counter 255
  #define min_counter 0
#endif

#ifdef rotary4
  //schwarzer rotary encoder
  #define mqtt_client_on
  #define ANZAHL_LEDS 4
  #define RGB_LED_DATA_PIN 15
  #define WS2812_LEDS
  #define RXD2 35
  #define TXD2 33
 
  #define ROTARY_ENCODER_A_PIN 26
  #define ROTARY_ENCODER_B_PIN 12
  #define ROTARY_ENCODER_BUTTON_PIN 21
  #define LED_PIN 22
  
  #define BUTTON_DISABLED 0
  #define BUTTON_ENABLED 1
  #define timeSeconds 500
  #define updaterate_leds 2000
  #define max_counter 255
  #define min_counter 0
#endif

#ifdef rotary5
    // ESP32 Base mit Lora
  //#define mqtt_client_on
  #define ANZAHL_LEDS 1
  #define RGB_LED_DATA_PIN 25
  #define WS2812_LEDS
  //#define SK6812_LEDS
  #define RXD2 35
  #define TXD2 33
 
  #define ROTARY_ENCODER_A_PIN 26
  #define ROTARY_ENCODER_B_PIN 12
  #define ROTARY_ENCODER_BUTTON_PIN 21
  #define LED_PIN 22
  
  #define BUTTON_DISABLED 0
  #define BUTTON_ENABLED 1
  #define timeSeconds 500
  #define updaterate_leds 2000
  #define max_counter 255
  #define min_counter 0
#endif

#ifdef rotary6
    // ESP32 Schreibtischlampe mit Lora
  //#define mqtt_client_on
  //#define ANZAHL_LEDS 36
  #define ANZAHL_LEDS 4//36
  #define RGB_LED_DATA_PIN 25
  
  #define OBEN_LED_DATA_PIN 26
  #define OBEN_LEDS 1
  
  //#define WS2812_LEDS
  #define SK6812_LEDS
  #define RXD2 35
  #define TXD2 33
 
  #define ROTARY_ENCODER_A_PIN 35
  #define ROTARY_ENCODER_B_PIN 32
  #define ROTARY_ENCODER_BUTTON_PIN 34
  #define LED_PIN 22
  
  #define BUTTON_DISABLED 0
  #define BUTTON_ENABLED 1
  #define timeSeconds 500
  #define updaterate_leds 2000
  #define max_counter 255
  #define min_counter 0
#endif
