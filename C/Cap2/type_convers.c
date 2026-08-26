/*
Esistono delle conversioni che vengono fatte in automatico
in un tipo comune partendo da un tipo ristretto fino ad uno più grande
come int i; float f; i+f-->float
*/

#include <stdio.h>

int atois(char s[]); //esempio di conversione da char a int
int lower(int);
int htois(char esa[]);

int htois(char esa[]){
    int n=0;
    int i=0;
    if (esa[0] == '0' && (esa[1] == 'x' || esa[1] == 'X')) {
        i = 2; // C'è! Allora spostiamo il punto di partenza dopo la 'x'
    }
    for(i; esa[i]!='\0'; i++){
        if(esa[i]>='0' && esa[i]<='9'){
            n=16*n+(esa[i]-'0');
        }
        else if(esa[i]>='a' && esa[i]<='f'){
            n=16*n+(esa[i]-'a'+10);
        }
        else if(esa[i]>='A' && esa[i]<='F'){
            n=16*n+(esa[i]-'A'+10);
        }
        else{
            break;
        }
    }
    
    return n;

}

int lower(int c){
    if (c >= 'A' && c <= 'Z')
        return c + 'a' - 'A';
    else
        return c;  
}

int atois(char s[]){
    int i, n;
    n=0;
    for(i=0; s[i]>='0' && s[i]<='9'; i++){
        n=10*n+(s[i]-'0'); //ricordo che s[i]-'0' fornisce il valore numerico del char memorizzato in s
    }   //si fa *10 per vai della convesrione in decimale
    return n;
}

int main(){
    char s[]="1050";
    int res1=atois(s);
    printf("%d\n", res1);
    char a='C';
    int res2=lower(a);
    printf("%d\n", res2);

    /*
    In realtà si usano le funzioni in ctype.h per questo
    Le conversioni avvengono anche tramite assegnazione
    */

    int i;
    char c;
    i=c; //il valore di c viene convertito ad int
    i=c; //viceversa
    // vale anche da int a float e viceversa

    /*
    Esistono tuttavia anche le conversioni esplicite:
    (nome_tipo) espressione
    */

    int numero=0x1A3;
    printf("Formato maiuscolo: %X\n", numero);
    printf("Formato minuscolo: %x\n", numero);

    char esa[] = "0xFF"; //si usano le sequence escape per una stringa in esadecimale
    int risul=htois(esa);
    printf("%d\n", risul);

}
