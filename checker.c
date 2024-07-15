#include <stdio.h>
#include <assert.h>
/*ErrMsgPrint function is used to print error message
ErrMsg - Error message
*/
void ErrMsgPrint(char *ErrMsg)
{
  printf("%s\n", ErrMsg);
}

 /*
 CheckRange function is used to validate the range of values 
 */
int CheckRangeofValues(float Value, float MinValue, float MaxValue, char *ErrMsg)
{
    char Ret = 0;
    if(!(Ret = ((Value >= MinValue) && (Value <= MaxValue)) ? 1: 0))
        ErrMsgPrint(ErrMsg);
    return Ret;
}

/*batteryIsOk is used to check the range of values of battery temperature, SOC, charge rate 
temperature - Actual temperature value
soc - Actual state of charge
chargeRate - Actual charge rate
*/
int batteryIsOk(float temperature, float soc, float chargeRate) {
  return CheckRangeofValues(temperature, 0, 45, "Temperature out of range!\n") + CheckRangeofValues(soc, 20, 80, "State of Charge out of range!\n") + CheckRangeofValues(chargeRate, 0, 0.8, "Charge Rate out of range!\n") ? 1 : 0;
}
 
int main() {
  assert(batteryIsOk(25, 70, 0.7));
  assert(!batteryIsOk(50, 85, 0));
}
