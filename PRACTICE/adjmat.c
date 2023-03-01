#include<stdio.h>
#include<stdlib.h>

typedef struct graph{
    int V;
    int E;
    int** adj;
} GRAPH;


GRAPH* adjMatOfGraph(){
    //u: indicates total no of vertices, v: indicates total no of edges
    int u,v,i;

    GRAPH* G = (GRAPH*)malloc(sizeof(GRAPH));
    if(G == NULL){
        printf("Memory not allocated\n");
    }
    printf("Enter no of nodes and edges:\n");
    scanf("%d %d",&G->V,&G->E);
    
    //creating the 2d array
    G->adj = (int**)malloc(sizeof(int) * G->V * G->V);
    for (u = 0; u < G->V;  u++){
        for (v  = 0; v < G->V; v++){
            //stores 0's in all the cells
            G->adj[u][v] = 0;
        }
    }
    printf("Enter node no's in pair for an edge:\n");
    
    for (i = 0; i < G->E; i++){
         scanf("%d %d",&u, &v);
         G->adj[u][v] = 1;
         G->adj[v][u] = 1;
    }
    return G;
}

void display(GRAPH* G){
    int u,v;
    printf("Adjacency matrix:\n");
    for (u = 0; u < G->V; u++){
        for (v  = 0; v < G->V; v++){
            printf("%d ", G->adj[u][v]);
        }
        printf("\n");
    }
}

int main(){
    GRAPH* G = adjMatOfGraph();
    display(G);
    return 0;
}

