//Pesquisa por um elemento na lista.

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

int desenfileira(Lista *f) {
    node *ptr = f->ini;
    int dado;
    if (ptr != NULL) {
        f->ini = ptr->prox;
        ptr->prox = NULL;
        dado = ptr->dado;
        free(ptr);
        if (f->ini == NULL) {
            f->fim = NULL;
        }

        return dado;
    } else {
        printf("Fila Vazia.");
        return 0;
    }
}

void imprimeFile(Lista *f) {
    node *ptr = f->ini;
    if (ptr != NULL) {
        while (ptr != NULL) {
            printf(" %d ", ptr->dado);
            ptr = ptr->prox;
        }
    } else {
        printf("Fila Vazia\n");
        return;
    }
}

void search(int element, Lista *l)
{
    node *ptr = l->ini;
    if (ptr != NULL) {
        while (ptr != NULL) {
            if(ptr->dado == element)
            {
                printf("Numero buscado: %i Numero encontrado: %d Endereco de memoria: %i", element, ptr->dado, &ptr->dado);
                return;
            }
            ptr = ptr->prox;

        }

        printf("Valor nao encontrado");
    } else {
        printf("Fila Vazia\n");
        return;
    }
}

int main(void) {
    int option;
    Lista *fila1 = (Lista *)malloc(sizeof(Lista));

    if (fila1 == NULL) {
        printf("Erro de alocacao");
        exit(-1);
    } else {
        inicializaFila(fila1);
        enfileira(10, fila1);
        enfileira(20, fila1);
        enfileira(30, fila1);



        imprimeFile(fila1);
        printf("\nDigite o numero que voce quer achar: ");
        scanf("%i", &option);
        search(option,fila1);


    }
}
