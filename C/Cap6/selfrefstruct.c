#include <stdio.h>
#include <stdlib.h> // Serve per malloc()

typedef struct NodoOggetto{
    char *nome;
    int danno;

    struct NodoOggetto *prossimo;
}NodoOggetto; //lista conc

typedef struct Abilita {
    char *nome;
    int livello_richiesto;
    
    // Invece di un solo 'prossimo', abbiamo due bivi!
    struct Abilita *evoluzione_sinistra;
    struct Abilita *evoluzione_destra;
} Abilita; //alb delle abilità

int main(){
    NodoOggetto *spada=malloc(sizeof(NodoOggetto));
    spada->nome="Peppina";
    spada->danno=100;

    NodoOggetto *ascia=malloc(sizeof(NodoOggetto));
    ascia->nome="Gigi";
    ascia->danno=180;

    spada->prossimo=ascia;
    ascia->prossimo=NULL;

    NodoOggetto *corrente=spada;

    while(corrente!=NULL){
        printf("- %s\n", corrente->nome);
        corrente=corrente->prossimo;
    }

    free(spada);
    free(ascia);

}