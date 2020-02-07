/*
 * stack.h
 *
 *  Created on: Feb 4, 2020
 *      Author: Youssef Harby
 */

#ifndef STACK_H_
#define STACK_H_

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

typedef enum ST_stackStatus{
	STACK_EMPTY = 0,
	STACK_FULL = 1,
	STACK_NORMAL_CONDITION = 2
}ST_stackStatus;

/*- STRUCTS AND UNIONS -------------------------------------*/

typedef struct ST_stackInfo{
	/* current index of the stack. */
	uint16_t count;

	/* full size of the stack. */
	uint16_t size;

	/* points at the last element that has been pushed to the stack. */
	sint32_t* stackPointer;

	/* points at the stack (used for dynamic allocation and points at the first element of the stack). */
	struct ST_stackInfo* stackTop;
}ST_stackInfo;


/*- FUNCTION DECLARATIONS ----------------------------------*/

/**
 * Description: A function to create a new stack with a specific size
 * @param info: address of the stack control block structure
 * @param size: the required size of the new stack
 */
extern void createStack(ST_stackInfo* info, uint16_t size);

/**
 * Description: A function to push an element to the stack
 * @param info: address of the stack control block structure
 * @param data: the data which is to be pushed to the stack
 */
extern void push(ST_stackInfo* info, sint32_t data);

/**
 * Description: A function to pop an element from the stack
 * @param info: address of the stack control block structure
 * @param data: address of the variable which is to carry the data that will be popped from the stack
 */
extern void pop(ST_stackInfo* info, sint32_t* data);


/* Bonus API's Prototypes */

/**
 * Description: A function to check the status of the stack whether it is full, empty or in a normal condition
 * @param info: address of the stack control block structure
 * @return status of the stack
 */
extern sint8_t stackStatus(ST_stackInfo* info);

/**
 * Description: A function to print the stack
 * @param info: address of the stack control block structure
 */
extern void printStack(ST_stackInfo* info);

/**
 * Description: A function to get the last element that has been pushed to the stack
 * @param info: address of the stack control block structure
 * @return last element that has been pushed to the stack
 */
extern sint32_t stackPeek(ST_stackInfo* info);


#endif /* STACK_H_ */
