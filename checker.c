#include <stdio.h>
#include <assert.h>

int isTemperatureOk(float temperature) {
  if(temperature < 0 || temperature > 45) {
    printf("Temperature out of range!\n");
    return 0;
  }
  return 1;
}

int isSocOk(float soc) {
  if(soc < 20 || soc > 80) {
    printf("State of Charge out of range!\n");
    return 0;
  }
  return 1;
}

int isChargeRateOk(float chargeRate) {
  if(chargeRate > 0.8) {
    printf("Charge Rate out of range!\n");
    return 0;
  }
  return 1;
}

int batteryIsOk(float temperature, float soc, float chargeRate) {
  return isTemperatureOk(temperature) && isSocOk(soc) && isChargeRateOk(chargeRate);
}

int main() {
  assert(batteryIsOk(25, 70, 0.7));
  assert(!batteryIsOk(50, 85, 0));
  assert(!batteryIsOk(-1, 70, 0.7));  // Temperature below range
  assert(!batteryIsOk(25, 85, 0.7));  // SoC above range
  assert(!batteryIsOk(25, 70, 0.9));  // Charge rate above range
  assert(batteryIsOk(0, 20, 0.8));    // Edge case where all parameters are exactly on the edge of the valid range
  printf("All tests passed!\n");
  return 0;
}
