#include <stdio.h>
#include <stdlib.h>
#define MAX 100


int  *p; /*Aponta para a região de memoria livre */
int *tos; /* Ponteiro para o topo da pilha */
int *bos; /*Ponteiro para a base da bilha */
void push (int i);
int pop (void);

int main()
{
    int a, b;
    char s[80];
    p = (int *) malloc(MAX*sizeof (int)); /* Aloca memoria para a pilha */
    if(!p){
        printf("Erro de alocação de memoria\n");
        exit(1);
    }
    tos = p;
    bos = p+MAX-1;
    printf("Calculadora\n");
    do {
        printf(":");
        gets(s);
        switch(*s) {
        case '+':
            a = pop();
            b = pop();
            printf("%d\n", b+a);
            push(b+a);
            break;
        case '-':
            a = pop();
            b = pop();
            printf("%d\n", b-a);
            push(b-a);
            break;
        case '*':
            a = pop();
            b = pop();
            printf("%d\n", b*a);
            push(b*a);
            break;
        case '/':
            a = pop();
            b = pop();
            if (a==0){
                printf("divisão por 0\n");
                break;
            }
            printf("%d\n", b/a);
            push(b/a);
            break;
        case '.':
            a = pop();
            push(a);
            printf("Valor corrente no topo da pilha: %d\n",a);
            break;
        default:
            push(atoi (s));
        }
    } while (*s!='q');
return 0;
}

/* Armazena um elemento na Pilha = empilha() */
void push (int i) /* O push ele não retorna nada, recebe um número inteiro*/
{
    if (p>bos) { /* teste para saber se a pilha está cheia*/
        printf("Pilha cheia\n");
        return;
    }
    *p = i; /* coloca o número que recebeu no p que é o ponteiro da pilha*/
    p++; /*avança o ponteiro de 1*/
}
/* Recupera um elemento da Pilha = desempilha() */
pop (void)
{
    p--; /*decrementa a contagem de elementos*/
    if (p<tos){ /*testa se a pilha ficou vazia*/
        printf("Pilha Vazia\n");
        return 0;
    }
    return *p; /*retorna o elemento p/ qual ele está apontando*/
}
