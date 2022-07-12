#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct sPessoa{
	char nome[31];
	int idade;
	float peso;
}Pessoa;

typedef struct sNo{
	Pessoa info;
	struct sNo *esq;
	struct sNo *dir;
}NO;

typedef struct sArvore{
	NO* ptRaiz;
} Arvore;

void arv_inicializar(Arvore* ptrA){
	ptrA->ptRaiz = NULL;
}

NO* alocarNo(){
	return (NO*)malloc(sizeof(NO));
}

void visita(Arvore* ptrA){
	fflush(stdin);
	puts(ptrA->ptRaiz->info.nome);
	fflush(stdin);
	printf("Idade: %d\nPeso: %.2f\n\n", ptrA->ptRaiz->info.idade, ptrA->ptRaiz->info.peso);
}

void pre_ordem(Arvore* ptrA){
	if (ptrA->ptRaiz != NULL){
		visita(ptrA);
		pre_ordem(ptrA->ptRaiz->esq);
		pre_ordem(ptrA->ptRaiz->dir);
	}
}

void em_ordem(Arvore* ptrA){
	if (ptrA != NULL){
		pre_ordem(ptrA->ptRaiz->esq);
		visita(ptrA);
		pre_ordem(ptrA->ptRaiz->dir);
	}
}

void pos_ordem(Arvore* ptrA){
	if (ptrA != NULL){
		pos_ordem(ptrA->ptRaiz->esq);
		pos_ordem(ptrA->ptRaiz->dir);
		visita(ptrA);
	}
}

