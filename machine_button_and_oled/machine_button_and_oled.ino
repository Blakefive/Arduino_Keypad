#include "Keyboard.h"
#include "Mouse.h"
#include "U8glib.h"
U8GLIB_SSD1306_128X32 u8g(U8G_I2C_OPT_NONE);


int check = 0;
int mousecheck = 0;
int delaytime = 1;
int mousemovespeed = 1;
int buttonspeed = 190;
String display_string = "t";


void display_show(){
  char ch[10000];
  display_string.toCharArray(ch, display_string.length());
  u8g.firstPage();
    do{
        u8g.setFont(u8g_font_courB18);
        u8g.drawStr(0,22, ch);
    }while(u8g.nextPage());
    return;
}


void setup() {
  Serial.begin(9600);
  Serial.println("Serial Start");
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
  Serial.println("test");
  Serial.print(analogRead(A0));
  Serial.print(" ");
  Serial.println(analogRead(A1));
  if (digitalRead(7) == HIGH && digitalRead(6) == HIGH && digitalRead(5) == HIGH && digitalRead(4) == LOW){
    if(check < 5){
      check += 1;
    }
    else if(check == 5){
      check = 0;
    }
    delay(int(buttonspeed/0.9));
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
  
  if (analogRead(A0) <= 300) {
    if(mousecheck == 1){
      Mouse.move(0,0,1);
      delay(12);
    }
    else{
      Mouse.move(0, -mousemovespeed, 0);
      delay(delaytime);
    }
  }
  if (analogRead(A0) >= 700) {
    if(mousecheck == 1){
      Mouse.move(0,0,-1);
      delay(12);
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
      Mouse.move(0,0,1);
      Keyboard.releaseAll();
      delay(12);
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
      display_string = "ST T WT";
      display_show();
  }
  else if(check == 2){
    display_string = "SB SF A";
    display_show();
  }
  else if(check == 3){
    display_string = "Z SZ S";
    display_show();
  }
  else if(check == 4){
    display_string = "C V X";
    display_show();
  }
  else if(check == 5){
    if(mousecheck == 1){
      display_string = "W.M";
      display_show();
    }
    else if(mousecheck == 2){
      display_string = "W.S:";
      display_show(); 
    }
    else if(mousecheck == 3){
      display_string = "B.S:";
      display_show();  
    }
    else{
      display_string = "ML W MR";
      display_show();
    }
  }
  else{
    display_string = "W< W> AT";
    display_show();
  }
}
