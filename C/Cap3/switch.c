/*
Il costrutto switch con i suoi case si comporta proprio come
gli if, else if ed else. Si mette un break dopo un'azione dentro il case
per evitare che continui a leggere i successivi case sebbene se ne soddisfi uno precedente
*/

#include <stdio.h>

void escape(char s[], char t[]);

void escape(char s[], char t[]){
    int i=0;
    int j=0;
    while(t[i]!='\0'){
        switch(t[i]){
            case '\n':
                s[j]='\\';
                j++;
                s[j]='n';
                j++;
                break;
            case '\t':
                s[j]='\\';
                j++;
                s[j]='t';
                j++;
                break;
            default:
                s[j]=t[i];
                j++;
                break;
        }
        i++;

    }

    s[j]='\0';

    printf("%s",s);
}

int main(){ /* count digits, white space, others */

    int c, i, nwhite, nother, ndigit[10];
    
    nwhite = nother = 0;
    
    for (i = 0; i < 10; i++)
        ndigit[i] = 0;
        
    while ((c = getchar()) != EOF) {
        switch (c) {
            case '0': case '1': case '2': case '3': case '4':
            case '5': case '6': case '7': case '8': case '9':
                ndigit[c-'0']++;
                break;
            case ' ':
            case '\n':
            case '\t':
                nwhite++;
                break;
            default:
                nother++;
                break;
        }
    }
    
    printf("digits =");
    for (i = 0; i < 10; i++)
        printf(" %d", ndigit[i]);
        
    printf(", white space = %d, other = %d\n", nwhite, nother);
    
}