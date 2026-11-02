/*
Si incrementa tramite ++ e -- di 1 in tutti e due i casi.
*/

#include <stdio.h>

void squeeze(char s[], int c);
void squeeze2(char s1[], char s2[]);
int any(char s1[], char s2[]);

int any(char s1[], char s2[]){
    for(int i=0; s1[i]!='\0'; i++){
        for(int j=0; s2[j]!='\0'; j++){
            if(s1[i]==s2[j]){
                return i;
            }
        }
    }

    return -1;  
}

void squeeze2(char s1[], char s2[]){
    char s3[1000];
    int k=0;
    for(int i=0; s1[i]!='\0'; i++){
        int flag=1;
        for(int j=0; s2[j]!='\0'; j++){
            if(s1[i]==s2[j]){
                flag=0;
                break;
            }
        }
        if(flag==1){
            s3[k]=s1[i];
            k++;
        }
    }
    s3[k]='\0';
    printf("%s\n", s3);
} //si uisa la logica del flag come per ricordarsi degli stati precedenti

/* squeeze: elimina tutte le occorrenze di c da s */
void squeeze(char s[], int c)
{
    int i, j;
    for (i = j = 0; s[i] != '\0'; i++){
        if (s[i] != c) {
            s[j] = s[i];
            j++;
        }
    }
    s[j] = '\0';
}//prima si copia il char diuverso in j e poi ci si sposta

int main(){

    int a=4;
    printf("%d\n",a++); //prima si usa la variabile e si incrementa
    int b=4;
    printf("%d\n",++b); //prima si incrementa e poi si usa la var
    //stampano rispettivam 4 e 5!
    char s1[]="ciao";
    char s2[]="bio";
    squeeze2(s1,s2);
    int ris=any(s1,s2);
    printf("%d\n",ris);
}