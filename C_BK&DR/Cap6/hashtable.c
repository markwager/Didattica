#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define GRAND_TABELLA 101 // Un numero primo riduce le collisioni

// 1. Il Nodo della nostra Hash Table (Identico al K&R)
typedef struct NodoMostro {
    char *nome_mostro;    // Es: "Drago"
    int hp_base;          // I dati del mostro
    
    struct NodoMostro *prossimo; // Per gestire le collisioni!
} NodoMostro;

// L'Array di puntatori (La Hash Table vera e propria)
NodoMostro *tabella_mostri[GRAND_TABELLA];

// 2. Finta funzione Hash (trasforma "Drago" in un numero da 0 a 100)
unsigned int calcola_hash(char *nome) {
    unsigned int valore = 0;
    for (int i = 0; nome[i] != '\0'; i++) {
        valore = valore + nome[i]; // Somma i valori delle lettere
    }
    return valore % GRAND_TABELLA; // Assicura che non superi 100
}

// 3. LA RICERCA ISTANTANEA (L'equivalente di 'lookup')
NodoMostro *cerca_mostro(char *nome_cercato) {
    // A. Trovo il numero magico! Non devo scorrere tutta la tabella.
    unsigned int indice = calcola_hash(nome_cercato);
    
    // B. Uso l'idioma standard del C per scorrere la Linked List in quello slot
    NodoMostro *corrente;
    for (corrente = tabella_mostri[indice]; corrente != NULL; corrente = corrente->prossimo) {
        
        // Se trovo il nome esatto, restituisco lo scatolone!
        if (strcmp(nome_cercato, corrente->nome_mostro) == 0) {
            return corrente;
        }
    }
    
    return NULL; // Mostro non trovato!
}