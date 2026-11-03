#include <stdio.h> //libreria di base

int main(void){ //funzione che ritorna un intero e non accetta argomenti

    printf("ciao pippo\n"); //stampa e vai a capo
    printf("prova...\n1.\n2..\n3...\n");

    int a=3;
    int b=5;
    int sum=a+b;
    int diff=a-b;
    printf("La somma tra %d e %d è %d\n", a,b,sum); //si  può usare anche %i
    printf("La differenza tra %d e %d è %d\n", a,b,diff); //si  può usare anche %i


    
    return 0;
}