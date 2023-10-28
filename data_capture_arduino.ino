// Dr. Christoph Reuter 28.10.2023
// Die Datenerfassung erfolgt über einen Arduino Mega mit Adafruit AS7262 6-Channel Visible Light / Color Sensor Breakout
// Die Sensordaten werden über die serielle Schnittstelle an den Linuxserver Übertragen und dort weiterverarbeitet
#include <Wire.h>
#include "Adafruit_AS726x.h"
#include <Adafruit_GFX.h> // Core graphics library
#include <Adafruit_ST7735.h>  // Hardware-specific library
#include <SPI.h>
