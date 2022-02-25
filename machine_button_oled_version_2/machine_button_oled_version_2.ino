#include "Keyboard.h"
#include "Mouse.h"
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 32 

#define OLED_RESET     4
#define SCREEN_ADDRESS 0x3C 
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

#define NUMFLAKES     10 

int check = 0;
int mousecheck = 0;
int delaytime = 1;
int mousemovespeed = 1;
int buttonspeed = 190;
int ALT_TAP_check = 0;
String display_string = "t";

void display_show(){
  display.clearDisplay();
  display.setTextSize(3);
  display.setTextColor(WHITE);
  display.setCursor(0,0);
  display.println(display_string);
  display.display();
}

void setup() {
  Serial.begin(9600);
  display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS);
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
    if(ALT_TAP_check == 0){
      if(check < 5){
        check += 1;
      }
      else if(check == 5){
        check = 0;
      }
    }
    else{
      Keyboard.releaseAll();
      ALT_TAP_check = 0;
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
      delay(buttonspeed);
    }
    else if(mousemovespeed > 1 && mousecheck != 3){
      mousemovespeed--;
      delay(buttonspeed);
    }
    else if(mousecheck != 3){
      delaytime++;
      delay(buttonspeed);
    }
    else if(buttonspeed > 0){
      buttonspeed--;
      delay(buttonspeed);
    }
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
    if(ALT_TAP_check == 0){
      Keyboard.releaseAll();
      Keyboard.press(KEY_LEFT_ALT);
      Keyboard.press(KEY_TAB);
      ALT_TAP_check = 1;
      Keyboard.release(KEY_TAB);
    }
    else{
      Keyboard.press(KEY_TAB);
      Keyboard.release(KEY_TAB);
    }
    Keyboard.press(KEY_LEFT_ALT);
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
      delay(buttonspeed);
    }
    else if(delaytime > 0 && mousecheck != 3){
      delaytime--;
      delay(buttonspeed);
    }
    else if(mousecheck !=3){
      mousemovespeed++;
      delay(buttonspeed);
    }
    else{
      buttonspeed++;
      delay(buttonspeed);
    }
  }
  else if((check == 5) && (digitalRead(8) == LOW)){
    if(mousecheck < 3){
      if(mousecheck == 0){
        mousecheck++;
      }
      mousecheck++;
      delay(buttonspeed+50);
    }
    else if(mousecheck == 3){
      mousecheck = 0;
      delay(buttonspeed+50);
    }
  }
  
  if (analogRead(A0) <= 300) {
    if(mousecheck == 1){
      Mouse.move(0,0,mousemovespeed);
      delay(12);
    }
    else{
      Mouse.move(0, -mousemovespeed, 0);
      delay(delaytime);
    }
  }
  if (analogRead(A0) >= 700) {
    if(mousecheck == 1){
      Mouse.move(0,0,-mousemovespeed);
      delay(delaytime+11);
    }
    else{
      Mouse.move(0, mousemovespeed, 0);
      delay(delaytime);
    }
  }
  if (analogRead(A1) <= 300) {
    if(mousecheck == 1){
      Keyboard.releaseAll();
      Keyboard.press(KEY_LEFT_SHIFT);
      Mouse.move(0,0,mousemovespeed);
      Keyboard.releaseAll();
      delay(delaytime+11);
    }
    else{
      Mouse.move(-mousemovespeed, 0, 0);
      delay(delaytime);
    }
  }
  if (analogRead(A1) >= 700) {
    if(mousecheck == 1){
      Keyboard.releaseAll();
      Keyboard.press(KEY_LEFT_SHIFT);
      Mouse.move(0,0,-mousemovespeed);
      Keyboard.releaseAll();
      delay(delaytime+11);
    }
    else{
      Mouse.move(mousemovespeed, 0, 0);
      delay(delaytime);
    }
  }
  
  
 if(check == 1){
  if(display_string != "ST T WT"){
      display_string = "ST T WT";
      display_show();
  }
  }
  else if(check == 2){
    if(display_string != "SB SF A"){
    display_string = "SB SF A";
    display_show();
    }
  }
  else if(check == 3){
    if(display_string != "Z SZ S"){
    display_string = "Z SZ S";
    display_show();
    }
  }
  else if(check == 4){
    if(display_string != "C V X"){
    display_string = "C V X";
    display_show();
    }
  }
  else if(check == 5){
    if(mousecheck == 1){
      if(display_string != "W.M"){
      display_string = "W.M";
      display_show();
      }
    }
    else if(mousecheck == 2){
      String mousemovespeed_string = String(mousemovespeed-delaytime);
      if(display_string != "W.S:"+mousemovespeed_string){
      display_string = "M.S:"+mousemovespeed_string;
      display_show(); 
      }
    }
    else if(mousecheck == 3){
      String buttonspeed_string = String(buttonspeed-190);
      if(display_string != "B.S:"+buttonspeed_string){
      display_string = "B.S:"+buttonspeed_string;
      display_show();  
      }
    }
    else{
      if(display_string != "ML W MR"){
      display_string = "ML W MR";
      display_show();
    }
    }
  }
  else{
    if(display_string != "< > AT"){
    display_string = "< > AT";
    display_show();
    }
  }
}
