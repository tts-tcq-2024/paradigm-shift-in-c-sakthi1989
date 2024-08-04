#include "Common.h"
#include <assert.h>

int LanguageSel = 0;

int batteryIsOk(float temperature, float soc, float chargeRate) {
    BatteryParamLimits TemperatureLimits = {0, 45, 40, 45, \
	"Temperature out of range!", "Temperatur außerhalb des Bereichs!", \
	"Warning: Temperature is decreasing", "Warnung: Die Temperatur sinkt", \
	"Warning: Temperature is increasing", "Warnung: Die Temperatur steigt"};
    
	BatteryParamLimits SocLimits = {20, 80, 24, 76, \
	"State of Charge out of range!", "Ladezustand außerhalb des Bereichs!", \
	"Warning: Approaching discharge", "Warnung: Herannahende Entladung", \
	"Warning: Approaching charge peak", "Warnung: Annäherung an die Ladespitze"};
    
	BatteryParamLimits ChargeRateLimits = {0, 0.8, 0.76, 0.8, \
	"Charge Rate out of range!", "Laderate außerhalb des Bereichs!", \
	"Warning: Charge Rate is decreasing", "Warnung: Die Laderate sinkt", \
	"Warning: Charge Rate is increasing", "Warnung: Die Laderate steigt"};

   int status = 1;
    status &= ParameterCheck(temperature, TemperatureLimits);
    status &= ParameterCheck(soc, SocLimits);
    status &= ParameterCheck(chargeRate, ChargeRateLimits);

    return status;
}

int main()
{
    LanguageSel = 0;
    //assert(batteryIsOk(25, 70, 0.7));
    assert(!batteryIsOk(50, 85, 0));
    assert(batteryIsOk(30, 22, 0.5));
    assert(batteryIsOk(30, 78, 0.5));

    LanguageSel = 1;
    //assert(batteryIsOk(25, 70, 0.7));
    assert(!batteryIsOk(50, 85, 0));
    assert(batteryIsOk(30, 22, 0.5));
    assert(batteryIsOk(30, 78, 0.5));

    return 0;
}
