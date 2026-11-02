/*
Programma che legge un insieme di linee e printa la più lunga
Qui andremo a scrivere la funzione getline che seleziona la linea più lunga e la copia con la funzione copy
*/

#include <stdio.h>
#define MAXLINE 1000 //massima lunghezza di linea in input

int mygetline(char s[], int line);
void copy(char to[], char from[]);
int charcountline();
void printline80();
void printdel();
void reverse();

void reverse(){
    int len=0; //lunghezza linea corrente
    char line[MAXLINE]; //linea in input corrente qui

    while((len=mygetline(line, MAXLINE))>0){
        for(len; len>=0; len--){
            printf("%c", line[len]);
        }
    }
    
}

void printdel(){
    int len=0; //lunghezza linea corrente
    char line[MAXLINE]; //linea in input corrente qui

    while((len=mygetline(line, MAXLINE))>0){
        while(len-2>=0 && (line[len-2]==' ' || line[len-2]=='\t')){
            len--;
        }
        line[len]='\n';
        line[len+1]='\0';

        printf("%s\n", line);
    }
    
}

void printline80(){
    int len=0; //lunghezza linea corrente
    int max_len=0; //max lunghezza vista finora
    char line[MAXLINE]; //linea in input corrente
    char longest[MAXLINE]; //linea più lunga salvata qui

    while((len=mygetline(line, MAXLINE))>0){
        if(len>max_len){
            max_len=len;
            copy(longest,line);
        }
    }

    if(max_len>80){
        printf("%s", longest);
    }

}

int charcountline(){
    long counter = 0;
    int c;
    while((c = getchar()) != EOF && c != '\n'){
        counter += 1;
    }
    
    if (c == '\n'){
        counter += 1;
    }
    return counter;
}

int mygetline(char s[], int line){ //leggi dalla tastiera ed immetti in s una riga 
    int c;
    int i=0;
    for(i; i<line-1; i++){
        c=getchar();
        if(c==EOF || c=='\n'){
            break;
        }
        s[i]=c;
    }
    if(c=='\n'){ //salva anche 'n'
        s[i]=c;
        i+=1;
    }
    s[i]='\0';
    return i;
}

void copy(char to[], char from[]){
    int i=0;
    for(i=0; from[i]!='\0'; i++){
        to[i]=from[i];
    }
    to[i]='\0';

}

int main1(){

    int len=0; //lunghezza linea corrente
    int max_len=0; //max lunghezza vista finora
    char line[MAXLINE]; //linea in input corrente
    char longest[MAXLINE]; //linea più lunga salvata qui

    while((len=mygetline(line, MAXLINE))>0){
        if(len>max_len){
            max_len=len;
            copy(longest,line);
        }
    }

    if(max_len>0){
        printf("%s", longest);
    }

}

int main2(){

    int len=0; //lunghezza linea corrente
    int max_len=0; //max lunghezza vista finora
    char line[MAXLINE]; //linea in input corrente
    char longest[MAXLINE]; //linea più lunga salvata qui

    while((len=mygetline(line, MAXLINE))>0){
        if(len == MAXLINE - 1 && line[len - 1] != '\n'){
            len += charcountline(); // Sommiamo i caratteri rimanenti!
        }
        if(len>max_len){
            max_len=len;
            copy(longest,line);
        }
    }

    if(max_len>0){
        printf("%s, %d\n", longest, max_len);
    }

}

int main(){

    //printline80();
    //printdel();
    reverse();

}


