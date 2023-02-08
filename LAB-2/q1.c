/*Write a program to find GCD using consecutive integer checking method and
analyze its time efficiency.*/
#include<stdio.h>

int smallest(int a, int b){
    if(a > b){
        return a;
    }
    else return b;
}

int CalcGcd(int m,int n){
    int min = smallest(m,n);
    while (1){
        if(m % min == 0 && n % min == 0){
            return min;
        }
        min--;
    }
}

int main(){
    int m,n,ans;
    printf("Enter the first number:\n");
    scanf("%d",&m);
    printf("Enter the second number:\n");
    scanf("%d",&n);
    ans = CalcGcd(m,n);
    printf("The gcd(%d, %d) = %d",m,n,ans);
    return 0;
}
