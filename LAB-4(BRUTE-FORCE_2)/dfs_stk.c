/*Write a program for depth-first search of a graph. Identify the push and pop order
of vertices.*/
#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 100

/*
Note on :printDFS()
1.It creates an empty stack using the create_stack() function.
2.It pushes the start_vertex onto the stack and marks it as visited in the visited_array.
3.It enters a loop that continues until the stack is empty.
4.In each iteration of the loop, it pops the top vertex from the stack using the pop() function and prints it.
5.It examines all the neighbors of the current vertex (i.e., vertices that share an edge with it) by iterating over all vertices in the graph.
6.For each neighbor that has not been visited yet, it marks it as visited in the visited_array and pushes it onto the stack using the push() function.
The loop continues until all vertices reachable from the starting vertex have been visited.*/

int visited_array[MAX_SIZE];

typedef struct{
    int top;
    int arr[MAX_SIZE];
} STACK;

STACK* init(){
    STACK* s = (STACK*)malloc(sizeof(s));
    s->top = -1;
    return s; 
}

int isEmpty(STACK* s){
    return s->top == -1;
}

void push(STACK* s, int ele){
    s->arr[++s->top] = ele;
}

int pop(STACK* s){
    if (!isEmpty(s)){
        return s->arr[s->top--];
    }
    else{
        return -1;
    }
}

int peek(STACK* s){
    if (!isEmpty(s)){
        return s->arr[s->top];
    }
    return -1;
}

typedef struct graph{
    int V;
    int E;
    int** adj;
} GRAPH;

GRAPH* adjMatofGraph(){
    int u,v,i;
    GRAPH* G = (GRAPH*)malloc(sizeof(GRAPH));
    
    if (G == NULL){
        printf("Memory not allocated\n");
        return NULL;
    }

    printf("Enter the number of edges and vertices:\n");
    scanf("%d %d",&G->V,&G->E);
    
    G->adj = (int**)malloc(sizeof(int*) * G->V);
    
    for (u = 0; u < G->V; u++){
        G->adj[u] = (int*)malloc(sizeof(int) * G->V);
        
        for (v  = 0; v < G->V; v++){
            G->adj[u][v] = 0;
        }
    }

    printf("Enter the node's in pairs for an edge(u,v):\n");
    for (i = 0; i < G->E; i++){
        scanf("%d %d", &u,&v);
        G->adj[u][v] = 1;
        G->adj[v][u] = 1;
    }
    return G;
}

void printDFS(GRAPH* G){
    //create empty stack using init()
    STACK* s = init();
    int start_vertex;
    /*pushes the start_vertex onto the stack 
    and marks it as visited in the visited_array.*/
    
    push(s,start_vertex);
    visited_array[start_vertex] = 1;

    //until the stck is empty pop the top vertex 
    while (!isEmpty(s)){
        int curr_vertex = pop(s);
        printf("%d ", curr_vertex);
    
    /*It examines all the neighbors of the current vertex (i.e., vertices that share an edge with it) 
    by iterating over all vertices in the graph.*/

        for (int i = 0; i < G->V; i++){
            if(G->adj[curr_vertex][i] && !visited_array[i]){
                visited_array[i] = 1;
                //for unvisited neighbours push mark as visitedd and push  to  stk
                push(s,i);
            }
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
    GRAPH* G = adjMatofGraph();
    if (G == NULL){
        return 1;
    }
    printf("\n");
    display(G);
    printf("\n");
    printf("DFS traversal:\n");
    printDFS(G);
    return 0;
}

