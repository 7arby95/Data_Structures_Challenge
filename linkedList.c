/*
 * linkedList.c
 *
 *  Created on: Feb 6, 2020
 *      Author: Youssef Harby
 */


#include "linkedLists.h"

void createList(ST_list *list)
{
	/* Initial values for the created list */
	/* Head points at null as this list is a new list with no nodes yet */
	list->listHead = NULL;
	/* No nodes yet, therefore the value of count = 0 */
	list->count = 0;
	/* Default values for those 3 pointers is NULL */
	list->currentNode = NULL;
	list->nextNode = NULL;
	list->previousNode = NULL;
}

void insertToList(ST_list* listPtr, uint8_t position, sint32_t data)
{
	/* A variable used for looping the list nodes */
	uint8_t au8_positionIndex = 1;

	/* Creating a new node with a pointer (link) pointing at it */
	struct ST_node* link = (struct ST_node*)malloc(sizeof(struct ST_node));

	/* Placing the required data into the new node */
	link->data = data;
	/* Default value for the link's "next" pointer is null */
	link->next = NULL;

	/* In case the node is to be added to the first position */
	if(position == 1)
	{
		/* In this case the link's "next" pointer is to point at the head in order for it to be
		 * inserted at the beginning of the list */
		link->next = listPtr->listHead;
		/* And then the head of the list is to point at the newly created node */
		listPtr->listHead = link;

		/* Incrementing the counter of nodes */
		listPtr->count++;

		return;
	}

	/* If the position for the new node isn't at the beginning of the list */
	/* Check if the list has a single node at least */
	if(listPtr->listHead == NULL)
	{
		/* If not, then this is the first node */
		/* In this case the list head is to point at the newly created node */
		listPtr->listHead = link;

		/* Incrementing the counter of nodes */
		listPtr->count++;

		return;
	}

	/* If the previous cases are not the current case then the other pointers are to be
	 * used (current, previous and next) */

	/* Initial value for the "current node" pointer is to be equal to list head */
	listPtr->currentNode = listPtr->listHead;

	/* In case of the required position value to be higher than the current number of nodes
	 * then the node is to be inserted and the end of the list */
	if(position > listPtr->count)
	{
		/* Start looping the list nodes nodes until reaching the current last node (pointing
		 * to null) */
		while(listPtr->currentNode->next != NULL)
		{
			/* Incrementing the current node value by making it point to the next node
			 * in case the current node isn't the last node (pointing to null) */
			listPtr->currentNode = listPtr->currentNode->next;
		}

		/* When reaching the current last node, make its "next" pointer point to the newly
		 * created node */
		listPtr->currentNode->next = link;

		/* Incrementing the counter of nodes */
		listPtr->count++;

		/* Resetting the "current node" pointer value to null */
		listPtr->currentNode = NULL;

		return;
	}

	/* In case the required position is in range of the current number of nodes then the
	 * technique below will be used */

	/* Initial value for the "previous node" pointer is to be equal to list head */
	listPtr->previousNode = listPtr->listHead;

	/* Start looping until the list until reaching the required position */
	while(au8_positionIndex < position)
	{
		/* This If condition is used for making the "previous node" pointer one step behind
		 * the "current node" pointer */
		if(au8_positionIndex != 1)
			listPtr->previousNode = listPtr->previousNode->next;
		/* Incrementing the current node value by making it point to the next node */
		listPtr->currentNode = listPtr->currentNode->next;

		/* Incrementing the variable responsible for looping the list */
		au8_positionIndex++;
	}

	/* Placing the new node in between of the current node and the previous node */
	link->next = listPtr->previousNode->next;
	listPtr->previousNode->next = link;

	/* Incrementing the counter of nodes */
	listPtr->count++;

	/* Resetting the pointers values to null */
	listPtr->currentNode = NULL;
	listPtr->previousNode = NULL;

	return;
}

void deleteFromList(ST_list* listPtr, uint8_t position, sint32_t* data)
{
	/* A variable used for looping the list nodes */
	uint8_t au8_positionIndex = 1;

	/* In case the position is more than the current number of nodes or position is 0,
	 * then this position is invalid */
	if(position > listPtr->count || position == 0)
	{
		printf("No such position\n");

		return;
	}

	/* In case the first node is the node to be deleted */
	if(position == 1)
	{
		/* Make the "current node" pointer point to the first node to be able to free it later */
		listPtr->currentNode = listPtr->listHead;
		/* Incrementing the "head" pointer to point to the next node */
		listPtr->listHead = listPtr->currentNode->next;

		/* Decrementing the counter of nodes */
		listPtr->count--;

		/* an assertion to make sure the pointer doesn't point at address 0 before dereferencing it */
		assert(data != NULL);
		/* Taking out the data from the node to be deleted */
		*data = listPtr->currentNode->data;
		/* And finally freeing the "current node" pointer */
		free(listPtr->currentNode);

		/* Resetting the "current node" pointer to point to null */
		listPtr->currentNode = NULL;

		return;
	}
	/* In case the position is valid and does not refer to the first node of the list */
	else
	{
		/* Setting the initial value of the pointers "current node" and "previous node"
		 * to be equal to the "head" pointer */
		listPtr->currentNode = listPtr->listHead;
		listPtr->previousNode = listPtr->listHead;

		/* Looping the list nodes until the required node is reached */
		while(au8_positionIndex < position)
		{
			/* This If condition is used for making the "previous node" pointer one step behind
			 * the "current node" pointer */
			if(au8_positionIndex != 1)
				listPtr->previousNode = listPtr->previousNode->next;
			/* Incrementing the current node value by making it point to the next node */
			listPtr->currentNode = listPtr->currentNode->next;

			/* Incrementing the variable responsible for looping the list */
			au8_positionIndex++;
		}

		/* removing the node from the list */
		listPtr->previousNode->next = listPtr->currentNode->next;

		/* Decrementing the counter of nodes */
		listPtr->count--;

		/* an assertion to make sure the pointer doesn't point at address 0 before dereferencing it */
		assert(data != NULL);
		/* Taking out the data from the node to be deleted */
		*data = listPtr->currentNode->data;
		/* And finally freeing the "current node" pointer */
		free(listPtr->currentNode);

		/* Resetting the pointers to point to null */
		listPtr->currentNode = NULL;
		listPtr->previousNode = NULL;
	}
}

ST_node* searchIntoList(ST_list* listPtr, sint32_t data)
{
	/* Check first if the list is empty */
	if(listPtr->listHead == NULL)
	{
		printf("Linked List is empty\n");

		return 0;
	}

	/* Start checking from the first node by making the "current node" pointer point to the first node */
	listPtr->currentNode = listPtr->listHead;

	/* Looping the list until the last node */
	while(listPtr->currentNode != NULL)
	{
		/* In case the node with the required data found */
		if(listPtr->currentNode->data == data)
		{
			/* Return the address of the node */
			return (listPtr->currentNode);
		}

		/* In case it wasn't found, increment the "current node" pointer to point at the next node */
		listPtr->currentNode = listPtr->currentNode->next;
	}

	/* Item not found in the list */
	printf("%ld does not exist in the list\n", data);

	return 0;
}

void printList(ST_list* listPtr)	//Bonus
{
	/* Creating a local pointer to node in order to loop the list */
	struct ST_node* ptr = listPtr->listHead;

	/* Referring to the "list head" pointer */
	printf("[head] =>");

	/* Start looping until the last node of the list */
	while(ptr != NULL)
	{
		/* Print the node data */
		printf(" %ld =>", ptr->data);
		/* Incrementing the pointer to point to the next node */
		ptr = ptr->next;
	}

	/* Referring to the "NULL" address */
	printf(" [NULL]\n");
}

void sortList(ST_list* listPtr)		//Bonus
{

}

void reverseList(ST_list* listPtr)	//Bonus
{

}
