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
void input_student_info()
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
					tempName[incrimenter]=letter;
					incrimenter++;
					// printf("%s\n", "c");
					break;
				case 3://waits for the tabs
					tempName[incrimenter]='\0';
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
					short id = atoi(tempIdChar);
					printf("%d\t", id);
					incrimenter = 0;
					while(tempName[incrimenter]!='\0')
						printf("%c",tempName[incrimenter++]);
					incrimenter = 0;
					printf("%s", "\t");
					int age = atoi(tempAgeChar);
					printf("%d\n", age);
						
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

}
void input_exam_info()
{

}
int main()
{
	input_student_info();
	/* code */
	return 0;
}