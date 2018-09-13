/* 2018-08-25 (as of writing this header)
* Assignment 0 created by Isabel Herrick for CS 201 @UA
* The purpose of the program is to create a dynamic array,
* a circular dynamic array, and a queue & stack based on those.
*/


#include <stdio.h>
#include <stdlib.h>
#include "da.h"  
#include "integer.h"

int main(void) {
	DA *items = newDA();
	setDAdisplay(items, &displayINTEGER);
	setDAfree(items, &freeINTEGER);
	debugDA(items, 1);

	//insert 100 values, starting at one
	for (int i = 1; i <= 100; i++) {
		insertDAback(items, newINTEGER(i));
	}
	printf("Insert 100 values, starting at one: ");  displayDA(items, stdout); printf("\n");

	//remove 70 values from the back
	for (int i = 0; i < 70; i++) {
		freeINTEGER(removeDAback(items));
	}
	printf("Remove 70 values from the back: "); displayDA(items, stdout); printf("\n");

	//insert 40 values at the beginning
	for (int i = 101; i <= 140; i++) {
		insertDA(items, 0, newINTEGER(i));
	}
	printf("Insert 101-140 at the beginning: "); displayDA(items, stdout); printf("\n");

	//Empty the array
	while (sizeDA(items) > 0) {
		freeINTEGER(removeDAback(items));
	}
	printf("Empty the array: ");  displayDA(items, stdout); printf("\n");
	printf("Size of empty array: %d\n", sizeDA(items));

	//fill it with values from the back
	for (int i = 1; i < 100; i++) {
		insertDAback(items, newINTEGER(i));
	} printf("Insert 1-99 at the back: "); displayDA(items, stdout); printf("\n");


	//insert 10 values in the center
	for (int i = 201; i <= 240; i++) {
		insertDA(items, (sizeDA(items)) / 2, newINTEGER(i)); 
	}
	printf("Insert 201-240 in the center: "); displayDA(items, stdout); printf("\n");

	//remove 15 values in the center
	for (int i = 0; i < 15; i++) {
		freeINTEGER(removeDA(items, 1));
	}printf("Remove the first 15 values after 1: "); displayDA(items, stdout); printf("\n");

	freeDA(items);
}