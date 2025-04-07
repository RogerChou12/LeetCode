int cmpInt(const void *a, const void *b){
    return*(int*)a-*(int*)b;
}

int findContentChildren(int* g, int gSize, int* s, int sSize) {
    qsort(g, gSize, sizeof(int), cmpInt);
    qsort(s, sSize, sizeof(int), cmpInt);

    int kids=0, cookies=0, content=0;
    while(kids<gSize && cookies<sSize){
        if(s[cookies] >= g[kids]){
            content++;
            cookies++;
            kids++;
        }
        else{
            cookies++;
        }
    }
    return content;
}