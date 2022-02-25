#include <Keyboard.h>
#include "Mouse.h"

int check = 0;
int mousecheck = 0;
int delaytime = 1;
int mousemovespeed = 1;
int buttonspeed = 190;

void setup() {
  Serial.begin(9600);
  Keyboard.begin();
  Mouse.begin();
  pinMode(4,INPUT);
  pinMode(5,INPUT);
  pinMode(6,INPUT);
  pinMode(7,INPUT);
  pinMode(8, INPUT_PULLUP);
  pinMode(9,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(0,OUTPUT);
  pinMode(2,OUTPUT);
}

void loop() {
  if (digitalRead(7) == HIGH && digitalRead(6) == HIGH && digitalRead(5) == HIGH && digitalRead(4) == LOW){
    if(check < 5){
      check += 1;
    }
    else if(check == 5){
      check = 0;
    }
    delay(buttonspeed);
  }
  else if ((check==0) && (digitalRead(7) == HIGH && digitalRead(6) == HIGH && digitalRead(5) == LOW && digitalRead(4) == HIGH)){
    Keyboard.releaseAll();
    Keyboard.press(KEY_LEFT_GUI);
    Keyboard.press(KEY_LEFT_CTRL);
    Keyboard.press(KEY_LEFT_ARROW);
    Keyboard.releaseAll();
    delay(buttonspeed);
  }
  else if ((check==1) && (digitalRead(7) == HIGH && digitalRead(6) == HIGH && digitalRead(5) == LOW && digitalRead(4) == HIGH)){
    Keyboard.releaseAll();
    Keyboard.press(KEY_LEFT_CTRL);
    Keyboard.press(KEY_LEFT_SHIFT);
    Keyboard.press(KEY_TAB);
    Keyboard.releaseAll();
    delay(buttonspeed);
  }
  else if ((check==2) && (digitalRead(7) == HIGH && digitalRead(6) == HIGH && digitalRead(5) == LOW && digitalRead(4) == HIGH)){
    Keyboard.releaseAll();
    Keyboard.press(KEY_LEFT_ALT);
    Keyboard.press(KEY_LEFT_ARROW);
    Keyboard.releaseAll();
    delay(buttonspeed);
  }
  else if ((check==3) && (digitalRead(7) == HIGH && digitalRead(6) == HIGH && digitalRead(5) == LOW && digitalRead(4) == HIGH)){
    Keyboard.releaseAll();
    Keyboard.press(KEY_LEFT_CTRL);   
    Keyboard.press(122);          
    Keyboard.releaseAll();
    delay(buttonspeed);
  }
  else if ((check==4) && (digitalRead(7) == HIGH && digitalRead(6) == HIGH && digitalRead(5) == LOW && digitalRead(4) == HIGH)){
    Keyboard.releaseAll();
    Keyboard.press(KEY_LEFT_CTRL);
    Keyboard.press(99);
    Keyboard.releaseAll();
    delay(buttonspeed);
  }
  else if ((check==5) && (digitalRead(7) == HIGH && digitalRead(6) == HIGH && digitalRead(5) == LOW && digitalRead(4) == HIGH)){
    if(mousecheck != 2 && mousecheck != 3){
      Mouse.click(MOUSE_LEFT);
    }
    else if(mousemovespeed > 1 && mousecheck != 3){
      mousemovespeed--;
    }
    else if(mousecheck != 3){
      delaytime++;
    }
    else if(buttonspeed > 0){
      buttonspeed--;
    }
    delay(buttonspeed);
  }
  else if((check==0) &&(digitalRead(7) == HIGH && digitalRead(6) == LOW && digitalRead(5) == HIGH && digitalRead(4) == HIGH)){
    Keyboard.releaseAll();
    Keyboard.press(KEY_LEFT_GUI);
    Keyboard.press(KEY_LEFT_CTRL);
    Keyboard.press(KEY_RIGHT_ARROW);
    Keyboard.releaseAll();
    delay(buttonspeed);
  }
  else if((check==1) &&(digitalRead(7) == HIGH && digitalRead(6) == LOW && digitalRead(5) == HIGH && digitalRead(4) == HIGH)){
    Keyboard.releaseAll();
    Keyboard.press(KEY_LEFT_CTRL);
    Keyboard.press(KEY_TAB);
    Keyboard.releaseAll();
    delay(buttonspeed);
  }
  else if((check==2) &&(digitalRead(7) == HIGH && digitalRead(6) == LOW && digitalRead(5) == HIGH && digitalRead(4) == HIGH)){
    Keyboard.releaseAll();
    Keyboard.press(KEY_LEFT_ALT);
    Keyboard.press(KEY_RIGHT_ARROW);
    Keyboard.releaseAll();
    delay(buttonspeed);
  }
  else if((check==3) &&(digitalRead(7) == HIGH && digitalRead(6) == LOW && digitalRead(5) == HIGH && digitalRead(4) == HIGH)){
    Keyboard.releaseAll();
    Keyboard.press(KEY_LEFT_CTRL);
    Keyboard.press(KEY_LEFT_SHIFT);
    Keyboard.press(122);
    Keyboard.releaseAll();
    Keyboard.press(KEY_LEFT_CTRL);
    Keyboard.press(121);
    Keyboard.releaseAll();
    delay(buttonspeed);
  }
  else if((check==4) &&(digitalRead(7) == HIGH && digitalRead(6) == LOW && digitalRead(5) == HIGH && digitalRead(4) == HIGH)){
    Keyboard.releaseAll();
    Keyboard.press(KEY_LEFT_CTRL);
    Keyboard.press(118);
    Keyboard.releaseAll();
    delay(buttonspeed);
  }
  else if((check==5) &&(digitalRead(7) == HIGH && digitalRead(6) == LOW && digitalRead(5) == HIGH && digitalRead(4) == HIGH)){
    if(mousecheck == 1){
      mousecheck = 0;
    }
    else{
      mousecheck = 1;
    }
    delay(buttonspeed);
  }
  else if ((check==0) &&(digitalRead(7) == LOW && digitalRead(6) == HIGH && digitalRead(5) == HIGH && digitalRead(4) == HIGH)){
    Keyboard.releaseAll();
    Keyboard.press(KEY_LEFT_ALT);
    Keyboard.press(KEY_TAB);
    Keyboard.releaseAll();
    delay(buttonspeed);
  }
  else if ((check==1) &&(digitalRead(7) == LOW && digitalRead(6) == HIGH && digitalRead(5) == HIGH && digitalRead(4) == HIGH)){
    Keyboard.releaseAll();
    Keyboard.press(KEY_LEFT_GUI);
    Keyboard.press(116);
    Keyboard.releaseAll();
    delay(buttonspeed);
  }
  else if ((check==2) &&(digitalRead(7) == LOW && digitalRead(6) == HIGH && digitalRead(5) == HIGH && digitalRead(4) == HIGH)){
    Keyboard.releaseAll();
    Keyboard.press(KEY_LEFT_CTRL);
    Keyboard.press(97);       
    Keyboard.releaseAll();
    delay(buttonspeed);
  }
  else if ((check==3) &&(digitalRead(7) == LOW && digitalRead(6) == HIGH && digitalRead(5) == HIGH && digitalRead(4) == HIGH)){
    Keyboard.releaseAll();
    Keyboard.press(KEY_LEFT_CTRL);
    Keyboard.press(115);
    Keyboard.releaseAll();
    delay(buttonspeed);
  }
  else if ((check==4) &&(digitalRead(7) == LOW && digitalRead(6) == HIGH && digitalRead(5) == HIGH && digitalRead(4) == HIGH)){
    Keyboard.releaseAll();
    Keyboard.press(KEY_LEFT_CTRL);
    Keyboard.press(120);
    Keyboard.releaseAll();
    delay(buttonspeed);
  }
  else if ((check==5) &&(digitalRead(7) == LOW && digitalRead(6) == HIGH && digitalRead(5) == HIGH && digitalRead(4) == HIGH)){
    if(mousecheck != 2 && mousecheck != 3){
      Mouse.click(MOUSE_RIGHT);
    }
    else if(delaytime > 0 && mousecheck != 3){
      delaytime--;
    }
    else if(mousecheck !=3){
      mousemovespeed++;
    }
    else{
      buttonspeed++;
    }
    delay(buttonspeed);
  }
  else if((check == 5) && (digitalRead(8) == LOW)){
    if(mousecheck < 3){
      if(mousecheck == 0){
        mousecheck++;
      }
      mousecheck++;
    }
    else if(mousecheck == 3){
      mousecheck = 0;
    }
    delay(buttonspeed+50);
  }
  if (analogRead(A4) <= 450) {
    if(mousecheck == 1){
      Mouse.move(0,0,1);
      delay(12);
    }
    else{
      Mouse.move(0, -mousemovespeed, 0);
      delay(delaytime);
    }
  }
  if (analogRead(A4) >= 550) {
    if(mousecheck == 1){
      Mouse.move(0,0,-1);
      delay(12);
    }
    else{
      Mouse.move(0, mousemovespeed, 0);
      delay(delaytime);
    }
  }
  if (analogRead(A5) <= 400) {
    if(mousecheck == 1){
      Keyboard.releaseAll();
      Keyboard.press(KEY_LEFT_SHIFT);
      Mouse.move(0,0,1);
      Keyboard.releaseAll();
      delay(12);
    }
    else{
      Mouse.move(-mousemovespeed, 0, 0);
      delay(delaytime);
    }
  }
  if (analogRead(A5) >= 550) {
    if(mousecheck == 1){
      Keyboard.releaseAll();
      Keyboard.press(KEY_LEFT_SHIFT);
      Mouse.move(0,0,-1);
      Keyboard.releaseAll();
      delay(12);
    }
    else{
      Mouse.move(mousemovespeed, 0, 0);
      delay(delaytime);
    }
  }
  if(check == 1){
    digitalWrite(9,HIGH);
    digitalWrite(11,LOW);
    digitalWrite(0,LOW);
    digitalWrite(2,LOW);
  }
  else if(check == 2){
    digitalWrite(9,LOW);
    digitalWrite(11,HIGH);
    digitalWrite(0,LOW);
    digitalWrite(2,LOW);
  }
  else if(check == 3){
    digitalWrite(9,LOW);
    digitalWrite(11,LOW);
    digitalWrite(0,HIGH);
    digitalWrite(2,LOW);
  }
  else if(check == 4){
    digitalWrite(9,LOW);
    digitalWrite(11,LOW);
    digitalWrite(0,LOW);
    digitalWrite(2,HIGH);
  }
  else if(check == 5){
    if(mousecheck == 1){
      digitalWrite(9,LOW);
      digitalWrite(11,HIGH);
      digitalWrite(0,HIGH);
      digitalWrite(2,LOW);
    }
    else if(mousecheck == 2){
      digitalWrite(9,HIGH);
      digitalWrite(11,LOW);
      digitalWrite(0,LOW);
      digitalWrite(2,HIGH);
    }
    else if(mousecheck == 3){
      digitalWrite(9,HIGH);
      digitalWrite(11,LOW);
      digitalWrite(0,HIGH);
      digitalWrite(2,LOW);
    }
    else{
      digitalWrite(9,HIGH);
      digitalWrite(11,HIGH);
      digitalWrite(0,HIGH);
      digitalWrite(2,HIGH);
    }
  }
  else{
    digitalWrite(9,LOW);
    digitalWrite(11,LOW);
    digitalWrite(0,LOW);
    digitalWrite(2,LOW);
  }
  Serial.print(check);
  Serial.print(" ");
  Serial.print(mousecheck);
  Serial.print(" ");
  Serial.print(mousemovespeed);
  Serial.print(" ");
  Serial.print(delaytime);
  Serial.print(" ");
  Serial.println(buttonspeed);
}
