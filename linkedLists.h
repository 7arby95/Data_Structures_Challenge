/*
 * linkedLists.h
 *
 *  Created on: Feb 6, 2020
 *      Author: Youssef Harby
 */

#ifndef LINKEDLISTS_H_
#define LINKEDLISTS_H_

/*- INCLUDES -----------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "std_types.h"


/*- PREPROCESSOR MACROS ------------------------------------*/

#ifndef ERROR
#define ERROR		-1
#endif

#ifndef OK
#define OK			-1
#endif

/*- STRUCTS AND UNIONS -------------------------------------*/

typedef struct ST_list{
	/* current number of nodes in the list. */
	uint16_t count;
	/* a pointer to node to store the address of the first node in the list */
	struct ST_node* listHead;
	/* a pointer to node to store the address of the current node in the list */
	struct ST_node* currentNode;
	/* a pointer to node to store the address of the node before the current node in the list */
	struct ST_node* previousNode;
	/* a pointer to node to store the address of the node after the current node in the list */
	struct ST_node* nextNode;
}ST_list;

typedef struct ST_node{
	/* a variable to store each node's data */
	sint32_t data;
	/* a pointer to structure of type node to point to the next node in the list */
	struct ST_node* next;
}ST_node;


/*- FUNCTION DECLARATIONS ----------------------------------*/

/**
 * Description: A function to Initialize the list structure contents.
 * @param list: A pointer to structure of type list, to store initial values inthe structure of
 * the created list
 */
void createList(ST_list *list);

/**
 * Description: A function to insert a new node into the list in a specific position.
 * @param listPtr: A pointer to structure of type list to point that this is the list we need to
 * create a new node into
 * @param position: A variable to decide which position the new node will be created at
 * @param data: A variable holding the data which needs to be stored into the new node
 */
void insertToList(ST_list* listPtr, uint8_t position, sint32_t data);

/**
 * Description: A function to delete a node from the list
 * @param listPtr: A pointer to structure of type list to point that this is the list we need to
 * delete a node from.
 * @param position: A variable to decide the position of the node to be deleted
 * @param data: A pointer to variable to store the value of the data of the node to be deleted
 */
void deleteFromList(ST_list* listPtr, uint8_t position, sint32_t* data);

/**
 * Description: A function to search for a node in the list.
 * @param listPtr: A pointer to structure of type list to point that this is the list into which we
 * need to find the required node
 * @param data: A variable representing the data of the required node
 */
ST_node* searchIntoList(ST_list* listPtr, sint32_t data);

/**
 * Description: A function to print the list nodes data.
 * @param listPtr: A pointer to structure of type list to point that this is the list we need to
 * print.
 */
void printList(ST_list* listPtr);	//Bonus

void sortList(ST_list* listHead);	//Bonus

void reverseList(ST_list* listPtr);	//Bonus


#endif /* LINKEDLISTS_H_ */
