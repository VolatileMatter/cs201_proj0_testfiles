/* 2018-08-25 (as of writing this header)
* Assignment 0 created by Isabel Herrick for CS 201 @UA
* The purpose of the program is to create a dynamic array,
* a circular dynamic array, and a queue & stack based on those.
*/


#include <stdio.h>
#include <stdlib.h>
#include "stack.h"  
#include "integer.h"

int main(void) {
	STACK *items = newSTACK();
	setSTACKdisplay(items, &displayINTEGER);
	setSTACKfree(items, &freeINTEGER);

	for (int i = 1; i <= 100; i++) {
		push(items, newINTEGER(i));
	}
	displaySTACK(items, stdout); printf("\n");
	printf("\n");
	for (int i = 0; i < 50; i++) {
		pop(items);
	}
	displaySTACK(items, stdout);
	debugSTACK(items, 2);
	printf("\n\n");
	displaySTACK(items, stdout);
	printf("\n");

	freeSTACK(items);
}