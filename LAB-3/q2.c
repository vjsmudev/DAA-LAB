/*Write a program to implement brute-force string matching. Analyze its time
efficiency.*/

#include<stdio.h>
#include<string.h>

void search(char* pat, char* txt){
    int m = strlen(pat);
    int n = strlen(txt);
    int opc = 0;
//loop to slide past the pattern one by one
// n-m maximum possible starting position of the string without exceeding the end of the text string
    for (int i = 0; i < n - m; i++){
       
        int j;

        //For current index i check for the pattern match
        for (j = 0; j < m; j++){
             opc++;
//Checks if the current character in the  txt[i+j] is not equal to the current character in the text string 

/*For example, if the pattern string is "abc" and the text string is "defgabcxyz",
 then the loop would iterate through 
 starting positions 0, 1, 2, 3, and 4,
  because starting at position 5 would 
  only leave the characters "a", "b", and "c" outside the end of the text string.*/
            if (txt[i+j] != pat[j]){
                break;
            }
        }
        /*This if statement checks if the inner loop completed iterating 
        through the entire string pattern without finding mismatchse*/
            if (j == m){
                printf("Pattern found at index %d",i);
            }
        }
        printf("Operation count:%d\n",opc);
    }

    int main(){
        char txt[100];
        char pat[100];
        
        printf("Enter the text string:\n");
        scanf(" %[^\n]s ", txt);

        printf("Enter the pattern string:\n");
        scanf(" %[^\n]s ", pat);

        search(pat,txt);
        return 0;
    }
