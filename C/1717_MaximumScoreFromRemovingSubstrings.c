char *removeSub(char *input, char *sub){
    int top=0, input_len=strlen(input);
    char *remain=malloc(sizeof(char)*(1+input_len));
    for(int i=0;i<input_len;i++){
        if(input[i]==sub[1] && top!=0 && remain[top-1]==sub[0]){
            top--;
        }
        else{
            remain[top++]=input[i];
        }
    }

    remain[top]='\0';
    return remain;
}

int maximumGain(char* s, int x, int y) {
    int score=0, s_len=strlen(s);
    char *high=(x>y)?"ab":"ba";
    char *low=(x<=y)?"ab":"ba";

    // Remove pair with higher score
    char *firstRemove=removeSub(s, high);
    int firstRemove_len=strlen(firstRemove);
    score += ((s_len-firstRemove_len)/2)*fmax(x,y);
    // Remove pair of lower score
    char *secondRemove=removeSub(firstRemove, low);
    score += ((firstRemove_len-strlen(secondRemove))/2)*fmin(x,y);

    return score;
}