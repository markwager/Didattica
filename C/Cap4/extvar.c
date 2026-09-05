#include <stdio.h>
#include <stdlib.h> /* per atof() */
#include <ctype.h>  /* per isdigit() */

#define MAXOP 100   /* dimensione massima dell'operando o operatore */
#define NUMBER '0'  /* segnale che è stato trovato un numero */
#define MAXVAL 100  /* profondità massima dello stack dei valori */
#define BUFSIZE 100 /* dimensione del buffer per ungetch */

/* Dichiarazioni delle funzioni (Prototipi) */
int getop(char []);
void push(double);
double pop(void);
int getch(void);
void ungetch(int);

/* --- VARIABILI ESTERNE (GLOBALI) --- */
int sp = 0;         /* prossima posizione libera nello stack */
double val[MAXVAL]; /* stack dei valori */
char buf[BUFSIZE];  /* buffer per ungetch */
int bufp = 0;       /* prossima posizione libera in buf */


/* --- FUNZIONE PRINCIPALE --- */
int main()
{
    int type;
    double op2;
    char s[MAXOP];

    while ((type = getop(s)) != EOF) {
        switch (type) {
            case NUMBER:
                push(atof(s));
                break;
            case '+':
                push(pop() + pop());
                break;
            case '*':
                push(pop() * pop());
                break;
            case '-':
                op2 = pop();
                push(pop() - op2);
                break;
            case '/':
                op2 = pop();
                if (op2 != 0.0)
                    push(pop() / op2);
                else
                    printf("errore: divisore zero\n");
                break;
            case '\n':
                printf("\t%.8g\n", pop());
                break;
            default:
                printf("errore: comando sconosciuto %s\n", s);
                break;
        }
    }
    return 0;
}

/* --- GESTIONE DELLO STACK --- */

/* push: inserisce f nello stack dei valori */
void push(double f)
{
    if (sp < MAXVAL)
        val[sp++] = f;
    else
        printf("errore: stack pieno, impossibile inserire %g\n", f);
}

/* pop: estrae e restituisce il valore in cima allo stack */
double pop(void)
{
    if (sp > 0)
        return val[--sp];
    else {
        printf("errore: stack vuoto\n");
        return 0.0;
    }
}

/* --- GESTIONE DELL'INPUT --- */

/* getop: ottiene il prossimo carattere o operando numerico */
int getop(char s[])
{
    int i, c;

    /* Salta gli spazi bianchi e le tabulazioni */
    while ((s[0] = c = getch()) == ' ' || c == '\t')
        ;
    s[1] = '\0';

    /* Se non è un numero e non è il punto decimale, è un operatore (+, -, ecc.) */
    if (!isdigit(c) && c != '.')
        return c; 
        
    i = 0;
    
    /* Raccoglie la parte intera */
    if (isdigit(c)) 
        while (isdigit(s[++i] = c = getch()))
            ;
            
    /* Raccoglie la parte frazionaria (se c'è) */
    if (c == '.') 
        while (isdigit(s[++i] = c = getch()))
            ;
            
    s[i] = '\0';
    
    /* Se ha letto un carattere di troppo, lo rimette nel buffer */
    if (c != EOF)
        ungetch(c);
        
    return NUMBER;
}

/* getch: ottiene un carattere (dal buffer o dalla tastiera) */
int getch(void) 
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

/* ungetch: reinserisce il carattere letto per sbaglio nel buffer */
void ungetch(int c) 
{
    if (bufp >= BUFSIZE)
        printf("ungetch: troppi caratteri\n");
    else
        buf[bufp++] = c;
}