/*
Un flusso di testo è una sequenza di caratteri divisi in linee; ogni linea ha zero
o più caratteri seguiti da un carattere di newline.
getchar serve a leggere un carattere e putchar a scrivere un carattere
Ogni volta che getchar è chiamato, legge il prossimo carattere di input da un flusso
di testo e lo ritorna come suo valore:
c=getchar(); contiene il prossimo carattere di input
putchar(c) stampa un carattere ogni volta che viene chiamata
*/


#include <stdio.h>

#define IN 1 //dentro una word
#define OUT 0 //fuori una word

void ver2(); //versione migliore
void true_false();
void charcount();
void linecount();
void ctncount();
void rep1();
void rep2();
void wcp();

void ver2(){
    int c;
    while((c=getchar())!=EOF){
        putchar(c);

    }
}

void true_false(){
    int c;
    while(c=getchar()!=EOF){
        printf("%d\n", c);

    }
} //non-esempio di uso di getchar

void charcount(){

    long counter=0;
    int c;
    while((c=getchar())!=EOF){
        counter+=1;
    }
    printf("\n");
    printf("%ld\n", counter);
}

void linecount(){
    int c;
    long counter=0;
    while((c=getchar())!=EOF){
        if(c=='\n'){ //apice singolo rappresenta l'intero di quel carattere
            counter+=1;
        }
    }
    printf("%ld\n", counter);
}

void ctncount(){
    int c;
    long cb=0;
    long ct=0;
    long cnew=0;
    while((c=getchar())!=EOF){
        if(c=='\n'){ //apice singolo rappresenta l'intero di quel carattere
            cnew+=1;
        }
        if(c=='\t'){
            ct+=1;
        }
        if(c==' '){
            cb+=1;
        }
    }
    printf("num di newline: %ld\n", cnew);
    printf("num di tab: %ld\n", ct);
    printf("num di spazi: %ld\n", cb);

}

void rep1(){
    int c;
    int lastchar;
    while((c=getchar())!=EOF){
        if((c!=' ') || (lastchar!=' ')){ //apice singolo rappresenta l'intero di quel carattere
            putchar(c);
        }

        lastchar=c;
    }
}

void rep2(){
    int c;
    int lastchar=0;
    while((c=getchar())!=EOF){
        if((c=='\t')){ //apice singolo rappresenta l'intero di quel carattere
            putchar('\\');
            putchar('t');
        }

        if((c=='\b')){ //apice singolo rappresenta l'intero di quel carattere
            putchar('\\');
            putchar('b');
        }
        
        if(c=='\\'){
            putchar('\\');
            putchar('\\');

        }
    
        putchar(c);

    }   
}

void wcp(){
    int c;
    int state=OUT;
    while((c = getchar())!=EOF){
        if(c==' ' || c=='\n' || c=='\t'){
            if(state==OUT){
                putchar('\n');
                state=IN;
            }
        }
        else{
            putchar(c);
            state=OUT;
        }

    }
}

int main1(){

    int c;
    c=getchar(); //leggo il primo carattere immesso dalla tastiera
    while(c!=EOF){
        putchar(c);
        c=getchar();

    }
    printf("%d\n", c); //printa il valore di EOF: -1
 /*sebbene si legga e si scriva 1! char, in realtà si stampa tutto un carattere alla volta a un velocità tale
 che sembra che abbia stampato tutta una parola
 */


}

int main2(){
    //charcount();
    //linecount();
    //ctncount();
    //rep1();
    //rep2();
    int c, nl, nw, nc, state;
    state = OUT;
    nl = nw = nc = 0;
    while((c = getchar())!=EOF){
        nc+=1;
        if(c=='\n'){
            nl+=1;
        }
        if(c==' ' || c=='\n' || c=='\t'){
            state = OUT;
        }
        else if(state == OUT) {
            state = IN;
            nw+=1;
        }
    }
    printf("%d %d %d\n", nl, nw, nc);


}

int main(){

    wcp();

}