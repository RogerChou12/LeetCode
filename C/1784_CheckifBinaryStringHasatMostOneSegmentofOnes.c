#include<stdbool.h>
#include<string.h>

bool checkOnesSegment(char* s) {
    return strstr(s, "01")==NULL;
}