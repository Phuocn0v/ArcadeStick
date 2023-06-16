#include <XInput.h>

const int ADC_Max = 1023;

const uint8_t pin_joyX = A1;
const uint8_t pin_joyY = A2;

const uint8_t pin_button_A = 2;
const uint8_t pin_button_B = 3;
const uint8_t pin_button_X = 4;
const uint8_t pin_button_Y = 5;
const uint8_t pin_button_L1 = 6;
const uint8_t pin_button_R1 = 7;
const uint8_t pin_button_L2 = 8;
const uint8_t pin_button_R2 = 9;

const uint8_t pin_button_start = 10;
const uint8_t pin_button_back = 16;

void setup()
{
  pinMode(pin_joyY, INPUT);
  pinMode(pin_joyX, INPUT);
  
  pinMode(pin_button_A, INPUT_PULLUP);
  pinMode(pin_button_B, INPUT_PULLUP);
  pinMode(pin_button_X, INPUT_PULLUP);
  pinMode(pin_button_Y, INPUT_PULLUP);
  pinMode(pin_button_L1, INPUT_PULLUP);
  pinMode(pin_button_R1, INPUT_PULLUP);
  pinMode(pin_button_L2, INPUT_PULLUP);
  pinMode(pin_button_R2, INPUT_PULLUP);
  
  pinMode(pin_button_start, INPUT_PULLUP);
  pinMode(pin_button_back, INPUT_PULLUP);
  
  XInput.setJoystickRange(0, ADC_Max);
  XInput.setAutoSend(false);
  XInput.begin();
}

void loop()
{
  boolean button_A = !digitalRead(pin_button_A);
  boolean button_B = !digitalRead(pin_button_B);
  boolean button_X = !digitalRead(pin_button_X);
  boolean button_Y = !digitalRead(pin_button_Y);
  boolean button_L1 = !digitalRead(pin_button_L1);
  boolean button_R1 = !digitalRead(pin_button_R1);
  boolean button_L2 = !digitalRead(pin_button_L2);
  boolean button_R2 = !digitalRead(pin_button_R2);
  
  boolean button_start = !digitalRead(pin_button_start);
  boolean button_back = !digitalRead(pin_button_back);
  
  XInput.setButton(BUTTON_A, button_A);
  XInput.setButton(BUTTON_B, button_B);
  XInput.setButton(BUTTON_X, button_X);
  XInput.setButton(BUTTON_Y, button_Y);
  XInput.setButton(BUTTON_LB, button_L1);
  XInput.setButton(BUTTON_RB, button_R1);
  XInput.setButton(TRIGGER_LEFT, button_L2);
  XInput.setButton(TRIGGER_RIGHT, button_R2);
  
  XInput.setButton(BUTTON_START, button_start);
  XInput.setButton(BUTTON_BACK, button_back);
  
  int leftJoyX = analogRead(pin_joyX);
  int leftJoyY =  1024 - analogRead(pin_joyY);
  
  XInput.setJoystickX(JOY_LEFT, leftJoyX);
  XInput.setJoystickY(JOY_LEFT, leftJoyY);
  
  XInput.send();
}