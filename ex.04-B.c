// b. Divis�o de uma lista em duas

#include <stdio.h>
#include <stdlib.h>
typedef struct No {
    int dado;
    struct No *prox;
} node;

typedef struct list {
    node *ini;
    node *fim;
} Lista;

void inicializaFila(Lista *f) {
    f->ini = NULL;
    f->fim = NULL;
}

void enfileira(int dado, Lista *f) {
    node *ptr = (node *)malloc(sizeof(node));
    if (ptr == NULL) {
        printf("Erro ao alocar memoria");
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


void imprimeFile(Lista *f) {
    node *ptr = f->ini;
    if (ptr != NULL) {
        while (ptr != NULL) {
            printf(" %d ", ptr->dado);
            ptr = ptr->prox;
        }
        printf("\n");
    } else {
        printf("Fila Vazia\n");
        return;
    }
}

int qtdItems(Lista *l)
{
    node *ptr = l->ini;
    int i = 0;
    if (ptr != NULL) {
        while (ptr != NULL) {
            i++;
            ptr = ptr->prox;

        }
        return i;

    } else {
        printf("Fila Vazia\n");
        return 0;
    }
}

void divFila(int itensPorFila, Lista *l1, Lista *l2, Lista *l3 ){
    node *ptr = l1->ini;

    if (ptr != NULL) {

        for(int j = 0; j < itensPorFila; j++) {
            enfileira(ptr->dado, l2);
            ptr = ptr->prox;
        }

        for (int k = 0; k < itensPorFila; k++) {
            enfileira(ptr->dado, l3);
            ptr = ptr->prox;
        }


    } else {
        printf("Fila Vazia\n");
        return;
    }


}

int main(void) {
    Lista *fila1 = (Lista *)malloc(sizeof(Lista));
    Lista *fila2 = (Lista *)malloc(sizeof(Lista));
    Lista *fila3 = (Lista *)malloc(sizeof(Lista));
    if (fila1 == NULL || fila2 == NULL || fila3 == NULL) {
        printf("Erro de alocação");
        exit(-1);
    } else {
        inicializaFila(fila1);
        inicializaFila(fila2);
        inicializaFila(fila3);
        enfileira(10, fila1);
        enfileira(20, fila1);
        enfileira(30, fila1);
        enfileira(40, fila1);
        enfileira(55, fila1);
        enfileira(32, fila1);
        enfileira(45, fila1);
        enfileira(9, fila1);


        divFila(qtdItems(fila1) / 2, fila1, fila2, fila3);
        imprimeFile(fila2);
        imprimeFile(fila3);
    }
}
