// 4. DICHIARAZIONI EXTERN MULTIPLE
// Anche questo file si "aggancia" alle variabili nate nel main.
extern int player_x;
extern int punteggio;

void MuoviNemico() {
    // Il nemico legge la posizione del giocatore
    if (player_x > 100) {
        // Il nemico modifica il punteggio globale
        punteggio = punteggio - 10; 
    }
}