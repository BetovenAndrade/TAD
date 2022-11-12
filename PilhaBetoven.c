#include <stdio.h>
#include <stdlib.h>

//Definindo o que vamos armazenar
struct No{
	int num;
	struct No *prox;
};
typedef struct No No;

//Quantos bytes tem um No???
int tamNo= sizeof(No);

No *Pilha;
int qtd=0;

int main(){
	//Declarando quais métodos vamos utilizar
	void show();
	void push(int elemento);	
	void pop();
	void clear();
		
	//loop que fica disponibilizando as opções
	int i= 7;	int opc;	int valor;
	while(i==7){
		printf("Escolha a opcao\n");
		printf("1. PUSH\n");
		printf("2. POP\n");
		printf("3. SHOW\n");
		printf("4. LIMPAR\n");
		printf("7. EXIT\n");
		printf("Opcao: "); scanf("%d", &opc);
		
		switch(opc){
			case 1:
				printf("\nDigite o numero a inserir:" );
				scanf("%d", &valor);
				push(valor);
				break;
			case 2:
				pop();
				break;
			case 3:
				show();
				break;
			case 4:
				clear();
				break;
			case 7:
				clear();
				return 0;
				break;
			default:
				printf("\nOpcao invalida");
				break;
		}
	} 
	getch();
	return 0;
}

//Mostrar Pilha
void show(){
	if (qtd>=1){
		No *tmp;
		tmp = Pilha;
		printf("PILHA:");
		
		while( tmp != NULL){
			printf("%5d", tmp->num);
			tmp = tmp->prox;
		}
		
		printf("\n        ");
		
		int cont;
		for(cont=0 ; cont < qtd ; cont++)
			printf("  ^  ");
		
		printf("\nOrdem:");
		
		for(cont=0 ; cont < qtd ; cont++)
			printf("%5d", cont+1);
		
		printf("\n\n");	
	}
}

//inserir
void push(int elemento){
	if(qtd>=2){
		//criando um no, armazenando o valor e apontando o próximo para nulo
		No *novo= (No *) malloc(tamNo);
		novo->prox= NULL;
		novo->num= elemento;
		
		//Percorrendo a pilha ate encontrar o topo
		No *tmp = Pilha->prox;
  		while(tmp->prox != NULL)
   			tmp = tmp->prox;
		//O novo nó é inserido no topo 
  		tmp->prox = novo;	
	}
	else if(qtd==1){
		//criando um no, armazenando o valor e apontando o próximo para nulo
		No *novo= (No *) malloc(tamNo);
		novo->prox= NULL;
		novo->num= elemento;
		
		Pilha->prox= novo;	
	}
	else
	{
		Pilha= (No *) malloc(tamNo);
		Pilha->prox= NULL;
		Pilha->num= elemento;
	}
	++qtd;
}

//remover
void pop(){
	if(qtd>=2){
		//percorrer até encontrar o topo
		No *ultimo = Pilha->prox;
        No *penultimo = Pilha;

		while(ultimo->prox != NULL){
		   penultimo = ultimo;
		   ultimo = ultimo->prox;
		}
		
		 penultimo->prox = NULL;
		 free(ultimo);
		--qtd;
	}
	else if(qtd==1){
		free(Pilha);
		--qtd;
	}
	else
	{
		printf("\nA pilha ja estah vazia");
	}
}

void clear(){
	if(qtd>0){
		No *proxNode, *atual;
	
		atual = Pilha->prox;
		while(atual != NULL){
			proxNode = atual->prox;
			free(atual);
			atual = proxNode;
	  	}
	  	free(Pilha);
	  	qtd=0;
	}
}
