#include <stdio.h> 


int main(void)
{
	int selectedValue;
	int checkValue;
	printf('Hello you will be selecting from a list of messages to display \n 1\t monkeys are good\n2\tmonkeys are bad\n3\t anty jake is had monkey butter for breakfast \n which message do you want to see again 1, 2 or 3\n');
	do{
		scanf("%d",&selectedValue);
		if(setlectedValue<0){
			exit();
		}
		if(selectedValue>0 && selectedValue<4){
			int checkValue == 1;
			if(selectedValue == 1){
				printf(' monkeys are good');
			}
			if(selectedValue == 2){
				printf(' monkeys are Bad');
			}
			if(selectedValue == 3){
				printf(' anty jake is had monkey butter for breakfast ');
			}
		
		}
		if(selectedValue!>0 && selectedValue!<4){
			printf('You have not selected a value which is in the menu please try again');
		}
	}while(checkValue != 1)
}