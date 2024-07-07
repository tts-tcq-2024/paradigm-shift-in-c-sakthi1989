#include <stdio.h>
#include <assert.h>
 
int Check(float Value, float MinValue, float MaxValue, char *ErrMsg)
{
    char Ret = 0;
    if(!(Ret = ((Value >= MinValue) && (Value <= MaxValue)) ? 1: 0))
        printf("%s\n", ErrMsg);
    
    return Ret;
}

int batteryIsOk(float temperature, float soc, float chargeRate) {
  return Check(temperature, 0, 45, "Temperature out of range!\n") + Check(soc, 20, 80, "State of Charge out of range!\n") + Check(chargeRate, 0, 0.8, "Charge Rate out of range!\n") ? 1 : 0;
}
 
int main() {
  assert(batteryIsOk(25, 70, 0.7));
  assert(!batteryIsOk(50, 85, 0));
}
