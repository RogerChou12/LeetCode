#include<stdbool.h>
#include<ctype.h>

bool isValid(char* word) {
    int len=strlen(word);
    int vowel=0, consonant=0;

    if(len < 3){
        return false;
    }

    for(int i=0;i<len;i++){
        if(!isdigit(word[i]) && !isalpha(word[i])){
            return false;
        }
        if(isalpha(word[i])){
            char w=tolower(word[i]);
            if(w=='a' || w=='e' || w=='i' || w=='o' || w=='u'){
                vowel++;
            }
            else{
                consonant++;
            }
        }
    }
    return (vowel && consonant);
}