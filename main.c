#include "Common.h"
#include <assert.h>

int LanguageSel = 0;

int batteryIsOk(float temperature, float soc, float chargeRate) {
    Check checks[] = {
        {isTemperatureInRange, temperature, 2.25, "Temperature out of range!\n", "Warning: Approaching low temperature limit!\n", "Warning: Approaching high temperature limit!\n"},
        {isSocInRange, soc, 4.0, "State of Charge out of range!\n", "Warning: Approaching low SoC limit!\n", "Warning: Approaching high SoC limit!\n"},
        {isChargeRateInRange, chargeRate, 0.04, "Charge Rate out of range!\n", "Warning: Approaching low charge rate limit!\n, "Warning: Approaching high charge rate limit!\n"}
    };

    float minLimits[] = {0, 20, 0};
    float maxLimits[] = {45, 80, 0.8};

    for (int i = 0; i < sizeof(checks) / sizeof(checks[0]); ++i) {
        if (!performCheck(&checks[i], minLimits[i], maxLimits[i])) {
            return 0;
        }
    }
    return 1;
}

int main() {
    assert(batteryIsOk(25, 70, 0.7));
    assert(!batteryIsOk(50, 85, 0));
    assert(!batteryIsOk(30, 85, 0));
    assert(!batteryIsOk(25, 70, 0.9));
    
    // Warning test cases
    assert(batteryIsOk(2.15, 70, 0.7)); 
    assert(batteryIsOk(44.85, 70, 0.7)); 
    assert(batteryIsOk(25, 23.95, 0.7)); 
    assert(batteryIsOk(25, 76.05, 0.7));
    assert(batteryIsOk(25, 70, 0.76)); 
	
    return 0;
}
