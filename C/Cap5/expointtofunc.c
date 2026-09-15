#include <stdio.h>

int bevi_pozione(int hp, int (*effetto_segreto)(int)){
    return effetto_segreto(hp);
}

int effetto_cura(int hp){
    printf("Sapore di mela! Le tue ferite si chiudono. (+50 HP)\n");
    return hp+50;
}

int effetto_veleno(int hp){
    printf("Sapore amaro... I tuoi organi bruciano! (-30 HP)\n");
    return hp-30;
}

void inizia_gioco(){
    printf("inizia\n");

}

void mostra_opzioni(){
    printf("opzioni\n");
}

void esci_gioco(){
    printf("esci\n");

}

void apri_forziere(){
    printf("apri cassa!\n");

}

void leggi_cartello(){
    printf("leggi:\n");
}

void accarezza_cane(){
    printf("accarezzi e doggo è felice!\n");

}

int main(){
    void (*azione_attuale)(); //puntatore a funzione

    azione_attuale=apri_forziere;
    printf("hai premuto E\n");
    azione_attuale();

    azione_attuale=accarezza_cane;
    printf("hai premuto E\n");
    azione_attuale();

    void (*scelta_attuale[3])() = {inizia_gioco, mostra_opzioni, esci_gioco};

    int scelta=1;

    scelta_attuale[scelta]();

    int hp=100;
    hp=bevi_pozione(hp, effetto_cura);

}