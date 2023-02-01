/*Write a program to construct a binary tree to support the following operations. Assume no duplicate elements while constructing the tree.            
 i.Given a key, perform a search in the binary search tree. If the key is found then display “key found” else insert the key in the binary search tree.           
 ii.Display the tree using inorder, preorder and post order traversal methods */

#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node* left,*right;
} NODE;

NODE* createNode(int ele){
    NODE* temp = (NODE*)malloc(sizeof(NODE));
    temp->data = ele;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

NODE* insert(NODE* root, int key){
    if(root == NULL)
        return createNode(key);

    if(key < root->data)
        root->left = insert(root->left, key);
    
    else if(key > root->data)
        root->right = insert(root->right, key);
    
    return root;
}


NODE* search(NODE* root, int key){
    if (root == NULL||root->data == key)
        return root;

    if(root->data < key)
        return search(root->right,key);

    return search(root->left,key);
}

void inorder(NODE* root){
    if(root != NULL){
        inorder(root->left);
        printf(" %d ", root->data);
        inorder(root->right);
    }
}

void preorder(NODE* root){
    if(root != NULL){
        printf(" %d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(NODE* root){
    if(root != NULL){
        postorder(root->left);
        postorder(root->right);
        printf(" %d ", root->data);
    }
}

int main(){
    NODE* root = NULL;
    int ch, key;
    int flag = 0;
    while(!flag){
        printf("List of operations:\n1.Insert\n2.Search\n3.Inorder traversal\n4.Preorder traversal\n5.Postorder traversal\n6.Exit\n");
        scanf("%d",&ch);

        if(ch == 1){
            if(key == -1){
                break;
            }
            printf("Enter the key to insert(no duplicate values and -1 to exit):\n");
            scanf("%d",&key);
            root = insert(root, key);
        }
        else if(ch == 2){
            printf("Enter the key to search:\n");
            scanf("%d",&key);
            if(search(root, key) == NULL){
                printf("key is not found\n");
                NODE* ans  = search(root, key);
                root = insert(root, key);
            }
            else{
                printf("key is found\n");
            }
        }

        else if(ch == 3){
            printf("Inorder traversal\n");
            inorder(root);
            printf("\n");
        }

        else if(ch == 4){
            printf("Preorder traversal\n");
            preorder(root);
            printf("\n");
        }
        
        else if(ch == 5){
            printf("Postorder traversal\n");
            postorder(root);
            printf("\n");
        }

        else if(ch == 6){
            flag = 0;
        }
        
        else{
            printf("Enter a valid choice\n");
        }
    }
    return 0;
}
