#ifndef EXPLICANDO_H_INCLUDED
#define EXPLICANDO_H_INCLUDED
#include <stdio.h>
#define PATH "C:\temp"
#define MAX_CHAR 20
#define MAX_DADOS 100

/*
enum grau_ensino { CTeSP = 1, Licenciatura, Mestrado };
*/
typedef struct {
	char nome[MAX_CHAR];
	int grau_ensino;
	char unidade_curricular[MAX_CHAR];
	float valor_ph;
	int num_hrs;
}TExplicando;




TExplicando EscaneiaExplicando() {
	TExplicando exp;

	printf("\nInsira os dados do explicando\n");

	printf("Nome: ");
	scanf("%s", &exp.nome);
	fseek(stdin, 0, SEEK_END);

	printf("Grau de ensino [1]CTeSP [2]Licenciatura [3]Mestrado: ");
	scanf("%d", &exp.grau_ensino);

	printf("Unidade curricular: ");
	scanf("%s", &exp.unidade_curricular);
	fseek(stdin, 0, SEEK_END);

	printf("Valor por hora: ");
	scanf("%f", &exp.valor_ph);

	printf("Numero de horas: ");
	scanf("%d", &exp.num_hrs);

	return exp;
}


void LimpaVetor(TExplicando* vetor) {
	int i;
	for (i = 0; i < MAX_DADOS; i++) {
		vetor[i].num_hrs = -1;
	}
}//inicializa e limpa um vetor [MAX_DADOS]


void InsereExplicando(TExplicando exp_inserido, TExplicando* vetor) {
	int i;
	for (i = 0; i < MAX_DADOS; i++) {
		if (vetor[i].num_hrs == -1) {
			vetor[i] = exp_inserido;
			break;
		}
	}
}//procura um espaço nulo no vetor e grava o TExplicando quando encontrar*/

void GravarExplicandos(TExplicando* vetor) {

	FILE* arquivo = fopen(PATH, "wb"); //abre o arquivo em binario
	if (arquivo == NULL) {
		printf("Erro ao abrir o ficheir0 %s\n", PATH);
		exit(1);
	}

	int i, j;
	for (i = 0; vetor[i].num_hrs != -1; i++) {//Grava cada registro no arquivo
		fwrite(&vetor[i], sizeof(TExplicando), 1, arquivo);
	}
	if (i > 1)
		printf("\n %d Explicandos foram gravados.", i);
	else
		printf("\n %d Explicando foi gravado.", i);

	fclose(arquivo);
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void LerExplicandos(TExplicando* vetor) {								//nao ta gravando no vetor
	int i = 0;
	FILE* arquivo = fopen(PATH, "rb"); //abre o arquivo em binario
	if (arquivo == NULL) {
		printf("Erro ao abrir o ficheiro %s\n", PATH);
		exit(1);
	}

	for (int i = 0; i < MAX_DADOS; i++)	//lê cada registro do arquivo para o vetor
		fread(&vetor[i], sizeof(TExplicando), 1, arquivo);

	fclose(arquivo);
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void MostrarExplicando(TExplicando* vetor, TExplicando exp) {
	printf("\n\tRESULTADO DA PESQUISA");
	printf("\n Nome: %s", exp.nome);
	printf("\n Grau de ensino: %d", exp.grau_ensino);
	printf("\n Unidade curricular: %s", exp.unidade_curricular);
	printf("\n Valor por hora: %0.2fE", exp.valor_ph);
	printf("\n Numero de horas: %d", exp.num_hrs);
	putchar('\n');


}

void PesquisaExplicando(TExplicando* vetor, TExplicando* ultimo) {
	TExplicando* cur;
	char pesq[MAX_DADOS];
	fseek(stdin, 0, SEEK_END);
	printf("\nQual o nome a pesquisar? ");
	gets(pesq);
	for (cur = vetor; cur < ultimo; cur++)
		if (strstr(cur->nome, pesq) != NULL) {
			MostrarExplicando(vetor, *cur);
			return;
		}
}

void ListarExplicandos(TExplicando* vetor) {
	for (int i = 0; vetor[i].num_hrs != -1; i++) {
		printf("\n--> [%d] Explicando ", i + 1);
		printf("\n Nome: %s", vetor[i].nome);
		printf("\n Grau de ensino: %d", vetor[i].grau_ensino);
		printf("\n Unidade curricular: %s", vetor[i].unidade_curricular);
		printf("\n Valor por hora: %0.2fE", vetor[i].valor_ph);
		printf("\n Numero de horas: %d", vetor[i].num_hrs);
		putchar('\n');
	}
}


#endif