/*
 *	LDblLinkedList: Double linked list item storage	<ldbllinkedlist.h>
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

#ifndef _LDblLinkedList_H
#define _LDblLinkedList_H

typedef struct LDblLinkedList_node_ {
	void * item;
	struct LDblLinkedList_node_* next;
	struct LDblLinkedList_node_* prev;

} LDblLinkedList_node;

//! LDblLinkedList Data Structure
/*! Stores any datatype in a double-linked list data structure.
 */
class LDblLinkedList {
	private:
		LDblLinkedList_node* first;
		LDblLinkedList_node* cursor;
		int num_items;

	public:
		//! Creates a new LDblLinkedList linked list
		/*!
		 * \return	Pointer to new LDblLinkedList
		 */
		LDblLinkedList();
		//! Destructor for LDblLinkedList
		~LDblLinkedList();

		//! Moves the cursor to the first list item
		/*!
		 * \return	true if successful; false if no list items
		 */
		int gotoFirst();
		//! Moves the cursor to the last list item
		/*!
		 * \return	true if successful; false if no list items
		 */
		int gotoLast();
		//! Gets number of nodes
		/*!
		 * \return	Number of nodes
		 */
		int getNodeCount();
		//! Returns the item at the current list position
		/*!
		 * \return	Pointer to item
		 */
		void * getNodeItem();
		//! Returns the item at the current list position
		/*!
		 * \param	additem	Pointer to item to add
		 */
		void addNode(void* additem);

		//! Returns if the current list position is the first item
		/*!
		 * \return	true if first item; false otherwise or if no list items
		 */
		int isNodeFirst();
		//! Returns if the current list position is the last item
		/*!
		 * \return	true if last item; false otherwise or if no list items
		 */
		int isNodeLast();
 
		//! Removes the current node
		/*! This will throw an assert if there are no list items
		 */
		void deleteNode();
		//! Moves the cursor to the next node
		void gotoNext();
		//! Moves the cursor to the next node
		void gotoPrev();
};

#endif

