#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MEMORIA 0x400024;

#define ADD_OP 0x0;
#define ADD_FUNC 0x20;

#define SUB_OP 0x0;
#define SUB_FUNC 0x22;

#define	BEQ_OP 0x4;

#define BNE_OP 0x5;

#define ADDI_OP 0x8;

#define NOR_OP 0x0;
#define NOR_FUNC 0x27;

#define AND_FUNC 0x24;
#define AND_OP 0x0;
#define ANDI_OP 0xc;

#define OR_OP 0x0;
#define OR_FUNC 0x25;
#define ORI_OP 0x0d;

#define J_OP 0x2;
#define JAL_OP 0x3;

#define JR_OP 0x0;
#define JR_FUNC 0x8;

#define LW_OP 0x23;
#define SW_OP 0x2b;

#define SLT_OP 0x0;
#define SLT_FUNC 0x2a;
#define SLTI_OP 0xa;

#define SLL_OP 0x0;
#define SLL_FUNC 0x0;

#define SRL_OP 0x0;
#define SRL_FUNC 0x2;

#define LB_OP 0x20;

struct Node{
	char label[20];
	int linha;
	struct Node *prox;
	int endereco;
};

typedef struct Node node;
typedef struct node* LISTA; 

int idetifica(char *s);

void imprimir(node *L);

/* FUNÇÃO DE INSERIR NA LISTA PARA GUARDAR LABELS
*/
node* inserirLista(node *L, char *lab, int lin);

/* FUNÇÃO DE BUSCAR NA LISTA OS LABELS
*/
node* buscaLista(node *L, char *lab);

 // funcoes de montagem de binarios

int monta_add(int rs, int rt, int rd);

int monta_addi(int rs, int rt, int imm);

int monta_sub(int rs, int rt, int rd);

int monta_beq(int rs, int rt, int imm);

int monta_bne(int rs, int rt, int imm);

int monta_nor(int rs, int rt, int rd);

int monta_and(int rs, int rt, int rd);

int monta_andi(int rs, int rt, int imm);

int monta_or(int rs, int rt, int rd);

int monta_ori(int rs, int rt, int imm);

int monta_j(int imm);

int monta_jal(int imm);

int monta_jr(int rs);

int monta_sw(int rs, int rt, int imm);

int monta_lw(int rs, int rt, int imm);

int monta_slt(int rs, int rt, int rd);

int monta_slti(int rs, int rt, int imm);

int monta_sll(int rs, int rt, int rd);

int monta_srl(int rs, int rt, int rd);

int monta_lb(int rs, int rt, int imm);
