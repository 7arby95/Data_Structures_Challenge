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
#define OK		-1
#endif

/*- STRUCTS AND UNIONS -------------------------------------*/

typedef struct ST_list{
	uint16_t count;
	struct ST_node* listHead;
	struct ST_node* currentNode;
	struct ST_node* previousNode;
	struct ST_node* nextNode;
}ST_list;

typedef struct ST_node{
	sint32_t data;
	struct ST_node* next;
}ST_node;


/*- FUNCTION DECLARATIONS ----------------------------------*/

/**
 * Description: A function to
 * @param
 * @param
 */
char createList(ST_list *list);

void insertToList(ST_list* listHead, uint8_t position, sint32_t data);

void deleteFromList(ST_list* listHead, uint8_t position, sint32_t* data);

ST_node* searchIntoList(ST_list* listHead, sint32_t data);

void printList(ST_list* listPtr);	//Bonus

void sortList(ST_list* listHead);	//Bonus

void reverseList(ST_list* listPtr);	//Bonus


#endif /* LINKEDLISTS_H_ */
