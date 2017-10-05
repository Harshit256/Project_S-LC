
/*
 #include "DHT.h"                        //include the DHT library
#include <LiquidCrystal.h>              //include the LiquidCrystal library
#define DHTPin 2                        //define DHT pin
LiquidCrystal lcd(1, 3, 4, 5, 6, 7);    //define LCD pins (RS, E, D4, D5, D6, D7)
DHT dht;

void setup() {
  dht.setup(DHTPin);  
  lcd.begin(16,2);                      //initializes the LCD and specifies the dimensions
}
void loop() {
  float temp = dht.getTemperature();
  float humi = dht.getHumidity();
  lcd.setCursor(0,0);
  lcd.print("Temp: ");
  lcd.print(temp);
  lcd.print(" C");
  lcd.setCursor(0,1);
  lcd.print("Humi: ");
  lcd.print(humi);
  lcd.print(" %");
  delay(2000);
}


*/
//
//    FILE: dht_test.ino
//  AUTHOR: Rob Tillaart
// VERSION: 0.1.07
// PURPOSE: DHT Temperature & Humidity Sensor library for Arduino
//     URL: http://arduino.cc/playground/Main/DHTLib
//
// Released to the public domain
//


//set pin numbers
//const won't change
const int ledPin = 13;   //the number of the LED pin
const int ldrPin = A1;  //the number of the LDR pin

#include <dht.h>
#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

dht DHT;

//#define DHT11_PIN 2
//#define DHT21_PIN 5
#define DHT22_PIN 6

void setup()
{
  Serial.begin(115200);
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  //lcd.print("HELLO WORLD");
  pinMode(ledPin, OUTPUT);  //initialize the LED pin as an output
  pinMode(ldrPin, INPUT);   //initialize the LDR pin as an input
  Serial.println("Type \tstatus \tHumidity (%) \tTemperature (C) \tMoisture Content \tLight");

//Piezo Sensor Pin to be coonected as output.

  pinMode(10, OUTPUT);
  beep(50);
  beep(50);
  beep(50);
  delay(1000);
 }

void loop()
{
  // READ DATA
  Serial.print("DHT22 \t");
  int chk = DHT.read22(DHT22_PIN);
  switch (chk)
  {
    case DHTLIB_OK:  
    Serial.print("OK \t"); 
    break;
    case DHTLIB_ERROR_CHECKSUM: 
    Serial.print("Checksum error,\t"); 
    break;
    case DHTLIB_ERROR_TIMEOUT: 
    Serial.print("Time out error,\t"); 
    break;
    default: 
    Serial.print("Unknown error,\t"); 
    break;
  }
  
// DISPLAY DATA
  
  float temp = DHT.temperature;
  float humi = DHT.humidity;
  int sensorValue = analogRead(A0);
  Serial.print(humi);
  Serial.print(" \t\t");
  Serial.print(temp);
  Serial.print(" \t\t\t");
  Serial.print(sensorValue);
  Serial.print(" \t\t\t");
  lcd.setCursor(0,0);
  lcd.print("T-");
  lcd.print(temp);
  lcd.print("C");
  lcd.setCursor(0,1);
  lcd.print("H-");
  lcd.print(humi);
  lcd.print("% ");
  lcd.setCursor(9,0);
  lcd.print("M-");
  lcd.print(sensorValue);
  lcd.setCursor(9,1);
  lcd.print("L-");
  int ldrStatus = analogRead(ldrPin);   //read the status of the LDR value

 //check if temperature is greater than 32.2 then buzzer beeps sound.
  if(temp >  32.2)
  {
    beep(100);  //calls a function beep().
  }
   //check if the LDR status is <= 300
  //if it is, the LED is HIGH


   if (ldrStatus <=100) 
   {
    digitalWrite(ledPin, HIGH);               //turn LED on
    Serial.println("DARK , SIGNAL DANGER"); 
    lcd.print("LOW");
   }
  else
  {
    digitalWrite(ledPin, LOW);          //turn LED off
    Serial.println("LIGHT , SIGNAL FINE");
    lcd.print("HIGH");
  } 
  delay(1000);


/*    // READ DATA
  Serial.print("DHT21, \t");
  chk = DHT.read21(DHT21_PIN);
  switch (chk)
  {
    case DHTLIB_OK:  
    Serial.print("OK,\t"); 
    break;
    case DHTLIB_ERROR_CHECKSUM: 
    Serial.print("Checksum error,\t"); 
    break;
    case DHTLIB_ERROR_TIMEOUT: 
    Serial.print("Time out error,\t"); 
    break;
    default: 
    Serial.print("Unknown error,\t"); 
    break;
  }
  // DISPLAY DATA
  Serial.print(DHT.humidity, 1);
  Serial.print(",\t");
  Serial.println(DHT.temperature, 1);

  delay(1000);

  // READ DATA
  Serial.print("DHT11, \t");
  chk = DHT.read11(DHT11_PIN);
  switch (chk)
  {
    case DHTLIB_OK:  
    Serial.print("OK,\t"); 
    break;
    case DHTLIB_ERROR_CHECKSUM: 
    Serial.print("Checksum error,\t"); 
    break;
    case DHTLIB_ERROR_TIMEOUT: 
    Serial.print("Time out error,\t"); 
    break;
    default: 
    Serial.print("Unknown error,\t"); 
    break;
  }
 // DISPLAY DATA
  Serial.print(DHT.humidity,1);
  Serial.print(",\t");
  Serial.println(DHT.temperature,1);

  delay(1000);

  */
}

void beep(unsigned char delayms){
  analogWrite(10, 20);      // Almost any value can be used except 0 and 255
                           // experiment to get the best tone
  delay(delayms);          // wait for a delayms ms
  analogWrite(10, 0);       // 0 turns it off
  //delay(delayms);          // wait for a delayms ms   
}  


//
// END OF FILE
//
