/* Assignment 3, Covid-19 social distancing effect simulation
 * The main aim of this assigment is getting familiar with dynamic arrays and heap management. 
 *  
 *  Please write your name and Student ID as comment below.
 *  Name and Surname:               Student ID:
 */



#include <stdio.h>
#include <stdlib.h>



int main( int argc, char *argv[] )  {

   printf("Program name %s\n", argv[0]);
 
   if( argc == 5 ) {
	printf("The first argument supplied is %d\n", atoi(argv[1]));
	printf("The second argument supplied is %d\n", atoi(argv[2]));
  	printf("The third argument supplied is %d\n", atoi(argv[3]));
	printf("The forth argument supplied is %d\n", atoi(argv[4]));
   }
   else if( argc > 5 ) {
      printf("Too many arguments supplied.\n");
   }
   else {
      printf("Expected 4 arguments but only %d argument passed.\n", argc-1);
   }
      
}
