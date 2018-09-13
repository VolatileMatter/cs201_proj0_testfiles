/* 2018-08-25 (as of writing this header)
* Assignment 0 created by Isabel Herrick for CS 201 @UA
* The purpose of the program is to create a dynamic array,
* a circular dynamic array, and a queue & stack based on those.
*/


#include <stdio.h>
#include <stdlib.h>
#include "cda.h"  
#include "integer.h"

int main(void) {
	CDA *items = newCDA();
	setCDAdisplay(items, &displayINTEGER);
	setCDAfree(items, &freeINTEGER);
	debugCDA(items, 11);
	printf("INITIALIZATION SUCCESSFUL.\n");

	//insert 100 values, starting at one
	for (int i = 1; i <= 100; i++) {
		//printf("Inserting %d...\n", i);
		insertCDAback(items, newINTEGER(i));
	}
	printf("Insert 100 values, starting at one: ");  displayCDA(items, stdout);

	//remove 70 values from the back
	for (int i = 0; i < 70; i++) {
		freeINTEGER(removeCDAback(items));
	}
	printf("Remove 70 values from the back: "); displayCDA(items, stdout);

	
	//insert 40 values at the beginning
	for (int i = 101; i <= 140; i++) {
		insertCDA(items, 0, newINTEGER(i));
	}
	printf("Insert 101-140 at the beginning: "); displayCDA(items, stdout);

	/*//Empty the array
	while (sizeCDA(items) > 0) {
		freeINTEGER(removeCDAback(items));
	}
	printf("Empty the array: ");  displayCDA(items, stdout);
	printf("Size of empty array: %d\n", sizeCDA(items)); */

	freeCDA(items);
}