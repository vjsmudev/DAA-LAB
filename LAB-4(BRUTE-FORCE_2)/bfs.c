/*Write a program for breadth-first search of a graph.*/

#include<stdio.h>
#include<stdlib.h>
#define MAX_VERTICES 100

typedef struct {
    int arr[MAX_VERTICES];
    int front;
    int rear;
} QUEUE;

QUEUE* init(){
    QUEUE* q = (QUEUE*)malloc(sizeof(QUEUE));
    q->front = q->rear = -1;
    return q;
}

int isEmpty(QUEUE* q){
    if (q->rear == -1){
        return 1;
    }
    else{
        return 0;
    }
}

void enqueue(QUEUE* q, int ele){
    if (q->rear == MAX_VERTICES - 1){
        printf("Queue is full\n");
    }
    else{
        if (q->front == -1){
            q->front = 0;
            q->rear++;
            q->arr[q->rear] =  ele;
        }    
    }
}

int dequeue(QUEUE* q){
    int ele;
    if (isEmpty(q)){
        printf("Queue is empty\n");
        ele = -1;
    }
    else{
        ele = q->arr[q->front];
        q->front++;
        if (q->front > q->rear){
            q->front = q->rear = -1;
        }
    }
    return ele;
}

typedef struct graph{
    int V;
    int** adj;
} GRAPH;

GRAPH* createGraph(int v){
    GRAPH* G = (GRAPH*)malloc(sizeof(GRAPH));
    G->V = v;
    G->adj = (int**)malloc(sizeof(int*)*v);
    for (int i = 0; i < v; i++){
        G->adj[i] = (int*)malloc(sizeof(int)*v);
    }
    return G;
}

void addEdge(GRAPH* G, int src, int des){
    G->adj[src][des] = 1;
    G->adj[des][src] = 1;
}

void BFS(GRAPH* G, int start_vertex,  int visted[]){
    QUEUE* q = init();
    visted[start_vertex] = 1;
    enqueue(q,start_vertex);

    while(!isEmpty(q)){
        int curr_vertex = dequeue(q);
        printf("%d ", curr_vertex);

        for (int i = 0; i < G->V; i++){
            if (G->adj[curr_vertex][i] == 1 & !visted[i]){
                visted[i] = 1;
                enqueue(q, i);
            } 
        }
    }
}


int main(){
    int v,e,src,des;
    printf("Enter the numebr of vertices:\n");
    scanf("%d",&v);
    
    GRAPH* G = createGraph(v);

    printf("Enter the number of edges:\n");
    scanf("%d", &e);

    for (int i = 0; i < e; i++){
        printf("Enter the source and destination vertex of edge %d: \n",i+1);
        scanf("%d %d", &src,&des);
        addEdge(G,src,des);
    }
    
    int visited[G->V];
   
    for (int i = 0; i < G->V; i++){
        visited[i] = 0;
    }

    printf("BFS:\n");
    BFS(G,0,visited);
    

    return 0;
}

