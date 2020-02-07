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

	/* queue front pointer of the created queue which points at the first element to be removed from the queue */
	info->frontPointer = (sint32_t*)(info->queueTop);

	/* stack pointer of the created stack which points at the last element to be removed from the queue */
	info->rearPointer = (sint32_t*)(info->queueTop);
}

void enqueue(ST_queueInfo *info, sint32_t data)
{
	if(info->count == 0)
	{
		assert(info->rearPointer != NULL);
		*(info->rearPointer) = data;
		info->count++;
	}else if(info->count == info->size)
	{
		printf("The queue is full\n");
		fflush(stdout);
	}else
	{
		info->rearPointer++;
		if(info->rearPointer == (sint32_t*)info->queueTop + info->size)
			info->rearPointer = (sint32_t*)info->queueTop;
		*(info->rearPointer) = data;
		info->count++;
	}
}

void dequeue(ST_queueInfo *info, sint32_t* data)
{
	if(info->count == 0)
	{
		printf("The queue is empty\n");
		fflush(stdout);
	}else
	{
		assert(info->frontPointer != NULL);
		assert(data != NULL);
		*data = *(info->frontPointer);
		info->frontPointer++;
		if(info->frontPointer == (sint32_t*)info->queueTop + info->size)
			info->frontPointer = (sint32_t*)info->queueTop;
		else if(info->frontPointer > info->rearPointer
				|| ((info->rearPointer - info->frontPointer == info->size - 1) && (info->count == 1)))
			info->frontPointer--;
		info->count--;
	}
}

