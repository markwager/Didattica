#include <stdio.h>

int pwr(int, int);

int pwr(int base, int exp){
    int r=1;
    if(exp==0){
        return 0;
    }

    for(int i=0; i<exp; i++){
        r*=base;
    }

    return r;
}

int main(){

    int s=pwr(2,5);
    printf("%d\n", s);

}