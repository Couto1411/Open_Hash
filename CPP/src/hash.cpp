#include "hash.hpp"

Table* criaHash(int tam){
    Table* t = new Table;
    if (t == nullptr)
    {
        return nullptr;
    }
    t->quantidade = 0;
	t->collisions =0;
    t->tamanho = proxPrimo(2*tam);
    t->table = new Entry*[t->tamanho];
    return t;
}

void insertHash(Table* t, int valor){
	int achou=0;
	int index = valor % t->tamanho;
	if (t->table[index] != nullptr){
		index = (valor*index+t->tamanho)%t->tamanho;
		while (t->table[index]!=nullptr&&achou<2){
			index++;
			if (index>=t->tamanho){
				index=0;
				achou+=1;
			}
			t->collisions+=1;
		}
		t->collisions+=1;
	}
	if ((float)t->quantidade / t->tamanho >= 1){
		Table* nova = new Table;
		nova->quantidade = 0;
		nova->collisions =t->collisions;
		nova->tamanho = proxPrimo(2*t->tamanho);;
		nova->table = new Entry*[nova->tamanho];
		for (int i = 0; i < t->tamanho; i++)
		{
			if (t->table[i]!=nullptr)
				insertHash(nova,t->table[i]->value);
		}
		t->table=nova->table;
		t->quantidade=nova->quantidade;
		t->collisions=nova->collisions;
		t->tamanho=nova->tamanho;
		insertHash(t,valor);
	}
	else{
		t->table[index] = new Entry;
		t->table[index]->key = index;
		t->table[index]->value = valor;
		t->quantidade++;
	}
}

void removeHash(Table* t, int valor){
	int achou=0,diminui=0;
	int index = valor % t->tamanho;
	if (t->table[index] != nullptr && t->table[index]->value==valor){
		free(t->table[index]);
		t->table[index]=nullptr;
		t->quantidade--;
	}
	else{
		index = (valor*index+t->tamanho)%t->tamanho;
		while ((t->table[index]==nullptr||t->table[index]->value!=valor)&&achou<2){
			index++;
			if (index>=t->tamanho){
				index=0;
				achou+=1;
			}
			diminui+=1;
		}
		diminui+=1;
		if (achou<2){
			free(t->table[index]);
			t->table[index]=nullptr;
			t->quantidade--;
			t->collisions=t->collisions-diminui;
		}
	}
}

Entry* searchHash(Table* t, int valor){
	int achou=0;
	int index = valor % t->tamanho;
	if (t->table[index] != nullptr && t->table[index]->value==valor)
		return t->table[index];
	else{
		index = (valor*index+t->tamanho)%t->tamanho;
		while ((t->table[index]==nullptr||t->table[index]->value!=valor)&&achou<2){
			index++;
			if (index>=t->tamanho){
				index=0;
				achou+=1;
			}
		}
		if (achou<2)
			return t->table[index];
	}
	return nullptr;
}

void printHash(Table* t){
	printf("Hash de tamanho: %d\n",t->tamanho);
	for (int i = 0; i < t->tamanho; i++)
	{
		if (t->table[i]!=nullptr)
			printf("%d: %d\n",i,t->table[i]->value);
	}
	printf("Houveram %d colisoes.\n", t->collisions);
}

bool ePrimo(int n){
    if (n <= 1)  return false;
    if (n <= 3)  return true;

    if (n%2 == 0 || n%3 == 0) return false;
   
    for (int i=5; i*i<=n; i=i+6)
        if (n%i == 0 || n%(i+2) == 0)
           return false;

    return true;
}

int proxPrimo(int N){
    if (N <= 1)
        return 2;
 
    int prime = N;
    bool found = false;

    while (!found) {
        prime++;
        if (ePrimo(prime))
            found = true;
    }
 
    return prime;
}