// gioco.h
#ifndef GIOCO_H   // "Include Guard": evita che il file venga letto due volte!
#define GIOCO_H

// 1. Dichiarazioni delle variabili (Nessuna memoria creata, solo 'extern')
extern int punteggio;
extern int player_x;

// 2. Prototipi delle funzioni
void MuoviGiocatore();
void MuoviNemico();

#endif