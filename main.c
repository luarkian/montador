#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "montador.h"

void pegarLabel(node *list,FILE *in){
int contLinha=0;
char linha[100];
char *token;
    	 while (!feof(in))
  {
  	contLinha++;
	fgets(linha, 100, in);

	if(!(memchr(linha,':',strlen(linha))) == 0){
		token = strtok(linha,":");
       // printf("%d %s \n",contLinha,token);
		push(list,token,contLinha);
	}
  }
}

void operacoesEscrita(node *list,FILE *in,FILE *out){
    int rs=0,rt=0,rd=0, binario=0,imm=0, target=0;
    char *token, *token0, *token1, *token2;
    char linha[100];

   while (!feof(in))
  {
	fgets(linha, 100, in);

	token = strtok(linha," ");
	token0= strtok(NULL,",");

	if(identifica(token) == 1){
			/* instrução do tipo R*/
	rd = id_registrador(token0);

	token1= strtok(NULL,",");
	token2= strtok(NULL," ");

		rs = id_registrador(token1);
		rt = id_registrador(token2);

		binario = funcoes_tipo_r(token,rs,rt,rd);

		printf("0x%08x \t\t - %s %s, %s, %s  || rs:%d rt:%d rd:%d\n",binario,token , token0, token1, token2,rs,rt,rd);
		fprintf(out,"0x%08x\n",binario);
	}
	else if(identifica(token) == 2){
			/* instrução do tipo I*/

        if((strcmp(token,"sw")==0) ||(strcmp(token,"lw")==0) || (strcmp(token,"lb")==0) ||(strcmp(token,"sb")==0)){
                token1= strtok(NULL,"(");
                token2= strtok(NULL," ");

                rt= id_registrador(token0);

                imm=id_registrador(token1);
                
                if(imm < 0)
                imm = (imm & 0x0000FFFF);
                
                rs= id_registrador(token2);

                binario = funcoes_tipo_i(token,rs,rt,imm);
			}
		else if((strcmp(token,"bne")==0) ||(strcmp(token,"beq")==0)){
                token1= strtok(NULL,",");
                token2= strtok(NULL," ");

                imm =buscaLista(list,token2);

                rs = id_registrador(token0);
                rt = id_registrador(token1);


                binario = funcoes_tipo_i(token,rs,rt,imm);
		}
		else{
            token1= strtok(NULL,",");
            token2= strtok(NULL," ");

            rt = id_registrador(token0);
            rs = id_registrador(token1);
            imm = atoi(token2);

            if(imm < 0)
            imm = (imm & 0x0000FFFF);
            
            binario = funcoes_tipo_i(token,rs,rt,imm);

		}
            printf("0x%08x \t\t - %s %s, %s, %s  || rs:%d rt:%d imm:%d\n",binario,token , token0, token1, token2,rs,rt,imm);
            fprintf(out,"0x%08x\n",binario);
	}
	else if (identifica(token) == 3)
	{
			/* jumpers */
			if(strcmp(token,"jr")==0){
                
                target = 31;
			}else
			target = buscaLista(list,token0);

        binario = funcoes_tipo_j(token,target);


		printf("0x%08x \t\t - %s %s [0x%08x]\n",binario,token , token0,target);
		fprintf(out,"0x%08x\n",binario);
	}
	else;
  }

}
int main(){

	FILE *in = fopen("entrada.txt", "r");
	FILE *out = fopen("saida.txt","w");
	node *list = aloca();
	char *token,*token0,*token1,*token2;
	char *test;
	char linha[100];
	int contLinha = 0,rs=0, rd=0, rt=0, imm=0, binario=0, target=0;

	if(in == NULL){
		printf("Nao foi possivel abrir o arquivo");
		exit(1);
	}

/*PRIMEIRA LEITURA DO ARQUIVO P/ PEGAR OS LABEL
*
*/
pegarLabel(list,in);

/* TESTAR LABELS
   */
    exibe(list);

/* LEITURA INSTRUÇÕES E ESCRITA ARQUIVO DE SAIDA
 *
 */
 rewind(in);
 operacoesEscrita(list,in,out);


	free(list);
	fclose(in);
	fclose(out);

return 0;
}

