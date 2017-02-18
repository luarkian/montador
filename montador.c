#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "montador.h"


void imprimir(node *L)//Imprime os valores de todos os nós
{
    if (L == NULL)
    {
        printf("\n A lista esta vazia! \n");
        return;
    }
    node *no = L;
    while (no != NULL)
    {
        printf(" %d  - %s\n", no->linha, no->label);
        no = no->prox;
    }
}
/* FUNÇÃO DE INSERIR NA LISTA PARA GUARDAR LABELS
*/
node* inserirLista(node *L, char *lab, int lin ){
/*
	node *aux;
	aux = (node*)malloc( sizeof(node));
	strcpy(lab, aux->label);
	aux->linha =lin;
	aux->prox = NULL;
	
	if( L == NULL){
	
		return aux;
	}
		node *tmp = L->prox;

		while(tmp->prox != NULL){
			tmp = tmp->prox;
		}		
		tmp->prox = aux; 
	*/
	return L;
}

node* buscaLista(node *L, char *lab){

	node *i = L->prox;

		while(i != NULL){
			if(strcmp(i->label, lab) == 0){
				return i;
			}
			i = i->prox;
		}
}
int idetifica(char *s){

	if(strcmp(s,"add") | strcmp(s,"sub") | strcmp(s,"and") | strcmp(s,"or") | strcmp(s,"sll") | strcmp(s,"slr") | strcmp(s,"slt") ) {
		return 1;
	}
	else if(strcmp(s,"addi") | strcmp(s,"andi") | strcmp(s,"ori") | strcmp(s,"sll") | strcmp(s,"bqe") | strcmp(s,"bne") | strcmp(s,"slti") | strcmp(s,"lw") | strcmp(s,"sw") | strcmp(s,"lb" ) ){
		return 2;
	}
	else if(strcmp(s,"j") | strcmp(s,"jal") | strcmp(s,"jr")){
		return 3;
	}
}


 // funcoes de montagem de binarios


int monta_add(int rs, int rt, int rd) {
	/*
	 * insere os primeiros 6 bits do opcode na instrução binaria
	 * |OP|
	 */
	int binario = ADD_OP
	;
	/*
	 * insere os 5 bits registrador rs
	 * |OP|RS|
	 */
	binario |= (rs << 21);
	/*
	 * insere os 5 bits registrador rt
	 * |OP|RS|RT|
	 */
	binario |= (rt << 16);
	/*
	 * insere os 5 bits registrador rd
	 * |OP|RS|RT|Rd|
	 */
	binario |= (rd << 11);
	/*
	 * insere os 5 bits registrador rd
	 * |OP|RS|RT|Rd|SHAMT|FUNC|
	 */
	binario |= ADD_FUNC;

	return binario;
}
int monta_addi(int rs, int rt, int imm){
	/*
	 * insere os primeiros 6 bits do opcode na instrução binaria
	 * |OP|
	 */
	int binario = ADDI_OP
	;
	/*
	 * insere os 5 bits registrador rs
	 * |OP|RS|
	 */
	binario |= (rs << 21);
	/*
	 * insere os 5 bits registrador rt
	 * |OP|RS|RT|
	 */
	binario |= (rt << 16);
	/*
	 * insere os 16 bits registrador imm
	 * |OP|RS|RT|IMM|
	 */
	binario |= imm;

	return binario;

}

int monta_sub(int rs, int rt, int rd){
	/*
	 * insere os primeiros 6 bits do opcode na instrução binaria
	 * |OP|
	 */
	int binario = SUB_OP;
	/*
	 * insere os 5 bits registrador rs
	 * |OP|RS|
	 */
	binario |= (rs << 21);
	/*
	 * insere os 5 bits registrador rt
	 * |OP|RS|RT|
	 */
	binario |= (rt << 16);
	/*
	 * insere os 5 bits registrador rd
	 * |OP|RS|RT|Rd|
	 */
	binario |= (rd << 11);
	/*
	 * insere os 5 bits registrador rd
	 * |OP|RS|RT|Rd|SHAMT|FUNC|
	 */
	binario |= SUB_FUNC;

	return binario;

}

int monta_nor(int rs, int rt, int rd){
		/*
	 * insere os primeiros 6 bits do opcode na instrução binaria
	 * |OP|
	 */
	int binario = NOR_OP
	;
	/*
	 * insere os 5 bits registrador rs
	 * |OP|RS|
	 */
	binario |= (rs << 21);
	/*
	 * insere os 5 bits registrador rt
	 * |OP|RS|RT|
	 */
	binario |= (rt << 16);
	/*
	 * insere os 5 bits registrador rd
	 * |OP|RS|RT|Rd|
	 */
	binario |= (rd << 11);
	/*
	 * insere os 5 bits registrador rd
	 * |OP|RS|RT|Rd|SHAMT|FUNC|
	 */
	binario |= NOR_FUNC;

	return binario;
}

int monta_and(int rs, int rt, int rd){
	/*
	 * insere os primeiros 6 bits do opcode na instrução binaria
	 * |OP|
	 */
	int binario = AND_OP
	;
	/*
	 * insere os 5 bits registrador rs
	 * |OP|RS|
	 */
	binario |= (rs << 21);
	/*
	 * insere os 5 bits registrador rt
	 * |OP|RS|RT|
	 */
	binario |= (rt << 16);
	/*
	 * insere os 5 bits registrador rd
	 * |OP|RS|RT|Rd|
	 */
	binario |= (rd << 11);
	/*
	 * insere os 5 bits registrador rd
	 * |OP|RS|RT|Rd|SHAMT|FUNC|
	 */
	binario |= AND_FUNC;

	return binario;

}

int monta_andi(int rs, int rt, int imm){
	/*
	 * insere os primeiros 6 bits do opcode na instrução binaria
	 * |OP|
	 */
	int binario = ANDI_OP
	;
	/*
	 * insere os 5 bits registrador rs
	 * |OP|RS|
	 */
	binario |= (rs << 21);
	/*
	 * insere os 5 bits registrador rt
	 * |OP|RS|RT|
	 */
	binario |= (rt << 16);
	/*
	 * insere os 16 bits registrador imm
	 * |OP|RS|RT|IMM|
	 */
	binario |= imm;
	return binario;

}

int monta_or(int rs, int rt, int rd){
	/*
	 * insere os primeiros 6 bits do opcode na instrução binaria
	 * |OP|
	 */
	int binario = OR_OP
	;
	/*
	 * insere os 5 bits registrador rs
	 * |OP|RS|
	 */
	binario |= (rs << 21);
	/*
	 * insere os 5 bits registrador rt
	 * |OP|RS|RT|
	 */
	binario |= (rt << 16);
	/*
	 * insere os 5 bits registrador rd
	 * |OP|RS|RT|Rd|
	 */
	binario |= (rd << 11);
	/*
	 * insere os 5 bits registrador rd
	 * |OP|RS|RT|Rd|SHAMT|FUNC|
	 */
	binario |= OR_FUNC;

	return binario;

}

int monta_ori(int rs, int rt, int imm){
	/*
	 * insere os primeiros 6 bits do opcode na instrução binaria
	 * |OP|
	 */
	int binario = ORI_OP
	;
	/*
	 * insere os 5 bits registrador rs
	 * |OP|RS|
	 */
	binario |= (rs << 21);
	/*
	 * insere os 5 bits registrador rt
	 * |OP|RS|RT|
	 */
	binario |= (rt << 16);
	/*
	 * insere os 16 bits registrador rd
	 * |OP|RS|RT|IMM|
	 */
	binario |= imm;
	
	return binario;
}

int monta_beq(int rs, int rt, int imm){
	/*
	 * insere os primeiros 6 bits do opcode na instrução binaria
	 * |OP|
	 */
	int binario = BEQ_OP
	;
	/*
	 * insere os 5 bits registrador rs
	 * |OP|RS|
	 */
	binario |= (rs << 21);
	/*
	 * insere os 5 bits registrador rt
	 * |OP|RS|RT|
	 */
	binario |= (rt << 16);
	/*
	 * insere os 16 bits registrador rd
	 * |OP|RS|RT|IMM|
	 */
	binario |= imm;
	
	return binario;
}

int monta_bne(int rs, int rt, int imm){
	/*
	 * insere os primeiros 6 bits do opcode na instrução binaria
	 * |OP|
	 */
	int binario = BNE_OP
	;
	/*
	 * insere os 5 bits registrador rs
	 * |OP|RS|
	 */
	binario |= (rs << 21);
	/*
	 * insere os 5 bits registrador rt
	 * |OP|RS|RT|
	 */
	binario |= (rt << 16);
	/*
	 * insere os 16 bits registrador rd
	 * |OP|RS|RT|IMM|
	 */
	binario |= imm;
	
	return binario;	

}

int monta_j(int imm){
	/*
	 * insere os primeiros 6 bits do opcode na instrução binaria
	 * |OP|
	 */
	int binario = J_OP;
	/*
	 * insere os 16 bits registrador rd
	 * |OP|RS|RT|IMM|
	 */
	binario |= imm;
	

	return binario;
}

int monta_jal( int imm){
	/*
	 * insere os primeiros 6 bits do opcode na instrução binaria
	 * |OP|
	 */
	int binario = JAL_OP;
	/*
	 * insere os 16 bits registrador rd
	 * |OP|IMM|
	 */
	binario |= imm;
	

	return binario;
}

int monta_jr(int rs){
/*
	 * insere os primeiros 6 bits do opcode na instrução binaria
	 * |OP|
	 */
	int binario = JR_OP
	;
	/*
	 * insere os 5 bits registrador rs
	 * |OP|RS|
	 */
	binario |= (rs << 21);


	return binario;
}

int monta_sw(int rs, int rt, int imm){

}

int monta_lw(int rs, int rt, int imm){

}

int monta_slt(int rs, int rt, int rd){
/*
	 * insere os primeiros 6 bits do opcode na instrução binaria
	 * |OP|
	 */
	int binario = SLT_OP
	;
	/*
	 * insere os 5 bits registrador rs
	 * |OP|RS|
	 */
	binario |= (rs << 21);
	/*
	 * insere os 5 bits registrador rt
	 * |OP|RS|RT|
	 */
	binario |= (rt << 16);
	/*
	 * insere os 5 bits registrador rd
	 * |OP|RS|RT|Rd|
	 */
	binario |= (rd << 11);
	/*
	 * insere os 5 bits registrador rd
	 * |OP|RS|RT|Rd|SHAMT|FUNC|
	 */
	binario |= SLT_FUNC;

	return binario;
}

int monta_slti(int rs, int rt, int imm){

}

int monta_sll(int rs, int rt, int rd){
	/*
	 * insere os primeiros 6 bits do opcode na instrução binaria
	 * |OP|
	 */
	int binario = SLL_OP
	;
	/*
	 * insere os 5 bits registrador rs
	 * |OP|RS|
	 */
	binario |= (rs << 21);
	/*
	 * insere os 5 bits registrador rt
	 * |OP|RS|RT|
	 */
	binario |= (rt << 16);
	/*
	 * insere os 5 bits registrador rd
	 * |OP|RS|RT|Rd|
	 */
	binario |= (rd << 11);
	/*
	 * insere os 5 bits registrador rd
	 * |OP|RS|RT|Rd|SHAMT|FUNC|
	 */
	binario |= SLL_FUNC;

	return binario;
}

int monta_srl(int rs, int rt, int rd){
	/*
	 * insere os primeiros 6 bits do opcode na instrução binaria
	 * |OP|
	 */
	int binario = SRL_OP
	;
	/*
	 * insere os 5 bits registrador rs
	 * |OP|RS|
	 */
	binario |= (rs << 21);
	/*
	 * insere os 5 bits registrador rt
	 * |OP|RS|RT|
	 */
	binario |= (rt << 16);
	/*
	 * insere os 5 bits registrador rd
	 * |OP|RS|RT|Rd|
	 */
	binario |= (rd << 11);
	/*
	 * insere os 5 bits registrador rd
	 * |OP|RS|RT|Rd|SHAMT|FUNC|
	 */
	binario |= SRL_FUNC;

	return binario;
}

int monta_lb(int rs, int rt){

}