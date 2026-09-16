/*perchè i puntatori?
1)Prestazioni: quando si passa una struct o una variabile in una funzione, il C fa una fotocopia dei dati
Quindi senza puntatori il gioco laggerebbe tanto, ma coi puntatori si passa la posizione della struct/var in ram

2)Mutabilità: le var normali passate alle funzioni sono isolate, le funzioni lavorano su cloni.
Senza puntatoir, se volessimo curare hp del giocatore, non si riusciremmo!
Ma coi punattori sì

3)Sopravvivenza: le var normali nelle funzioni muoiono.
Senza puntatori, si crea una struct normale di un oggetto. Ma quando finisce la funzione, quell'ogg si distrugge
Coi puntatori non succede, al momento del bisogno facciamo free

*/


/*



L BIGNAMI DI K&R (Capitoli 5 e 6) - Uso Pratico nel Game Design

Capitolo 5.1 - 5.4: Puntatori Base (& e *)

    Regola d'Oro: & prende l'indirizzo. * apre la scatola per leggere o modificare il valore.

    Uso Pratico (Game Design): Passaggio per Riferimento. Serve per modificare i veri HP del giocatore, invece di curare una sua "fotocopia" temporanea che andrà persa.

Capitolo 5.5 - 5.9: Aritmetica dei Puntatori

    Regola d'Oro: p++ sposta il puntatore per sempre. p + 1 dà solo una "sbirciata" alla cella accanto senza muovere davvero il puntatore.

    Uso Pratico (Game Design): Navigazione Mappa. Usi la sbirciata (+1) per controllare se la cella a destra ha un muro, prima di muovere fisicamente l'entità.

Capitolo 5.6: Array di Puntatori

    Regola d'Oro: Mostro *attivi[50]; (oppure char *dialoghi[10];). È un array dove ogni slot contiene solo un indirizzo.

    Uso Pratico (Game Design): Gestione Entità. Crei una "lista VIP" dei mostri attualmente vivi nel livello. Invece di spostare o copiare le loro pesanti Struct intere, l'array contiene solo i bigliettini con i loro indirizzi. Se un mostro muore, metti il suo slot a NULL. Utile anche per salvare liste di testi (dialoghi) di lunghezza variabile senza sprecare RAM.

Capitolo 5.7: Puntatori ad Array (Da non confondere con gli Array di Puntatori)

    Regola d'Oro: int (*mappa)[10]; Le parentesi forzano il C a creare un singolo puntatore che mira a un intero array da 10 slot.

    Uso Pratico (Game Design): Mappe 2D e Griglie. Lo usi per passare l'intera mappa del livello a una funzione (es. per calcolare il percorso dei nemici), permettendoti di continuare a usare la comoda sintassi a griglia mappa[y][x].

Capitolo 5.11: Puntatori a Funzione

    Regola d'Oro: void (*tasto_azione)(); Salva l'indirizzo di un intero blocco di codice dentro una variabile.

    Uso Pratico (Game Design): Input e IA. Permette di assegnare azioni diverse a un tasto a seconda del menu in cui ti trovi, o di cambiare l'Intelligenza Artificiale di un nemico al volo senza usare enormi catene di if/else.

Capitolo 5.12: Typedef

    Regola d'Oro: typedef int (*Calcolo)(int); Crea un alias pulito e leggibile per dichiarazioni complesse.

    Uso Pratico (Game Design): Codice Pulito. Ti fa dimenticare le sintassi orrende del C, permettendoti di creare tipi personalizzati eleganti (es. Eroe, Nemico, Magia).

Capitolo 6.1: Basi delle Struct (Il Punto .)

    Regola d'Oro: giocatore.hp = 100; Il punto naviga all'interno della struttura.

    Uso Pratico (Game Design): Creazione Entità. Ti permette di raggruppare coordinate (x,y), salute e nome in una singola variabile compatta invece di avere decine di variabili sparse.

Capitolo 6.1 (Bonus): Struct contenenti Array

    Regola d'Oro: struct { int hp; int inventario_rapido[4]; }; Uno scatolone può contenere scaffali multipli.

    Uso Pratico (Game Design): Slot Fissi. Si usa per dare all'eroe una cintura rapida (es. 4 slot per le pozioni). Il vantaggio enorme è che, essendo dentro la Struct, copiando la Struct copierai in automatico anche tutto l'inventario senza usare for o malloc.

Capitolo 6.2: Struct e Funzioni (La Freccia ->)

    Regola d'Oro: boss->hp -= 10; È la scorciatoia inventata dal C per non dover scrivere il tremendo (*boss).hp.

    Uso Pratico (Game Design): Prestazioni. Passi alla funzione il puntatore di un'entità pesante (come un Boss) e usi la freccia, evitando che la CPU ne faccia pesanti fotocopie a ogni frame.

Capitolo 6.3: Array di Struct e sizeof

    Regola d'Oro: sizeof(arr) / sizeof(arr[0]) Calcola in automatico la lunghezza di un array.

    Uso Pratico (Game Design): Database. Lo usi per creare la lista completa del Bestiario o delle Armi, senza doverti ricordare e aggiornare a mano il totale degli elementi ogni volta che aggiungi un mostro nuovo.

Capitolo 6.4: Iterazione con Puntatori

    Regola d'Oro: for (p = array; p < array + TOT; p++) Usa i puntatori per scorrere invece degli indici [i]. Restituisce NULL se non trova il bersaglio.

    Uso Pratico (Game Design): Game Loop Sicuro. Per scorrere le liste di nemici in modo efficiente. Verifichi sempre che il puntatore non sia NULL per evitare che il gioco crashi.

Capitolo 6.5: Strutture Autoreferenziali

    Regola d'Oro: Una Struct che contiene un puntatore a un'altra Struct identica a se stessa (->prossimo).

    Uso Pratico (Game Design): Inventari Infiniti (Linked List). Usi malloc() per agganciare un nuovo oggetto in fondo alla catena, senza i rigidi limiti di spazio degli Array (ricordando di usare free() quando lo butti).

Capitolo 6.6: Tabelle Hash (Lookup)

    Regola d'Oro: Trasforma una parola in un indice matematico (Hash). Usa le Linked List per gestire le parole con lo stesso numero (collisioni).

    Uso Pratico (Game Design): Ricerca Veloce di Asset. Ti permette di trovare istantaneamente le statistiche di un oggetto (es. "Spada di Fuoco") in un database di 10.000 elementi partendo dal suo nome, senza dover scorrere l'intero array.

Capitolo 6.8: Union

    Regola d'Oro: Una variabile "mutaforma" in cui tutti i membri si sovrappongono e condividono lo stesso identico spazio fisico in memoria.

    Uso Pratico (Game Design): Risparmio RAM. Ottimizzi l'inventario per far occupare a un singolo slot i dati di un'Arma (usando un int), OPPURE di una Pozione (usando un float), a seconda di cosa raccogli.






*/