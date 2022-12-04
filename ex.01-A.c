/* Dada uma lista sequencial ordenada L1, escreva métodos em C que:
a. Verifique se L1 está ordenada ou não (a ordem pode ser crescente ou
decrescente)*/ 

#include <stdio.h>
#include <stdlib.h>

typedef struct lista{
	int info;
	struct lista *prox;
}Lista;

Lista* cria(){
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

int ordemCresc(Lista *ref){ //Retorna se a lista está em ordem crescente
	
    if (ref != NULL)
    {
        while (ref->prox != NULL)
        {
            if (ref->info > ref->prox->info){
            	return 0;
			}
            ref = ref->prox;
        }
    }
    return 1;
}

int ordemDecresc(Lista *ref){ //Retorna se a lista está em ordem crescente
	
    if (ref != NULL)
    {
        while (ref->prox != NULL)
        {
            if (ref->info < ref->prox->info){
            	return 0;
			}
            ref = ref->prox;
        }
    }
    return 1;
}
int main(){
	Lista *ref;
	ref=cria();
	ref=insere(ref,3);
	ref=insere(ref,4);
	ref=insere(ref,5);
	ref=insere(ref,6);
	imprime(ref);
	
	if(ordemCresc(ref)==0){
		printf("\nLista nao esta em ordem crescente\n");
	}else{
		printf("\nLista em ordem crescente\n");
	}
	
	if(ordemDecresc(ref)==0){
		printf("\nLista nao esta ordem decrescente\n");
	}else{
		printf("\nLista em ordem decrescente\n");
	}
	return 0;
}
