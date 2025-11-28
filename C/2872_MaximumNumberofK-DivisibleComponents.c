typedef struct {
    int neis;
    int* nei;
} Graph;

int maxKDivisibleComponents(int n, int** edges, int edgesSize, int* edgesColSize, int* values, int valuesSize, int k) {
    if (n < 2)
        return 1;
    int count = 0;
    int* indegree = calloc(n, sizeof(int));
    int* leaf = calloc(n, sizeof(int));
    Graph *graph = malloc(sizeof(Graph)*n);
    for(int i=0;i<n;i++){
        graph[i].neis=0;
    }
    long long *Lvalues=malloc(sizeof(long long)*valuesSize);
    for(int i=0;i<valuesSize;i++){
        Lvalues[i]=values[i];
    }
    for (int i = 0; i < edgesSize; i++) {
        int node1 = edges[i][0];
        int node2 = edges[i][1];
        graph[node1].neis++;
        graph[node2].neis++;
        indegree[node1]++;
        indegree[node2]++;
    }
    for(int i=0;i<n;i++){
        graph[i].nei=malloc(sizeof(int)*graph[i].neis);
        graph[i].neis=0;
    }
    for (int i = 0; i < edgesSize; i++) {
        int node1 = edges[i][0];
        int node2 = edges[i][1];
        graph[node1].nei[graph[node1].neis++]=node2;
        graph[node2].nei[graph[node2].neis++]=node1;
    }

    int leaf_len=0;
    for(int node=0;node<n;node++){
        if(indegree[node]==1){
            leaf[leaf_len++]=node;
        }
    }
    for(int l=0;l<leaf_len;l++){
        int curNode=leaf[l];
        indegree[curNode]--;
        long long addValue=0;
        if(Lvalues[curNode]%k==0){
            count++;
        }
        else{
            addValue=Lvalues[curNode];
        }
        for(int i=0;i<graph[curNode].neis;i++){
            int neighbor=graph[curNode].nei[i];
            if(indegree[neighbor]){
                indegree[neighbor]--;
                Lvalues[neighbor]+=addValue;
                if(indegree[neighbor]==1){
                    leaf[leaf_len++]=neighbor;
                }
            }
        }
    }
    return count;
}