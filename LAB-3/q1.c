/*Write a program to sort set of integers using bubble sort. Analyze its time
efficiency. Obtain the experimental result of order of growth. Plot the result for
the best and worst case.*/

#include<stdio.h>
void swap(int *a, int *b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp; 
}

void bsort(int arr[], int n){
    int opc = 0;
    for (int i = 0; i < n-1; i++){
        for (int j = 0; j < n - i - 1; j++){ 
            if (arr[j] > arr[j+1]){
                swap(&arr[j],&arr[j+1]);
                opc++;
            }
        }   
    } 
    printf("Operation count: %d\n",opc);
}

void display(int arr[], int n){
    for (int i = 0; i < n-1; i++){
        printf(" %d ", arr[i]);
    }
}

int main(){
    int n,arr[30];
    printf("Enter the size of the array:\n");
    scanf("%d",&n);
    printf("Enter the elements in the array:\n");
    
    for (int i = 0; i < n; i++){
        scanf("%d",&arr[i]);
    }

    printf("Array:\n");
    display(arr,n);
    printf("\n");

    printf("After bubble sort:\n");
    bsort(arr,n);
    display(arr,n);
    return 0;
}

