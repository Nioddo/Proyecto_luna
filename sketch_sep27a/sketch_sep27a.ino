#include <Adafruit_NeoPixel.h>
 
#define PIN 11 // Pin donde está conectado el neopixel
#define NUMPIXELS 5 // Número de neopixels
 
Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
 
void setup() {
    Serial.begin(9600);
    pixels.begin();
}
 
void loop() {
    if (Serial.available()) {
        String command = Serial.readStringUntil('\n');
        int ledIndex = command.substring(0, command.indexOf(':')).toInt();
        String rgbValues = command.substring(command.indexOf(':') + 1);
        int r = rgbValues.substring(0, rgbValues.indexOf(',')).toInt();
        int g = rgbValues.substring(rgbValues.indexOf(',') + 1, rgbValues.lastIndexOf(',')).toInt();
        int b = rgbValues.substring(rgbValues.lastIndexOf(',') + 1).toInt();
        
        // Establecer el color del LED correspondiente
        pixels.setPixelColor(ledIndex, pixels.Color(r, g, b));
        pixels.show();
    }
}
 
