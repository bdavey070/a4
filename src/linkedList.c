/********************************************************************************************
Student Name: Benjamin Davey    Student Number: 0885413 
Date: Wednesday, April 1, 2015    Course Name: CIS2500

I have exclusive control over this submission via my password.
By including this statement in this header comment, I certify that:
     1) I have read and understood the University policy on academic integrity;
     2) I have completed the Computing with Integrity Tutorial on Moodle; and
     3) I have achieved at least 80% in the Computing with Integrity Self Test.
I assert that this work is my own. I have appropriately acknowledged any and all material
(data, images, ideas or words) that I have used, whether directly quoted or paraphrased.
Furthermore, I certify that this assignment was prepared by me specifically for this course.
**********************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedList.h"

Food * createRecord(char * name, char * group, double calories, char theType) {
	Food * item = malloc(sizeof(Food));
	item->name = malloc(sizeof(char)*25);
	item->foodGroup = malloc(sizeof(char)*10);
	strcpy(item->name, name);
	strcpy(item->foodGroup, group);
	item->calories = calories;
	item->type = theType;
	item->next = NULL;
	return item;
}

char * printRecord(Food * toPrint) {
	char * output;
	output = malloc(sizeof(char)*100);
	sprintf(output, "%s (%s):%3.2f[%c]", toPrint->name, toPrint->foodGroup, toPrint->calories, toPrint->type);
	return output;
}

void destroyElement(Food * theElement) {
	free(theElement->name);
	free(theElement->foodGroup);
}

Food * addToFront(Food * theList, Food * toBeAdded) {
	toBeAdded->next = theList;
	return toBeAdded;
}

Food * addToBack(Food * theList, Food * toBeAdded) {
	Food * current;
	current = theList;
	if (current == NULL) {
		return toBeAdded;
	} else {
		while (current->next != NULL) {
			current = current->next;
		}
		current->next = toBeAdded;
	}
	return theList;
}

Food * removeFromFront(Food * theList) {
	if (theList == NULL) {
		return NULL;
	} else if (theList->next == NULL) {
		return NULL;
	} else {
		return theList->next;
	}
}

Food * removeFromBack(Food * theList) {
	Food * current;
	Food * previous;
	if (theList == NULL) {
		return NULL;
	}
	previous = theList;
	current = theList;
	while (current->next != NULL) {
		previous = current;
		current = current->next;
	}
	previous->next = NULL;
	return theList;
}

Food * getLastItem(Food * theList) {
	Food * current = theList;
	if (theList == NULL) {
		return NULL;
	}
	while(current->next != NULL) {
		current = current->next;
	}
	return current;
}

bool isEmpty(Food * theList) {
	if (theList == NULL) {
		return true;
	} else {
		return false;
	}
}

void printList(Food * theList) {
	Food * current;
	current = theList;
	while (current->next != NULL) {
		printf("%s (%s):%3.2f[%c]\n", current->name, current->foodGroup, current->calories, current->type);
		current = current->next;
	}
	printf("%s (%s):%3.2f[%c]\n", current->name, current->foodGroup, current->calories, current->type);
}

void destroyList(Food * theList) {
	Food * current;
	Food * previous;
	if (theList->next != NULL) {
		return;
	} else {
		while (current->next != NULL) {
			previous = current;
			current = current->next;
			free(previous);
		}
	}
}
