#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"


struct LinkedList* createLinkedList() {
	struct LinkedList* list = malloc(sizeof(LinkedList));
	if (list == NULL) return NULL;
	list->head = NULL;
	return list;

}

struct Node* getNewNode(int x) {
	struct Node* newNode = calloc(1, sizeof(struct Node));
	if (newNode) {
		newNode->data = x;
		newNode->next = NULL;
	}
	return newNode;
}

void addToEnd(struct LinkedList* list, int value) {
	struct Node* newNode = getNewNode(value);

	if (list->head == NULL) {
		list->head = newNode;
		return;
	}

	struct Node* last = list->head;

	while (last->next != NULL) {
		last = last->next;
	}

	last->next = newNode;
}

void addToIndexPosition(struct LinkedList* list, unsigned int pos, int value) {
	Node* current = list->head;
	struct Node* node = getNewNode(value);
	if (pos == 0) {
		node->next = list->head;
		list->head = node;
		return;
	}

	while (pos != 1) {
		current = current->next;
		pos--;
	}

	node->next = current->next;
	current->next = node;
}

void changeValueOnPosition(struct LinkedList* list, unsigned int pos, int value) {
	Node* current = list->head;
	if (current == NULL || current->next == NULL) {
		printf("Index out of range.\n");
		exit(1);
	}
	while (pos != 0) {
		current = current->next;
		pos--;
	}

	if (pos > 0 || pos < 0) {
		printf("Index out of range.\n");
		exit(1);
	}

	current->data = value;
}


int get(struct LinkedList* list, int index) {
	Node* current = list->head;

	while (index != 0) {
		current = current->next;
		index--;
		if (current == NULL) {
			printf("Index out of range.\n");
			exit(1);
		}
	}
	return current->data;
}

long size(struct LinkedList* list) {
	if (list == NULL || list->head == NULL) return 0;

	Node* current = list->head;

	unsigned int count = 0;

	while (current != NULL) {
		current = current->next;
		count++;
	}

	return count;
}

void print(struct LinkedList* list) {
	if (list->head == NULL) return;

	Node* current = list->head;

	printf("[");
	while (current != NULL) {
		if (current->next != NULL) printf("%d, ", current->data);
	
		if (current->next == NULL) printf("%d", current->data);

		current = current->next;
	}
	printf("]\n");
}