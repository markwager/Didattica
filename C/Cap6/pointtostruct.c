#include <stdio.h>


typedef struct {
    char *nome;
    int hp;
    int x, y;
} Mostro;

Mostro lista_mostri[10]={
    {"Caccone", 111, 1, 2},
    {"Andrea", 50, 2, 3},
    {"Gianni", 1200, 3, 4},
    {"Jane", 104, 4, 5}
};

int main(){

    /*anzichè creare un for per visualizzare i membri in questo modo:
    for (int i = 0; i < TOTALE; i++) { bestiario[i].hp = 0; }
    creiamo un puntatore
    */

    Mostro *p;
    for(p=lista_mostri; p<lista_mostri+10; p++){
        printf("Mostro: %s\n", p->nome);
    }
}