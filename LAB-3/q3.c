/*Write a program to implement solution to partition problem using brute-force
technique and analyze its time efficiency theoretically. A partition problem takes
a set of numbers and finds two disjoint sets such that the sum of the elements in
the first set is equal to the second set. [Hint: You may generate power set]*/


/* 1.Calculate the sum of the array. If the sum is odd, 
there can not be two subsets with an equal sum, 
so return false. 
2. If the sum of the array elements is even, calculate sum/2 
and find a subset of the array with a sum equal to sum/2. */

/*1.First, check if the sum of the elements is even or not
2.After checking, call the recursive function isSubsetSum with parameters as input array, array size, and sum/2
    -If the sum is equal to zero then return true (Base case)
    -If n is equal to 0 and sum is not equal to zero then return false (Base case)
    -Check if the value of the last element is greater than the remaining sum then call this function again by removing the last element
    else call this function again for both the cases stated above and return true, if anyone of them returns true
3)Print the answer*/

#include<stdio.h>


int checkSubsetSum(int arr[], int n, int sum){
    if(sum == 0){
        return 1;
    }

    if(n == 0 && sum != 0){
        return 0;
    }

    //if last ele > sum, call the func to remove the last ele

    if (arr[n - 1] > sum){
        return checkSubsetSum(arr, n - 1, sum);
    }
    
    /*else check if the sum can be obtained by:
    -including the last ele
    -excluding the last ele*/

    return checkSubsetSum(arr,n-1,sum) || checkSubsetSum(arr,n-1,sum - arr[n-1]);
}

int findPartition(int arr[], int n){
    //find the sum of all ele in arr
    int opc = 0;
    int sum = 0;
    for (int i = 0; i < n; i++){
        sum = sum + arr[i];
    }
    
    /*check if sum is odd, there cannot be 2 subsets 
    with equal subsets with equal sum*/

    if(sum % 2 != 0){
        return 0;
    }
    opc++;
    printf("Operation count: %d\n",opc);

    //check if there is a subset with sum equal to half of total sum
    return checkSubsetSum(arr, n, sum/2);
}

void display(int arr[], int n){
    printf("Displaying array:\n");
    for (int i = 0; i < n; i++){
        printf("  %d ",arr[i]);
    }
}

int main(){
    int arr[20];
    int n;
    printf("Enter the size of the array:\n");
    scanf("%d",&n);
    printf("Enter the elements in the array:\n");
    
    for (int i = 0; i < n; i++){
        scanf("%d",&arr[i]);
    }

    display(arr,n);

    printf("\n");

    if (findPartition(arr,n) == 1){
        printf("Can be divided into subsets of equal sum\n");
    }

    else{
         printf("Cannot be divided into subsets of equal sum\n");
    }

    return 0;
}