#include <stdio.h>
#include <stdlib.h>
typedef struct student student;
typedef struct course course;
typedef struct exam exam;
typedef struct stats stats;
FILE *file, *file2;
struct student {
	short id;		/* unique identity of the student	*/
	char name[30]; 	/* name of student 					*/
	int age;		/* age of student					*/
};
struct course {
	short id;		/* unique identity of the course	*/
	char name[30]; 	/* name of course 					*/
};
struct exam {
	struct student* student;	/* pointer to student 						*/
	struct course* course;		/* pointer to the course					*/
	short grade;				/* grade obtained by student for this exam	*/
};
struct student stud[50];
struct course cors[50];
void input_student_info(int *studRecIncriment)
{
	int lastChar; /*This is used to store the */
	int secLastChar;
	char tempIdChar[3];
	int tempId;
	int clearHeader = 0;
	int incrimenter=0;
	char letter;
	char tempAgeChar[2];
	int optionSelector;
	file = fopen("students.txt", "r");
	if(file==NULL)
	{
		printf("%s\n","couldn't load the file" );
		exit(1);
	}
	if(file)
	{
		int readLocation = 0;
		while((lastChar=getc(file))!= EOF)
		{
			/*Used to skip the first line as it contains the names for the tables*/
			
			while((clearHeader==0)&&((lastChar=getc(file))!= EOF))
			{
				if(lastChar==13)
				{
					clearHeader = 1;
					lastChar = getc(file);
				}
			}
			if((secLastChar==9&&lastChar!=secLastChar)||secLastChar!=lastChar&&lastChar==9||lastChar==13)
			{
				readLocation++;
			}
			char letter = (char) lastChar;
			switch(readLocation){
				case 0://reads the first value
					tempIdChar[incrimenter]=letter;
					incrimenter++;
					break;
				case 1://waits for the tabs to pass
					incrimenter=0;
					break;
				case 2://reads the 2nd value
					stud[*studRecIncriment].name[incrimenter]=letter;
					incrimenter++;
					break;
				case 3://adds an end charicter.
					stud[*studRecIncriment].name[incrimenter]='\0';
					readLocation=4;
					break;
				case 4://Sets the incrimenter back to 0
					incrimenter = 0;
					break;
				case 5: // reads the last value
					tempAgeChar[incrimenter] = letter;
					incrimenter++;
					break;
				case 6: //logs the data
					stud[*studRecIncriment].id = atoi(tempIdChar);
					stud[*studRecIncriment].age = atoi(tempAgeChar);
					incrimenter = 0;
					*studRecIncriment=*studRecIncriment+1;	//Used to increase the record count
					readLocation = 0;
					break;
				}
			secLastChar = lastChar;
		}
			
		fclose(file);
	}

}
void input_course_info(int *coursRecNum)
{
	int lastChar;
	int secLastChar;
	char tempName[30];
	char tempIdChar[3];
	int tempId;
	int clearHeader = 0;
	int incrimenter=0;
	char letter;
	char tempAgeChar[2];
	file2 = fopen("courses.txt", "r");
	
	if(file2==NULL)
	{
		printf("%s\n","couldn't load the file" );
		exit(1);
	}
	if(file2)
	{

		int readLocation = 0;
		while((lastChar=getc(file2))!= EOF)
		{
			/*Used to skip the first line as it contains the names for the tables*/
			
			while((clearHeader==0)&&((lastChar=getc(file2))!= EOF))
			{
				if(lastChar==13)
				{
					clearHeader = 1;
					lastChar = getc(file2);
				}
			}
			if((secLastChar==9&&lastChar!=secLastChar)||secLastChar!=lastChar&&lastChar==9||lastChar==13)
			{
				readLocation++;
			}
			char letter = (char) lastChar;
			// printf("\t%d", readLocation);
			switch(readLocation){
				case 0://reads the first value
					tempIdChar[incrimenter]=letter;
					incrimenter++;
					break;
				case 1://waits for the tabs to pass
					incrimenter=0;
					break;
				case 2://reads the 2nd value
					cors[*coursRecNum].name[incrimenter]=letter;
					incrimenter++;
					break;
				case 3://Adds an end charicter 
					cors[*coursRecNum].name[incrimenter]='\0';
					readLocation=4;
					break;
				case 4://
					cors[*coursRecNum].id = atoi(tempIdChar);
					incrimenter = 0;
					*coursRecNum=*coursRecNum+1;	//Used to increase the record count
					readLocation = 0;
					break;
				}
			secLastChar = lastChar;

		}
			
		fclose(file2);
	}

}
void input_exam_info()
{

}
int main()
{
	int studentRec=0;
	int examCourseRec=0;
	int incrimenter;
	int menuSelector=0;
	int programExiter = 0;
	printf("%s\n","This program will be used to record information regarding students , Courses and exams.\n");
	/*This is the option menu which runs the program*/
	while(!programExiter){
		printf("%s\n","Please use the following menu to run the program\n1) Add student records\n2) Add courses Information\n3) Input exam results\n4) Calculate course statistics\n5) Remove results if higher grades available\n6) Show Student information\n7) Show Course information\n8) Show statistics\n9) Exit the program");
		scanf("%d",&menuSelector);
		switch(menuSelector){
			/*This inputs the data into the */
			case 1: input_student_info(&studentRec);
				break;
			case 2: input_course_info(&examCourseRec);
				break;
			case 3:
				break;
			case 4:
				break;
			case 5:
				break;
			/*This prints the stored records to the consol*/
			case 6:	for(int count=0;count<studentRec;count++){
						printf("%d\t", stud[count].id);
						incrimenter = 0;
						while(stud[count].name[incrimenter]!='\0')
							printf("%c",stud[count].name[incrimenter++]);
						incrimenter = 0;
						printf("%s", "\t");					
						printf("%d\n", stud[count].age);

					}
				break;
			case 7:	for(int count=0;count<examCourseRec;count++){
						printf("%d\t", cors[count].id);
						incrimenter = 0;
						while(cors[count].name[incrimenter]!='\0')
							printf("%c",cors[count].name[incrimenter++]);
						incrimenter = 0;
						printf("%s","\n" );
					}
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