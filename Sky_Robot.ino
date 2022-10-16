#include<Servo.h> //include the servo library 
int servoPin=3;  // set the pin number for the servo motor
int servoPos=90;  // set the angular position of the servo 
Servo myServo;

#include<LiquidCrystal.h>  // include the lcd library
// set the pin number for the lcd 
int rs=7;
int en=8;
int d4=9;
int d5=10;
int d6=11;
int d7=12;
LiquidCrystal lcd(rs,en,d4,d5,d6,d7);
// set the pin for the IR sensor
int pirPin=5;
int pirVal;




void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(servoPin,OUTPUT);
myServo.attach(servoPin);
lcd.begin(16,2);
pinMode(pirPin,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
 pirVal=digitalRead(pirPin); // reading the value from the IR sensor
Serial.println(pirVal);  // Printing the IR sensor value
// execute the following code when the IR sensor value is zero
  if(pirVal==0){
    for(int j=0; j<2;j++){
      lcd.clear();
      lcd.setCursor(0,0);
lcd.print("Hello,I am Sky");
     lcd.setCursor(0,1);
     lcd.print("Have a good one");
     delay(200);
      for(int i=40; i<80; i++){
        myServo.write(i);
           delay(10); 

      }
      
    }
    


  }
else{
 
  myServo.write(0);
lcd.setCursor(0,0);
lcd.print("wanna meet me?");
lcd.setCursor(0,1);
lcd.print("Then Wave at me!!");

}

}
