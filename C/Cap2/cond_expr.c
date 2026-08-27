#include <stdio.h>

int lower(int); //versione alternativa di lower

/* lower: converte il carattere c in minuscolo; funziona solo con codifica ASCII */
int lower(int c)
{
    c=(c >= 'A' && c <= 'Z') ? c + 'a' - 'A' : c;
    return c;
}

int main(){

    int a=5;
    int b=4;
    int z;

    if (a > b)
        z = a;
    else
        z = b;

    z = (a > b) ? a : b;    /* z = max(a, b) */

    //sono equivalenti: se a>b --> z=a else z=b
}