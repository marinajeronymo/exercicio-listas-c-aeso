/*Escreva uma função em C para trocar os elementos m e n de uma lista dinâmica (m e n
podem ser chaves ou mesmo ponteiros para os elementos – a escolha é sua).*/

#include <locale.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int info;
    struct no *prox;
} No;

typedef struct{
    No *ini;
    No *fim;
}Lista;
void criaLista(Lista *f) {
    f->ini = NULL;
    f->fim = NULL;
}
void insere(int dado, Lista *f) {
    No *novo = (No*)malloc(sizeof(No));
    if (novo == NULL) {
        printf("ERRO");
        return;
    } else {
        novo->info = dado;
        novo->prox = NULL;
        if (f->ini == NULL) {
            f->ini = novo;
        } else {
            f->fim->prox = novo;
        }
        f->fim = novo;
    }
}


void imprimir(Lista *f) {
    No *p = f->ini;
    if (p != NULL) {
        while (p != NULL) {
            printf(" %d ", p->info);
            p = p->prox;
        }
    } else {
        printf("vazia");
        return;
    }
}
void alterar(Lista *f) {
    No *p = f->ini;
    int op;
    int dado;

    if (p != NULL) {
        printf("\ndigite o valor para ser trocado:");
        scanf("%d", &op);

        while (p != NULL) {
            if (op == p->info) {
                printf("\nDigite o novo valor:");
                scanf("%d", &dado);
                p->info = dado;

            } else {
                p = p->prox;
            }
        }
    }
}

int main() {
    Lista *ref = (Lista*)malloc(sizeof(Lista));
    if (ref == NULL) {
        printf("erro ao alocar fila");
        exit(-1);
    } else {
        criaLista(ref);

        insere(15, ref);
        insere(20, ref);
        insere(45, ref);

        imprimir(ref);
        alterar(ref);

        imprimir(ref);
    }
    return 0;
}
