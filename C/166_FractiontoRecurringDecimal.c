#include<stdio.h>

struct HashMap {
    long value;
    int position;
    struct HashMap *next;
};

void push(struct HashMap *map, long value, int position){
    struct HashMap *map01=map;
    while(map01->next){
        map01=map01->next;
    }
    struct HashMap *temp=malloc(sizeof(struct HashMap));
    temp->value=value;
    temp->position=position;
    temp->next=NULL;
    map01->next=temp;
}

int pop(struct HashMap *map, long value){
    struct HashMap *m=map->next;
    while(m){
        if(m->value==value){
            return m->position;
        }
        m=m->next;
    }
    return 0;
}

char* fractionToDecimal(int numerator, int denominator) {
    if(numerator==0){
        return "0";
    }
    
    int index=0;
    char *ans=malloc(sizeof(char)*10000);
    if((numerator>0)^(denominator>0)){
        ans[index++]='-';
    }

    long num=numerator, den=denominator;
    num=(num>0)?num:-num;
    den=(den>0)?den:-den;
    long quotient=num/den;
    long remainder=num%den;
    int id=0;
    int *integer=calloc(10000, sizeof(int));
    if(quotient){
        while(quotient){
            integer[id++]=quotient%10;
            quotient /= 10;
        }
        for(int i=id-1;i>=0;i--){
            ans[index++]=integer[i]+'0';
        }
    }
    else{
        ans[index++]='0';
    }
    free(integer);

    if(remainder==0){
        ans[index++]='\0';
        ans=realloc(ans, sizeof(char)*index);
        return ans;
    }
    ans[index++]='.';
    struct HashMap *map=malloc(sizeof(struct HashMap));
    map->value=-1;
    map->position=-1;
    map->next=NULL;
    while(remainder){
        int prev=pop(map, remainder); // Position of remainder which is the same value as previous value
        if(prev){
            for(int i=index;i>prev;i--){
                ans[i]=ans[i-1]; // shift right
            }
            index++;
            ans[prev]='(';
            ans[index++]=')';
            break;
        }
        push(map, remainder, index);
        remainder *= 10;
        ans[index++]=remainder/den + '0';
        remainder %= den;
    }
    ans[index++]='\0';
    ans=realloc(ans, sizeof(char)*index);
    return ans;
}