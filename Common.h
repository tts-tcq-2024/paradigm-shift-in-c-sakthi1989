typedef enum {
    ENGLISH,
    GERMAN
} Language;

void PrintMessage(const char* msg_en, const char* msg_de);
int OutOfRange(float val, float min, float max, const char* msg_en, const char* msg_de);
