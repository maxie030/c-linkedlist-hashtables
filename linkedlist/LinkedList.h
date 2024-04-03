#ifndef LINKEDLIST_H
#define LINKEDLIST_H

typedef struct Node Node;

typedef struct LinkedList LinkedList;

struct LinkedList* createLinkedList();
struct Node* getNewNode(int x);
void addToEnd(struct LinkedList* list, int value);
void addToIndexPosition(struct LinkedList* list, unsigned int pos, int value);
void changeValueOnPosition(struct LinkedList* list, unsigned int pos, int value);
int get(struct LinkedList* list, int index);
long size(struct LinkedList* list);
void print(struct LinkedList* list);

struct Node {
	int data;
	struct Node* next;
};

struct LinkedList {
	Node* head;
};

#endif