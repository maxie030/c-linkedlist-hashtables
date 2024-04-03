#include <stdio.h>
#include <stdlib.h>
#include "hashtable.h"

HashTable* createHashtable(size_t key, size_t value) {
	struct HashTable* map = (HashTable*) malloc(sizeof(HashTable));

	if (!map) return NULL;

	map->nodes = NULL;
	map->keySize = key;
	map->valueSize = value;
	map->size = 0;
	return map;
}

HTNode* createHTNode(void* key, void* value) {
	HTNode* node = malloc(sizeof(HTNode));

	if (node == NULL) return NULL;

	node->key = key;
	node->value = value;
	node->next = NULL;
	return node;
}

void put(HashTable* map, void* key, void* value) {
	if (map->nodes != NULL) {
		HTNode* current = map->nodes;
		while (current->next != NULL) {
			if (current->key == key) {
				printf("Key '%d' already exists\n", key);
				return;
			}
			current = current->next;
		}
		current->next = createHTNode(key, value);
	}
	else 
		map->nodes = createHTNode(key, value);

	++map->size;
}



void printHashTable(HashTable* map) {
	HTNode* current = map->nodes;
	
	printf("{");
	while (current != NULL) {
		if (current->next != NULL) {
			printf("%d: ", *(int*) current->key);
			printf("%f, ", *(double*) current->value);
		} else {
			printf("%d: ", *(int*) current->key);
			printf("%f", *(double*) current->value);
		}
		current = current->next;
	}
	printf("}\n");
}


