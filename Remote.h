#ifndef Remote_h//if motor class is not yet defined
#define Remote_h// defne motr class
#include <Arduino.h>//include arduino default library
#define IR_RECEIVE_PIN 9
#include <IRremote.hpp>
unsigned long res;
unsigned long fres;
String button;
String RemRun(){
  
 if (IrReceiver.decode()) {
    res = IrReceiver.decodedIRData.decodedRawData; // Print "old" raw data
      IrReceiver.resume(); // Enable receiving of the next value
  }
  
  if(res!= 0 && res!=fres){

fres= res;
Serial.println(fres);
switch (fres) {       // if results.value is equal to....
      case 3125149440:               // the On/off button then...
        Serial.println("ON/OFF");  // serial print on/ off
      button = "ON/OFF";
        break;
      case 4061003520:             // the rept button
        Serial.println("REPT");  // serial print rept   
         button = "REPT";// set toggle equal to 1
        break;
      case 3860463360:           // the EQ button
        Serial.println("EQ");  // serial print EQ
        button = "EQ";
        break;
      case 3910598400:
        Serial.println("0");
        button = "0";
        break;
      case 4077715200:
        Serial.println("1");
      button = "1";
        break;
      case 3877175040:
        Serial.println("2");
        button = "2";
        break;
      case 2707357440:
        Serial.println("3");
        button = "3";
        break;
      case 4144561920:
        Serial.println("4");
        button = "4";
        break;
      case 3810328320:
        Serial.println("5");
        button = "5";
        break;
      case 2774204160:
      Serial.println("6");
        button = "6";

        break;
      case 3175284480:
        Serial.println("7");
        button = "7";
        break;
      case 2907897600:
        Serial.println("8");
          button = "8";
        break;
      case 3041591040:
        Serial.println("9");
        button = "9";
        break;
         case 3208707840:
        Serial.println("play");
        button = "PLAY";
        fres = 0;
        res = 0;
        break;   // if results.value is equal to....
      case 3108437760:             //the VOL + button then...
        Serial.println("VOL+");  // Serial print Vol +
        button = "VOL+";
         // bool r is equal to 0
        break;

      case 3141861120:            //the |<< button then...
        Serial.println("|<<");  // Serial print |<< 
        button = "|<<";                 // bool r is equal to 0
        break;

      case 3158572800:            //the >>| button then...
        Serial.println(">>|");  // Serial print >>|
        button = ">>|";                  // bool r is equal to 1
        break;

      case 3927310080:             //the VOL + button then...
        Serial.println("VOL-");  // Serial print Vol -
            button = "VOL-";           // bool r is equal to 0
        break;

      case 4127850240:
        Serial.println("^^");
        button = "^^";

        break;  
    case 4161273600:
        Serial.println("vv");
        button = "vv";
       
        break; 
}}
}
#endif