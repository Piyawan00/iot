// DHT22 and LCD  by Nitigan


/* You must include element for dht22
*/
#include "DHT.h"
#define DHTPIN 2
#define DHTTYPE DHT22
DHT dht(DHTPIN, DHTTYPE);

#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);  // set the LCD address to 0x27 for a 16 chars and 2 line display //ค่าจอiedแสดงผล

// Define 16x2 LCD
int screenWidth = 16;
int screenHeight = 2;

// To move ONLY one line needs to move one character at a time

// Define two line

String line1 = " Temp & Humid "; // stationary " LCD ep3: "
String line2 = " Data is "; // scroll this line " This is a one line scrolling tutorial! "

int stringStart, stringEnd = 0;
int scrollCursor = screenWidth; 

void setup() {

  // use dht begin
  dht.begin();
  Serial.begin(9600);
  Serial.println(F("DHTxx test!"));

  lcd.init();
  lcd.backlight();
  lcd.begin(screenWidth, screenHeight);
}

void loop() {
  float h = dht.readHumidity();
  // Read temperature as Celsius (the default)
  float t = dht.readTemperature();
  // Read temperature as Fahrenheit (isFahrenheit = true)
  float f = dht.readTemperature(true);

  // Check if any reads failed and exit early (to try again).
  if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }

  // Compute heat index in Fahrenheit (the default)
  float hif = dht.computeHeatIndex(f, h);
  // Compute heat index in Celsius (isFahreheit = false)
  float hic = dht.computeHeatIndex(t, h, false);
  lcd.setCursor(0, 0); // Seting the cursor on first row 
  lcd.print(F("Temp: "));
  lcd.print(t);
  lcd.setCursor( 0 , 1);
  lcd.print(F("Humidity: "));
  lcd.print(h); // Seting the cursor on first row and (scrolling from left end to right)
  lcd.print(line2); // To print line1 first character "T"

  delay(1000);
  
  lcd.clear(); // clear message

  Serial.print(F("Humidity: "));
  Serial.print(h);
  Serial.print(F("Temp: "));
  Serial.print(t);
  Serial.print(F("°C "));
  Serial.print(f);
  Serial.print(F("°F  Heat index: "));
  Serial.print(hic);
  Serial.print(F("°C "));
  Serial.print(hif);
  Serial.println(F("°F"));

  /*
      get data from dht22




  */

  /*

    show data from dht with LCD
  
  
  */

 
}