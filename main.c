/* Assignment 3, Covid-19 social distancing effect simulation
 * The main aim of this assigment is getting familiar with dynamic arrays and heap management. 
 *  
 *  Please write your name and Student ID as comment below.
 *  Name and Surname:               Student ID:
 */



#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define FRATE 0.03
#define RRATE 0.97
#define INITIALCASES 0.05


typedef struct Person {
    char condition;
    int pos;
    int neighbors[8];
    int sickCycles;
} Person;

Person** initialWorld(int n,int worldSize) {
    Person** world = malloc(sizeof(Person*) * worldSize);
    int i;
    for (i = 0; i< worldSize; i++) {
        world[i] = malloc(sizeof(Person));
	world[i]->pos = i;
        if((i % n) == 0) {
            if(i / n == 0) {
                world[i]->neighbors[0] = i+1;
                world[i]->neighbors[1] = i+n;
                world[i]->neighbors[2] = i+n+1;
            } else if (i/n == n-1) {
                world[i]->neighbors[0] = i-n;
                world[i]->neighbors[1] = i-n+1;
                world[i]->neighbors[2] = i+1;
            } else {
                world[i]->neighbors[0] = i-n;
                world[i]->neighbors[1] = i-n+1;
                world[i]->neighbors[2] = i+1;
                world[i]->neighbors[3] = i+n;
                world[i]->neighbors[4] = i+n+1;
            }
        } else if ((i % n) == n-1) {
            if(i / n == 0) {
                world[i]->neighbors[0] = i-1;
                world[i]->neighbors[1] = i+n-1;
                world[i]->neighbors[2] = i+n;
            } else if (i/n == n-1) {
                world[i]->neighbors[0] = i-n-1;
                world[i]->neighbors[1] = i-n;
                world[i]->neighbors[2] = i-1;
            } else {
                world[i]->neighbors[0] = i-n-1;
                world[i]->neighbors[1] = i-n;
                world[i]->neighbors[2] = i-1;
                world[i]->neighbors[3] = i+n-1;
                world[i]->neighbors[4] = i+n;
            }
        } else {
            if(i / n == 0) {
                world[i]->neighbors[0] = i-1;
                world[i]->neighbors[1] = i+1;
                world[i]->neighbors[2] = i+n-1;
                world[i]->neighbors[3] = i+n;
                world[i]->neighbors[4] = i+n+1;
            } else if (i/n == n-1) {
                world[i]->neighbors[0] = i-n-1;
                world[i]->neighbors[1] = i-n;
                world[i]->neighbors[2] = i-n+1;
                world[i]->neighbors[3] = i-1;
                world[i]->neighbors[4] = i+1;
            } else {
                world[i]->neighbors[0] = i-n-1;
                world[i]->neighbors[1] = i-n;
                world[i]->neighbors[2] = i-n+1;
                world[i]->neighbors[3] = i-1;
                world[i]->neighbors[4] = i+1;
                world[i]->neighbors[5] = i+n-1;
                world[i]->neighbors[6] = i+n;
                world[i]->neighbors[7] = i+n+1;
            }
        }
    }
    return world;
}

int main( int argc, char *argv[] )  {
   int worldSize = (int) pow(atoi(argv[1]), 2);
   double infectionChance = 1 - (atoi(argv[2])) / 100;
   int simLength = atoi(argv[3]);
   Person** world = initialWorld(atoi(argv[1]), worldSize);
   int i;
   
   return 0;
}
