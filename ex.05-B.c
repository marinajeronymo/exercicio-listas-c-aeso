/*Considere listas dinâmicas implementadas por encadeamento simples, então pede-se
para implementar funções que:
b. Concatenar/intercalar (Merge) duas listas*/

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


Lista* merge(Lista* a, Lista* b){

    Lista* aux = a;
    while(aux != NULL){
        b = insere(b, aux->info);
        aux = aux->prox;
    }
    return b;
}

int main(){
	Lista *ref1, *ref2;
	ref1=criaLista();
	ref2=criaLista();
	ref1=insere(ref1,3);
	ref1=insere(ref1,4);
	ref1=insere(ref1,5);
	ref1=insere(ref1,6);
	imprime(ref1);
	merge(ref1,ref2);
	printf("\n\n");
	imprime(ref2);
	
	return 0;
}
