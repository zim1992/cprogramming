
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
	struct student students;	/* pointer to student 						*/
	struct course course;		/* pointer to the course					*/
	short grade;				/* grade obtained by student for this exam	*/
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
	for(int counter=0;counter<*numberOfStudents;counter++){//used to search for sudent record
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
			while((grade<1)||(grade>10)){
				printf("%s\n", "Please insert the grade of the user. The grade should be between 1 and 10");
				scanf("%hu",&grade);
			}
			exams[*numberOfResults].students=stud[studRecNum];
			exams[*numberOfResults].course=cors[coursRecNum];
			exams[*numberOfResults].grade=grade;
			printf("%s\n",exams[*numberOfResults].students.name);
			*numberOfResults=*numberOfResults+1;
		}
	}
	
}
