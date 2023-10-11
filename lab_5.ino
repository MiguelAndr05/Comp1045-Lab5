/*
Miguel Andrade
Tuesday October 10th, 2023
Using Buttons to change LEDS and RGB and cycle between
*/


int redLed = 12;
int blueLed = 13; //The blue LED is connected pin 13 of the Arduino.
int button1 = 2; //The button 1 connect to pin 2 of the Arduino.
int button2 = 3; //The buttons 2 ic connected to pin 3

int red = 9; //rgb pins
int blue = 10;
int green = 11;

int buttonState1 = 0; 
int buttonState2 = 1;
int count = 0; //count sfor lvl3

int countBR = 0; //counts f or lvl 4
int countRGB = 0;

void loop() {
  //level1();
  //level2();
  //level3();
  level4();
  
  
}
//function for lvl3
void lightOff() {
  count = 1;
}


void setup() { //The Setup function runs once
pinMode(blueLed, OUTPUT); //Setup blue LED pin as an output pin.
pinMode(redLed, OUTPUT);
pinMode(button1, INPUT); //Setup button1 pin as an input pin.
pinMode(button2, INPUT); 
pinMode(red, OUTPUT);
pinMode(green, OUTPUT);
pinMode(blue, OUTPUT);
  //intruput changing the value from higher to lower
attachInterrupt(digitalPinToInterrupt(button2), lightOff, FALLING);
Serial.begin(9600);
 //leve 4 intruputts for when pin goes high to low
attachInterrupt(digitalPinToInterrupt(button1), toggleButton1, FALLING);
  attachInterrupt(digitalPinToInterrupt(button2), toggleButton2, FALLING);
  
}


void level1() { //Loops level one

   
  if (digitalRead(button1) == HIGH) { //Check to see if button1 is pressed.
digitalWrite(blueLed, HIGH);//Turn on the blue LED.
} else {
digitalWrite(blueLed, LOW); //Turn off the blue LED.
}


}


void level2() {
  
    if (digitalRead(button1) == HIGH) { //Check to see if button1 is pressed.
digitalWrite(blueLed, HIGH);//Turn on the blue LED.
} else {
digitalWrite(blueLed, LOW); //Turn off the blue LED.
}

  if (digitalRead(button2) == HIGH) { //Check to see if button1 is pressed.
digitalWrite(redLed, HIGH);//Turn on the blue LED.
} else {
digitalWrite(redLed, LOW); //Turn off the blue LED.
}

  
}

void level3() {
  
  
   buttonState1 = digitalRead(button1);
  buttonState2 = digitalRead(button2);
//checks if button1 was clicked and if the count = 0
  while (buttonState1 == HIGH && count == 0) {
    digitalWrite(red, HIGH);
    digitalWrite(green, LOW);
    digitalWrite(blue, LOW);
    delay(500);
    
    digitalWrite(red, LOW);
    digitalWrite(green, HIGH);
    digitalWrite(blue, LOW);
    delay(500);

    digitalWrite(red, LOW);
    digitalWrite(green, LOW);
    digitalWrite(blue, HIGH);
    delay(500);
  } 

//if button2 is clicked shut off rgb
  if (buttonState2 == LOW) {
    digitalWrite(red, LOW);
    digitalWrite(green, LOW);
    digitalWrite(blue, LOW);
    count = 0;
  }
}

void level4(){
  //if first button is off, turn red LED on, and turn off blue LED and RGB led
  if(countBR == 0){
    digitalWrite(redLed, HIGH);
    digitalWrite(blueLed, LOW);
    digitalWrite(red, LOW);
    digitalWrite(green, LOW);
    digitalWrite(blue, LOW);
  }
  //if first button is on turn blue LED on and turn off red LED
  if(countBR == 1){
    digitalWrite(redLed, LOW);
    digitalWrite(blueLed, HIGH);
    //second button off turn rgb off
    if(countRGB == 0){
      digitalWrite(red, LOW);
      digitalWrite(green, LOW);
      digitalWrite(blue, LOW);
    }
    //if seconnd button is on turn rgb on cycle and 3 checks
    if(countRGB == 1){
      digitalWrite(red, HIGH);
      digitalWrite(green, LOW);
      digitalWrite(blue, LOW);
      delay(500);
      
      if(countRGB == 1){
      	digitalWrite(green, HIGH);
        digitalWrite(red, LOW);
        digitalWrite(blue, LOW);
        delay(500);
      }
      if(countRGB == 1){
        digitalWrite(blue, HIGH);
        digitalWrite(red, LOW);
        digitalWrite(green, LOW);
        delay(500);
      }
    }
  }
}
//checkfs for buttons clicks

void toggleButton1(){
  if(countBR == 0){
  	countBR = 1;
  }else if(countBR == 1){
    countRGB = 0;
  	countBR = 0;
  }
}
//checks for button clicks
void toggleButton2(){

   if(countRGB == 0){
  	 countRGB = 1;
   }else if(countRGB == 1){
  	 countRGB = 0;
   }
  
}


  
