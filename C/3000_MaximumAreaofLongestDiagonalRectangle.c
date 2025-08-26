int areaOfMaxDiagonal(int** dimensions, int dimensionsSize, int* dimensionsColSize) {
    float diagonal=0.0;
    int area=0;

    for(int i=0;i<dimensionsSize;i++){
        int length=dimensions[i][0], width=dimensions[i][1];
        float temp=sqrt(length*length+width*width);
        if(temp>diagonal){
            diagonal=temp;
            area=length*width;
        }
        else if(temp==diagonal){
            area=(length*width > area)?(length*width):area;
        }
    }
    return area;
}