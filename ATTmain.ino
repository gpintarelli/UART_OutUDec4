// ATtiny85 datalogger
// GBPintarelli
// 07/08/2016
// Last info: Funciona muito bem!

#include<SoftwareSerial.h>

int value=0;
int pinadc = 3; // HW pin 2 (or analog input 1)
int pinleddebug = 4; // HW pin 7
const byte rxpin = 0;
const byte txpin = 1;
SoftwareSerial BTSerial(rxpin,txpin); // Rx = 0 e Tx = 1

void setup() {
  BTSerial.begin(9600);
  delay(2000);
  BTSerial.println("HI!");
/*
Bluetooth.println("AT"); // just a check
delay(100);
Bluetooth.print("AT+NAMEModulo");
delay(100);
Bluetooth.println("AT+ROLE0"); // st up as Master
delay(100);
Bluetooth.println("AT+BAUD4");
delay(100);
Bluetooth.println("AT+PIN101010");
delay(100);
Bluetooth.println("AT+RESET"); // reseta para fazer valer as novas configs*/
}

void loop() {

  value=analogRead(pinadc);
  //value = 5*value/1023;
  BTSerial.print(value,DEC);
  BTSerial.write(";");
  digitalWrite(pinleddebug, HIGH);    // sets the LED on
  delay(500);                         // waits for a second
  digitalWrite(pinleddebug, LOW);     // sets the LED off
  delay(500);                         // waits for a second
}
