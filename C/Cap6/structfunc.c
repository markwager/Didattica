#include <stdio.h>

typedef struct{
    float x;
    float y;
}Vector2;

Vector2 crea_vettore(float x, float y){
    Vector2 temp;
    temp.x=x;
    temp.y=y;
    return temp; //restituisce intero struct
}

Vector2 add_mov(Vector2 pos, Vector2 vel){
    pos.x+=vel.x;
    pos.y+=vel.y;

    return pos;
}

typedef struct {
    Vector2 in_alto_a_sinistra;
    Vector2 in_basso_a_destra;
} Hitbox;

// La telecamera o l'attacco stanno colpendo la hitbox del nemico?
int collisione(Vector2 colpo, Hitbox scatola_nemico) {
    // Usiamo il punto (.) per navigare nell'annidamento
    return colpo.x >= scatola_nemico.in_alto_a_sinistra.x && 
           colpo.x <= scatola_nemico.in_basso_a_destra.x &&
           colpo.y >= scatola_nemico.in_alto_a_sinistra.y && 
           colpo.y <= scatola_nemico.in_basso_a_destra.y;
}

typedef struct{
    char nome[50];
    int hp;
    int mp;
    //altri vari KB di roba
}Boss;

void cura_boss(Boss *b){ //puntiamo all'indirizzo dell astruct anzichè fare una fotocopia-->+ efficiente
    b->hp+=100;
}

int main(){
    Vector2 spawn_fulvio=crea_vettore(11.2,12.1);
    Vector2 pos_giocatore = {5.0f, 5.0f};
    Vector2 camminata_destra = {1.0f, 0.0f};
    
    // Devo SOVRASCRIVERE la posizione originale con il risultato della funzione
    pos_giocatore = add_mov(pos_giocatore, camminata_destra);

    Boss drago={"Gianluca", 200, 20};

    cura_boss(&drago);
}