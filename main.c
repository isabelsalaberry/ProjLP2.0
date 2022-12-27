#include "header.h"
#define PATH "C:\\temp\\projLP\\projLP\\explicandos.dat"
#define MAX_DADOS 256
#define MAX_CHAR 20



int main() {
	TExplicando vetor[MAX_DADOS];
	LimpaVetor(vetor);



	int opcao;
	TExplicando* ultimo = vetor;
	TExplicando temp;
	printf("---------------------------------------Trabalho de LP---------------------------------------");
	printf("\nInstituto Politecnico de Braganca - Engenharia Informatica - Professor Luis Manuel Alves");
	printf("\nAlunas:\tIsabel Irigon(52983) e Nelia Sofia Pires(52247)");
	printf("\nJaneiro de 2023");
	do {
		printf("\n\n\t-------------------------------------------------------------------------");
		printf("\n\t|\t\t\t\tMenu\t\t\t\t\t|\n");
		printf("\t|\t\t\t\t\t\t\t\t\t|\n");
		printf("\t|[1] Inserir a Informacao dos Explicandos\t\t\t\t|\n");
		printf("\t|[2] Gravar a Informacao dos Explicandos no Ficheiro\t\t\t|\n");
		printf("\t|[3] Ler do Ficheiro e Mostrar todos Explicandos\t\t\t|\n");
		printf("\t|[4] Procurar um explicando\t\t\t\t\t\t|\n");
		printf("\t|[0] Sair\t\t\t\t\t\t\t\t|\n");
		printf("\t-------------------------------------------------------------------------");
		printf("\nEscolha uma opcao: ");
		scanf("%d", &opcao);


		switch (opcao) {
		case 1:
			temp = EscaneiaExplicando(vetor);//consertar o enum
			InsereExplicando(temp, vetor);
			ultimo++;
			break;
		case 2:
			GravarExplicandos(vetor);
			break;
		case 3:
			LerExplicandos(vetor);
			ListarExplicandos(vetor);
			break;
		case 4:
			//LerExplicandos(vetor);
			PesquisaExplicando(vetor, ultimo);//não tá funcionando o ler do binario pro vetor e pesquisar
		}
	} while (opcao != 0);
	printf("\n\n\n Fim do programa! Obrigada pela avaliacao :D\n");
}

