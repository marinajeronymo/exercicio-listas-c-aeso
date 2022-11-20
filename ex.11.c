#include <stdio.h>
#include <stdlib.h>

/*11. Considere a implementação de listas encadeadas utilizando apontadores vista em sala
e responda a seguinte pergunta:
Escreva uma função void Inverte(TipoLista *Lista) que, dada uma lista com um
número qualquer de elementos, inverte a ordem dos elementos da lista, como
exemplificado na figura abaixo. (Obs. Não vale trocar apenas os campos item
ou usar uma lista / fila / pilha auxiliar! Você deverá fazer a manipulação dos
apontadores para trocar as células de posição).*/

typedef struct lista{
	int info;
	struct lista *prox;
}Lista;

Lista* crialista(){
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


void invertaLista(Lista **ref)
  {
      Lista *aux, *p, *pd;
   if (*ref != NULL){
        aux = NULL;
        p = *ref;
        pd = p->prox;
        do{
        	p->prox = aux;
            aux = p;
            p = pd;
            if (pd != NULL){
            	pd = pd->prox;
			}
          }while (p != NULL);
          
          *ref = aux;
       }
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
	
	Lista *ref=crialista();
	
	ref = insere(ref,1);
	ref = insere(ref,2);
	ref = insere(ref,3);
	ref = insere(ref,4);
	printf("\nlista normal\n");
	imprimir(ref);
	invertaLista(&ref);
	printf("\nLista invertida\n");
	imprimir(ref);
	
	return 0;
}
