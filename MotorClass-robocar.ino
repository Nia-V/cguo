#include <Servo.h>
#include "Remote.h"
#include"Motorclass.h"
#include"Display4.h"
int D1 = A1;
int D2 = A5;
int D3 = A4;
int D4 = A2;
int latch = 11; 
int clock = 12; 
int data= 13; 
int servo = 90;
bool s = 0;
bool r = 0;  // Declaring Bool variable named r set to 0
bool l = 0;  // Declaring Bool variable named l set to 0
bool u = 0;  // Declaring Bool variable named u set to 0
bool d = 0;
bool ri = 0;
bool le = 0;

Servo myservo; 
Car Car;
SevSeg my7(D1, D2, D3, D4, latch, clock, data);

const byte table[10]=
{
    B11111100,  // 0
  B01100000,  // 1
  B11011010,  // 2
  B11110010,  // 3
  B01100110,  // 4
  B10110110,  // 5
  B10111110,  // 6
  B11100000,  // 7
  B11111110,  // 8
  B11100110,  // 9
};



void setup()
{
Serial.begin(9600);
  IrReceiver.begin(IR_RECEIVE_PIN, ENABLE_LED_FEEDBACK); // Start the receiver
   myservo.attach(10);
  my7.init();
}

void loop() {
  my7.display(x,y,z,a);
    myservo.write(servo);
  RemRun();

  if (button == ">>|") {  //if r is equal to 1
      Car.Right(50);  //Move right at speed 100
    }
    if (button == "VOL+") {    //if u is equal to 1
      Car.Forwards(50);  //Move forward at speed 100
    }
    if (button == "|<<") {  //if l is equal to 1
      Car.Left(50);   //Move left at speed 100
    }
    if (button == "VOL-") {     //if d is equal to 1
      Car.Backwards(50);  //Move backward at speed 100
    } 
    if(button == "^^"){
    Serial.println("ri");
    servo = 180;
     }
     if(button == "vv"){
    Serial.println("le");
    servo = 0;}
  if (button == "ON/OFF"){
      Car.STOP();
      servo = 90;}
}
