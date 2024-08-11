#include <stdio.h>
#include <assert.h>
#include "Common.h"

Language language;

int batteryIsOk(float temperature, float soc, float chargeRate)
{
  // Messages in English and German
    const char* msg_temp_en = "Temperature out of range!";
    const char* msg_soc_en = "SOC out of range!";
    const char* msg_charge_en = "Charge Rate out of range!";
    
    const char* msg_temp_de = "Temperatur außerhalb des zulässigen Bereichs!";
    const char* msg_soc_de = "SOC außerhalb des zulässigen Bereichs!";
    const char* msg_charge_de = "Ladestrom außerhalb des zulässigen Bereichs!";
    
    return OutOfRange(temperature, 0, 45, msg_temp_en, msg_temp_de)
        && OutOfRange(soc, 20, 80, msg_soc_en, msg_soc_de)
        && OutOfRange(chargeRate, 0, 0.8, msg_charge_en, msg_charge_de);
}

int main() {
  assert(batteryIsOk(25, 70, 0.7));
  assert(!batteryIsOk(50, 85, 0));
}
