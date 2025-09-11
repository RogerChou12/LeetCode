int cmpChar(const void *a, const void *b){
    return *(char*)a-*(char*)b;
}
char* sortVowels(char* s) {
    int n=strlen(s);
    char vowels[n];
    int v=0;

    for(int i=0;i<n;i++){
        char lowercase=tolower(s[i]);
        if(lowercase=='a' || lowercase=='e' || lowercase=='i' || lowercase=='o' || lowercase=='u'){
            vowels[v++]=s[i];
        }
    }

    qsort(vowels, v, sizeof(char), cmpChar);
    v=0;
    for(int i=0;i<n;i++){
        char lowercase=tolower(s[i]);
        if(lowercase=='a' || lowercase=='e' || lowercase=='i' || lowercase=='o' || lowercase=='u'){
            s[i]=vowels[v++];
        }
    }
    return s;
}