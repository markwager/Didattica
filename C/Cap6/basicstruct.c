#include <stdio.h>

struct point{
    int x; //membro
    int y; //membro
};

/*
questa è una struttura: elenco di dichiarazioni
point è l'etichetta
*/
// 1. Definiamo un Punto 2D (la nostra base per le coordinate)
// Usiamo typedef per non dover scrivere "struct" ogni volta!
typedef struct {
    int x;
    int y;
} Posizione2D;

// 2. Definiamo le statistiche di combattimento
typedef struct {
    int hp_massimi;
    int hp_attuali;
    int attacco;
} Statistiche;

// 3. LA STRUCT ANNIDATA (Il nostro Eroe)
typedef struct {
    char nome[30];
    Posizione2D pos;    // Lo scatolone "Posizione" dentro lo scatolone "Eroe"
    Statistiche stats;  // Lo scatolone "Statistiche" dentro lo scatolone "Eroe"
    char simbolo;       // Il carattere stampato su schermo, es: '@'
} Eroe;

int main(){
    struct point punto;
    punto.x=10;
    punto.y=20;

    printf("%d,%d\n", punto.x, punto.y);

    Eroe giocatore = { 
        "Artorius", 
        {5, 10},        // Inizializza Posizione2D (x=5, y=10)
        {100, 100, 15}, // Inizializza Statistiche
        '@' 
    };

    // Usiamo il PUNTO per navigare nell'annidamento
    printf("L'eroe %s si trova alle coordinate X:%d, Y:%d\n", 
            giocatore.nome, 
            giocatore.pos.x, 
            giocatore.pos.y);
            
    printf("Il mostro colpisce!\n");
    giocatore.stats.hp_attuali -= 20; // Modifichiamo un valore interno
    
    printf("HP rimasti: %d / %d\n", giocatore.stats.hp_attuali, giocatore.stats.hp_massimi);
}