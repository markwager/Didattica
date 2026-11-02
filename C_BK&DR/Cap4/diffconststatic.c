/*
const int MAX_OGGETTI_INVENTARIO = 20;

void RaccogliOggetto() {
    // MAX_OGGETTI_INVENTARIO = 21; // ERRORE! Il compilatore ti blocca istantaneamente.
}
*/
//rende il valore di sola lettura, previene modifiche accidentali

/*
// in player.c
static int velocita_di_corsa = 5; // Privata! Solo player.c sa che esiste.

// Puoi modificarla tranquillamente:
void PrendiPowerUp() {
    velocita_di_corsa += 2; // Funziona! Non è const.
}
*/
//static come variabile fuori da funzioni nello stesso file fa  nascondere il suo uso ad altri file

/*
void GeneraNemico() {
    // Nasce a 0 solo la primissima volta. Poi sopravvive di nascosto!
    static int contatore_mostri = 0; 

    contatore_mostri++; // Modificabile!
    printf("Hai spawnato il mostro numero: %d\n", contatore_mostri);
}
// Chiami la funzione 3 volte? Stamperà 1, poi 2, poi 3!
// Senza 'static', stamperebbe 1, 1, 1 (perché nascerebbe e morirebbe ogni volta).
*/
//static dentro una funzione vuol dire di tenerla viva, non ucciderla alla fine della funzione