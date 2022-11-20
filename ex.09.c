#include <stdio.h>
#include <stdlib.h>

/*9. Você foi contratado pela Google para refazer o Orkut. A sua primeira tarefa é
implementar uma estrutura de dados para representar as relações de amizade dentro
do Orkut. Ou seja, para cada pessoa cadastrada você tem que armazenar a sua lista
de amigos. Considere que cada pessoa no Orkut tem um identificador único que é um
número inteiro.
a. Declare os tipos necessários para a implementação dessa estrutura.
b. Escreva um procedimento para cadastrar dois amigos:
void Relaciona(int Amigo1, int Amigo2, TipoOrkut* pOrkut) 
Considere que o Amigo1 já está cadastrado no Orkut, enquanto o Amigo2 pode ou não
já estar cadastrado.*/

typedef struct{
	char nome[50];
	int id;
}Usuario;

typedef struct tipoOrkut{
	Usuario info;
	struct tipoOrkut *prox;
}TipoOrkut;

TipoOrkut* crialista(){
	return NULL;
}

Usuario cadastra_usuario(Usuario usuario){
	printf("Digite seu nome:\n");
	fflush(stdin);
	gets(usuario.nome);
	printf("Digite o Id:\n");
	scanf("%d",&usuario.id);

	return usuario;
}

// função para inserir no início

TipoOrkut* insere(TipoOrkut *ref, Usuario valor){
	TipoOrkut *novoNo = malloc(sizeof(TipoOrkut));
	novoNo->info=valor;
	novoNo->prox = ref;
	ref= novoNo;
	return ref;
}

// procedimento para inserir no meio
//amigo1 já está cadastrado e amigo 2 vai ser inserido na sua lista de amigos
void relaciona(TipoOrkut *ref, Usuario amigo1, Usuario amigo2){
    TipoOrkut *aux, *novo = malloc(sizeof(TipoOrkut));

    if(novo!=NULL){
        novo->info = amigo2;
        // é o primeiro?
        if(ref == NULL){
            novo->prox = NULL;
            ref->prox = novo;
        }
        else{
            aux = ref;
            while(aux->info.id != amigo1.id && aux->prox !=NULL)
                aux = aux->prox;
            novo->prox = aux->prox;
            aux->prox = novo;
        }
    }
    else
        printf("Erro ao alocar memoria!\n");
}


void imprimir(TipoOrkut *ref){
	TipoOrkut *p;
	if(ref==NULL){
		printf("Lista Vazia");
	}else{
		/*p = ao ponteiro que aponta para o começo da lista, enquanto ele não 
		apontar pra nulo(fim) e pulando para o próximo nó*/
		for(p=ref;p!=NULL;p=p->prox){
			printf("Nome:%s\t Id:%2d\n ",p->info.nome, p->info.id);
		}
	}
}

int main() {
	 int op, resp;
	 Usuario novoUser, cadAmigo;
	 TipoOrkut *ref;
	 
	 do{
	 	printf("\n*****menu*****\n");
	 	printf("Escolha a opcao:\n 1 - Deseja criar uma nova Lista?\n 2 - Quer adicionar um novo amigo à sua lista\n 3- Imprimir\n 4 - Sair");
	 	scanf("\n%d",&resp);
	 
	 	switch (resp){
	 	case 1:
	 		ref=crialista();
	 		novoUser = cadastra_usuario(novoUser);
	 		ref=insere(ref, novoUser);
	 	break;
	 	case 2:
	 		cadAmigo = cadastra_usuario(cadAmigo);
	 		if(cadAmigo.id==novoUser.id){
	 			printf("Esse id ja existe, escolha outro!");
	 		}else{
				relaciona(ref, novoUser, cadAmigo);
			 }
	 	break;
	 	case 3:
	 		imprimir(ref);
	 	break;
	 	default:
	 		if(resp!=4){
	 			printf("opcao invalida");
			 }
	 	break;
		 }
	 }while(resp!=4);
	
	 


	
	return 0;
}
