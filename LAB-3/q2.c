/*Write a program to implement brute-force string matching. Analyze its time
efficiency.*/
#include<stdio.h>
#include<string.h>

int main(){
    char txt[50];
    char pat[50];
    printf("Enter the text:\n");
    gets(txt);
    printf("Enter the pattern text:\n");
    gets(txt);
    int m,n,opc,j,i;
    m = strlen(pat);
    n = strlen(txt);
    
    for (i = 0; i <= n - m; i++){
        
        for(j = 0; j < m; j++){
            opc++;
            if(txt[i + j] != pat[j]){
                break;
            }
        }
        if(j == m){
            printf("Pattern found at index %d\n",i);
        }
        else{
            printf("Operation count: %d\n",opc);
        }
    }   
}

