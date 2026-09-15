#include <stdio.h>


/*
un errore è quello di creare 10 mostri con array paralleli
// L'INCUBO DEGLI ARRAY PARALLELI (Non farlo mai!)
int hp_mostri[10];
int x_mostri[10];
int y_mostri[10];
char *nomi_mostri[10];

è un incubo!
*/

//raggruppiamo tutto in un unico array di struct!
typedef struct {
    char *nome;
    int hp;
    int x, y;
} Mostro;

Mostro lista_mostri[10]; // 10 mostri perfetti in un solo array!

typedef struct {
    int id;
    char *nome;
    int danno;
} TipoOggetto;


int main(){
        // Creiamo il database globale. Il compilatore conta gli elementi da solo!
    TipoOggetto database_armi[] = {
        {1, "Pugnale di Legno", 2},
        {2, "Spada Corta", 5},
        {3, "Ascia da Battaglia", 12},
        {4, "Spadone Infuocato", 25}
    };

    // Dimensione Totale (80) / Dimensione del Primo Elemento (20) = 4
    int totale_armi = sizeof(database_armi) / sizeof(database_armi[0]);

    // 3. Posso usare il totale per fare un ciclo for perfetto
    for (int i = 0; i < totale_armi; i++) {
        printf("%d. %s (ATK: %d)\n", 
               i+1, 
               database_armi[i].nome, 
               database_armi[i].danno);
    }
}