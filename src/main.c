#include "hash.h"

int main(){
	Table *tabela;
	tabela=criaHash(10);
	int vetor[20]={1378, 3012, 600, 4700, 918, 175, 2051, 3653, 4558, 1210, 1468, 2724, 1055, 2143, 1136, 546, 3350, 1610, 3412, 1096};
	for (int i = 0; i < 20; i++){
		insertHash(tabela, vetor[i]);
	}
	printHash(tabela);
	if (searchHash(tabela,4558)!=NULL)
		printf("Item existe na Hash\n");
	removeHash(tabela,4558);
	printHash(tabela);
	if (searchHash(tabela,4558)!=NULL)
		printf("Item existe na Hash\n");
	else
		printf("Item nao existe na Hash\n");
	insertHash(tabela, 4558);
	insertHash(tabela, 4559);
	insertHash(tabela, 4560);
	insertHash(tabela, 4561);
	insertHash(tabela, 4562);
	insertHash(tabela, 4551);
	printHash(tabela);
	return 0;
}
