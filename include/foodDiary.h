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
#include "linkedList.h"

typedef struct tracker {
	int vegfruitCount;
	int meatCount;
	int dairyCount;
	int grainsCount;
	int fatCount;
	double vegfruitCal;
	double meatCal;
	double dairyCal;
	double grainsCal;
	double fatCal;
}tracker;

/*************************************************************************************************************
Function: parseString
Purpose: To convert string containing struct elements into struct by parsing string and calling createRecord. 
Pre: Takes in pointer to string containing struct elements.
Post: Returns pointer to the newly created struct.
*************************************************************************************************************/
Food * parseString(char * string);

/*************************************************************************************************************
Function: 
Purpose: 
Pre: 
Post: 
*************************************************************************************************************/
double updateTracker(tracker * calTracker, Food * newFood, double calories);

/*************************************************************************************************************
Function: 
Purpose: 
Pre: 
Post: 
*************************************************************************************************************/
void printAverage(tracker * calTracker);

/*************************************************************************************************************
Function: 
Purpose: 
Pre: 
Post: 
*************************************************************************************************************/
double getAverage(int count, double calories);