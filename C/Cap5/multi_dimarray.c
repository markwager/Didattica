#include <stdio.h>

// È fondamentale definire le costanti per le dimensioni
#define MAP_WIDTH  6  // Colonne (X)
#define MAP_HEIGHT 5  // Righe   (Y)

// Enum per rendere il codice leggibile
enum TileType { VUOTO, MURO, EROE, TESORO};

/* 
 * LA REGOLA D'ORO DEL C: 
 * Se passi una matrice a una funzione, DEVI specificare quante COLONNE ha.
 * Il numero di righe puoi ometterlo (lasciando la prima quadra vuota).
 */
void disegna_mappa(int mappa[MAP_HEIGHT][MAP_WIDTH]) {
    for (int x = 0; x < MAP_HEIGHT; x++) {
        for (int y = 0; y < MAP_WIDTH; y++) {
            
            // mappa[x][y] accede alla riga 'x' e colonna 'y'
            switch (mappa[x][y]) {
                case MURO:   printf("# "); break;
                case EROE:   printf("@ "); break;
                case TESORO: printf("$ "); break;
                case VUOTO:  printf(". "); break;
            }
        }
        printf("\n"); // A capo alla fine di ogni riga
    }
}

int main() {
    // Inizializziamo la matrice bidimensionale.
    // L'ordine è mappa[X][Y], quindi [Righe][Colonne]
    int livello[MAP_HEIGHT][MAP_WIDTH] = {
        {1, 1, 1, 1, 1, 1},
        {1, 2, 0, 0, 3, 1},
        {1, 0, 1, 1, 0, 1},
        {1, 0, 0, 0, 0, 1},
        {1, 1, 1, 1, 1, 1}
    };

    printf("--- DUNGEON LIVELLO 1 ---\n");
    
    // Passiamo la matrice alla funzione. Passiamo solo il NOME (che è l'indirizzo base)
    disegna_mappa(livello);

}