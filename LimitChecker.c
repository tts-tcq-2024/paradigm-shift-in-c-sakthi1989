#include "Common.h"

int CheckAndPrint(float value, float lowerLimit, float upperLimit, const char* lowerMsgEng, const char* lowerMsgGer, const char* upperMsgEng, const char* upperMsgGer) {
    if (value < lowerLimit) {
        PrintMsg(lowerMsgEng, lowerMsgGer);
        return 0;
    } else if (value > upperLimit) {
        PrintMsg(upperMsgEng, upperMsgGer);
        return 0;
    }
    return 1;
}

int ParameterCheck(float value, BatteryParamLimits Limits) {
    if (!CheckAndPrint(value, Limits.WarLwrLmt, Limits.LwrLmt, Limits.WarLwrPrintMsgInEng, Limits.WarLwrPrintMsgInGer, Limits.OutOfRngPrintMsgInEng, Limits.OutOfRngPrintMsgInGer)) {
        return 0;
    }
    if (!CheckAndPrint(value, Limits.UprLmt, Limits.WarUprLmt, Limits.OutOfRngPrintMsgInEng, Limits.OutOfRngPrintMsgInGer, Limits.WarUprPrintMsgInEng, Limits.WarUprPrintMsgInGer)) {
        return 0;
    }
    return 1;
}
