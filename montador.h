#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MEMORIA 4194340 // 0x400024

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
#define SB_OP 0x28;

#define ZERO 0
#define AT 1
#define V0 2
#define V1 3
#define A0 4
#define A1 5
#define A2 6
#define A3 7
#define T0 8
#define T1 9
#define T2 10
#define T3 11
#define T4 12
#define T5 13
#define T6 14
#define T7 15
#define S0 16
#define S1 17
#define S2 18
#define S3 19
#define S4 20
#define S5 21
#define S6 22
#define S7 23
#define T8 24
#define T9 25
#define K0 26
#define K1 27
#define GP 28
#define SP 29
#define FP 30
#define RA 31

struct Node{
 char label[15];
 int linha;
 int adrress;
 struct Node *prox;
};
typedef struct Node node;

int identifica(char *s);

void libera(node *PILHA);

void exibe(node *PILHA);

node* aloca();

void push(node *PILHA, char *lab, int lin);

void inicia(node *PILHA);

/* FUNÇÃO DE BUSCAR NA LISTA OS LABELS
*/
int buscaLista(node *L, char *lab);

 // funcoes de montagem de binarios

int monta_add(int rs, int rt, int rd);

int monta_addi(int rs, int rt, int imm);

int monta_sub(int rs, int rt, int rd);

int monta_beq(int rs, int rt, int label);

int monta_bne(int rs, int rt, int label);

int monta_nor(int rs, int rt, int rd);

int monta_and(int rs, int rt, int rd);

int monta_andi(int rs, int rt, int imm);

int monta_or(int rs, int rt, int rd);

int monta_ori(int rs, int rt, int imm);

int monta_j(int target);

int monta_jal(int target);

int monta_jr(int rs);

int monta_sw(int rt,int rs, int imm);

int monta_lw(int rt,int rs, int imm);

int monta_lb(int rt,int rs, int imm);

int monta_sb(int rt,int rs,int imm);

int monta_slt(int rs, int rt, int rd);

int monta_slti(int rs, int rt, int imm);

int monta_sll(int rs, int rt, int shamt);

int monta_srl(int rs, int rt, int shamt);

int id_registrador(char *reg);

int funcoes_tipo_r(char *reg, int rs, int rt, int rd);

int funcoes_tipo_i(char *reg, int rs,int rt,int imm);

int funcoes_tipo_j(char *reg, int target);
