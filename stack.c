/*
 * stack.c
 *
 *  Created on: Feb 4, 2020
 *      Author: Youssef Harby
 */


/*- INCLUDES -----------------------------------------------*/

#include "stack.h"

/*- APIs IMPLEMENTATION ------------------------------------*/

void createStack(ST_stackInfo* info, uint16_t size)
{
	/* store the stack size in the structure */
	info->size = size;

	/* reservation of the required memory size in the heap */
	info->stackTop = (ST_stackInfo*)malloc((info->size)*sizeof(sint32_t));

	/* index of the space of the element that will be added next */
	info->count = 0;

	/* stack pointer of the created stack which points at the space of the element that will be added next */
	info->stackPointer = (sint32_t*)(info->stackTop);
}

void push(ST_stackInfo* info, sint32_t data)
{
	/* check first if the stack is not full before pushing */
	if(stackStatus(info) != STACK_FULL)
	{
		/* an assertion to make sure the pointer doesn't point at address 0 before dereferencing it */
		assert(info->stackPointer != NULL);

		/* pushing the data to the stack */
		*(info->stackPointer) = data;

		/* incrementing the stack pointer to the next place */
		info->stackPointer++;

		/* incrementing the counter */
		info->count++;
	}else
	{
		/* Do nothing, as the stack is full. */
	}
}


/* Bonus API's Implementation */

void pop(ST_stackInfo* info, sint32_t* data)
{
	/* check first if the stack is not empty before popping from it */
	if(stackStatus(info) != STACK_EMPTY)
	{
		/* an assertion to make sure the pointer doesn't point at address 0 before dereferencing it */
		assert(info->stackPointer != NULL);

		/* an assertion to make sure the pointer doesn't point at address 0 before dereferencing it */
		assert(data != NULL);

		/* decrementing the stack pointer to the previous place */
		info->stackPointer--;

		/* popping the data from the stack */
		*data = *(info->stackPointer);

		/* decrementing the counter */
		info->count--;
	}else
	{
		/* Do nothing, as the stack is empty. */
	}
}

sint8_t stackStatus(ST_stackInfo* info)
{
	if(info->count == 0)
	{
		/* return status is empty in case the counter value equals 0 */
		return STACK_EMPTY;
	}else if(info->count == info->size)
	{
		/* return status is full in case the counter value equals the location of the last element place */
		return STACK_FULL;
	}else
	{
		/* otherwise, return status is normal condition */
		return STACK_NORMAL_CONDITION;
	}
}

void printStack(ST_stackInfo* info)
{
	/* a pointer to data, pointing at the first element that has been pushed to the stack */
	sint32_t* pa32_elementAddress = (sint32_t*)(info->stackTop);
	/* a pointer to data, pointing at the last element that has been pushed to the stack */
	sint32_t* pa32_lastElementAddress = pa32_elementAddress + info->count - 1;

	/* print the elements of the stack */
	while(pa32_elementAddress < pa32_lastElementAddress)
	{
		printf("[%ld], ", *pa32_elementAddress);
		pa32_elementAddress++;
	}

	if(pa32_elementAddress == pa32_lastElementAddress)
		printf("[%ld]\n", *pa32_elementAddress);
	/* in case the stack has no elements, print the following */
	else
		printf("Stack is empty.\n");
}

sint32_t stackPeek(ST_stackInfo* info)
{
	assert(info->stackPointer != NULL);
	/* an if condition to check whether the stack is empty or not */
	if(stackStatus(info) != STACK_EMPTY)
		/* return the last element that has been pushed */
		return (*(info->stackPointer - 1));
	else
	{
		printf("Stack is empty\n");
		return ERROR;
	}
}
