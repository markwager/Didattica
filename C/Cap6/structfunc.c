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

int main(){
    Vector2 spawn_fulvio=crea_vettore(11.2,12.1);
}