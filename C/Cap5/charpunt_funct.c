#include <stdio.h>

void strcpy1(char *s, char *t);
void strcpy2(char *s, char *t);
int strcmps(char *s, char *t);
void strcaz(char *s, char *t);

void strcaz(char *s, char *t){ //concatena t alla fine di s
    int i=0;
    int j=0;

    while(*s!='\0')
        s++;
    
    while(*t!='\0'){
        *(s)=*(t);
        s++;
        t++;
    }

    *s='\0';
}

/* strcmp: restituisce <0 se s<t, 0 se s==t, >0 se s>t */
int strcmps(char *s, char *t){

    int i;
    for (i = 0; s[i] == t[i]; i++)
        if (s[i] == '\0')
            return 0;
    return s[i] - t[i];
}

/* strcpy: copia t in s; versione con puntatori */
void strcpy2(char *s, char *t){
    int i;
    i = 0;
    while ((*s = *t) != '\0') {
        s++;
        t++;
    }
}

/* strcpy: copia t in s; versione con indici di array */
void strcpy1(char *s, char *t){
    int i;
    i = 0;
    while ((s[i] = t[i]) != '\0')
        i++;
}

int main(){
    char amessage[] = "now is the time"; /* un array */
    char *pmessage = "now is the time";  /* un puntatore */
    //esiste una differenza tra array di char e puntatore a char:
    //nel primo posso modificare i caratteri e nel secondo no poichè punta a una mem di sola lettura
    char s[100]; 
    char t[100]="cacca";
    strcpy1(s,t);
    printf("%s\n", s);
    amessage[0]='m';
    //non puoi fare pmessage[0]='a'-->errore!
    char z[100]=" aiuto";
    strcaz(s,z);
    printf("%s\n", s);

}

