/*Write a program to implement the following graph representations and display them.      
i. Adjacency list           
ii. Adjacency matrix*/

#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

// Adjacency List Representation
struct EdgeNode {
    int vertex;
    struct EdgeNode *next;
};

struct VertexNode {
    int vertex;
    struct EdgeNode *head;
};

struct GraphAdjList {
    int numVertices;
    struct VertexNode vertices[MAX_VERTICES];
};

// Adjacency Matrix Representation
struct GraphAdjMatrix {
    int numVertices;
    int adjMatrix[MAX_VERTICES][MAX_VERTICES];
};

void initializeAdjListGraph(struct GraphAdjList *graph) {
    int i;
    graph->numVertices = 0;

    for (i = 0; i < MAX_VERTICES; i++) {
        graph->vertices[i].vertex = i;
        graph->vertices[i].head = NULL;
    }
}

void addEdgeAdjList(struct GraphAdjList *graph, int src, int dest) {
    struct EdgeNode *edge;

    edge = malloc(sizeof(struct EdgeNode));
    edge->vertex = dest;
    edge->next = graph->vertices[src].head;
    graph->vertices[src].head = edge;
}

void displayAdjListGraph(struct GraphAdjList *graph) {
    int i;
    struct EdgeNode *edge;

    for (i = 0; i < graph->numVertices; i++) {
        printf("%d: ", i);
        edge = graph->vertices[i].head;
        while (edge != NULL) {
            printf("%d ", edge->vertex);
            edge = edge->next;
        }
        printf("\n");
    }
}

void initializeAdjMatrixGraph(struct GraphAdjMatrix *graph) {
    int i, j;

    graph->numVertices = 0;
    for (i = 0; i < MAX_VERTICES; i++) {
        for (j = 0; j < MAX_VERTICES; j++) {
            graph->adjMatrix[i][j] = 0;
        }
    }
}

void addEdgeAdjMatrix(struct GraphAdjMatrix *graph, int src, int dest) {
    graph->adjMatrix[src][dest] = 1;
}

void displayAdjMatrixGraph(struct GraphAdjMatrix *graph) {
    int i, j;

    for (i = 0; i < graph->numVertices; i++) {
        for (j = 0; j < graph->numVertices; j++) {
            printf("%d ", graph->adjMatrix[i][j]);
        }
        printf("\n");
    }
}

int main(void) {
    int i;
    struct GraphAdjList graphAdjList;
    struct GraphAdjMatrix graphAdjMatrix;

    initializeAdjListGraph(&graphAdjList);
    graphAdjList.numVertices = 4;

    int numEdges;
    int src, dest;

    printf("Enter the number of edges: ");
    scanf("%d", &numEdges);

    for (i = 0; i < numEdges; i++) {
        printf("Enter the source and destination vertex of edge %d: ", i + 1);
        scanf("%d %d", &src, &dest);
        addEdgeAdjList(&graphAdjList, src, dest);
    }

    printf("Adjacency List Representation:\n");
    displayAdjListGraph(&graphAdjList);

    initializeAdjMatrixGraph(&graphAdjMatrix);
    graphAdjMatrix.numVertices = 4;

    for (i = 0; i < numEdges; i++) {
        printf("Enter the source and destination vertex of edge %d: ", i + 1);
        scanf("%d %d", &src, &dest);
        addEdgeAdjMatrix(&graphAdjMatrix, src, dest);
    }

    printf("Adjacency Matrix Representation:\n");
    displayAdjMatrixGraph(&graphAdjMatrix);

    return 0;
}

