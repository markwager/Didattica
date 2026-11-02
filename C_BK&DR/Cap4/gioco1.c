#include <stdio.h>
#include "gioco.h" // BOOM! Includendo questo, includi in automatico anche giocatore.h e nemico.h!

// Creazione effettiva della memoria per le variabili extern
int punteggio = 0;
int player_x = 100;

int main() {
    printf("Inizio! X: %d, Punti: %d\n", player_x, punteggio);
    
    // Il main conosce queste funzioni perché gioco.h le ha importate!
    MuoviGiocatore();
    MuoviNemico();
    
    printf("Fine! X: %d, Punti: %d\n", player_x, punteggio);
    return 0;
}