/*
Creiamo un programma che conti le occorrenze di ogni carattere
L'array conterrà le occorrenze di tutti i numeri
*/

#include <stdio.h>

#define OUT 0
#define IN 1

void hist1();
void hist2();

void hist2(){
    int c, i, nwhite;
    int ndigit[10]; //gli elementi sono da 0 a 9
    int nother[256];
    

    nwhite=0;
    for(i=0; i<10; i++){
        ndigit[i]=0;
    }

    for(i=0; i<256; i++){
        nother[i]=0;
    }

    while((c=getchar())!=EOF){
        if(c>='0' && c<='9'){
            ndigit[c-'0']++; //l'indice è la sottrazione tra due interi
        }
        else if(c==' ' || c=='\n' || c=='\t'){
            nwhite++;
        }
        else{
            nother[c]++;
        }
    }

    printf("Occorrenze numeri: ");
    for(i=0; i<10; i++){
        printf(" %d", ndigit[i]);
    }
    printf(", white space = %d\n", nwhite);
    printf("Occorrenze caratteri: ");
    printf("\n");
    for(i=0; i<256; i++){
        if(nother[i]>=1){
            printf("'%c'  : %d ", i, nother[i]);
            for(int j=0; j<nother[i]; j++){
                printf("#");
            }
            printf("\n");
        }
    }
    printf("\n");
}

void hist1(){
    int c;
    int state=OUT;
    int len=0;

    while((c = getchar())!=EOF){
        len+=1;
        if(c==' ' || c=='\n' || c=='\t'){
            if(state==OUT){
                printf("\n");
                state=IN;
            }
        }
        
        else{
            printf("%d",len);
            state=OUT;
        }

        len=0;

    }
}

int main1(){

    int c, i, nwhite, nother;
    int ndigit[10]; //gli elementi sono da 0 a 9

    nwhite=nother=0;
    for(i=0; i<10; i++){
        ndigit[i]=0;
    }

    while((c=getchar())!=EOF){
        if(c>='0' && c<='9'){
            ndigit[c-'0']++; //l'indice è la sottrazione tra due interi
        }
        else if(c==' ' || c=='\n' || c=='\t'){
            nwhite++;
        }
        else{
            nother++;
        }
    }

    printf("Occorrenze numeri: ");
    for(i=0; i<10; i++){
        printf(" %d", ndigit[i]);
    }
    printf(", white space = %d, other = %d\n",
    nwhite, nother);

}

int main(){
    //hist1();
    hist2();
}