#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "montador.h"


void inicia(node *PILHA){
 PILHA->prox = NULL;
}
int vazia(node *PILHA){
 if(PILHA->prox == NULL)
  return 1;
 else
  return 0;
}
void push(node *PILHA, char *lab, int lin){
 node *novo= aloca();
 strcpy(novo->label,lab);
 novo->linha = lin;
 novo->prox = NULL;

 if(vazia(PILHA))
  PILHA->prox=novo;
 else{
  node *tmp = PILHA->prox;

  while(tmp->prox != NULL)
   tmp = tmp->prox;

  tmp->prox = novo;
 }
}
node* aloca(){
 node *novo=(node *) malloc(sizeof(node));
 if(!novo){
  printf("Sem memoria disponivel!\n");
  exit(1);
 }
  return novo;
}
void exibe(node *PILHA){
 if(vazia(PILHA)){
  printf("PILHA vazia!\n\n");
  return ;
 }

 node *tmp;
 tmp = PILHA->prox;
 printf("LABELS: ");
 while( tmp != NULL){
  printf("%s - ", tmp->label);
  tmp = tmp->prox;
 }
 printf("\n\n");
}
void libera(node *PILHA){
 if(!vazia(PILHA)){
  node *proxNode,
     *atual;

  atual = PILHA->prox;
  while(atual != NULL){
   proxNode = atual->prox;
   free(atual);
   atual = proxNode;
  }
 }
}
int buscaLista(node *L, char *lab){
	int adress=0;
	node *i = L;
	char aux[15];
	char *token;
	token = strtok(lab," ");
	//printf("    -%s-   ",lab  );

		while(i != NULL){
			if(strcmp(i->label, lab) == 0){
				adress = MEMORIA;
				adress = adress + i->linha * 4 ;
//				printf("   label: %s  memoria: 0x%08x linha: %d \n",i->label,adress,i->linha);
				return adress;
			}
			i = i->prox;
		}
}
int identifica(char *s){

	if(strcmp(s,"add") ==0 || strcmp(s,"sub")==0 || strcmp(s,"and")==0 || strcmp(s,"or")==0 || strcmp(s,"sll")==0 || strcmp(s,"slr")==0 || strcmp(s,"slt")==0 ) {
		return 1;
	}
	else if(strcmp(s,"addi")==0 || strcmp(s,"andi")==0 || strcmp(s,"ori")==0 || strcmp(s,"sll")==0 || strcmp(s,"bqe")==0 || strcmp(s,"bne")==0 || strcmp(s,"slti") ==0|| strcmp(s,"lw")==0 || strcmp(s,"sw")==0 || strcmp(s,"lb" )==0 ){
		return 2;
	}
	else if(strcmp(s,"j")==0 || strcmp(s,"jal")==0 || strcmp(s,"jr")==0){
		return 3;
	}
	else
        return 4;
}

 // funcoes de montagem de binarios
int monta_add(int rs, int rt, int rd) {
	/*
	 * insere os primeiros 6 bits do opcode na instrução binaria
	 * |OP|
	 */
	int binario = ADD_OP;
	binario |= (binario << 26);
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
	 * |OP|RS|RT|Rd|SHAMT|
	 */
	binario |= ADD_FUNC;
		//printf("%08x \n",binario);

	return binario;
}
int monta_addi(int rs, int rt, int imm){
	/*
	 * insere os primeiros 6 bits do opcode na instrução binaria
	 * |OP|
	 */
	int binario = ADDI_OP;
	binario |=(binario << 26);
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
	binario |= (binario << 26);
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

	int binario = NOR_OP;
	binario |= (binario << 26);
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

	int binario = AND_OP;
	binario |= (binario << 26);
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
	int binario = ANDI_OP;
	binario |=(binario << 26);
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

	int binario = OR_OP;
	binario |= (binario << 26);
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
	int binario = ORI_OP;
	binario |=(binario << 26);
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

int monta_beq(int rs, int rt, int label){
	/*
	 * insere os primeiros 6 bits do opcode na instrução binaria
	 * |OP|
	 */
	int binario = BEQ_OP;
	binario |=(binario << 26);
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
	binario |= label;

	return binario;
}

int monta_bne(int rs, int rt, int label){
	/*
	 * insere os primeiros 6 bits do opcode na instrução binaria
	 * |OP|
	 */
	int binario = BNE_OP;
	binario |=(binario << 26);
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
	binario |= label;

	return binario;

}

int monta_j(int target){
	/*
	 * insere os primeiros 6 bits do opcode na instrução binaria
	 * |OP|
	 */
	int binario = J_OP;
	binario |= (binario << 26);
	/*
	 * insere os 16 bits registrador rd
	 * |OP|RS|RT|IMM|
	 */
	binario |= target;


	return binario;
}

int monta_jal(int target){
	/*
	 * insere os primeiros 6 bits do opcode na instrução binaria
	 * |OP|
	 */
	int binario ;//= JAL_OP;
	binario |= (0x3 << 26);
	/*
	 * insere os 16 bits registrador rd
	 * |OP|IMM|
	 */

	binario |= binario | target;


	return binario;
}

int monta_jr(int rs){

	int binario = JR_OP;
	binario |= (binario << 26);
	/*
	 * insere os 5 bits registrador rs
	 * |OP|RS|
	 */
	binario |= (rs << 21);

	binario |= JR_FUNC;


	return binario;
}

int monta_sw(int rt,int rs, int imm){

    int binario; //OP_SW
    binario |= (0x2b << 26);

   // printf(" %x\n",binario );
    binario |= (rs << 21);

    //printf(" %x\n",binario );
    binario |= (rt << 16);

    //printf(" %x\n",binario );
    binario |= imm;

    //printf(" %x\n",binario );
    return binario;
}

int monta_lw(int rt,int rs, int imm){
    int binario; //= LW_OP;
    binario |= (0x23 << 26);

    binario |= (rs << 21);

    binario |= (rt << 16);

    binario |= imm;

    return binario;
}

int monta_slt(int rs, int rt, int rd){

	int binario = SLT_OP;
	binario |= (binario << 26);
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
	
	int binario;// = SLTI_OP;
	binario |= (0xa << 26);
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
	 * |OP|RS|RT|IMM|
	 */
	binario = (binario |imm);
	return binario;
}

int monta_sll(int rs, int rt, int shamt){
	/*
	 * insere os primeiros 6 bits do opcode na instrução binaria
	 * |OP|
	 */
	int binario = SLL_OP;
		binario |= (binario << 26);
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
	binario |= (shamt << 6);
	/*
	 * insere os 5 bits registrador rd
	 * |OP|RS|RT|Rd|SHAMT|FUNC|
	 */
	binario |= SLL_FUNC;

	return binario;
}

int monta_srl(int rs, int rt, int shamt){


	int binario = SRL_OP;
	binario |= (binario << 26);
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
	 * |OP|RS|RT|Rd|SHAMT
	 */
	binario |= (shamt << 6);
	/*
	 * insere os 5 bits registrador rd
	 * |OP|RS|RT|Rd|SHAMT|FUNC|
	 */
	binario |= SRL_FUNC;

	return binario;
}

int monta_lb(int rs, int rt, int imm){
	int binario ;//= LB_OP;
    binario |= (0x20 << 26);

    binario |= (rs << 21);

    binario |= (rt << 16);

    binario |= imm;

    return binario;
}

int monta_sb(int rs,int rt, int imm){
	int binario ;//= SB_OP;
    binario |= (0x28 << 26);

    binario |= (rs << 21);

    binario |= (rt << 16);

    binario |= imm;

    return binario;

}

int funcoes_tipo_r(char *reg, int rs, int rt, int rd){

	if(strcmp(reg,"add") == 0){
		return monta_add(rs,rt,rd);
	}
	else if(strcmp(reg,"sub") == 0){
		return monta_sub(rs,rt,rd);
	}
	else if(strcmp(reg,"and") == 0){
		return monta_and(rs,rt,rd);
	}
	else if(strcmp(reg,"or") == 0){
		return monta_or(rs,rt,rd);
	}
	else if(strcmp(reg,"sll") == 0){
		return monta_sll(rs,rt,rd);
	}
	else if(strcmp(reg,"srl") == 0){
		return monta_srl(rs,rt,rd);
	}
	else if(strcmp(reg,"slt") == 0){
		return monta_slt(rs,rt,rd);
	}
}
int funcoes_tipo_i(char *reg, int rs,int rt,int imm){
	//printf("  debug -  %s", reg);
	if(strcmp(reg,"addi") == 0){
        return monta_addi(rs,rt,imm);
	}
	else if(strcmp(reg,"sw") == 0){
        return monta_sw(rs,rt,imm);
	}
	else if(strcmp(reg,"lw") == 0){
        return monta_lw(rs,rt,imm);
	}
	else if(strcmp(reg,"lb") == 0){
        return monta_lb(rs,rt,imm);
	}
	else if(strcmp(reg,"sb") == 0){
        return monta_sb(rs,rt,imm);
	}
	else if(strcmp(reg,"andi") == 0){
        return monta_andi(rs,rt,imm);
	}
	else if(strcmp(reg,"ori") == 0){
        return monta_ori(rs,rt,imm);
	}
	else if(strcmp(reg,"beq") == 0){
        return monta_beq(rs,rt,imm);
	}
	else if(strcmp(reg,"bne") == 0){
        return monta_bne(rs,rt,imm);
	}
	else if(strcmp(reg,"slti") == 0){
        return monta_slti(rs,rt,imm);
	}
}
int funcoes_tipo_j(char *reg, int target){
	if(strcmp(reg,"j") == 0){
		return monta_j(target);
	}
	else if(strcmp(reg,"jal") == 0){
		return monta_jal(target);
	}
	else if(strcmp(reg,"jr") == 0){
		return monta_jr(target);
	}

}

int id_registrador(char *reg){

	if((strcmp(reg," $t0") == 0)|| (strcmp(reg,"$t0") == 0)|| (strcmp(reg,"$t0)") == 0)){

		return T0;
	}
	else if((strcmp(reg," $t1") == 0)|| (strcmp(reg,"$t1") == 0)|| (strcmp(reg,"$t1)") == 0)){

		return T1;
	}
	else if((strcmp(reg," $t2") == 0)|| (strcmp(reg,"$t2") == 0)|| (strcmp(reg,"$t2)") == 0)){

		return T2;
	}
	else if((strcmp(reg," $t3") == 0) || (strcmp(reg,"$t3") == 0)|| (strcmp(reg,"$t3)") == 0)){

		return T3;
	}
	else if((strcmp(reg," $t4") == 0) || (strcmp(reg,"$t4") == 0)|| (strcmp(reg,"$t4)") == 0)){

		return T4;
	}
	else if((strcmp(reg," $t5") == 0) || (strcmp(reg,"$t5") == 0)|| (strcmp(reg,"$t5)") == 0)){

		return T5;
	}
	else if((strcmp(reg," $t6") == 0) || (strcmp(reg,"$t6") == 0)|| (strcmp(reg,"$t6)") == 0)){

		return T6;
	}
	else if((strcmp(reg," $t7") == 0) || (strcmp(reg,"$t7") == 0)|| (strcmp(reg,"$t7)") == 0)){
		return T7;
	}
	else if((strcmp(reg," $t8") == 0) || (strcmp(reg,"$t8") == 0)|| (strcmp(reg,"$t8)") == 0)){
		return T8;
	}
	else if((strcmp(reg," $t9") == 0) || (strcmp(reg,"$t9") == 0)|| (strcmp(reg,"$t9)") == 0)){
		return T9;
	}
	else if((strcmp(reg," $v0") == 0) || (strcmp(reg,"$v0") == 0)){
		return V0;
	}
	else if((strcmp(reg," $v1") == 0) || (strcmp(reg,"$v1") == 0)){
		return V1;
	}
	else if((strcmp(reg," $a0") == 0) || (strcmp(reg,"$a0") == 0)){
		return A0;
	}
	else if((strcmp(reg," $a1") == 0) || (strcmp(reg,"$a1") == 0)){
		return A1;
	}
	else if((strcmp(reg," $a2") == 0) || (strcmp(reg,"$a2") == 0)){
		return A2;
	}
	else if((strcmp(reg," $a3") == 0) || (strcmp(reg,"$a3") == 0)){
		return A3;
	}
	else if((strcmp(reg," $s0") == 0) || (strcmp(reg,"$s0") == 0)|| (strcmp(reg,"$s0)") == 0)){
		return S0;
	}
	else if((strcmp(reg," $s1") == 0) || (strcmp(reg,"$s1") == 0)|| (strcmp(reg,"$s1)") == 0)){
		return S1;
	}
	else if((strcmp(reg," $s2") == 0) || (strcmp(reg,"$s2") == 0)|| (strcmp(reg,"$s2)") == 0)){
		return S2;
	}
	else if((strcmp(reg," $s3") == 0) || (strcmp(reg,"$s3") == 0)|| (strcmp(reg,"$s3)") == 0)){
		return S3;
	}
	else if((strcmp(reg," $s4") == 0) || (strcmp(reg,"$s4") == 0)|| (strcmp(reg,"$s4)") == 0)){
		return S4;
	}
	else if((strcmp(reg," $s5") == 0) || (strcmp(reg,"$s5") == 0)|| (strcmp(reg,"$s5)") == 0)){
		return S5;
	}
	else if((strcmp(reg," $s6") == 0) || (strcmp(reg,"$s6") == 0)|| (strcmp(reg,"$s6)") == 0)){
		return S6;
	}
	else if((strcmp(reg," $s7") == 0) || (strcmp(reg,"$s7") == 0)|| (strcmp(reg,"$s7)") == 0)){
		return S7;
	}
	else if((strcmp(reg," $ra") == 0) || (strcmp(reg,"$ra") == 0)|| (strcmp(reg,"$ra)") == 0)){
		return RA;
	}
	else if((strcmp(reg," $sp") == 0) || (strcmp(reg,"$sp") == 0)|| (strcmp(reg,"$sp)") == 0)){
		return SP;
	}
	else if(strcmp(reg,"$gp") == 0){
		return GP;
	}
	else if(strcmp(reg,"$0") == 0){
		return ZERO;
	}
	else
	{
        return atoi(reg);
	}
}

