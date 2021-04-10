/* Assignment 3, Covid-19 social distancing effect simulation
 * The main aim of this assigment is getting familiar with dynamic arrays and heap management. 
 *  
 *  Please write your name and Student ID as comment below.
 *  Name and Surname: Umur Berkay Karakas        Student ID: 69075
 */



#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define FRATE 3
#define RRATE 97
#define INITIALCASES 0.05


typedef struct Person {
    char condition;
    int neighbors[8];
    int sickCycles;
} Person;

void writeToFile(Person** world, int cycleNum, int n, int worldSize);
Person** initialWorld(int n, int worldSize);
void cycleWorld(Person** world,int n, int simLength, int worldSize, int infectionChance);

Person** initialWorld(int n,int worldSize) {
    Person** world = malloc(sizeof(Person*) * worldSize);
    int i,k;
    int j = 0;
    for (i = 0; i< worldSize; i++) {
        world[i] = malloc(sizeof(Person));
        world[i]->condition = 49;
        world[i]->sickCycles = 0;
        for(k = 0; k< 8; k++) {
            world[i]->neighbors[k] = 0;
        }
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
    while(j<INITIALCASES*worldSize) { 
        int index = rand() % worldSize;
        if(world[index]->condition == 49) {
            world[index]->condition = 42;
            world[index]->sickCycles = 1;
            j++;
        }
    }
    return world;
}

void cycleWorld(Person** world, int n, int simLength, int worldSize, int infectionChance) {
    int j,m,k,randVal,randVal2,overLimit,toDie;
    m = 0;
    int i=1;
    while(i<simLength) {
        for(j = 0; j<worldSize; j++) { 
            if((world[j]->sickCycles > 0) && (world[j]->condition == 42)) {
                for(k = 0; k<8; k++) {
                    randVal = rand() % 100;  
                    if(k == 0) {
                        if(randVal < infectionChance) {
                            if((world[(world[j]->neighbors)[k]]->sickCycles == 0) && (world[(world[j]->neighbors)[k]]->condition == 49)) {
                                world[(world[j]->neighbors)[k]]->condition = 42;
                            }
                        } 
                    } else {
                        if(world[j]->neighbors[k] != 0) {  
                            if(randVal < infectionChance) {
                                if((world[(world[j]->neighbors)[k]]->sickCycles == 0) && (world[(world[j]->neighbors)[k]]->condition == 49)) {
                                    world[(world[j]->neighbors)[k]]->condition = 42;
                                }
                            }        
                        }
                    }
                }
            }
            
        }
        
        for(j = 0; j<worldSize; j++) {
            if(world[j]->condition == 42) {
                world[j]->sickCycles++;
            }
        }
        for(j = 0; j<worldSize; j++) {
            randVal2 = rand() % 100;
            if((world[j]->sickCycles > 4) && (world[j]->condition == 42)) {
                if(randVal2 < FRATE) {
                    world[j]->condition = 48;
                } else {
                    world[j]->condition = 49;
                }
            }
        }       
        i++;
        writeToFile(world, i, n, worldSize);
    }
}

void writeToFile(Person** world, int cycleNum, int n, int worldSize) {
    FILE *fp;
    char txt[13];
    snprintf(txt, 13, "CYCLE%d.txt", cycleNum);

    fp = fopen(txt, "w");
    char temp[3] = "1 ";
    int i,j;
    for(i = 0; i<n; i++) {
        for(j = 0; j<n; j++) {
            temp[0] = world[i*n+j]->condition;
            fputs(temp, fp); 
        }
        fputs("\n", fp);
    }
}

int main( int argc, char *argv[] )  {
   int worldSize = atoi(argv[1]) * atoi(argv[1]);
   printf("%d\n", worldSize);
   int infectionChance = 100 - atoi(argv[2]);
   int simLength = atoi(argv[3]);
   int seed = atoi(argv[4]);
   srand(seed);
   Person** world = initialWorld(atoi(argv[1]), worldSize);
   writeToFile(world, 1, atoi(argv[1]), worldSize);
   cycleWorld(world, simLength, worldSize, infectionChance);
   return 0;
}
