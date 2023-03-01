#include<stdio.h>
#include<stdlib.h>

typedef struct graph{
    int V;
    int E;
    int** adj;
} GRAPH;

int visited_array[100];

GRAPH* adjMatOfGraph(){
    //u: no of vertices and v: no of edges
    int u,v,i;

    
    GRAPH* G = (GRAPH*)malloc(sizeof(GRAPH));

    if(G == NULL){
        printf("Memory not allocated\n");
        return NULL;
    }

    printf("Enter no of nodes and edges:\n");
    scanf("%d %d",&G->V,&G->E);
    
    /*allocates memory for an array of integer pointers, 
    which will point to the rows of the 2D array representing the adjacency matrix of the graph G*/

    G->adj = (int**)malloc(sizeof(int*) * G->V);
    for (u = 0; u < G->V;  u++){
        //allocates memory for a row in the adjacency matrix
        G->adj[u] = (int*)malloc(sizeof(int) * G->V);
        for (v  = 0; v < G->V; v++){
            //intializing all the cells of the matrix to 0
            G->adj[u][v] = 0;
        }
    }
    printf("Enter node no's in pair for an edge (u,v):\n");
    
    for (i = 0; i < G->E; i++){
         scanf("%d %d",&u, &v);
         //
         G->adj[u][v] = 1;
         G->adj[v][u] = 1;
    }
    return G;
}

void DFStraversal(GRAPH* G, int u){
    vis[u] = 1;
    printf(" %d ", u);
    for (int v = 0; v < G->V; v++){
        if (!visited_array[v] && G->adj[u][v]){
            DFS(G,v);
        }
    }
}

void DFS(GRAPH* G){
    for (int i = 0; i < 100; i++){
        vis[i] = 0; 
    }
    for (int i = 0; i < G->V; i++){
        if (!vis[i]){
            DFS(G,V);
        }    
    }
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
    if (G == NULL){
        return 1;
    }
    display(G);
    printf("\n");
    printf("DFS traversal:\n");
    DFStraversal(G);
    return 0;
}

