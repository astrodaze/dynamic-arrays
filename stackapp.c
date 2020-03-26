/*	stack.c: Stack application. */
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "dynamicArray.h"



/* ***************************************************************
Using stack to check for unbalanced parentheses.
***************************************************************** */

/* Returns the next character of the string, once reaches end return '0' (zero)
	param: 	s pointer to a string 	
			
*/
char nextChar(char* s)
{
	static int i = -1;	
	char c;
	++i;	
	c = *(s+i);			
	if ( c == '\0' )
		return '\0';	
	else 
		return c;
}
/*
 * ===  FUNCTION  ==========================================================
 *         Name:  stringlength(char string[])
 *  Description:  Takes string array as an arg and returns the size
 * =========================================================================
 */
int stringLength(char string[])
{
	int size = 0;
	while (string[size] != '\0')
	{
		size++;
	}
	return size;

}
/*
 * ===  FUNCTION  ==========================================================
 *         Name:  int isSymbol(char x)
 *  Description:  Takes a char as an arg and checks whether it is a symbol
 * =========================================================================
 */
int isSymbol(char x)
{
	if (x == '{' || x == '}' || x == '[' || x == ']' || x == ')' || x == '(')
	{
		return 1;
	}
	return 0;
}
/*
 * ===  FUNCTION  ==========================================================
 *         Name:  containsSymbols(char *s)
 *  Description:  Takes pointer and checks if the string contains symbols
 * =========================================================================
 */
int containsSymbols(char *s)
{
	for (int i = 0; i < stringLength(s); i++)
	{
		if (isSymbol(s[i]) == 1)
		{
			return 1;
		}
	}
	return 0;
}

/* Checks whether the (), {}, and [] are balanced or not
	param: 	s pointer to a string 	
	pre: 	
	post:	
*/
int isBalanced(char* s)
{
	/* FIXME: You will write this function */
	DynArr *myStack;
	myStack = newDynArr(6);   //stack with 6 capacity
	char x = nextChar(s);
	while(x != '\0')
	{
		//if opening symbol, push closing symbol to the stack
		if(x == '(')
		{
			pushDynArr(myStack, ')');

		}
		if(x == '{')
		{
			pushDynArr(myStack, '}');
		}
		if(x == '[')
		{
			pushDynArr(myStack, ']');
		}
		//if char is a closing symbol, compare it to the top of the stack
		//return 0 if the stack is empty or it does not match the top
		if(x == ')')
		{
			//if the stack is empty or the top does not match x
			if(isEmptyDynArr(myStack) || topDynArr(myStack) != x)
			{
				deleteDynArr(myStack);
				return 0;
			}
			if(topDynArr(myStack) == x)
			{
				popDynArr(myStack);
			}
		}
		if(x == '}')
		{
			//if the stack is empty or the top does not match x
			if(isEmptyDynArr(myStack) || topDynArr(myStack) != x)
			{
				deleteDynArr(myStack);
				return 0;
			}
			if(topDynArr(myStack) == x)
			{
				popDynArr(myStack);
			}
		}
		if(x == ']')
		{
			//if the stack is empty or the top does not match x
			if(isEmptyDynArr(myStack) || topDynArr(myStack) != x)
			{
				deleteDynArr(myStack);
				return 0;
			}
			if(topDynArr(myStack) == x)
			{
				popDynArr(myStack);
			}
		}
		x = nextChar(s);
	}

	//stack should be empty if the expression is balanced
	if(isEmptyDynArr(myStack))
	{
		deleteDynArr(myStack);
		return 1;
	}
	deleteDynArr(myStack);
	return 0;
}



int main(int argc, char* argv[]){
	
	char* s=argv[1];	
	int res;
	
	printf("Assignment 2\n");

	//if string is null, then it is balanced
	if(s==0)
	{
		printf("The string %s is balanced\n",s);
		return 0;
	}

	do
	{
		//rejects strings that are empty or do not have brackets
		if(s == 0 || stringLength(s) <= 0 || containsSymbols(s) == 0)
		{
			printf("\nInvalid input.\n");
			printf("Enter a string with parenthesis or brackets to evaluate: ");
			fgets(s, 100, stdin);
		}
	}while(s == 0 ||stringLength(s) <= 0 || containsSymbols(s) == 0); 

	res = isBalanced(s);

	if (res)
		printf("The string %s is balanced\n",s);
	else 
		printf("The string %s is not balanced\n",s);
	
	return 0;	
}

