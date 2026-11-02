#include "gioco.h"

void MuoviNemico() {
    // Conosce player_x e punteggio perché ha incluso gioco.h
    if(player_x > 105) {
        punteggio -= 5;
    }
}