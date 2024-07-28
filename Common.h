typedef struct {
    float LwrLmt;
    float UprLmt;
    float WarLwrLmt;
    float WarUprLmt;
    const char* OutOfRngPrintMsgInEng;
    const char* OutOfRngPrintMsgInGer;
    const char* WarLwrPrintMsgInEng;
    const char* WarLwrPrintMsgInGer;
    const char* WarUprPrintMsgInEng;
    const char* WarUprPrintMsgInGer;
} BatteryParamLimits;

void PrintMsg(const char* PrintMsgInEng, const char* PrintMsgInGer);
int BatteryLmtCheck(float value, float LwrLmt, float UprLmt, const char* PrintMsgInEng, const char* PrintMsgInGer);
int ParameterCheck(float value, BatteryParamLimits Limits);
int batteryIsOk(float temperature, float soc, float chargeRate);
