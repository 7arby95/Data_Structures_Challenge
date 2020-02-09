/*
 * applications.c
 *
 *  Created on: Feb 4, 2020
 *      Author: Youssef Harby
 */

/* THIS FILE CONTAINS ONLY THE DECLARATION AND IMPLEMENTATION OF THE REQUIRED APPLICATIONS OF THE 3 DRIVERS */

/*- INCLUDES -----------------------------------------------*/

#include "stack.h"
#include "queue.h"
#include "linkedLists.h"
#include <string.h>

/* Global structures for testing */

ST_stackInfo gstr_stack1;
ST_stackInfo gstr_stack2;

ST_queueInfo gstr_queue1;
ST_queueInfo gstr_queue2;

ST_list gstr_list1;
ST_list gstr_list2;


/* Required API's prototypes */

uint8_t checkForBalancedParantheses(sint8_t* expression);

sint64_t evaluate(sint8_t* expression);


int main(void)
{
//	sint32_t test;
//
//	createQueue(&gstr_queue1, 3);
//
//	enqueue(&gstr_queue1, 1);
//	printf("%ld enqueued\n", *(gstr_queue1.rearPointer));
//	dequeue(&gstr_queue1, &test);
//	printf("%ld dequeued\n", test);
//
//	enqueue(&gstr_queue1, 2);
//	printf("%ld enqueued\n", *(gstr_queue1.rearPointer));
//	dequeue(&gstr_queue1, &test);
//	printf("%ld dequeued\n", test);
//
//	enqueue(&gstr_queue1, 3);
//	printf("%ld enqueued\n", *(gstr_queue1.rearPointer));
//	dequeue(&gstr_queue1, &test);
//	printf("%ld dequeued\n", test);
//
//	enqueue(&gstr_queue1, 4);
//	printf("%ld enqueued\n", *(gstr_queue1.rearPointer));
//	dequeue(&gstr_queue1, &test);
//	printf("%ld dequeued\n", test);
//
//	enqueue(&gstr_queue1, 5);
//	printf("%ld enqueued\n", *(gstr_queue1.rearPointer));
//	dequeue(&gstr_queue1, &test);
//	printf("%ld dequeued\n\n", test);
//
//	enqueue(&gstr_queue1, 1);
//	printf("%ld enqueued\n", *(gstr_queue1.rearPointer));
//
//	enqueue(&gstr_queue1, 2);
//	printf("%ld enqueued\n", *(gstr_queue1.rearPointer));
//
//	enqueue(&gstr_queue1, 3);
//	printf("%ld enqueued\n", *(gstr_queue1.rearPointer));
//
//	enqueue(&gstr_queue1, 4);
//	printf("%ld enqueued\n", *(gstr_queue1.rearPointer));
//
//	enqueue(&gstr_queue1, 5);
//	printf("%ld enqueued\n\n", *(gstr_queue1.rearPointer));
//
//	dequeue(&gstr_queue1, &test);
//	printf("%ld dequeued\n", test);
//
//	dequeue(&gstr_queue1, &test);
//	printf("%ld dequeued\n", test);
//
//	dequeue(&gstr_queue1, &test);
//	printf("%ld dequeued\n", test);
//
//	dequeue(&gstr_queue1, &test);
//	printf("%ld dequeued\n", test);
//
//	dequeue(&gstr_queue1, &test);
//	printf("%ld dequeued\n", test);

////	sint32_t x;
//
//	ST_node* ptr = NULL;
//	createList(&gstr_list1);
//
//	insertToList(&gstr_list1, 1, 6);
//	insertToList(&gstr_list1, 2, 4);
//	insertToList(&gstr_list1, 5, 3);
//	insertToList(&gstr_list1, 1, 2);
//
//	ptr = searchIntoList(&gstr_list1, 5);
//
//	if(ptr != NULL)
//		printf("%ld\n", ptr->data);
//
//
////	printList(&gstr_list1);
//
////	deleteFromList(&gstr_list1, 3, &x);
////	printf("%ld removed from list\n", x);
//
//	printList(&gstr_list1);


//
//	sint32_t example = 0;
//
//	example = checkForBalancedParantheses("({)}");
//
//	switch(example)
//	{
//	case 1:
//		printf("Correct order\n");
//		break;
//	case 0:
//		printf("Incorrect order\n");
//		break;
//	default:
//
//		break;
//	}
//
//	return 0;

	return 0;
}

sint64_t evaluate(sint8_t* expression)
{
	/* A variable to loop the required expression characters */
	uint16_t au16_index = 0;
	/* A variable to store each number/operation */
	sint32_t a32_temp = 0;
	/* A variable to store the resulting number of each set of numbers stored in the temp variable */
	sint32_t a32_number = 0;
	/* A variable to store the result of the mathematical operations */
	sint64_t a64_result = 0;
	/* A variable to store the operations (initial condition is + for first element) */
	uint8_t au8_operation = '+';
	/* A variable for looping the valid characters within the required expression */
	uint16_t au16_numberOfValidCharacters = 0;

	/* Doing the first part of the API which is required to decide whether the parentheses are in
	 * the right order or not */
	if(checkForBalancedParantheses(expression) == 0)
	{
		printf("Incorrect order\n");
	}else if(checkForBalancedParantheses(expression) == 1)
	{
		printf("Correct order\n");
	}

	/* Creating a queue to store the valid characters within the expression */
	createQueue(&gstr_queue1, strlen(expression));

	/* loop the expression characters until the null character */
	while(expression[au16_index])
	{
		/* If the current character is valid */
		if(expression[au16_index] == '+' ||
				expression[au16_index] == '-' ||
				expression[au16_index] == '/' ||
				expression[au16_index] == '*' ||
				(expression[au16_index] >= '0' && expression[au16_index] <= '9'))
		{
			/* store it in the queue (enqueue it) */
			enqueue(&gstr_queue1, expression[au16_index]);
			/* Incrementing the counter of valid characters */
			au16_numberOfValidCharacters++;
		}
		/* Incrementing the index counter */
		au16_index++;
	}

	/* Loop the queue a number of times equal to the number of valid characters */
	while(au16_numberOfValidCharacters > 0)
	{
		/* dequeue each valid character */
		dequeue(&gstr_queue1, &a32_temp);

		/* If it is a number */
		if(a32_temp >= '0' && a32_temp <= '9')
		{
			/* then concatenate every set of numbers into a valid number */
			a32_number = a32_number * 10 + (a32_temp - 48);

			/* A special condition in case this is the last valid character */
			if(au16_numberOfValidCharacters == 1)
			{
				/* A switch-case condition to decide which operation this is */
				switch(au8_operation)
				{
				case '+':
					a64_result += a32_number;
					break;
				case '-':
					a64_result -= a32_number;
					break;
				case '/':
					a64_result /= a32_number;
					break;
				case '*':
					a64_result *= a32_number;
					break;
				}

				/* Resetting the value of the number to create another one */
				a32_number = 0;
			}
		}else
		{
			/* A switch-case condition to decide which operation this is */
			switch(au8_operation)
			{
			case '+':
				a64_result += a32_number;
				break;
			case '-':
				a64_result -= a32_number;
				break;
			case '/':
				a64_result /= a32_number;
				break;
			case '*':
				a64_result *= a32_number;
				break;
			}

			/* Resetting the value of the number to create another one */
			a32_number = 0;
			/* Storing the operation in the temp variable to be able to be used as a next operation */
			au8_operation = a32_temp;
		}

		/* Decrementing the counter of valid characters */
		au16_numberOfValidCharacters--;
	}

	/* Free the queue whole size after being done with the application to avoid memory wasting */
	free(gstr_queue1.queueTop);

	return a64_result;
}

uint8_t checkForBalancedParantheses(sint8_t* expression)
{
	/* A variable to loop the required expression */
	uint16_t au16_index = 0;
	/* A variable to store the popped character from the stack */
	sint32_t a16_currentCharacter = 0;
	/* A flag to decide if each pushed element is popped or not */
	uint8_t au8_flag = 0;

	/* Creating a stack for the operation */
	createStack(&gstr_stack1, strlen(expression));

	/* looping the expression characters until the null character */
	while(expression[au16_index])
	{
		/* reset the current character variable before accessing it */
		a16_currentCharacter = 0;
		/* In case the character is the opening of a bracket of any type */
		if(expression[au16_index] == '(' || expression[au16_index] == '[' || expression[au16_index] == '{')
		{
			/* Push it to the stack */
			push(&gstr_stack1, expression[au16_index]);
			/* One push */
			au8_flag++;
		}
		/* In case the character is the closing of a bracket of any type */
		else if(expression[au16_index] == ')' || expression[au16_index] == ']' || expression[au16_index] == '}')
		{
			/* Pop it from the stack */
			pop(&gstr_stack1, &a16_currentCharacter);
			/* One pop */
			au8_flag--;

			/* A switch-case condition to decide which type of brackets this one is */
			switch(a16_currentCharacter)
			{
			case '(':
				/* In case the order is not correct */
				if(expression[au16_index] != ')')
				{
					/* freeing the stack size after being done with the application purpose */
					free(gstr_stack1.stackTop);
					return 0;
				}
				break;
			case '[':
				/* In case the order is not correct */
				if(expression[au16_index] != ']')
				{
					/* freeing the stack size after being done with the application purpose */
					free(gstr_stack1.stackTop);
					return 0;
				}
				break;
			case '{':
				/* In case the order is not correct */
				if(expression[au16_index] != '}')
				{
					/* freeing the stack size after being done with the application purpose */
					free(gstr_stack1.stackTop);
					return 0;
				}
				break;
			default:
				return 0;
				break;
			}
		}

		/* Incrementing the index of the expression characters */
		au16_index++;
	}

	/* freeing the stack size after being done with the application purpose */
	free(gstr_stack1.stackTop);

	/* A final decision in case the order is correct but the brackets in the expression are not symmetrical */
	if(au8_flag == 0)
		return 1;
	else
		return 0;
}
