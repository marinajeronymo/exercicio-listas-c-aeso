/*3. Usando listas, crie um programa que guarde strings. Re-implemente todas as
funcionalidades para que seja possível usar as funções básicas de inserção, remoção,
busca e detecção de fim de lista;
a. Implemente também a função que retorna o tamanho da lista (quantidade de
elementos), e a perda de memória (total da lista - quantidade de itens vazios)*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct lista{
	char info[50];
	struct lista *prox;
}Lista;

Lista* criaLista(){
	return NULL;
}

//inserir no inicio
Lista* insere(Lista *ref, char valor[]){
	
	Lista *novoNo = (Lista*)malloc(sizeof(Lista));
	strcpy(novoNo->info,valor);
	novoNo->prox = ref;
	ref= novoNo;
	return ref;
}

Lista* remover(Lista *ref, char valor[]){
	Lista *ant=NULL, *p=ref;
	//p vai procurar o elemento
	while(p!=NULL && strcmp(p->info, valor)!=0){
		ant=p;
		p=p->prox;
	}
	if(p==NULL){//elemento não foi encontrado
		return ref;
	}
	//remover primeiro elemento
	if(p==ref){
		ref=p->prox;
	}else{//remove do meio ou fim da lista
			ant->prox=p->prox;
	}
	
	free(p);
	return ref;
	}
	
void imprimir(Lista *ref){
	Lista *p;
	if(ref==NULL){
		printf("\nLista Vazia\n");
	}else{
		/*p = ao ponteiro que aponta para o começo da lista, enquanto ele não 
		apontar pra nulo(fim) e pulando para o próximo nó*/
		for(p=ref;p!=NULL;p=p->prox){
			printf("\t%s ",p->info);
		}
	}
}

void tamanho_lista(Lista *ref){
	Lista *p=ref;
	int i;
	for(p=ref;p!=NULL;p=p->prox){
			i++;
		}
	printf("\nTamanho da Lista:%d\n",i);
	}
	
void buscar(Lista *ref){
	Lista *p;
	char string[50];
	printf("\nQual string deseja buscar:\n");
	fflush(stdin);
	gets(string);
	for(p=ref;p!=NULL;p=p->prox){
		if(strcmp(p->info,string)==0){
			printf("\nstr '%s' encontrada\n", p->info);
		}else{
			printf("\nStr '%s' nao encontrada\n",string);
		}
	}
}

void menu(){
	printf("\n 1 - Inserir na lista\n 2 - Buscar na lista\n 3 - Remover\n 4 - Imprimir\n 5 - Tamanho da Lista\n 6 - Sair");
}

int main(){
	Lista *ref=criaLista(), str;
	char strProc[50];
	int op;
	
	do{
		menu();
		scanf("%d",&op);
		switch (op){
			case 1:
				printf("Escreva a String:");
				fflush(stdin);
				gets(str.info);
				ref = insere(ref,str.info);				
			break;
			case 2:
				buscar(ref);
			break;
			case 3:
				printf("Escreva a String que deseja remover:");
				fflush(stdin);
				gets(strProc);
				remover(ref,strProc);
			break;
			case 4:
				imprimir(ref);
			break;
			case 5:
				tamanho_lista(ref);
			break;
			default:
				if(op!=6){
					printf("opcao invalida");
				}
			break;
		}
	}while(op!=6);
	
	return 0;
}
