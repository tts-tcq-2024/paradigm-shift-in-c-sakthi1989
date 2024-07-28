#include <stdio.h>
#include "Common.h"

extern int LanguageSel;

void PrintMsg(const char* PrintMsgInEng, const char* PrintMsgInGer) {
    (LanguageSel == 0)  ?  printf("%s\n", PrintMsgInEng) : printf("%s\n", PrintMsgInGer);
}
