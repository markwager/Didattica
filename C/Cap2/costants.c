/*
Il valore di un intero può essere specificato in ottale
o in esadecimale anzichè in decimale.
Uno 0 iniziale è in ottale; 0x o 0X signfica esadecimale:
037 è 31 in ottale, in esadecimale è 0x1f o 0x1F.
Dopo questi esempi, posso mettere alla fine UL per unsigned long.
Un carratere racchiuso con apici singoli come 'x' o '0' rappresenta un intero (carattere costante)
Ci sono inoltre sequenze di caratteri che rappresentano in realtà solo un unico simbolo:
sequenze di escape come \n

L'insieme completo delle sequenze di escape è:

    \a: carattere di allerta (campanella)

    \b: backspace

    \f: avanzamento pagina (formfeed)

    \n: nuova riga (newline)

    \r: ritorno a capo (carriage return)

    \t: tab orizzontale

    \v: tab verticale

    \\: backslash

    \?: punto interrogativo

    \': apice singolo

    \": doppio apice

    \ooo: numero ottale

    \xhh: numero esadecimale

    \0: carattere nullo (vale 0)

Un'espressione costante invece coinvolge solo costanti per esempio:

    #define MAXLINE 1000
    char line[MAXLINE+1];

Una costante stringa (stringa) è una sequenza di 0 o più caratteri racchiusi tra
doppi apici "Io sono una stringa".
Tecnicamente un stringa è un array di caratteri
ATTENZIONE: "A" è una stringa con '\0' finale e  e 'A' è un interoi che rapppresenta quel carattere
*/

/*
Esiste un altro tipo di costante: costante di enumerazione.
è una lista di valori interi costanti.
Per esempio:
enum boolean { NO, YES }; 
Il primo nome in un enum ha valore 0, il successivo 1, e così via, a meno che non vengano specificati valori
espliciti. Se non tutti i valori sono specificati, i valori non specificati continuano la progressione dall'ultimo
valore specificato, come nel secondo di questi esempi:
enum escapes { BELL = '\a', BACKSPACE = '\b', TAB = '\t',
               NEWLINE = '\n', VTAB = '\v', RETURN = '\r' };
enum months { JAN = 1, FEB, MAR, APR, MAY, JUN,
              JUL, AUG, SEP, OCT, NOV, DEC };
              /* FEB = 2, MAR = 3, ecc. 

*/


#include <stdio.h>

enum Stato {FERMO, CAMMINA, SALTA};

int stringalen(char s[]);//questa funzione sta già in string.h

int stringalen(char s[]){ 
    int i=0;
    while(s[i]!='\0'){
        i++;
    }
    return i;
}


int main(){

    enum Stato stato_pg=SALTA;
    if(stato_pg==SALTA){
        printf("Il personaggio sta saltando ");
        printf("(%d)\n", stato_pg);
    }
    char s[]="Sono vally";
    int len=stringalen(s);
    printf("%d\n",len);

}