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
    opc = 0;
    m = strlen(pat);
    n = strlen(txt);
    printf("String length of text: %d\n",m);
    printf("String length of pattern: %d\n",m);
    
    /* A loop to slide pat[] one by one */
    for (i = 0; i <= n - m; i++){
        /* For current index i, check for pattern match */
        for(j = 0; j < m; j++){
            // the basic operation is the comparision between characters in the text and the pattern
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
    return 0;
}

