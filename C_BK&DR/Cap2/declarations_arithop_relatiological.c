/*
Si usa const affinchè la variabile non cambi valore
*/

#include <stdio.h>

int stringalen(const char[]);

int main(){
    const double e = 2.71828182845905;
    const char msg[] = "warning: ";
    float a=4;
    float b=3;
    float c=a/b;
    int z=4;
    printf("%f\n",c);
    if(z%2!=0){
        printf("No");
    }
    else{
        printf("Tutto ogay");
    }

    /*
    for (i=0; i < lim-1 && (c=getchar()) != '\n' && c != EOF; ++i){
        s[i] = c;

    }

    for(i = 0; i < lim - 1; i++) {
        
        // Leggo il carattere e controllo se NON è un Invio
        if ((c = getchar()) != '\n') {
            
            // Se non è un invio, controllo se NON è la fine del file
            if (c != EOF) {
                s[i] = c;  // Tutto ok, salvo il carattere nell'array!
            } else {
                break;     // È un EOF! Rompo il ciclo for e scappo fuori.
            }
            
        } else {
            break;         // È un Invio! Rompo il ciclo for e scappo fuori.
        }
    }
        */ //programmi equivalenti

}