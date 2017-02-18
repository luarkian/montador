#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "montador.h"

int main(){

	FILE *in = fopen("entrada.txt", "r");
	FILE *saida = fopen("saida.txt","w");
	LISTA list;
	char *token;
	char *test;
	char linha[100];
	int contLinha = 0;

	if(in == NULL){
		printf("Nao foi possivel abrir o arquivo");
		exit(1);
	}

/*PRIMEIRA LEITURA DO ARQUIVO P/ PEGAR OS LABEL
*
*/
	 while (!feof(in))
  {
  	++contLinha;
	fgets(linha, 100, in);	
	test = memchr(linha,':',strlen(linha));
	
	if(test != NULL){
		token = strtok(linha,":");
		printf(" %s \n",token);
		//inserirLista(list,token,contLinha);
	}
  }

  contLinha = 0;
/*
 * PASSAGEM PARA LER O PROGRAMA
 */
   while (!feof(in))
  {
  	++contLinha;
	fgets(linha, 100, in);
	token = strtok(linha," ");
	
  }
  /*
   * GERAR OS BINARIOS E ESCREVER NO ARQUIVO DE SAIDA
   */

  	//inserirLista(list,token,2);
 	//imprimir(list);
	
	free(list);
	fclose(in);
	fclose(saida);

return 0;
}