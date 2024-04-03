#ifndef LINKEDLIST_H
#define LINKEDLIST_H

typedef struct Node Node;

typedef struct LinkedList LinkedList;

LinkedList* createLinkedList();
Node* getNewNode(int x);
void addToEnd(LinkedList* list, int value);
void addToIndexPosition(LinkedList* list, unsigned int pos, int value);
void changeValueOnPosition(LinkedList* list, unsigned int pos, int value);
int get(LinkedList* list, int index);
long size(LinkedList* list);
void print(LinkedList* list);

struct Node {
	int data;
	struct Node* next;
};

struct LinkedList {
	Node* head;
};

#endif