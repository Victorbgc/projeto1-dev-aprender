#include "BBT_ArvDinamica4.c"

int main(){
	Arvore* ptRaiz;
	
	arv_inicializar(&ptRaiz);
	
	ptRaiz = alocarNo();
	
	ptRaiz->esq = NULL;
	ptRaiz->dir = NULL;
	
	if(ptRaiz == NULL){
		printf("Erro na alocacao!\n\n");
	}
	
	strcpy((ptRaiz)->info.nome, "Maria");
	(ptRaiz)->info.idade = 15;
	(ptRaiz)->info.peso = 55;
	
	pre_ordem(ptRaiz);
	em_ordem(ptRaiz);
	pos_ordem(ptRaiz);
}
