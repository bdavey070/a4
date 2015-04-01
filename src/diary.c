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

Food * parseString(char * string) {
	char * name;
	char * group;
	double calories;
	char * typePtr;
	char type;
	Food * tempFood;
	name = strtok(string, ",");
	group = strtok(NULL, ",");
	calories = atof(strtok(NULL, ","));
	typePtr = strtok(NULL, ",");
	type = *typePtr;
	tempFood = createRecord(name, group, calories, type);
	return tempFood;
}

double updateTracker(tracker * calTracker, Food * toBeAdded, double calories) {
	if (strcmp(toBeAdded->foodGroup, "vegfruit") == 0) {
		calTracker->vegfruitCount = calTracker->vegfruitCount + 1;
		calTracker->vegfruitCal = calTracker->vegfruitCal + toBeAdded->calories;
	} else if (strcmp(toBeAdded->foodGroup, "meat") == 0) {
		calTracker->meatCount = calTracker->meatCount + 1;
		calTracker->meatCal = calTracker->meatCal + toBeAdded->calories;
	} else if (strcmp(toBeAdded->foodGroup, "dairy") == 0) {
		calTracker->dairyCount = calTracker->dairyCount + 1;
		calTracker->dairyCal = calTracker->dairyCal + toBeAdded->calories;
	} else if (strcmp(toBeAdded->foodGroup, "grains") == 0) {
		calTracker->grainsCount = calTracker->grainsCount + 1;
		calTracker->grainsCal = calTracker->grainsCal + toBeAdded->calories;
	} else if (strcmp(toBeAdded->foodGroup, "fat") == 0) {
		calTracker->fatCount = calTracker->fatCount + 1;
		calTracker->fatCal = calTracker->fatCal + toBeAdded->calories;
	}
	calories = calories + toBeAdded->calories;
	return calories;
}

void printAverage(tracker * calTracker) {
	double tempDouble = 0.00;
	tempDouble = getAverage(calTracker->vegfruitCount, calTracker->vegfruitCal);
	if (calTracker->vegfruitCount != 0 && calTracker->vegfruitCal != 0){
		printf("%.2f\n", tempDouble);
	} else {
		printf("0.00\n");
	}
	tempDouble = getAverage(calTracker->meatCount, calTracker->meatCal);
	if (calTracker->meatCount != 0 && calTracker->meatCal != 0){
		printf("%.2f\n", tempDouble);
	} else {
		printf("0.00\n");
	}
	tempDouble = getAverage(calTracker->dairyCount, calTracker->dairyCal);
	if (calTracker->dairyCount != 0 && calTracker->dairyCal != 0){
		printf("%.2f\n", tempDouble);
	} else {
		printf("0.00\n");
	}
	tempDouble = getAverage(calTracker->grainsCount, calTracker->grainsCal);
	if (calTracker->grainsCount != 0 && calTracker->grainsCal != 0){
		printf("%.2f\n", tempDouble);
	} else {
		printf("0.00\n");
	}
	tempDouble = getAverage(calTracker->fatCount, calTracker->fatCal);
	if (calTracker->fatCount != 0 && calTracker->fatCal != 0){
		printf("%.2f\n", tempDouble);
	} else {
		printf("0.00\n");
	}
}

double getAverage(int count, double calories) {
	double average = 0.00;
	average = calories/count;
	return average;
}
