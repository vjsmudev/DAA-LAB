#include<stdio.h>
#include<stdlib.h>
#define maxNode 4

typedef struct node{
    int vertexNum;
    struct node* next;
} NODE;

//list of head nodes that stores address of neighbouring vertices
typedef struct list{
    NODE* head;
} LIST;

//
LIST* adjList[maxNode] = {0};

NODE* des_init(NODE* des, int d){
    des = (NODE*)malloc(sizeof(NODE));
    des->vertexNum = NULL;
    des->next = NULL;
    return des;
}

NODE* src_init(NODE* src, int s){
    src = (NODE*)malloc(sizeof(NODE));
    src->vertexNum = s;
    src->next = NULL;
    return src;
}

void addNode(int s,  int d){
    NODE* des,*tmp,*src;
    if (adjList[s]->head == NULL){
        //creates a new node
        src = src_init(*src, s)
        adjList[s]->head = src;
    }   
    des = des_init(*des, d);
    tmp = adjList[s]->head; 
    while (tmp->next != NULL){
        tmp = tmp->next; 
    }
    tmp->next = des;   
}

void printList(){
    NODE* temp;
    if (temp !=  NULL){
        printf(" %d ", temp->vertexNum);
        temp = temp->next;
    }
}

int main(){
        int i;
    //creating an array of head nodes
    for(i = 0;i < maxNode; i++){
        adjList[i] = (LIST*)malloc(sizeof(LIST));
        adjList[i]->head = NULL;
    }
    addNode(0,1);
    addNode(0,3);
    addNode(1,2);
    printList();
}
