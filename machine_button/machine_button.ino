#include <Keyboard.h>
#include "Mouse.h"

void setup() {
  Serial.begin(9600);
  pinMode(7,INPUT);
  pinMode(8, INPUT_PULLUP);
  Keyboard.begin();
  Mouse.begin();
}

void loop() {
  if (digitalRead(7) == LOW && digitalRead(6) == LOW && digitalRead(5) == HIGH && digitalRead(4) == HIGH){
      Keyboard.releaseAll();
      Keyboard.press(KEY_LEFT_GUI);
      Keyboard.press(KEY_LEFT_CTRL);
      Keyboard.press(KEY_RIGHT_ARROW); 
      Keyboard.releaseAll();
      delay(150);
    }
    else if (digitalRead(7) == LOW && digitalRead(6) == HIGH && digitalRead(5) == LOW && digitalRead(4) == HIGH){
      Keyboard.releaseAll();
      Keyboard.press(KEY_LEFT_CTRL); 
      Keyboard.press(97);  
      Keyboard.releaseAll();
      delay(150);
    }
    else if (digitalRead(7) == HIGH && digitalRead(6) == LOW && digitalRead(5) == LOW && digitalRead(4) == HIGH){
      Keyboard.releaseAll();
      Keyboard.press(KEY_LEFT_CTRL);
      Keyboard.press(115);
      Keyboard.releaseAll();
      delay(150);
    }
    else if (digitalRead(7) == LOW && digitalRead(6) == HIGH && digitalRead(5) == HIGH && digitalRead(4) == LOW){
      Keyboard.releaseAll();
      Keyboard.press(KEY_LEFT_CTRL);
      Keyboard.press(KEY_LEFT_SHIFT);   
      Keyboard.press(122);
      Keyboard.releaseAll();
      delay(150);
    }
    else if (digitalRead(7) == HIGH && digitalRead(6) == LOW && digitalRead(5) == HIGH && digitalRead(4) == LOW){
      Keyboard.releaseAll();
      Keyboard.press(KEY_LEFT_ALT);
      Keyboard.press(KEY_RIGHT_ARROW);
      Keyboard.releaseAll();
      delay(150);
    }
    else if (digitalRead(7) == HIGH && digitalRead(6) == HIGH && digitalRead(5) == LOW && digitalRead(4) == LOW){
      Keyboard.releaseAll();
      Keyboard.press(KEY_LEFT_GUI);
      Keyboard.press(KEY_LEFT_CTRL);
      Keyboard.press(KEY_LEFT_ARROW);
      Keyboard.releaseAll();
      delay(150);
    }
    else if (digitalRead(7) == HIGH && digitalRead(6) == HIGH && digitalRead(5) == HIGH && digitalRead(4) == LOW){
      Keyboard.releaseAll();
      Keyboard.press(KEY_LEFT_GUI);
      Keyboard.press(116);       
      Keyboard.releaseAll();
      delay(150);  
    }
    else if (digitalRead(7) == HIGH && digitalRead(6) == HIGH && digitalRead(5) == LOW && digitalRead(4) == HIGH){
      Keyboard.releaseAll();
      Keyboard.press(KEY_LEFT_ALT);
      Keyboard.press(KEY_TAB);
      Keyboard.releaseAll();
      delay(150);
    }
    else if(digitalRead(7) == HIGH && digitalRead(6) == LOW && digitalRead(5) == HIGH && digitalRead(4) == HIGH){
      Keyboard.releaseAll();
      Keyboard.press(KEY_LEFT_ALT);
      Keyboard.press(KEY_LEFT_ARROW);       
      Keyboard.releaseAll();
      delay(150);
    }
    else if (digitalRead(7) == LOW && digitalRead(6) == HIGH && digitalRead(5) == HIGH && digitalRead(4) == HIGH){
      Keyboard.releaseAll();
      Keyboard.press(KEY_LEFT_CTRL);   
      Keyboard.press(122);        
      Keyboard.releaseAll();
      delay(150);
      }
 
  
        if (digitalRead(8) == 0) {
      Mouse.click(MOUSE_LEFT);
      Serial.println("check");
    }
  if (analogRead(A4) <= 450) {
    Mouse.move(0, -1, 0);
  }
  if (analogRead(A4) >= 550) {
    Mouse.move(0, 1, 0);
  }
    if (analogRead(A5) <= 400) {
      Mouse.move(-1, 0, 0);
    }
    if (analogRead(A5) >= 550) {
      Mouse.move(1, 0, 0);
    }
}
