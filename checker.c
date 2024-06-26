#include <stdio.h>
#include <assert.h>

#define BATTERY_OK 1
#define BATTERY_NOT_OK 0

int batteryIsOk(float temperature, float soc, float chargeRate) {
  if(temperature < 0 || temperature > 45) {
    printf("Temperature out of range!\n");
    return BATTERY_NOT_OK;
  } 
  if(soc < 20 || soc > 80) {
    printf("State of Charge out of range!\n");
    return BATTERY_NOT_OK;
  } 
  if(chargeRate > 0.8) {
    printf("Charge Rate out of range!\n");
    return BATTERY_NOT_OK;
  }
  return BATTERY_OK;
}

void testBatteryIsOk() {
  assert(batteryIsOk(25, 70, 0.7) == BATTERY_OK);
  assert(batteryIsOk(0, 20, 0.8) == BATTERY_OK); // Edge case
  assert(batteryIsOk(45, 80, 0.8) == BATTERY_OK); // Edge case
  
  assert(batteryIsOk(-1, 70, 0.7) == BATTERY_NOT_OK); // Temperature below range
  assert(batteryIsOk(46, 70, 0.7) == BATTERY_NOT_OK); // Temperature above range
  assert(batteryIsOk(25, 19, 0.7) == BATTERY_NOT_OK); // SoC below range
  assert(batteryIsOk(25, 81, 0.7) == BATTERY_NOT_OK); // SoC above range
  assert(batteryIsOk(25, 70, 0.9) == BATTERY_NOT_OK); // Charge rate above range
}

int main() {
  testBatteryIsOk();
  printf("All tests passed!\n");
  return 0;
}
