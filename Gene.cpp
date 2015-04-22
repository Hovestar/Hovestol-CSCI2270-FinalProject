#include <cstdlib>
#include <ctime>
#include <stdio>
#include "LinkedList.h"


int popSize = 100;
double endProb = 0.1;
double mutationRate = 0.01;
List std; //standard string

char* chars = 'abcdefghijklmnopqrstuvwxyz ABCDEFGHIJKLMNOPQRSTUVWXYZ'
int bases = 53 // size of char* chars

List* initPop(List*);
float randomFloat();
int genLoop();

List* initPop(List* pop){
	/**Creates population 
	 * **/
	for(int i=0;i<popSize;i++){
		while(endProb<randomFloat){
			pop[i].addElement(chars[rand()%bases]);
		}
	}
	return pop;
}
float randomFloat(){
	/** Used to mutate population 
	* */
	return (float)rand()/(float)RAND_MAX;
}

int* findFit(List* pop){
	int* fit = new int[popSize];
	for(int i=0;i<popSize;i++){
		fit[i]=(pop==std);
	}
	return fit;
}

int* sortFit(List* &pop){
	int *fit = findFit(pop);
	List tmp;
	int min;
	for(int i=0;i<popSize;i++){
		min = -1;
		
	}
}

int genLoop(){
	List* pop = new List[popSize];
	pop = initPop(pop)
	int* fit = new int[popSize];
	fit = sortFit(&pop);
}
