#include <stdio.h>
//#define NDEBUG
#include <assert.h>
#include "LinkedList.h"

int main() {
	struct LinkedList* list = createLinkedList();

	addToEnd(list, 1);
	assert(get(list, 0) == 1);

	addToEnd(list, 2);
	addToEnd(list, 3);
	addToEnd(list, 4);
	addToEnd(list, 5);
	addToEnd(list, 6);

	assert(size(list) == 6);

	addToIndexPosition(list, 4, 22);
	assert(get(list, 4) == 22);
	assert(size(list) == 7);

	print(list);
	printf("size: %d\n", size(list));
	printf("value: %d\n", get(list, 1));

	changeValueOnPosition(list, 0, 40);
	assert(get(list, 0) == 40);

	print(list);

	//printf("%d\n", get(head, 0));
	//printf("hello wordl");
	//free(list);
	return 0;
}