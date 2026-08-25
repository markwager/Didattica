#include <stdio.h>

void conv(){

    printf("\n");

    for(int fahr=300; fahr>=0; fahr-=20){
        int celsius=5*(fahr-32)/9;
        printf("%3d %6d\n", fahr, celsius);
    }

}

int main(){


    for(int fahr=0; fahr<=300; fahr+=20){
        int celsius=5*(fahr-32)/9;
        printf("%3d %6d\n", fahr, celsius);
    }

    conv();

}