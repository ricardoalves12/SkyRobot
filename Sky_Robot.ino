#include<Servo.h>
int servoPin=3;
int servoPos=90;
Servo myServo;

#include<LiquidCrystal.h>
int rs=7;
int en=8;
int d4=9;
int d5=10;
int d6=11;
int d7=12;
LiquidCrystal lcd(rs,en,d4,d5,d6,d7);

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
 pirVal=digitalRead(pirPin);
Serial.println(pirVal);
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
