#include "Common.h"
#include <stdio.h>
extern Language language;
void PrintMessage(const char* msg_en, const char* msg_de)
{
    switch (language) 
    {
        case 0:
            printf("EN: %s\n", msg_en);
            break;
        case 1:
            printf("DE: %s\n", msg_de);
            break;
        default:
            printf("Language not supported\n");
            break;
    }
}
