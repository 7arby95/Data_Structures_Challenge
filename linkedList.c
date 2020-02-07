/*
 * linkedList.c
 *
 *  Created on: Feb 6, 2020
 *      Author: Youssef Harby
 */


#include "linkedLists.h"

char createList(ST_list *list)
{
	list->listHead = NULL;
	list->count = 0;
	list->currentNode = NULL;
	list->nextNode = NULL;
	list->previousNode = NULL;

	return OK;
}

//					previous			current				next
//										req
//					1					2					3				4
//		HEAD --> (4, nextNode) --> (6, nextNode) --> (8, nextNode) --> (10, nextNode) --> NULL

void insertToList(ST_list* listPtr, uint8_t position, sint32_t data)
{
	uint8_t positionIndex = 1;

	struct ST_node* link = (struct ST_node*)malloc(sizeof(struct ST_node));

	link->data = data;
	link->next = NULL;

	if(position == 1)
	{
		link->next = listPtr->listHead;
		listPtr->listHead = link;

		listPtr->count++;

		return;
	}

	/* Check if the list has a single node at least */
	if(listPtr->listHead == NULL)
	{
		/* If not, then this is the first node */
		listPtr->listHead = link;
		listPtr->count++;

		return;
	}

	listPtr->currentNode = listPtr->listHead;

	if(position > listPtr->count)
	{
		while(listPtr->currentNode->next != NULL)
		{
			listPtr->currentNode = listPtr->currentNode->next;
		}

		listPtr->currentNode->next = link;
		listPtr->count++;

		listPtr->currentNode = NULL;

		return;
	}

	listPtr->previousNode = listPtr->listHead;

	while(positionIndex < position)
	{
		if(positionIndex != 1)
			listPtr->previousNode = listPtr->previousNode->next;
		listPtr->currentNode = listPtr->currentNode->next;

		positionIndex++;
	}

	listPtr->nextNode = listPtr->currentNode->next;

	link->next = listPtr->previousNode->next;
	listPtr->previousNode->next = link;
	listPtr->count++;

	listPtr->currentNode = NULL;
	listPtr->nextNode = NULL;
	listPtr->previousNode = NULL;

	return;
}

void deleteFromList(ST_list* listPtr, uint8_t position, sint32_t* data)
{
	uint8_t positionIndex = 1;

	if(position > listPtr->count || position == 0)
	{
		printf("No such position\n");

		return;
	}

	if(position == 1)
	{
		listPtr->currentNode = listPtr->listHead;
		listPtr->listHead = listPtr->currentNode->next;
		listPtr->count--;

		*data = listPtr->currentNode->data;
		free(listPtr->currentNode);

		listPtr->currentNode = NULL;

		return;
	}else
	{
		listPtr->currentNode = listPtr->listHead;
		listPtr->previousNode = listPtr->listHead;

		while(positionIndex < position)
		{
			if(positionIndex != 1)
				listPtr->previousNode = listPtr->previousNode->next;
			listPtr->currentNode = listPtr->currentNode->next;

			positionIndex++;
		}

		listPtr->nextNode = listPtr->currentNode->next;
		listPtr->previousNode->next = listPtr->currentNode->next;
		listPtr->count--;

		*data = listPtr->currentNode->data;
		free(listPtr->currentNode);

		listPtr->nextNode = NULL;
		listPtr->currentNode = NULL;
		listPtr->previousNode = NULL;
	}
}

ST_node* searchIntoList(ST_list* listPtr, sint32_t data)
{
	int position = 1;

	// check if the linked list is empty
	if(listPtr->listHead == NULL)
	{
		printf("Linked List is empty\n");
		fflush(stdout);
		return 0;
	}

	// start checking from the first node
	listPtr->currentNode = listPtr->listHead;

	while(listPtr->currentNode != NULL)
	{
		if(listPtr->currentNode->data == data)
		{
			return (listPtr->currentNode);
		}

		listPtr->currentNode = listPtr->currentNode->next;
		position++;
	}

	// item not found in the list
	printf("%ld does not exist in the list\n", data);
	fflush(stdout);
	return 0;
}

void printList(ST_list* listPtr)	//Bonus
{
	struct ST_node* ptr = listPtr->listHead;

	printf("[head] =>");

	while(ptr != NULL)
	{
		printf(" %ld =>", ptr->data);
		ptr = ptr->next;
	}

	printf(" [NULL]\n");
}

void sortList(ST_list* listPtr)		//Bonus
{

}

void reverseList(ST_list* listPtr)	//Bonus
{

}
