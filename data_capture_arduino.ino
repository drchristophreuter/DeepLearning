// Dr. Christoph Reuter 28.10.2023
// Die Datenerfassung erfolgt über einen Arduino Mega mit Adafruit AS7262 6-Channel Visible Light / Color Sensor Breakout
// Die Sensordaten werden über die serielle Schnittstelle an den Linuxserver Übertragen und dort weiterverarbeitet
#include <Wire.h>
#include "Adafruit_AS726x.h"
#include <Adafruit_GFX.h> // Core graphics library
#include <Adafruit_ST7735.h>  // Hardware-specific library
#include <SPI.h>
// For the breakout, you can use any 2 or 3 pins
// These pins will also work for the 1.8" TFT shield
#define TFT_CS 10
#define TFT_RST 9 // you can also connect this to the Arduino reset
// in which case, set this #define pin to -1!
#define TFT_DC 8
#define SENSOR_MAX 5000
#define BLACK 0x0000
#define GRAY 0x8410
#define WHITE 0xFFFF
#define RED 0xF800
#define ORANGE 0xFA60
#define YELLOW 0xFFE0
#define LIME 0x07FF
#define GREEN 0x07E0
#define CYAN 0x07FF
#define AQUA 0x04FF
#define BLUE 0x001F
#define MAGENTA 0xF81F
#define PINK 0xF8FF
