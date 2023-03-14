/*Sort the array in ascending order.
Set the low index to the first element of the array and the high index to the last element.
Set the middle index to the average of the low and high indices.
If the element at the middle index is the target element, return the middle index.
If the target element is less than the element at the middle index, set the high index to the middle index – 1.
If the target element is greater than the element at the middle index, set the low index to the middle index + 1.
Repeat steps 3-6 until the element is found or it is clear that the element is not present in the array.*/

#include<stdio.h>

int binarySearch(int arr[],int l, int r, int x){
   
    if (r >= 1){
        int mid = l + (r - 1) / 2;
    
    if (arr[mid] == x){
        return mid;
    }
    
    if (x < arr[mid]){
        return binarySearch(arr, l, mid - 1,x);
    }
    
    return binarySearch(arr, mid + 1, r, x);
    }
    return -1;
}

int main(){
    int n;
    printf("Enter the size of the array:\n");
    scanf("%d",&n);
    int arr[20];
    
    printf("Enter the elements into array:\n");
    for (int i = 0; i < n; i++){
        scanf("%d",&arr[i]);
    }

    int key;
    printf("Enter the key to search for:\n");
    scanf("%d",&key);
    int ans =  binarySearch(arr,0,n-1,key);
    if (ans == -1){
        printf("Element is not present in the array \n");
    }
    else{
        printf("Element is present at index %d",ans);
    }
    
    return 0;
}
