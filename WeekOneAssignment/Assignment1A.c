#include <stdio.h> 
/*
The previous program would only print it twice because once it exited the second loop ctr would have a value of 8.
*/

void print_function( char letter ); 
int ctr; 
int btr;
int main( void ) 
{ 
 char star = '*'; 
 char dash = '-'; 
 
 for (ctr = 0 ; ctr < 10; ctr++ ) 
 { 
 print_function( star ); 
 print_function( dash ); 
printf("\n"); 
 }
system("pause"); 
 return 0; 
} 
void print_function ( char letter ) 
{ 
 for ( btr = 0; btr < 9; btr++) { 
 printf("%c", letter); 
 } 
} 