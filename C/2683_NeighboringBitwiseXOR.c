#include <stdbool.h>

bool doesValidArrayExist(int* derived, int derivedSize) {
    int xor=0;
    for(int i=0;i<derivedSize;i++){
        xor ^= derived[i];
    }
    return (xor==0);
}