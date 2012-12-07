/*
 *	LDbLLinkedList: Double linked list item storage	<ldbllinkedlist.cpp>
 */

/* 
Copyright (c) 2012, David Newell
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met: 

1. Redistributions of source code must retain the above copyright notice, this
   list of conditions and the following disclaimer. 
2. Redistributions in binary form must reproduce the above copyright notice,
   this list of conditions and the following disclaimer in the documentation
   and/or other materials provided with the distribution.
3. Neither the name of the author nor the names of contributors may be
   used to endorse or promote products derived from this software without
   specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR
ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

The views and conclusions contained in the software and documentation are those
of the authors and should not be interpreted as representing official policies, 
either expressed or implied, of the FreeBSD Project.
*/

#include "ldbllinkedlist.h"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

LDblLinkedList::LDblLinkedList() {
	first = NULL;
	cursor = NULL;
	num_items = 0;
}

LDblLinkedList::~LDblLinkedList() {
	while(num_items > 0) {
		fprintf(stdout,"[LDblLinkedList]: Node automatically released by destructor call. Possible leaked memory from node item.\n");
		deleteNode();
	}
}

/* returns -1 if no items */
int LDblLinkedList::gotoFirst() {
	if(num_items == 0)
		return -1;
	cursor = first;
	return 0;
}

/* returns -1 if no items */
int LDblLinkedList::gotoLast() {
	if(num_items == 0)
		return -1;
	cursor = first->prev;
	return 0;
}

int LDblLinkedList::getNodeCount() {
	return num_items;
}

void * LDblLinkedList::getNodeItem() {
	return cursor->item;
}

/* Adds a node after the cursor */
// TODO: Check whether this _is_ supposed to be after or before the cursor?
void LDblLinkedList::addNode(void* additem) {
	LDblLinkedList_node* new_node = (LDblLinkedList_node*) malloc(sizeof(LDblLinkedList_node));
	if(new_node == NULL) {
		fprintf(stderr, "Out of memory\n");
		exit(1);
	}

	if(num_items == 0) {
		cursor = first = new_node;
		cursor->item = additem;
		cursor->next = cursor;
		cursor->prev = cursor;
	}
	else {
		assert(cursor != NULL);
		assert(first != NULL);
		
		new_node->item = additem;
		new_node->next = cursor->next;
		cursor->next->prev = new_node;
		cursor->next = new_node;
		new_node->prev = cursor;
	}

	num_items++;
}

int LDblLinkedList::isNodeFirst() {
	if (num_items == 0)
		return false;	
	else
		return (cursor == first);
}

int LDblLinkedList::isNodeLast() {
	if (num_items == 0)
		return false;	
	else
		return (cursor == first->prev);
}

// FIXME: return -1 if list empty or assert?
// TODO: Change this so that it either returns int false or null pointer if no item, or true or item pointer otherwise. This is a suggestion to remove the no item assert.
void LDblLinkedList::deleteNode() {
	//fprintf(stdout,"[LDblLinkedList]: [DELETE]: In deleteNode()...\n");
	LDblLinkedList_node* grued_node = cursor;
	assert(num_items > 0);

	if(num_items == 1) {
		//fprintf(stdout,"[LDblLinkedList]: [DELETE]: There can only be one! Setting list pointers to NULL\n");
		// This is the last node.
		first = NULL;
		cursor = NULL;
	}
	else {
		//fprintf(stdout,"[LDblLinkedList]: [DELETE]: Not the last list item. Orphaning this node.\n");
		cursor->prev->next = cursor->next;
		cursor->next->prev = cursor->prev;

		//fprintf(stdout,"[LDblLinkedList]: [DELETE]: Moving cursor back one.\n");
		cursor = cursor->prev;
		if (first == grued_node) {
			//fprintf(stdout,"[LDblLinkedList]: [DELETE]: First points to the grue'd node; moving it to cursor.\n");
			first = cursor;
			}
	}

	//fprintf(stdout,"[LDblLinkedList]: [DELETE]: Freeing  node\n");
	free(grued_node);
	//fprintf(stdout,"[LDblLinkedList]: [DELETE]: Decrementing item count\n");
	num_items--;
}

void LDblLinkedList::gotoNext() {
	assert(num_items > 0);
	cursor = cursor->next;
}

void LDblLinkedList::gotoPrev() {
	assert(num_items > 0);
	cursor = cursor->prev;
}

