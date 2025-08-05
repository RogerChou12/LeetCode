int numOfUnplacedFruits(int* fruits, int fruitsSize, int* baskets, int basketsSize) {
    int unplace=0;

    for(int i=0;i<fruitsSize;i++){
        int noBasket=1;
        for(int j=0;j<basketsSize;j++){
            if(fruits[i] <= baskets[j]){
                baskets[j]=0; // Marked as used
                noBasket=0;
                break;
            }
        }
        unplace += noBasket;
    }
    return unplace;
}