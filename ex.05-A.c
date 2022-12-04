/*Considere listas dinâmicas implementadas por encadeamento simples, então pede-se
para implementar funções que:
a. Localize/ Pesquise/Encontre (search) elementos*/

#include <stdio.h>
#include <stdlib.h>

typedef struct lista{
	int info;
	struct lista *prox;
}Lista;

Lista* criaLista(){
	return NULL;
}

Lista* insere(Lista *ref, int valor){
	Lista *novo = (Lista*)malloc(sizeof(Lista));
	novo->info=valor;
	novo->prox=ref;
	return novo;
}

void imprime (Lista *ref){
	Lista *p;
	for(p=ref;p!=NULL;p=p->prox){
		printf("%d ",p->info);
	}
}

Lista* buscar(Lista *ref, int valor){
	Lista *p;
	
	for(p=ref;p!=NULL; p=p->prox){
		if(p->info==valor){
			printf("Elemento encontrado %d",p->info);
			return p;
		}
		return NULL;
	}
}

int main(){
	Lista *ref;
	int el;
	ref=criaLista();
	ref=insere(ref,3);
	ref=insere(ref,4);
	ref=insere(ref,5);
	ref=insere(ref,6);
	imprime(ref);
	printf("Escreva o elemento que deseja buscar:");
	scanf("%d",&el);
	buscar(ref,el);
	
	return 0;
}

