// 2. DICHIARAZIONE EXTERN
// Diciamo al compilatore: "Non creare una nuova scatola. 
// Fidati, player_x esiste già in un altro file (nel main.c)".
extern int player_x;

void MuoviGiocatore() {
    // 3. SCOPE LOCALE (Variabile automatica)
    // Questa variabile 'velocita' nasce ora e MUORE alla fine di questa funzione.
    // Nessun altro file potrà mai leggerla.
    int velocita = 5; 
    
    player_x = player_x + velocita; 
}