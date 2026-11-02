/*
Il C fornisce sei operatori per la manipolazione dei bit che sono
applicabili a char, int, short, long sia signed che unsigned

& AND bit a bit (bitwise AND)

| OR bit a bit inclusivo

^ OR bit a bit esclusivo (XOR)

<< scorrimento a sinistra (left shift)

>> scorrimento a destra (right shift)

~ complemento a uno (unario)
*/

#include <stdio.h>

unsigned getbits(unsigned, int, int);
unsigned setbits(unsigned, int, int, unsigned); //ritorna x con n bit cambiati dalla pos p prendendo gli n meno significativi di y
unsigned invert(unsigned, int, int); //restituisce x con gli n bit che iniziano alla posizione p invertiti
unsigned rightrot(unsigned, int); //rotazione verso destra di n pos di un numero x


unsigned rightrot(unsigned x, int n) {
    unsigned rbit; // Memorizza il bit che sta per cadere a destra
    
    // Ripetiamo l'operazione n volte
    while (n > 0) {
        
        // 1. Salviamo il bit all'estrema destra (prima che cada)
        rbit = x & 1;
        
        // 2. Facciamo scorrere tutto verso destra di 1 posizione
        x = x >> 1;
        
        // 3. Se il bit che è caduto era un 1, dobbiamo accenderlo a sinistra
        if (rbit == 1) {
            // Creiamo la maschera per il bit più a sinistra (Most Significant Bit)
            unsigned all_ones = ~0;
            unsigned msb_mask = ~(all_ones >> 1);
            
            // Incolliamo l'1 all'estrema sinistra con l'OR
            x = x | msb_mask;
        }
        
        n--; // Passiamo alla prossima rotazione
    }
    
    return x;
}

unsigned invert(unsigned x, int p, int n){
    return x^(~(~0<<n)<<(p+1-n));

}

unsigned setbits(unsigned x, int p, int n, unsigned y){
    int estract1=getbits(y, n-1, n); //ottengo gli n bit più a destra di y
    int y_shift=estract1<<(p+1-n); //shifto della giusta posizione verso sx il numero y
    int mask= ~(~(~0<<n)<<(p+1-n)); //creo la maschera per x: mask nelle giuste posizioni
    int x_hole=x&mask; //buco x nelle giuste posizioni
    return x_hole|y_shift;
}

/* getbits: ottiene n bit dalla posizione p da un numero decimale x*/
unsigned getbits(unsigned x, int p, int n)
{
    return (x >> (p+1-n)) & ~(~0 << n);
    /*
    la prima parte consiste nello shiftare verso dx i bit interessati
    la seconda invece crea la mask

    */
}

int main(){

    int a=5; // In binario: 00000101
    int b=3; // In binario: 00000011
    printf("%d\n", a&b);
    printf("%d\n", a|b);
    printf("%d\n", a&&b); //se a e b allora vero
    printf("%d\n", ~a);
    printf("%d\n", b<<2); //shifting di 2 bit a sx

    unsigned res1=getbits(10,4,3);
    printf("%d\n", res1);

    unsigned res2=setbits(10,4,3,5);
    printf("%d\n", res2);

    unsigned res3=invert(10,4,3);
    printf("%d\n", res3);

}