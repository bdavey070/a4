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
#include "foodDiary.h"

int main(int argc, char * argv[]) {
	char path[100];
	char token[50];
	char ** foodStringArray;
	FILE * input;
	int i = 0;
	if (argc != 2) {
		printf("Incorrect command line arguments\n");
		exit(0);
	}
	strcpy(path, argv[1]);
	input = fopen(path, "r");
	foodStringArray = malloc(sizeof(char * )*100);
	while(fgets(token, 50, input) != NULL) {
		strcpy(foodStringArray[i], token);
		i++;
	}

	return 0;
}