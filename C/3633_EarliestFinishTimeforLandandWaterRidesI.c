#include<limits.h>
#define min(a, b) (a<b?a:b)
#define max(a, b) (a>b?a:b)

int solve(int* Start1, int Start1Size, int* Duration1, int* Start2, int Start2Size, int* Duration2){
    int finish1=INT_MAX, finish2=INT_MAX;
    for(int i=0;i<Start1Size;i++){
        finish1=min(finish1, (Start1[i]+Duration1[i]));
    }
    for(int j=0;j<Start2Size;j++){
        finish2=min(finish2, (max(Start2[j], finish1)+Duration2[j]));
    }
    return finish2;
}

int earliestFinishTime(int* landStartTime, int landStartTimeSize, int* landDuration, int landDurationSize, int* waterStartTime, int waterStartTimeSize, int* waterDuration, int waterDurationSize) {
    int land_water=solve(landStartTime, landStartTimeSize, landDuration, waterStartTime, waterStartTimeSize, waterDuration);
    int water_land=solve(waterStartTime, waterStartTimeSize, waterDuration, landStartTime, landStartTimeSize, landDuration);
    return min(land_water, water_land);
}