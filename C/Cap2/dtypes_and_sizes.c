/*
Tipi di dati:
char: un singolo byte in grado di contenere solo un carattere
int: intero che riflette la grandezze in base al tipo di macchina
float: per i nunmeri decimali
double: per i decimali più grandi o precisi

Combinazioni per num interi:
short: intero corto
int: intero normale
long: intero lungo
si possono usare con questi signed e unsigned

Combinazioni per caratteri:
char: char normale
si possono usare signed e unsigned

Combinazioni per num float:
float: float a singola precisione
double: doppia precisione
long double: doppia precisione a precisione estesa
*/


#include <stdio.h>
#include <limits.h> //definisce costanti per la grandezza dei tipi interi
#include <float.h> //definisce costanti per la grandezza dei tipi float

int main(){

    printf("%d\n",CHAR_BIT);
    
}

/*
Gerarchia tipi di dato:
char (1 Byte) - Il più piccolo, usato per lettere o numeretti fino a 255.

short (2 Byte) - Interi piccoli.

int (4 Byte) - Il numero intero standard.

long (4 o 8 Byte) - Interi grandi.

long long (8 Byte) - Interi giganteschi (introdotto negli standard C più recenti).

float (4 Byte) - Decimali standard (vince sempre sugli interi nelle conversioni implicite, perché gestisce la virgola).

double (8 Byte) - Decimali ad alta precisione.

long double (12 o 16 Byte) - Il re assoluto della memoria, per la massima precisione scientifica.


*/

/*
L'ordine delle Operazioni Matematiche (Precedenza)
Se non metti le parentesi, il C esegue i calcoli esattamente in questo ordine (dall'alto verso il basso):


 * ==============================================================================
 *        GERARCHIA E PRECEDENZA DEGLI OPERATORI IN C (Dal primo all'ultimo)
 * ==============================================================================
 * 
 * ORDINE | OPERATORI         | DESCRIZIONE                      | LETTURA
 * -------|-------------------|----------------------------------|-------------------
 *   1°   | ( )               | Parentesi tonde                  | Sinistra -> Destra
 *   2°   | +  -  !  (tipo)   | Segno unario, NOT, Cast          | Destra -> Sinistra
 *   3°   | *  /  %           | Moltiplicazione, Div, Modulo     | Sinistra -> Destra
 *   4°   | +  -              | Addizione, Sottrazione           | Sinistra -> Destra
 *   5°   | <  <=  >  >=      | Confronti di grandezza           | Sinistra -> Destra
 *   6°   | ==  !=            | Uguaglianza / Disuguaglianza     | Sinistra -> Destra
 *   7°   | &&                | AND Logico (Tutti veri)          | Sinistra -> Destra
 *   8°   | ||                | OR Logico (Almeno uno vero)      | Sinistra -> Destra
 *   9°   | =                 | Assegnazione (es. x = 5)         | Destra -> Sinistra
 * 
 * ==============================================================================
 * NOTA: Il C risolve le espressioni leggendo questa tabella dall'alto verso 
 * il basso (livello 1 vince su tutti, livello 9 viene eseguito per ultimo).
 * ==============================================================================

*/