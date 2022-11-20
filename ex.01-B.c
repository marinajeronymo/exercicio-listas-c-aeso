/*1. Dada uma lista sequencial ordenada L1, escreva métodos em C que:
b. Faça uma cópia da lista L1 em uma outra lista L2;*/

#include <stdio.h>
#include <stdlib.h>

typedef struct lista{
	int info;
	struct lista *prox;
}Lista;

Lista* criaLista(){
	return NULL;
}

//inserir no inicio
Lista* insere(Lista *ref, int valor){
	Lista *novoNo = (Lista*)malloc(sizeof(Lista));
	novoNo->info=valor;
	novoNo->prox = ref;
	ref= novoNo;
	return ref;
}

void copiaLista(Lista **ref1, Lista **ref2){
	Lista *aux = *ref1;
	while(aux!=NULL){
		*ref2 = insere(ref2,aux->info);
		aux=aux->prox;
	}
}

void imprimir(Lista *ref){
	Lista *p;
	if(ref==NULL){
		printf("\nLista Vazia\n");
	}else{
		/*p = ao ponteiro que aponta para o começo da lista, enquanto ele não 
		apontar pra nulo(fim) e pulando para o próximo nó*/
		for(p=ref;p!=NULL;p=p->prox){
			printf("\t%d ",p->info);
		}
	}
}

int main(){
	Lista *lista1, *lista2;
	lista1=criaLista();
	lista2=criaLista();
	
	lista1 = insere(lista1,1);
	lista1 = insere(lista1,2);
	lista1 = insere(lista1,3);
	lista1 = insere(lista1,4);
	
	imprimir(lista1);
	printf("\n\n");
	copiaLista(&lista1,&lista2);
	printf("\nlista 2\n");
	imprimir(lista2);
	

	return 0;
}
