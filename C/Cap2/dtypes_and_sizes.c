/*
Tipi di dati:
char: un singolo byte in grado di contenere solo un carattere
int: intero che riflette la grandezze in base al tipo di macchina
float: per i nunmeri decimali
double: per i decimali più grandi o precisi

Combinazioni per num interi:
short: intero corto
int: intero normale
long: intero lungo
si possono usare con questi signed e unsigned

Combinazioni per caratteri:
char: char normale
si possono usare signed e unsigned

Combinazioni per num float:
float: float a singola precisione
double: doppia precisione
long double: doppia precisione a precisione estesa
*/


#include <stdio.h>
#include <limits.h> //definisce costanti per la grandezza dei tipi interi
#include <float.h> //definisce costanti per la grandezza dei tipi float

int main(){

    printf("%d\n",CHAR_BIT);
    
}