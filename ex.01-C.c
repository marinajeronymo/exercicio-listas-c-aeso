
//Faça uma cópia da Lista L1 em L2, eliminando elementos repetidos;

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

Lista* remover(Lista *ref, int valor){
	Lista *ant=NULL;
	Lista *p=ref;
	
	while(p!=NULL && p->info!=valor){
		ant=p;
		p=p->prox;
	}
	if(p==NULL){
		return ref;
	}
	if(ant==NULL){
		ref=p->prox;
	}else{
		ant->prox=p->prox;
	}
	free(p);
	return ref;
}

Lista* remove_duplicados(Lista* ref){
    Lista* x;
    Lista* p;
    Lista* y;

    for(p = ref; p != NULL; p = p -> prox ){
        x = NULL; //a cada varrimento a começa a NULL

        for(y = p-> prox; y!= NULL; ){ //sem incremento
            if(y->info==p->info){ //teste de igual
                if(x == NULL){ //remove do inicio
                    p-> prox = y-> prox;
                }
                else{ //ou do meio/fim
                    x-> prox= y-> prox;
                }

                Lista* remover = y;
                y = y-> prox;
                free(remover);
            }
            else { //so atualiza o anterior quando não é igual
                x = y;
                y = y->prox;
            }
        }
    }

    return ref;
}

void copiaLista(Lista **ref1, Lista **ref2){
	Lista *aux = *ref1;
	while(aux!=NULL){
		*ref2 = insere(ref2,aux->info);
		aux=aux->prox;
	}
}

int main (){
	Lista *lista1, *lista2;
	lista1=cria();
	lista2=cria();

	lista1=insere(lista1,3);
	lista1=insere(lista1,4);
	lista1=insere(lista1,5);
	lista1=insere(lista1,4);
	printf("\nLista Original:\n");
	imprime(lista1);
	remove_duplicados(lista1);
	copiaLista(&lista1,&lista2);
	printf("\nCopia sem duplicados:\n");
	imprime(lista2);
	
	return 0;
}
