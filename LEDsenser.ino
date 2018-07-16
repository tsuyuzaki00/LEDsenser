#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

#define PIN            6
#define NUMPIXELS      16

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

int delayval = 5;
int analogPin = 5;
int val = 0;
int senser = 0;

void setup() {
  Serial.begin(9600);
#if defined (__AVR_ATtiny85__)
  if (F_CPU == 16000000) clock_prescale_set(clock_div_1);
#endif

  pixels.begin();
}

void loop() {
  val = analogRead(analogPin);
  senser = map(val, 50, 600, 0, 255);
  Serial.println(val); 
  Serial.println(senser);      
  
  for(int i=0;i<NUMPIXELS;i++){

    pixels.setPixelColor(i, pixels.Color(senser,senser,senser));

    pixels.show();

    delay(delayval);

  }
}
