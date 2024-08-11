#include "Common.h"

int OutOfRange(float val, float min, float max, const char* msg_en, const char* msg_de) 
{
    if (val < min || val > max)
    {
        PrintMessage(msg_en, msg_de);
        return 0;
    }
    return 1;
}
