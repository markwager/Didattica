#include <stdio.h>
#include <string.h>
#include <stdbool.h>
// #include "raylib.h" // (Immagina che ci sia)

// Funzione principale VERA
int main(int argc, char *argv[]) { //argc:conteggio argomenti
    //*argv[]: array di puntatori
    
    // Variabili di configurazione del gioco di default
    bool modalita_debug = false;
    bool salta_intro = false;
    int livello_partenza = 1;

    // SCANSIONE DEGLI ARGOMENTI DI AVVIO
    // Partiamo da i=1 perché argv[0] è il nome del gioco (.exe)
    for (int i = 1; i < argc; i++) {
        
        // Se l'utente ha avviato il gioco con "-debug"
        if (strcmp(argv[i], "-debug") == 0) {
            modalita_debug = true;
            printf("ATTENZIONE: Modalita' Sviluppatore ATTIVATA!\n");
        }
        
        // Se ha avviato con "-skip"
        else if (strcmp(argv[i], "-skip") == 0) {
            salta_intro = true;
        }
        
        // Se ha avviato con "-level" (esempio: -level 5)
        else if (strcmp(argv[i], "-level") == 0) {
            // Controlliamo che ci sia un numero DOPO la parola "-level"
            if (i + 1 < argc) {
                // Leggiamo la parola successiva e la forziamo a numero (lo vedrai in futuro)
                // livello_partenza = atoi(argv[i + 1]); 
                printf("Caricamento forzato del livello da riga di comando.\n");
            }
        }
    }

    // --- INIZIO VERO E PROPRIO DEL GIOCO ---
    // InitWindow(800, 600, "Il mio Roguelike");
    
    if (salta_intro == false) {
        // Mostra il logo di Raylib e il tuo logo
        printf("Mostro il video introduttivo...\n");
    }

    if (modalita_debug) {
        // Disegna gli hitbox rossi attorno ai nemici, datti HP infiniti, ecc.
        printf("L'eroe è invincibile per i test.\n");
    }

    // Ciclo di gioco (while !WindowShouldClose()...)
}