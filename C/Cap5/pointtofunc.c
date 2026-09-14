/*
Una funzione in C non è una variabile, ma un blocco di codice ed è possibile definire
puntatori a funzioni,i quali possono essere assegnati, inseriti
in array, passati a funzioni, restituiti da funzioni, e così via.
Fino ad ora hai visto char * (punta a un testo) o int * (punta a un numero).
Il void * è un puntatore "nudo e crudo". Significa: "In questo indirizzo di memoria c'è qualcosa, ma non ti dico cos'è".


Un puntatore a funzione non è altro che una variabile che salva l'indirizzo di una funzione.
Pensa al tasto "A" del joypad. Il tasto "A" di per sé non fa nulla. È un "puntatore vuoto".

    Se stai esplorando, assegni al tasto "A" la funzione salta().

    Se stai parlando con un NPC, assegni al tasto "A" la funzione leggi_dialogo().

    Se sei nei menu, assegni al tasto "A" la funzione conferma_scelta().

Quando premi il tasto, il gioco non fa mille if. Esegue semplicemente qualsiasi funzione sia attualmente collegata a quel tasto.
*/

//Immagina di programmare l'attacco del tuo eroe. Hai tre armi diverse.

#include <stdio.h>

int applica_veleno(int hp_attuali) {
    printf("Il veleno brucia! (-5 HP)\n");
    return hp_attuali - 5;
}

int applica_rigenerazione(int hp_attuali) {
    printf("Le ferite si rimarginano! (+5 HP)\n");
    return hp_attuali + 5;
}

int arma_attuale=1;

void usa_spada() {
    printf("Fai un fendente con la spada! (Danno ravvicinato)\n");
}

void usa_arco() {
    printf("Scocchi una freccia! (Danno a distanza)\n");
}

void usa_bacchetta() {
    printf("Lanci una palla di fuoco! (Danno magico)\n");
}

//Dovresti salvare una variabile (es. int arma_attuale = 1;) e ogni volta che il giocatore preme il tasto d'attacco fare questo scempio:
int main1(){
    if (arma_attuale == 1){
    usa_spada();
    }
    else if (arma_attuale == 2){
    usa_arco();
    }
    else if (arma_attuale == 3){
    usa_bacchetta();
    }
}

int main() {
    // 1. Dichiaro il mio puntatore a funzione
    void (*attacco_corrente)();

    // 2. Il giocatore raccoglie un arco. 
    // Copio l'indirizzo della funzione 'usa_arco' dentro il mio puntatore!
    // (Nota: non metto le () dopo usa_arco, perché NON voglio eseguirla ora, 
    // voglio solo dirgli DOVE si trova!)
    attacco_corrente = usa_arco;

    printf("Hai premuto il tasto attacco:\n");
    // 3. Eseguo la funzione nascosta nel puntatore (basta aggiungere le parentesi)
    attacco_corrente(); 

    // 4. Il giocatore cambia arma e prende la Spada
    attacco_corrente = usa_spada;

    printf("\nHai premuto il tasto attacco:\n");
    // Eseguo DI NUOVO la stessa identica riga di codice, ma farà una cosa diversa!
    attacco_corrente();

    int hp_giocatore = 100;
    
    // Dichiaro il puntatore: "restituisce int, si chiama 'effetto_status', prende un int"
    int (*effetto_status)(int); 
    
    // Un mostro ti morde e ti avvelena!
    effetto_status = applica_veleno;
    
    // Fine del turno: applico l'effetto
    hp_giocatore = effetto_status(hp_giocatore);
    
    printf("HP rimasti: %d\n", hp_giocatore);
}