/*
Cristian Gutierrez
Robotic Arm w/Potentiometer Control
11/30/23
*/

#include <Servo.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define OLED_RESET 4
Adafruit_SSD1306 display(128, 64, &Wire, OLED_RESET);

Servo servo1, servo2, servo3, servo4, servo5;
int angle1 = 30, angle2 = 65, angle3 = 90, angle4 = 90, angle5 = 90;
float offset1 = 0, offset2 = 0, offset3 = 0, offset4 = 0, offset5 = 0;
int potVal1, potVal2, potVal3, potVal4, potVal5;

void setup() {
  servo1.attach(9);
  servo2.attach(6);
  servo3.attach(5);
  servo4.attach(3);
  servo5.attach(11);

  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(0, 0);
  display.println(F("Robotic Arm Control"));
  display.display();
  delay(3000);
}

void loop() {
  potVal1 = map(analogRead(0), 0, 1023, 0, 180);
  potVal2 = map(analogRead(1), 0, 1023, 0, 180);
  potVal3 = map(analogRead(2), 0, 1023, 0, 180);
  potVal4 = map(analogRead(3), 0, 1023, 0, 180);
  potVal5 = map(analogRead(6), 0, 1023, 35, 90);

  angle1 = potVal1;
  angle2 = potVal2;
  angle3 = potVal3;
  angle4 = potVal4;
  angle5 = potVal5;

  servo1.write(angle1 + offset1);
  servo2.write(angle2 + offset2);
  servo3.write(angle3 + offset3);
  servo4.write(angle4 + offset4);
  servo5.write(angle5 + offset5);

  display.clearDisplay();
  display.setTextSize(1);
  display.setCursor(0, 0);
  display.print("S1:");
  display.print(angle1);
  display.print(" S2:");
  display.print(angle2);
  display.print("\nS3:");
  display.print(angle3);
  display.print(" S4:");
  display.print(angle4);
  display.print("\nS5:");
  display.print(angle5);
  display.display();

  delay(50);
}
