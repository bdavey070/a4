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
#include <math.h>
#include "diary.h"
#include "linkedList.h"

int main(int argc, char * argv[]) {
/*Variable initialization*/
	char path[100];
	char token[50];
	FILE * input;
	Food * tempFood;
	char * test;
	Food * theList;
	double totalCalories = 0;
	tracker * calTracker = malloc(sizeof(tracker));
	Food * healthyList = malloc(sizeof(Food));
	Food * junkList = malloc(sizeof(Food));
/*Check command line arguments*/
	if (argc != 2) {
		printf("Incorrect command line arguments\n");
		exit(0);
	}
/*Open file*/
	strcpy(path, argv[1]);
	input = fopen(path, "r");
/*Creates a healthy and junk list*/
	while (test != NULL) {
		test = fgets(token, 100, input);
		if (test != NULL) {
			tempFood = parseString(token);
			totalCalories = updateTracker(calTracker, tempFood, totalCalories);
			if (tempFood->type == 'h') {
				healthyList = addToBack(healthyList, tempFood);
			} else {
				junkList = addToBack(junkList, tempFood);
			}
		}
	}
/*Removes null member from front*/
	healthyList = removeFromFront(healthyList);
	junkList = removeFromFront(junkList);
/*Merges healthy and junk lists*/
	theList = addToBack(healthyList, junkList);
/*Prints total calories*/
	totalCalories = ceil(totalCalories);
	printf("%.0f\n", totalCalories);
/*Prints average calories/item for each food group*/
	printAverage(calTracker);
/*Prints list*/
	printList(theList);
/*Freeing memory*/
	destroyElement(theList);
	destroyList(theList);
	free(calTracker);
/*Closing file*/
	fclose(input);
	return 0;
}
