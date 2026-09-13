#include <stdio.h>

// I tuoi ID nel gioco
enum ID_Nemico { 
    NESSUNO = 0, 
    GOBLIN = 1, 
    ORCO = 2, 
    DRAGO_ROSSO = 3 
};

const char *ottieni_nome_nemico(int id) {
    // Array statico di puntatori (il compilatore conta 4 elementi e crea sto array 1! volta)
    static const char *nomi_nemici[] = {
        "Entita Sconosciuta", // Indice 0
        "Goblin",             // Indice 1
        "Orco",               // Indice 2
        "Drago Rosso"         // Indice 3
    }; //questo è diverso da static const char nomi_nemici[][] --> questo occuperebbe too much spazio
    
    // Controlliamo che l'ID non sia sballato (es. id negativo o > 3)
    if (id < 0 || id > 3) {
        return nomi_nemici[0];
    }
    
    return nomi_nemici[id];
}

int main() {
    int mostro_attuale = ORCO; // Nel gioco vale 2
    
    // Al momento di stampare l'interfaccia (o il log dei combattimenti)
    printf("Un %s ti sbarra la strada!\n", ottieni_nome_nemico(mostro_attuale));
    
    // Se c'è un bug e passo un ID inesistente:
    printf("Hai evocato: %s\n", ottieni_nome_nemico(99)); 

    return 0;
}