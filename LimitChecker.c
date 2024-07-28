int BatteryLmtCheck(float value, float LwrLmt, float UprLmt, const char* PrintMsgInEng, const char* PrintMsgInGer)
{
	/*Limit check*/
    if (value < LwrLmt || value > UprLmt) {
        PrintMsg(PrintMsgInEng, PrintMsgInGer);
        return 0;
    }
    return 1;
}

int ParameterCheck(float value, BatteryParamLimits Limits) {
	/*Warning Limit check*/
	if (value >= Limits.WarLwrLmt && value < Limits.LwrLmt) {
        PrintMsg(Limits.WarLwrPrintMsgInEng, Limits.WarLwrPrintMsgInGer);
    } else if (value > Limits.UprLmt && value <= Limits.WarUprLmt) {
        PrintMsg(Limits.WarUprPrintMsgInEng, Limits.WarUprPrintMsgInGer);
	}
	
	return BatteryLmtCheck(value, Limits.LwrLmt, Limits.UprLmt, Limits.OutOfRngPrintMsgInEng, Limits.OutOfRngPrintMsgInGer);
}
