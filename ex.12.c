#include<stdio.h>
#include<stdlib.h>
#include <malloc.h>

typedef struct noArvore{
    int info;
    struct noArvore *esquerda;
    struct noArvore *direita; 
}No;

No* criarNo(int info){
    No *novo = (No*)malloc(sizeof(No));
    novo -> info = info;
    novo -> esquerda = NULL;
    novo -> direita = NULL;
    return novo;
}



void arvoreOrdem(No* raiz){
    if(raiz == NULL){
        return;
    }
    arvoreOrdem(raiz->esquerda);
    printf("%d->", raiz->info);
    arvoreOrdem(raiz->direita);

}

void espelhoArvore(No* raiz, No** espelho){
    if(raiz == NULL){
        espelho = NULL;
        return;
    }

    *espelho = criarNo(raiz->info);
    espelhoArvore(raiz->esquerda, &((*espelho)->direita));
    espelhoArvore(raiz->direita, &((*espelho)->esquerda));
}


int main(){
    No * arvore = criarNo(4);
    arvore->esquerda = criarNo(2);
    arvore->direita = criarNo(6);
    arvore->esquerda->esquerda = criarNo(1);
    arvore->esquerda->direita = criarNo(3);
    arvore->direita->esquerda = criarNo(5);
    arvore->direita->direita = criarNo(10);
    arvore->direita->direita->esquerda = criarNo(8);

    printf("arvore original: ");
    arvoreOrdem(arvore);
    No* espelho = NULL;
    espelhoArvore(arvore, &espelho);

    printf("\narvore espelhada: ");
    arvoreOrdem(espelho);

    return 0;

}
