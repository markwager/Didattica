#include <stdio.h>

/* Questa funzione riceve un array di puntatori a carattere.
   Nota: scrivere char *playlist[] come parametro è ESATTAMENTE 
   identico a scrivere char **playlist (puntatore a puntatore) */
void stampa_playlist(char **playlist, int num_canzoni){
    for (int i = 0; i < num_canzoni; i++) {
        printf("%d. %s\n", i + 1, playlist[i]);
    }
}

/* Funzione che scambia l'ordine di due canzoni scambiando i puntatori, 
   NON copiando le stringhe! */
void scambia_canzoni(char **playlist, int indice1, int indice2) {
    char *temp; // variabile temporanea che contiene un indirizzo di memoria
    
    // Scambio dei puntatori
    temp = playlist[indice1];
    playlist[indice1] = playlist[indice2];
    playlist[indice2] = temp;
}

int main() {
    // Creiamo un array di 4 puntatori a carattere.
    // Le stringhe vere e proprie sono salvate altrove in memoria.
    // L'array contiene solo i 4 indirizzi di partenza.
    char *mia_playlist[] = {
        "Bohemian Rhapsody - Queen",
        "Shape of You - Ed Sheeran",
        "Blinding Lights - The Weeknd",
        "Hotel California - Eagles"
    };
    
    int totale_canzoni = 4;

    printf("--- PLAYLIST ORIGINALE ---\n");
    stampa_playlist(mia_playlist, totale_canzoni);

    // L'utente vuole spostare "Hotel California" al primo posto, 
    // scambiandola con "Bohemian Rhapsody"
    scambia_canzoni(mia_playlist, 0, 3);

    printf("\n--- PLAYLIST MODIFICATA ---\n");
    stampa_playlist(mia_playlist, totale_canzoni);

}
