int numOfUnplacedFruits(int* fruits, int fruitsSize, int* baskets, int basketsSize) {
    int unplace=0;
    int sectionSize=sqrt(basketsSize);
    int sections=basketsSize/sectionSize + 1;
    int *sectionMax=malloc(sizeof(int)*sections);

    int cnt=0, max=0;
    for(int i=0;i<basketsSize;i+=sectionSize){
        max=baskets[i];
        for(int j=0;j<sectionSize && i+j<basketsSize;j++){
            max=fmax(max, baskets[i+j]);
        }
        sectionMax[cnt++]=max;
    }

    for(int i=0;i<fruitsSize;i++){
        int noBasket=1;
        for(int j=0;j<sections;j++){
            if(fruits[i]>sectionMax[j]){
                continue;
            }
            for(int k=0;k<sectionSize && j*sectionSize+k<basketsSize;k++){
                if(baskets[j*sectionSize+k]>=fruits[i]){
                    noBasket=0;
                    baskets[j*sectionSize+k]=0;
                    break;
                }
            }
            if(noBasket==0){
                sectionMax[j]=0;
                for(int k=0;k<sectionSize && j*sectionSize+k<basketsSize;k++){
                    sectionMax[j]=fmax(sectionMax[j], baskets[j*sectionSize+k]);
                }
                break;
            }
        }
        unplace += noBasket;
    }
    return unplace;
}