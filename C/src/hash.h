#ifndef HASHTABLE_H 
#define HASHTABLE_H

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct Entry Entry;
struct Entry {
	int key;
	int value;
};

typedef struct Table Table;
struct Table {
    Entry** table;
	int tamanho;
	int quantidade;
	int collisions;
};

void printHash(Table* t);
Table* criaHash(int tam);
void insertHash(Table* t, int valor);
void removeHash(Table* t, int valor);
Entry* searchHash(Table* t, int valor);
bool ePrimo(int n);
int proxPrimo(int N);
#endif