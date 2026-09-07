#include <stdio.h>

void UsaPozione(int*);
void UsaPozione1(int*);

void UsaPozione(int *vita_eroe) {
    *vita_eroe = *vita_eroe + 50;
}

void UsaPozione1(int *vita_eroe) {
    *vita_eroe = *vita_eroe + 50;
}

int main1() {
    int hp_giocatore = 20;
    int *p_hp;
    p_hp=&hp_giocatore;
    UsaPozione1(p_hp);
    printf("%d\n", *p_hp);
}

int main(){
    int hp_giocatore = 20;
    UsaPozione(&hp_giocatore);
    printf("%d\n", hp_giocatore);
    int mappa[100];
    // ... mappa viene riempita ...
    int *p_eroe = &mappa[50]; // L'eroe è al centro esatto
    printf("%d\n", *(p_eroe+1)); //guardo val a dx, non mi muovo 
    printf("%d\n", *(p_eroe-1)); //guardo il val a sx, non mi muovo
    //alla casella 0 segmentation fault se p_eroe--
    int mappa_dungeon[100] = { /* ... 99 numeri a caso ... e un 9 in mezzo */ };
    int *p_scan = mappa_dungeon; // Parcheggio la macchina all'inizio della mappa
    int i = 0;

    // Voglio controllare tutte e 100 le caselle usando un ciclo while
    while (i < 100) {
        
        if(*(p_scan++)==9) //mi sposto
            break;        
        i++;
    }
}

/*
void UsaPozione(int vita_eroe) {
    vita_eroe = vita_eroe + 50;
}

int main() {
    int hp_giocatore = 20;
    UsaPozione(hp_giocatore);
    // hp_giocatore qui è ancora 20! Il giocatore è furioso.
}
*/
//questo è sbagliato