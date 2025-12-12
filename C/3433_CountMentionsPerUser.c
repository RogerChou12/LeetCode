/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include<stdlib.h>
#include<string.h>

int cmpEvent(const void *a, const void *b){
    char **event1=*(char***)a;
    char **event2=*(char***)b;
    int time1=atoi(event1[1]);
    int time2=atoi(event2[1]);
    if(time1!=time2){
        return time1-time2;
    }
    return strcmp(event1[0], "OFFLINE")==0?-1:1;
}

int* countMentions(int numberOfUsers, char*** events, int eventsSize, int* eventsColSize, int* returnSize) {
    int *counts=calloc(numberOfUsers, sizeof(int));
    int *nextOnline=calloc(numberOfUsers, sizeof(int));
    qsort(events, eventsSize, sizeof(char**), cmpEvent);
    for(int i=0;i<eventsSize;i++){
        int curTime=atoi(events[i][1]);
        char *type=events[i][0];
        char mention[512];
        strcpy(mention, events[i][2]);
        if(strcmp(type, "MESSAGE")==0){
            if(strcmp(mention, "ALL")==0){
                for(int user=0;user<numberOfUsers;user++){
                    counts[user]++;
                }
            }
            else if(strcmp(mention, "HERE")==0){
                for(int user=0;user<numberOfUsers;user++){
                    if(nextOnline[user]<=curTime){
                        counts[user]++;
                    }
                }
            }
            else{
                char *token=strtok(mention, " ");
                while(token!=NULL){
                    int idx=atoi(token+2);
                    counts[idx]++;
                    token=strtok(NULL, " ");
                }
            }
        }
        else{
            int idx=atoi(mention);
            nextOnline[idx]=curTime+60;
        }
    }
    free(nextOnline);
    (*returnSize)=numberOfUsers;
    return counts;
}