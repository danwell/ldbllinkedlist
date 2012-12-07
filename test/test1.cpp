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
	printf("Moving forward one node...\n");
	mylist->gotoNext();
	listInfo(mylist);
	printf("Moving forward one node...\n");
	mylist->gotoNext();
	listInfo(mylist);
	printf("Moving forward one node...\n");
	mylist->gotoNext();
	listInfo(mylist);
	printf("Moving backward one node...\n");
	mylist->gotoPrev();
	listInfo(mylist);
	printf("Moving backward one node...\n");
	mylist->gotoPrev();
	listInfo(mylist);
	printf("Moving backward one node...\n");
	mylist->gotoPrev();
	listInfo(mylist);
	printf("Grabbing node item and freeing it\n");
	myint = (int*) mylist->getNodeItem();
	delete myint;
	mylist->deleteNode();
	listInfo(mylist);
	printf("Moving forward one node...\n");
	mylist->gotoNext();
	listInfo(mylist);
	printf("Moving forward one node...\n");
	mylist->gotoNext();
	listInfo(mylist);
	printf("Moving forward one node...\n");
	mylist->gotoNext();
	listInfo(mylist);
	printf("Moving backward one node...\n");
	mylist->gotoPrev();
	listInfo(mylist);
	printf("Moving backward one node...\n");
	mylist->gotoPrev();
	listInfo(mylist);
	printf("Moving backward one node...\n");
	mylist->gotoPrev();
	listInfo(mylist);
	printf("Deleting datastructure.\n");
	delete mylist;
	printf("Done.\n");
	return 0;
}

