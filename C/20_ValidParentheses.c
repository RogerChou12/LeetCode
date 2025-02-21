bool isValid(char* s) {
    int s_len=strlen(s);
    char *stack=malloc(sizeof(char)*s_len);
    int top=0;

    for(int i=0;i<s_len;i++){
        if(s[i]==')'){
            if(top==0) return false;
            if(stack[--top]!='(') return false;
        }
        else if(s[i]=='}'){
            if(top==0) return false;
            if(stack[--top]!='{') return false;
        }
        else if(s[i]==']'){
            if(top==0) return false;
            if(stack[--top]!='[') return false;
        }
        else{
            stack[top++]=s[i];
        }
    }
    return top==0;
}