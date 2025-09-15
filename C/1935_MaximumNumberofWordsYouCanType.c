#include<stdbool.h>
#include<string.h>

int canBeTypedWords(char* text, char* brokenLetters) {
    int words=0, mask=0, text_len=strlen(text), broken_len=strlen(brokenLetters);
    bool broken=false;
    for(int j=0;j<broken_len;j++){
        mask |= 1<<(brokenLetters[j]-'a');
    }
    for(int i=0;i<=text_len;i++){
        if(i==text_len || text[i]==' '){
            if(!broken){
                words++;
            }
            broken=false; // Reset
        }
        else{
            if(mask & 1<<(text[i]-'a')){
                broken=true;
            }
        }
    }
    return words;
}