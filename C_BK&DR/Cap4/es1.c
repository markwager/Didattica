/*
Esempio molto primitivo di comunicazione tra tre file.c con variabili
var extern che si dovrebbero ripetere troppo spesso--> sol funzionante ma ripetitiva
ricorda la differenza tra definire e dichiarare con extern: con la prima intendiamo
creare un posto in RAM per le variabili, la seconda dice di usare il nome della stessa
variabile previa "extern" per dire "hey fidati esiste già una variabile chiamata così in un altro file"
*/
#include <stdio.h>

// 1. DEFINIZIONE DELLE VARIABILI ESTERNE (Globali)
// Vengono create nella RAM una volta sola.
int punteggio = 0;
int player_x = 100;

// Prototipi delle funzioni che stanno negli altri file
void MuoviGiocatore();
void MuoviNemico();

int main() {
    printf("Inizio Gioco! Player X: %d\n", player_x);
    
    // Il Game Loop
    MuoviGiocatore();
    MuoviNemico();
    
    printf("Fine turno! Player X: %d, Punteggio: %d\n", player_x, punteggio);
    return 0;
}