/*
Il do while permette di eseguire l'azione almeno una volta
Quindi controlla la condizione while dopo, non prima
*/
#include <stdio.h>

void itoa(int n, char s[]);
void itoanew(int n, char s[]);
void itob(int n, char s[], int b);

void itob(int n, char s[], int b){
    int i, sign, resto;
    if ((sign = n) < 0)  
        n = -n;          
    i = 0;
    do {
        resto=n%b;       
        if(resto<=9)
            s[i++]=resto+'0';
        else
            s[i++]=resto-10+'A';
    } while ((n /= b) > 0);     
    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    reverse(s);
}

void itoanew(int n, char s[]){
    int i, sign;
    unsigned un;
    if ((sign=n)<0)  /* registra il segno */
        un=-n;
    else
        un=n;
              /* rendi n positivo */
    i=0;
    do{       /* genera le cifre in ordine inverso */
        s[i++] = n % 10 + '0';   /* prendi la cifra successiva */
    } while ((n /= 10) > 0);     /* eliminala */
    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    reverse(s);
}

/* itoa: converte n in caratteri in s */
void itoa(int n, char s[]){
    int i, sign;
    if ((sign = n) < 0)  /* registra il segno */
        n = -n;          /* rendi n positivo */
    i = 0;
    do {       /* genera le cifre in ordine inverso */
        s[i++] = n % 10 + '0';   /* prendi la cifra successiva */
    } while ((n /= 10) > 0);     /* eliminala */
    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    reverse(s);
}

int main(){

}