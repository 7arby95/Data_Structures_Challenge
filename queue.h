/*
 * queue.h
 *
 *  Created on: Feb 4, 2020
 *      Author: Youssef Harby
 */

#ifndef QUEUE_H_
#define QUEUE_H_

/*- INCLUDES -----------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "std_types.h"


/*- PREPROCESSOR MACROS ------------------------------------*/

#ifndef ERROR
#define ERROR		-1
#endif


/*- ENUMS --------------------------------------------------*/

typedef enum ST_queueStatus{
	EMPTY = 0,
	FULL = 1,
	NORMAL_CONDITION = 2
}ST_queueStatus;


/*- STRUCTS AND UNIONS -------------------------------------*/

typedef struct ST_queueInfo{
	/* full size of the stack. */
	uint16_t size;

	/* number of elements in the queue */
	uint16_t count;

	/* points at the last element that has been pushed to the stack. */
	sint32_t* frontPointer;

	/* points at the last element that has been pushed to the stack. */
	sint32_t* rearPointer;

	/* points at the stack (used for dynamic allocation and points at the first element of the stack). */
	struct ST_queueInfo* queueTop;
}ST_queueInfo;


/*- FUNCTION DECLARATIONS ----------------------------------*/

/**
 * Description: A function to create a new queue with a specific size
 * @param info: address of the queue control block structure
 * @param size: the required size of the new queue
 */
extern void createQueue(ST_queueInfo* info, sint32_t maxSize);

/**
 * Description: A function to add a new element to the queue
 * @param info: address of the queue control block structure
 * @param data: the data to be added to the queue
 */
extern void enqueue(ST_queueInfo *info, sint32_t data);

/**
 * Description: A function to remove an element from the queue
 * @param info: address of the queue control block structure
 * @param data: address of the variable which is to carry the data that will be removed from the queue
 */
extern void dequeue(ST_queueInfo *info, sint32_t* data);


#endif /* QUEUE_H_ */
