#include <ctype.h>
#include <stdio.h>
#include <string.h>

int atoibau(char s[]);
void reversebau(char s[]);
void expand(char s1[], char s2[]); //espande gli intervalli dei caratteri della stessa famiglia: a-z -> abc..z

void expand(char s1[], char s2[]){
    int i;
    int k=0;
    for(i=0; s1[i]!='\0'; i++){
        if(s1[i+1]=='-' && ((isdigit(s1[i]) && isdigit(s1[i+2])) || (islower(s1[i]) && islower(s1[i+2]))) || 
        isupper(s1[i]) && isupper(s1[i+2])){
            for(int j=s1[i]; j<s1[i+2]; j++){
                s2[k]=j;
                k++;
            }
            i++;
        }
        
        else{
            s2[k]=s1[i];
            k++;
        }
    }
    
    s2[k]='\0';
    printf("%s", s2);
}

/* reverse: inverte la stringa s sul posto */
void reverse(char s[])
{
    int c, i, j;
    for (i = 0, j = strlen(s)-1; i < j; i++, j--) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}

/* atoi: converte s in intero; versione 2 */
int atoibau(char s[])
{
    int i, n, sign;
    for (i = 0; isspace(s[i]); i++) /* salta gli spazi bianchi */
        ;
    sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-') /* salta il segno */
        i++;
    for (n = 0; isdigit(s[i]); i++)
        n = 10 * n + (s[i] - '0');
    return sign * n;
}

int main(){
    char s1[]="1-7";
    char s2[1000];
    expand(s1,s2);

}