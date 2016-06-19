
typedef struct student student;
typedef struct course course;
typedef struct exam exam;
typedef struct stats stats;
int strcmp(const char *str1, const char *str2);
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
	struct student students;	/* pointer to student 						*/
	struct course course;		/* pointer to the course					*/
	short grade;				/* grade obtained by student for this exam	*/
};
struct stats {	
	struct course course;				/* pointer to a course					*/
	short numberOfPasses;		/* number of students that passed			*/
	short numberOfFails;		/* number of students that failed			*/
	short numberOfStudents;		/* number of different students for this course		*/
	// stats next;					/* pointer to next element				*/
};
void printStudentInformation(struct student stud[], int *numberOfStudents)
{
	printf("%s\n","id\tName\t\tAge");
	for(int count=0;count<*numberOfStudents;count++){
		printf("%d\t", stud[count].id);
		int incrimenter = 0;
		while(stud[count].name[incrimenter]!='\0')
			printf("%c",stud[count].name[incrimenter++]);
		incrimenter = 0;
		printf("%s", "\t");					
		printf("%d\n", stud[count].age);

	}

}
void printCorsInformation(struct course corse[], int *numberOfCourses)
{
	printf("%s\n", "id\tCourse");
	for(int count=0;count<*numberOfCourses;count++){
		printf("%d\t", corse[count].id);
		int incrimenter = 0;
		while(corse[count].name[incrimenter]!='\0')
			printf("%c",corse[count].name[incrimenter++]);
		incrimenter = 0;
		printf("%s","\n" );
	}

}
void printStatInformation(struct stats stat[], int *numberOfCourses)
{
	printf("%s\n", "course Name\tNumber of Passes\tNumber of Fails\tNumber of Students");
	for(int count=0;count<*numberOfCourses;count++){
		printf("%s\t\t", stat[count].course.name);
		printf("%d\t\t",stat[count].numberOfPasses);
		printf("%d\t\t", stat[count].numberOfFails);
		printf("%d\n", stat[count].numberOfStudents);
	}

}
void input_student_info(struct student stud[],int *studRecIncriment)
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
void input_course_info(struct course cors[], int *coursRecNum)
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
void input_exam_info(struct exam exams[], int *numberOfResults, struct course cors[], int *numberOfCourses,struct student stud[], int *numberOfStudents)
{
	int tempId;
	int studRecNum=0;
	int coursRecNum=0;
	int validator=0;
	short grade=0;
	printf("%s\n", "We are going add a grade to a student for which an exam was conducted");
	printStudentInformation(stud,numberOfStudents);
	printf("%s\n","To do so we request that you type the id of the student which you would like to add exam records of:");
	scanf("%d",&tempId);
	/*Used to search for desired student*/
	for(int counter=0;counter<*numberOfStudents;counter++){
		if(tempId==stud[counter].id){
			studRecNum = counter;
			validator=1;
			break;			
		}
	}
	if(validator==0){
		printf("%s\n", "the following record does not exist\n Please first add the following user into the file containing the record.\n\n");
	}else{
		validator=0;
		printCorsInformation(cors,numberOfCourses);
		printf("%s\n", "Could you please input the course code");
		scanf("%d",&tempId);
		/*Search for a course model*/
		for(int counter=0;counter<*numberOfCourses;counter++){
			if(tempId==cors[counter].id){
				coursRecNum=counter;
				validator=1;
				break;
			}
		}
		if(validator=0){
			printf("%s\n", "The following course code could not be found. Please add the following course code in the course file");
		}else{
			/*A grade is inputting inth the system*/
			while((grade<1)||(grade>10)){
				printf("%s\n", "Please insert the grade of the user. The grade should be between 1 and 10");
				scanf("%hu",&grade);
			}
			/*The information is stored*/
			exams[*numberOfResults].students=stud[studRecNum];
			exams[*numberOfResults].course=cors[coursRecNum];
			exams[*numberOfResults].grade=grade;
			printf("You have succesfully entered the following grade %hu was given to %s for the course %s. ",grade,exams[*numberOfResults].students.name,exams[*numberOfResults].course.name);
			*numberOfResults=*numberOfResults+1;
		}
	}
	
}
void update_stats(struct stats stat[],struct course cors[], int* numberOfCourses, struct exam exams[], int* numberOfResults)
{
	int numberOfPasses=0;
	int numberOfFails=0;
	int numberOfStudents=0;
	for(int counter1=0;counter1<*numberOfCourses;counter1++){
		numberOfPasses=0;
		numberOfFails=0;
		numberOfStudents=0;
		for(int counter2=0;counter2<*numberOfResults;counter2++){
			if((strcmp(cors[counter1].name,exams[counter2].course.name)==0)&&(exams[counter2].grade>=6)){
				numberOfPasses++;
				printf("%s\n", "student passed");
			}
			if((strcmp(cors[counter1].name,exams[counter2].course.name)==0)&&(exams[counter2].grade<6)){
				numberOfFails++;
				printf("%s\n", "student failed");
			}
		}
		numberOfStudents=numberOfPasses+numberOfFails;
		stat[counter1].course=cors[counter1];
		stat[counter1].numberOfPasses = numberOfPasses;
		stat[counter1].numberOfFails = numberOfFails;
		stat[counter1].numberOfStudents = numberOfStudents;
	}

}    
