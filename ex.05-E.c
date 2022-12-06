//Ordenar (sort) ima lista por ordem crescente/decrescente

#include <locale.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct NO {
    int dado;
    struct NO *prox;
} NO;

typedef struct FILA {
    NO *ini;
    NO *fim;
} FILA;

void inicializaFILA(FILA *f){
    f->ini = NULL;
    f->fim = NULL;
}
void enfileira(int dado, FILA *f){
    NO *ptr = (NO *)malloc(sizeof(NO));
    if (ptr == NULL) {
        printf("ERRO");
        return;
    } else {
        ptr->dado = dado;
        ptr->prox = NULL;
        if (f->ini == NULL) {
            f->ini = ptr;
        } else {
            f->fim->prox = ptr;
        }
        f->fim = ptr;
    }
}


void imprimirFILA(FILA *f) {
    NO *ptr = f->ini;
    if (ptr != NULL) {
        while (ptr != NULL) {
            printf(" %d ", ptr->dado);
            ptr = ptr->prox;
        }
        printf("\n");
    } else {
        printf("vazia");
        return;
    }
}


void ordenaMenorEmostra(FILA *l){
    NO *ptr = l->ini;
    NO *ptr2 = ptr->prox;

    int aux;

    while(ptr != NULL){
        imprimirFILA(l);

        if(ptr->dado < ptr2->dado){


            aux = ptr->dado;

            ptr->dado = ptr2->dado;
            ptr->prox->dado = aux;

        }

        if(ptr2 != NULL && ptr != NULL){
            ptr2 = ptr2->prox;

            ptr = ptr->prox;

        }
    }

}

int main(){

    FILA *f1 = (FILA *)malloc(sizeof(FILA));

    if (f1 == NULL) {
        printf("erro ao alocar fila");
        exit(-1);
    } else {
        inicializaFILA(f1);

        enfileira(50, f1);
        enfileira(20, f1);
        enfileira(30, f1);

        ordenaMenorEmostra(f1);

        return 1;
    }

}
