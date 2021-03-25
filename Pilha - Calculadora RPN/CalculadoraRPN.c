#include <stdio.h>
#include <stdlib.h>
#define MAX 100


int  *p; /*Aponta para a regi�o de memoria livre */
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
        printf("Erro de aloca��o de memoria\n");
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
                printf("divis�o por 0\n");
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
void push (int i) /* O push ele n�o retorna nada, recebe um n�mero inteiro*/
{
    if (p>bos) { /* teste para saber se a pilha est� cheia*/
        printf("Pilha cheia\n");
        return;
    }
    *p = i; /* coloca o n�mero que recebeu no p que � o ponteiro da pilha*/
    p++; /*avan�a o ponteiro de 1*/
}
/* Recupera um elemento da Pilha = desempilha() */
pop (void)
{
    p--; /*decrementa a contagem de elementos*/
    if (p<tos){ /*testa se a pilha ficou vazia*/
        printf("Pilha Vazia\n");
        return 0;
    }
    return *p; /*retorna o elemento p/ qual ele est� apontando*/
}
