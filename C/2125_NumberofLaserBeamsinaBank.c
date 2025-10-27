int numberOfBeams(char** bank, int bankSize) {
    char *current;
    int total=0, count=0, preCount=0;
    for(int i=0;i<bankSize;i++){
        current=bank[i];
        count=0;
        while(*current){
            if(*current=='1'){
                count++;
                total+=preCount;
            }
            current++;
        }
        if(count){
            preCount=count;
        }
    }
    return total;
}