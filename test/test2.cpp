#include <stdlib.h>
#include <stdio.h>
#include "ldbllinkedlist.h"
#include <assert.h>

void listInfo(LDblLinkedList* list) {
	if (list->getNodeCount() == 0)
		printf("[TEST]: Nodes: %i\tFirst?\t%i\tLast? %i\t\tValue: No nodes\n",list->getNodeCount(),list->isNodeFirst(),list->isNodeLast());
	else
		printf("[TEST]: Nodes: %i\tFirst?\t%i\tLast? %i\t\tValue: %i\n",list->getNodeCount(),list->isNodeFirst(),list->isNodeLast(),*((int*) list->getNodeItem()));
	printf("\n");
}

int main() {
	int *myint;
	int i;
	printf("Creating list.\n");
	LDblLinkedList *mylist = new LDblLinkedList();
	listInfo(mylist);
	printf("Adding int of value 7...\n");
	myint = (int*) malloc(sizeof(int));
	*myint = 7;
	mylist->addNode(myint);
	listInfo(mylist);
	printf("Adding int of value 12...\n");
	myint = (int*) malloc(sizeof(int));
	*myint = 12;
	mylist->addNode(myint);
	listInfo(mylist);
	printf("Adding int of value 24...\n");
	myint = (int*) malloc(sizeof(int));
	*myint = 24;
	mylist->addNode(myint);
	listInfo(mylist);
	printf("Adding int of value 36...\n");
	myint = (int*) malloc(sizeof(int));
	*myint = 36;
	mylist->addNode(myint);
	listInfo(mylist);
	printf("Moving to end of list...\n");
	mylist->gotoLast();
	listInfo(mylist);
	printf("Adding int of value 48...\n");
	myint = (int*) malloc(sizeof(int));
	*myint = 48;
	mylist->addNode(myint);
	listInfo(mylist);
	printf("\nMoving forwards ten times...\n");
	for(i = 0; i < 10; i++) {
		mylist->gotoNext();
		listInfo(mylist);
		}
	printf("\nMoving backwards ten times...\n");
	for(i = 0; i < 10; i++) {
		mylist->gotoNext();
		listInfo(mylist);
		}
	printf("\nDeleting datastructure.\n");
	delete mylist;
	printf("Done.\n");
	return 0;
}
