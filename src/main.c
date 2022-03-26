#include "hash.h"

int main(){
	HashTable h;
	int M = 7;
	
	Initialize(&h, M);
	Imprime(&h);

	printf("\n\n");
	Insert(&h, 10, 2020);
	Insert(&h, 20, 4020);
	Insert(&h, 30, 5020);
	Imprime(&h);
	printf("\n\n");
	printf("Value:%d\n", getValue(&h, 20));
	printf("Value:%d\n", getValue(&h, 30));
	printf("Value:%d\n", getValue(&h, 10));

	Insert(&h, 40, 1000);
	Insert(&h, 41, 1000);
	Insert(&h, 42, 1000);
	Insert(&h, 43, 1000);

	printf("\n\n");
	Imprime(&h);


	return 0;
	
}
