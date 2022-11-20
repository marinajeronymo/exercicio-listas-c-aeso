/*2. Utilize uma lista como a que implementamos em sala de aula, com 50 slots;
b. Crie uma outra função que garanta a inserção de números em ordem
decrescente. Inspire-se na letra anterior;*/

#include <stdio.h>
#include <stdlib.h>

typedef struct lista{
	int info;
	struct lista *prox;
}Lista;

Lista* criaLista(){
	return NULL;
}


void inserir_ordenado_dec(Lista **ref, int num){
    Lista *aux, *novo = malloc(sizeof(Lista));

    if(novo){
        novo->info = num;
        // a lista está vazia?
        if(*ref == NULL){
            novo->prox = NULL;
            *ref = novo;
        } // é o menor?
        else if(novo->info > (*ref)->info){
            novo->prox = *ref;
            *ref = novo;
        }
        else{
            aux = *ref;
            while(aux->prox !=NULL && novo->info < aux->prox->info)
                aux = aux->prox;
            novo->prox = aux->prox;
            aux->prox = novo;
        }
    }
    else
        printf("Erro ao alocar memoria!\n");
}

void imprimir(Lista *ref){
	Lista *p;
	if(ref==NULL){
		printf("Lista Vazia");
	}else{
		/*p = ao ponteiro que aponta para o começo da lista, enquanto ele não 
		apontar pra nulo(fim) e pulando para o próximo nó*/
		for(p=ref;p!=NULL;p=p->prox){
			printf("%2d ",p->info);
		}
	}
}

int main(){
	Lista *ref, valor;
	int tam;
	ref=criaLista();
	
	do{
		printf("\nInsira um número na lista\n");
		scanf("%d",&valor.info);
		inserir_ordenado_dec(&ref,valor.info);
		tam++;
	}while(tam<5);
	imprimir(ref);
	
	
	return 0;
	
}
