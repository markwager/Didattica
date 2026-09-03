#include <ctype.h>
#include <stdio.h>

#define MAXLINE 100

double atofs(char s[]);
int getlines(char s[], int lim);

int getlines(char s[], int lim){
    int c, i;
    i = 0;
    while (--lim > 0 && (c=getchar()) != EOF && c != '\n')
        s[i++] = c;
    if (c == '\n')
        s[i++] = c;
    s[i] = '\0';
    return i;
}

/* atof: converte la stringa s in double */
double atofs(char s[])
{
    double val, power;
    int i, sign;
    
    for (i = 0; isspace(s[i]); i++)  /* salta gli spazi bianchi */
        ;
    sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-')
        i++;
    for (val = 0.0; isdigit(s[i]); i++)
        val = 10.0 * val + (s[i] - '0'); /*
        ricorda che l'espressione dentro la parentesi serve a convertire un carattere nel suo intero
        10.0*val serve a spostarsi verso destra
        */
    if (s[i] == '.')
        i++;
    for (power = 1.0; isdigit(s[i]); i++) {
        val = 10.0 * val + (s[i] - '0');
        power *= 10;
    }
    return sign * val / power;
}

int main(){
    char s[MAXLINE];
    double ris=0;
    int c;
    while((c=getlines(s, MAXLINE))>0){
        printf("%.2e\n", ris += atofs(s));
    }
}