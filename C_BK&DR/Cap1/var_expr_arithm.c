/*
Questo programma mostra l'uso di espressioni aritmetiche in C.
Questo programma usa la formula C=(5/9)(F-32)

*/

#include <stdio.h>

void conv();

void conv(){
    float celsius;
    float lower=0;
    float upper=300;
    float step=20;

    printf("\n");
    
    while(lower<=upper){
        celsius=(5.0/9.0)*(lower-32.0); //se facessi prima 5/9 il risultato sarebbe 0 per via di int che taglia la parte decimale
        //facendo prima la moltiplicazione e poi la divisione ottengo il risultato corretto
        printf("%3.0f %6.1f\n", lower, celsius); //print migliore perchè così le righe sono ben allineate: assegna la larghezza coi numeri 3 e 6 e mostrano 0 e 1 numeri dopo la virgola
        //printf("%d\t%d\n",lower,celsius); //printa fahr (tab) celsius (a capo)
        lower=lower+step;
    }
}

int main(){

    int celsius;
    int lower=0;
    int upper=300;
    int step=20;
    
    while(lower<=upper){
        celsius=5*(lower-32)/9; //se facessi prima 5/9 il risultato sarebbe 0 per via di int che taglia la parte decimale
        //facendo prima la moltiplicazione e poi la divisione ottengo il risultato corretto
        printf("%3d %6d\n", lower, celsius); //print migliore perchè così le righe sono ben allineate: assegna la larghezza coi numeri 3 e 6
        //printf("%d\t%d\n",lower,celsius); //printa fahr (tab) celsius (a capo)
        lower=lower+step;
    }

    conv();

}

/*
oltre ad int ci sono anche float, char (un singolo byte),
short (piccolo int), long (lungo int) e double (float doppiamente preciso)


*/