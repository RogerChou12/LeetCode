int find(int x, int *parent){
    if(parent[x]!=x){
        parent[x]=find(parent[x], parent);
    }
    return parent[x];
}

void unite(int a, int b, int *parent, int *rank){
    a=find(a, parent); // root of 'a'
    b=find(b, parent); // root of 'b'
    if(a==b) return;
    if(rank[a]<rank[b]){
        parent[a]=b;
    }
    else{
        parent[b]=a;
        if(rank[a]==rank[b]){
            rank[a]++; // Increment rank only on equal rank
        }
    }
}

int latestDayToCross(int row, int col, int** cells, int cellsSize, int* cellsColSize) {
    int days=row*col;
    int top=days, bottom=days+1; // Virtual nodes
    int *parent=calloc((days+2), sizeof(int));
    int *rank=calloc((days+2), sizeof(int));
    int *grid=calloc(days, sizeof(int)); // All water
    // Initialize 'parent'
    for(int i=0;i<(days+2);i++){
        parent[i]=i;
    }
    int dirRow[4]={-1,1,0,0};
    int dirCol[4]={0,0,-1,1};
    for(int d=days-1;d>=0;d--){
        int r=cells[d][0]-1;
        int c=cells[d][1]-1;
        int id=r*col+c;
        grid[id]=1; // water->land
        if(r==0){
            unite(id, top, parent, rank);
        }
        if(r==row-1){
            unite(id, bottom, parent, rank);
        }
        // Connect to neighbors
        for(int k=0;k<4;k++){
            int nr=r+dirRow[k];
            int nc=c+dirCol[k];
            if(nr>=0 && nr<row && nc>=0 && nc<col){
                int nid=nr*col+nc;
                if(grid[nid]){
                    unite(id, nid, parent, rank);
                }
            }
        }
        if(find(top, parent)==find(bottom, parent)){
            free(parent);
            free(rank);
            free(grid);
            return d;
        }
    }
    free(parent);
    free(rank);
    free(grid);
    return 0;
}