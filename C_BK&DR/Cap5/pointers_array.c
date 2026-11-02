/*
Forte relazione tra puntatori ed array: gli array sono
in realtà puntatori
*/


int main(){

    int a[10]; //definisce array di 10 elementi da 0 a 9
    //a[i] si riferisce all'i-esimo elemento di a
    int *pa;
    pa=&a[0]; //puntatore pa punta alla prima cella dell'array a
    //si può scrivere anche come pa=a;
    int x=*pa; //assegna ad x il valore a cui punta pa
    x=*(pa+1); //punta ora al valore della cella successiva: a[1]
    pa++; //punta a successiva cella (se pa fosse stato un array, allora sarebbe stata un'azioen illegale)
    //char s[] e char *s sono la stessa cosa
    //f(&a[2]) passa alla funzione f una parte dell'array
    //f(int arr[])<-->f(int *arr)
    
}