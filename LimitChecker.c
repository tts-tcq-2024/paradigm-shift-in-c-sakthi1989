#include "Common.h"

int ParameterCheck(float value, BatteryParamLimits Limits) {

#if 0
	(value >= Limits.WarLwrLmt && value < Limits.LwrLmt) ?  PrintMsg(Limits.WarLwrPrintMsgInEng, Limits.WarLwrPrintMsgInGer) : \
	(value > Limits.UprLmt && value <= Limits.WarUprLmt) ? PrintMsg(Limits.WarUprPrintMsgInEng, Limits.WarUprPrintMsgInGer) : 0; 
	
	(value < Limits.LwrLmt || value > Limits.UprLmt) ? PrintMsg(Limits.OutOfRngPrintMsgInEng, Limits.OutOfRngPrintMsgInGer) : 0;
	
	return (value < Limits.LwrLmt || value > Limits.UprLmt) ? 0 : 1;
#endif
	return 1; 
}
