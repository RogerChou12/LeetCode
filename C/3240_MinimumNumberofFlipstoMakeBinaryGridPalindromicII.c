int minFlips(int** grid, int gridSize, int* gridColSize) {
    int flips=0, ones=0, singleOne=0, doubleOne=0;

    for(int row=0;row<gridSize/2;row++){
        for(int col=0;col<gridColSize[row]/2;col++){
            ones = grid[row][col]+grid[row][gridColSize[row]-1-col]+grid[gridSize-1-row][col]+grid[gridSize-1-row][gridColSize[row]-1-col];
            flips += fmin(ones, 4-ones); //all 1s or all 0s
        }

        // Middle column
        if(gridColSize[row]%2){
            ones = grid[row][gridColSize[row]/2]+grid[gridSize-1-row][gridColSize[row]/2];
            singleOne += (ones==1); // (1,0), (0,1)
            doubleOne += (ones==2); // (1,1)
        }
    }
    // Middle row & center
    if(gridSize%2){
        for(int col=0;col<gridColSize[gridSize/2]/2;col++){
            ones = grid[gridSize/2][col]+grid[gridSize/2][gridColSize[gridSize/2]-1-col];
            singleOne += (ones==1); // (1,0), (0,1)
            doubleOne += (ones==2); // (1,1)
        }
        // Center
        if(gridColSize[0]%2){
            flips += grid[gridSize/2][gridColSize[0]/2]; // if center=1, flip to 0
        }
    }
    // the number of (1,1) pairs is even -> change all (1,0) to (0,0)
    // OR (1,0) pairs exist && the number of (1,1) pairs is odd -> change one (1,0) to (1,1),  others to (0,0)
    if(doubleOne%2==0 || singleOne>0){
        return flips+singleOne;
    }
    // no (1,0) pairs && the number of (1,1) pairs is odd -> change one (1, 1) to (0, 0)
    return flips+2;
}