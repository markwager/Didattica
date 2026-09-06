/*
Un puntatore è una variabile che contiene l'indirizzo di una variabile.
Puntatori e array sono strettamente legati.
La memoria è organizzata in questo modo in una macchina:
array di celle numerate/indirizzate che possono essere manipolate a gruppi o individualmente.
Un puntatore è un gruppo di celle che può archiviare un indirizzo-> es: c è un char e p un puntatore che punta a c.
Si rappresenta ciò con p=&c;
*/

#include <stdio.h>

void swap(int, int);
void swapnew(int*, int*);


void swapnew(int *px, int *py){ //questo invece punta direttamente alle var nel main e poi muiono i puntatori come arg della funzione
    int temp;
    temp=*px;
    *px=*py;
    *py=temp;
}

void swap(int x, int y){ /* SBAGLIATO perchè le variabili passate in input sono solo fotocopie di quelle nel main */
    int temp;
    temp = x;
    x = y;
    y = temp;
}


int main(){

    int x=1, y=2, z[10];
    int *ip; /* ip is a pointer to int */
    ip=&x; /* ip now points to x */
    y=*ip; /* y is now 1 */
    *ip=0; /* x is now 0 */
    ip=&z[0]; /* ip now points to z[0] */
    *ip+=10; //incrementa ip di 10
    int *iq;
    iq=ip; //iq punta a ciò a cui ip sta puntando

    int a=10;
    int b=5;
    int *px;
    int *py;
    px=&a;
    py=&b;
    printf("%d,%d\n", a,b);
    swap(x,y);
    printf("%d,%d\n", a,b);
    //è errato scambiare in questo modo il valore delle variabili

    swapnew(px,py);
    printf("%d,%d\n", *px,*py);

}