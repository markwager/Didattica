#include <stdio.h>
#include "esempio.h" // Incolla in automatico gli extern e i prototipi

int punteggio = 0; // Qui CREIAMO fisicamente la memoria
int player_x = 100;

int main(){
    printf("Inizio Gioco! Player X: %d\n", player_x);
    
    // Il Game Loop
    MuoviGiocatore();
    MuoviNemico();
    
    printf("Fine turno! Player X: %d, Punteggio: %d\n", player_x, punteggio);
    return 0;
}