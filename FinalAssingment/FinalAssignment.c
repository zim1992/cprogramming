#include <stdio.h>
#include <stdlib.h>
#include "dataStorer.h"

int main()
{
	int studentRec=0;
	int courseRec=0;
	int numberOfResults =0;
	int menuSelector=0;
	int programExiter = 0;
	struct student studData[50];
	struct course corsMat[50];
	struct exam examResult[50];
	printf("%s\n","This program will be used to record information regarding students , Courses and exams.\n");
	/*This is the option menu which runs the program*/
	while(!programExiter){
		printf("%s\n","Please use the following menu to run the program\n1) Add student records\n2) Add courses Information\n3) Input exam results\n4) Calculate course statistics\n5) Remove results if higher grades available\n6) Show Student information\n7) Show Course information\n8) Show statistics\n9) Exit the program");
		scanf("%d",&menuSelector);
		switch(menuSelector){
			/*This adds the data stored about students  */
			case 1: input_student_info(studData, &studentRec);
				break;
			case 2: input_course_info(corsMat, &courseRec);
				break;
			case 3: input_exam_info(examResult, &numberOfResults, corsMat, &courseRec,studData, &studentRec);
				break;
			case 4:
				break;
			case 5:
				break;
			/*This prints the stored records to the consol*/
			case 6: printStudentInformation(studData, &studentRec);
				break;
			/*This Prints all the data stored in exams*/
			case 7:	printCorsInformation(corsMat, &courseRec);
				break;
			case 8:
				break;
			case 9: programExiter = 1;
				break;
			default: 
				break;

		}
		
	}
	
	return 0;
}