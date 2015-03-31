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

int main() {
/*Variable initializations*/
	Food * testFood;
	Food * testFoodTwo;
	Food * testFoodThree;
	char name[10] = "testname";
	char group[10] = "testgroup";
	double calorie = 10.45;
	char type = 'j';
	char * printRecordString;
/*Testing createRecord*/
	testFood = createRecord(name, group, calorie, type);
	testFoodTwo = createRecord(name, group, calorie, type);
	testFoodThree = createRecord(name, group, calorie, type);
	printf("%s\n", testFood->name);
	printf("%s\n", testFood->foodGroup);
    printf("%f\n", testFood->calories);
    printf("%c\n", testFood->type);
/*Testing printRecord*/
    printRecordString = printRecord(testFood);
    printf("%s\n", printRecordString);
    testFoodTwo = createRecord(name, group, calorie, type);
/*Testing addToFront*/
    addToFront(testFood, testFoodTwo);
/*Testing addToBack*/
    addToBack(testFoodTwo, testFoodThree);
/*Testing removeFromFront*/
    removeFromFront(testFoodTwo);
/*Testing removeFromBack*/
    removeFromBack(testFoodTwo);
/*Testing getLastItem*/
    getLastItem(testFoodTwo);
/*Testing isEmpty*/
    isEmpty(testFoodTwo);
/*Testing printList*/
    printList(testFoodTwo);
/*Testing destroyList*/
    destroyList(testFoodTwo);
/*Testing destroyElement*/
    destroyElement(testFood);
	return 0;
}