#include <stdbool.h>

bool hasAllCodes(char* s, int k) {
    int sub_num=1<<k, count=0, hash=0, all_ones=~sub_num, s_len=strlen(s);
    bool sub[sub_num]; // Track which codes I've seen
    memset(sub, false, sizeof(sub));
    for(int i=0;i<s_len;i++){
        hash = (hash<<1) & all_ones; // Remove k-th bit to ensure 'hash' less than 2^k
        hash |= (s[i]-'0'); // Calculates hash with new character after removing first character of previous substring
        if((i>=k-1) && !sub[hash]){
            sub[hash] = true;
            count++;
        }
    }

    return count==sub_num;
}