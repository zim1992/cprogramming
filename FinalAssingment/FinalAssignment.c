#include <stdio.h>
#include <stdlib.h>
typedef struct student student;
typedef struct course course;
typedef struct exam exam;
typedef struct stats stats;
FILE *file, *file2;

struct student {
	short id;		/* unique identity of the student			*/
	char name[30]; 		/* name of student 					*/
	int age;		/* age of student					*/
};
struct course {
	short id;		/* unique identity of the course			*/
	char name[30]; 		/* name of course 					*/
};
struct exam {
	struct student* student;	/* pointer to student 					*/
	struct course* course;		 /*pointer to the course				*/
	short grade;		/* grade obtained by student for this exam		*/
};
struct student stud[50];
void input_student_info(int *studRecIncriment)
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
			// printf("\t%d", readLocation);
			switch(readLocation){
				case 0://reads the first value
					tempIdChar[incrimenter]=letter;
					incrimenter++;
					// printf("%s\n", "a");
					break;
				case 1://waits for the tabs to pass
					incrimenter=0;
					// printf("%s\n", "b");
					break;
				case 2://reads the 2nd value
					stud[*studRecIncriment].name[incrimenter]=letter;
					incrimenter++;
					// printf("%s\n", "c");
					break;
				case 3://waits for the tabs
					stud[*studRecIncriment].name[incrimenter]='\0';
					readLocation=4;
					// printf("%s\n", "d");
					break;
				case 4://
					incrimenter = 0;
					// printf("%s\n", "e");
					break;
				case 5: // reads the last value
					tempAgeChar[incrimenter] = letter;
					incrimenter++;
					break;
				case 6: //logs the data
					stud[*studRecIncriment].id = atoi(tempIdChar);
					stud[*studRecIncriment].age = atoi(tempAgeChar);
					incrimenter = 0;
					// printf("%d\t", stud[*studRecIncriment].id);
					// while(stud[*studRecIncriment].name[incrimenter]!='\0')
					// 	printf("%c",stud[*studRecIncriment].name[incrimenter++]);
					// incrimenter = 0;
					// printf("%s", "\t");					
					// printf("%d\n", stud[*studRecIncriment].age);
					*studRecIncriment=*studRecIncriment+1;	
					readLocation = 0;
					break;
				}
			secLastChar = lastChar;

		}
			
		fclose(file);
	}

}
void input_course_info()
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
	if(file2){

	}

}
void input_exam_info()
{

}
int main()
{
	int studentRec=0;
	int incrimenter;
	input_student_info(&studentRec);
	for(int count=0;count<studentRec;count++){
		printf("%d\t", stud[count].id);
		incrimenter = 0;
		while(stud[count].name[incrimenter]!='\0')
			printf("%c",stud[count].name[incrimenter++]);
		incrimenter = 0;
		printf("%s", "\t");					
		printf("%d\n", stud[count].age);

	}

	/* code */
	return 0;
}