/*
 * applications.c
 *
 *  Created on: Feb 4, 2020
 *      Author: Youssef Harby
 */

/*- INCLUDES -----------------------------------------------*/

#include "stack.h"
#include "queue.h"
#include "linkedLists.h"
#include <string.h>

ST_stackInfo gstr_stack1;
ST_stackInfo gstr_stack2;

ST_queueInfo gstr_queue1;
ST_queueInfo gstr_queue2;

ST_list gstr_list1;
ST_list gstr_list2;

uint8_t checkForBalancedParantheses(sint8_t* expression);

sint64_t evaluate(sint8_t* expression);

int main(void)
{
//	sint32_t x;

	ST_node* ptr = NULL;
	createList(&gstr_list1);

	insertToList(&gstr_list1, 1, 6);
	insertToList(&gstr_list1, 2, 4);
	insertToList(&gstr_list1, 5, 3);
	insertToList(&gstr_list1, 1, 2);

	ptr = searchIntoList(&gstr_list1, 5);

	if(ptr != NULL)
		printf("%ld\n", ptr->data);


//	printList(&gstr_list1);

//	deleteFromList(&gstr_list1, 3, &x);
//	printf("%ld removed from list\n", x);

	printList(&gstr_list1);

	return 0;
}


//sint64_t result = evaluate("(-+5[0+4]0-5*{2}/(10))");
//
//
//printf("%d\n", result);
//
//return 0;
//

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


sint64_t evaluate(sint8_t* expression)
{
	uint16_t au16_index = 0;
	sint32_t temp = 0;
	sint32_t number = 0;
	sint64_t result = 0;
	uint8_t operation = '+';
	uint16_t au16_numberOfValidCharacters = 0;

	if(checkForBalancedParantheses(expression) == 0)
	{
		printf("Incorrect order\n");
	}else if(checkForBalancedParantheses(expression) == 1)
	{
		printf("Correct order\n");
	}

	createQueue(&gstr_queue1, strlen(expression));

	while(expression[au16_index])
	{
		if(expression[au16_index] == '+' ||
				expression[au16_index] == '-' ||
				expression[au16_index] == '/' ||
				expression[au16_index] == '*' ||
				(expression[au16_index] >= '0' && expression[au16_index] <= '9'))
		{
			enqueue(&gstr_queue1, expression[au16_index]);
			au16_numberOfValidCharacters++;
		}

		au16_index++;
	}

	while(au16_numberOfValidCharacters > 0)
	{
		dequeue(&gstr_queue1, &temp);

		if(temp >= '0' && temp <= '9')
		{
			number = number * 10 + (temp - 48);

			if(au16_numberOfValidCharacters == 1)
			{
				switch(operation)
				{
				case '+':
					result += number;
					break;
				case '-':
					result -= number;
					break;
				case '/':
					result /= number;
					break;
				case '*':
					result *= number;
					break;
				}

				number = 0;
			}
		}else
		{
			switch(operation)
			{
			case '+':
				result += number;
				break;
			case '-':
				result -= number;
				break;
			case '/':
				result /= number;
				break;
			case '*':
				result *= number;
				break;
			}

			number = 0;
			operation = temp;
		}

		au16_numberOfValidCharacters--;
	}

	free(gstr_queue1.queueTop);

	return result;
}

uint8_t checkForBalancedParantheses(sint8_t* expression)
{
	uint16_t au16_index = 0;
	sint32_t a16_testingVariable = 0;
	uint8_t au8_flag = 0;

	createStack(&gstr_stack1, strlen(expression));

	while(expression[au16_index])
	{
		a16_testingVariable = 0;
		if(expression[au16_index] == '(' || expression[au16_index] == '[' || expression[au16_index] == '{')
		{
			push(&gstr_stack1, expression[au16_index]);
			au8_flag++;
		}else if(expression[au16_index] == ')' || expression[au16_index] == ']' || expression[au16_index] == '}')
		{
			pop(&gstr_stack1, &a16_testingVariable);
			au8_flag--;

			switch(a16_testingVariable)
			{
			case '(':
				if(expression[au16_index] != ')')
				{
					free(gstr_stack1.stackTop);
					return 0;
				}
				break;
			case '[':
				if(expression[au16_index] != ']')
				{
					free(gstr_stack1.stackTop);
					return 0;
				}
				break;
			case '{':
				if(expression[au16_index] != '}')
				{
					free(gstr_stack1.stackTop);
					return 0;
				}
				break;
			default:
				return 0;
				break;
			}
		}

		au16_index++;
	}

	free(gstr_stack1.stackTop);

	if(au8_flag == 0)
		return 1;
	else
		return 0;
}
