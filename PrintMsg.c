void PrintMsg(const char* PrintMsgInEng, const char* PrintMsgInGer) {
    if (LanguageSel == 0) {
        printf("%s\n", PrintMsgInEng);
    } else {
        printf("%s\n", PrintMsgInGer);
    }
}
