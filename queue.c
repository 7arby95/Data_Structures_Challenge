/*
 * queue.c
 *
 *  Created on: Feb 4, 2020
 *      Author: Youssef Harby
 */

/*- INCLUDES -----------------------------------------------*/

#include "queue.h"


void createQueue(ST_queueInfo* info, sint32_t maxSize)
{
	/* store the stack size in the structure */
	info->size = maxSize;

	/* reservation of the required memory size in the heap */
	info->queueTop = (ST_queueInfo*)malloc((info->size)*sizeof(sint32_t));

	/* queue front pointer of the created queue which points at the first element to be
	 * removed from the queue */
	info->frontPointer = (sint32_t*)(info->queueTop);

	/* stack pointer of the created stack which points at the last element to be removed
	 * from the queue */
	info->rearPointer = (sint32_t*)(info->queueTop);
}

void enqueue(ST_queueInfo *info, sint32_t data)
{
	/* In case this is the first element of the queue */
	if(info->count == 0)
	{
		/* an assertion to make sure the pointer doesn't point at address 0 before
		 * dereferencing it */
		assert(info->rearPointer != NULL);
		/* Placing the data in the next position in the queue */
		*(info->rearPointer) = data;

		/* Incrementing the counter of queue elements */
		info->count++;
	}
	/* In case the queue is full */
	else if(info->count == info->size)
	{
		printf("The queue is full\n");
	}
	/* In case the queue isn't empty or full */
	else
	{
		/* Incrementing the "rear" pointer to the next place and fill that next place with
		 * the required data */
		info->rearPointer++;
		if(info->rearPointer == (sint32_t*)info->queueTop + info->size)
			info->rearPointer = (sint32_t*)info->queueTop;
		*(info->rearPointer) = data;

		/* Incrementing the counter of queue elements */
		info->count++;
	}
}

void dequeue(ST_queueInfo *info, sint32_t* data)
{
	/* In case the queue is empty */
	if(info->count == 0)
	{
		printf("The queue is empty\n");
	}else
	{
		/* assertions to make sure the pointers don't point at address 0 before dereferencing
		 * them */
		assert(info->frontPointer != NULL);
		assert(data != NULL);
		/* Taking out the data from the "front" pointer and storing it in the address of the
		 * local pointer */
		*data = *(info->frontPointer);
		/* Incrementing the "front" pointer to point to the next element in the queue */
		info->frontPointer++;

		/* An operation to make the queue circular */
		if(info->frontPointer == (sint32_t*)info->queueTop + info->size)
			info->frontPointer = (sint32_t*)info->queueTop;
		else if(info->frontPointer > info->rearPointer
				|| ((info->rearPointer - info->frontPointer == info->size - 1) && (info->count == 1)))
			info->frontPointer--;

		/* Decrementing the counter of queue elements */
		info->count--;
	}
}

