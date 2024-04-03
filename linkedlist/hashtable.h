#ifndef HASHTABLE_H
#define HASHTABLE_H
#define	TABLE_SIZE 64

typedef struct HashTable HashTable;
typedef struct HTNode HTNode;

HashTable* createHashtable(size_t key, size_t value);
HTNode* createHTNode(void* key, void* value);
void put(HashTable* map, void* key, void* value);

void printHashTable(HashTable* map);

struct HashTable {
	size_t size;
	size_t keySize;
	size_t valueSize;
	HTNode* nodes;
};

struct HTNode {
	HTNode* next;
	void* key;
	void* value;
};


#endif
