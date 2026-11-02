#include <stdio.h>
#define MAXLINE 1000 /* lunghezza massima della riga di input */

int getlines(char line[], int max);
int strindex(char source[], char searchfor[]);

char pattern[] = "ould"; /* pattern da cercare */

/* trova tutte le righe che corrispondono al pattern */
int main(){

    char line[MAXLINE];
    int found = 0;
    
    while (getlines(line, MAXLINE) > 0)
        if (strindex(line, pattern) >= 0) {
            printf("%s", line);
            found++;
        }
    printf("%d\n",found);
}

/* getline: ottiene la riga in s, restituisce la lunghezza */
int getlines(char s[], int lim)
{
    int c, i;
    i = 0;
    while (--lim > 0 && (c=getchar()) != EOF && c != '\n')
        s[i++] = c;
    if (c == '\n')
        s[i++] = c;
    s[i] = '\0';
    return i;
}

int strindex(char s[], char t[]) {
    int i, j, k;

    for (i = 0; s[i] != '\0'; i++) {
        
        
        j = i; 
        k = 0; 
        

        while (t[k] != '\0' && s[j] == t[k]) {
            j++;
            k++;
        }
        
        if (k > 0 && t[k] == '\0') {
            return i; // Restituiamo l'indice di partenza
        }
    }
    
    return -1;
}