#define CUSTOM_SETTINGS
#define INCLUDE_LEDCONTROL_MODULE
#define LED 13
#include <DabbleESP32.h>
unsigned long lasttime=0;
void setup() {
  Serial.begin(115200);     // make sure your Serial Monitor is also set at this baud rate.
  Dabble.begin("MyEsp32");     //set bluetooth name of your device
  pinMode(LED, OUTPUT);
}

void loop() {
  Dabble.processInput();    //this function is used to refresh data obtained from smartphone.Hence calling this function is mandatory in order to get data properly from your mobile.
  Serial.print("State:");          //0 if led is Off. 1 if led is On.
  Serial.print(LedControl.getpinState());
  digitalWrite(LED, LedControl.getpinState());
  }
