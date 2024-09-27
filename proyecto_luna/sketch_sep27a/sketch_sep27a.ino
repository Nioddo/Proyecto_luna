#include <Adafruit_NeoPixel.h>

#define PIN 6 // Pin donde está conectado el neopixel
#define NUMPIXELS 5 // Número de neopixels

Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
    Serial.begin(9600);
    pixels.begin();
}

void loop() {
    if (Serial.available() >= 15) { // Espera 15 bytes (R, G, B x 5)
        for (int i = 0; i < NUMPIXELS; i++) {
            int red = Serial.read();
            int green = Serial.read();
            int blue = Serial.read();
            pixels.setPixelColor(i, pixels.Color(red, green, blue));
        }
        pixels.show();
    }
}
