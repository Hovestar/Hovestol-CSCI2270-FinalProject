#include <cstdlib>
#include <ctime>
#include <stdio>
#include "LinkedList.h"


using namespace std;

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
	/*Uses selection sort, upgrade to quicksort may be possible. Sorts two lists in unison*/
	int *fit = findFit(pop);
	List tmp;
	int index,pass;
	for(int i=0;i<popSize;i++){
		index=i;
		for(int j=i;j<popSize;j++){
			if(fit[j]<fit[index]){
				index = j;
			}
		}
		tmp = pop[i];
		pop[i] = pop[index];
		pop[index]= tmp;
		pass = fit[i];
		fit[i]=fit[index];
		fit[index] = pass;
	}
	return fit;
}

int choose(){
	/**Returns an index based on a simple weighting algorithm **/
	int i = rand()%(((popSize)*(popSize+1))/2);
	for(int j=0;i>=0;j++) i-=popSize-j;
	return j-1;
}

List* newGen(List* pop){
	/**"mates" two lists the mutates the baby the sticks it on the list**/
	List* exit = new List[popSize];
	List mom,dad;
	int index;
	exit[0] = pop[0]; //Keeps the best member
	for(int i=1;i<popSize;i++){
		dad = pop[choose()];
		mom = pop[choose()];
		index = rand()%dad.size();
		dad.swapTail(index,mom.swapTail(index,NULL)).mutate(mutationRate);
		exit[i]=dad;
	}
	delete[] pop;
	return exit;
}

int genLoop(){
	List* pop = new List[popSize];
	pop = initPop(pop)
	int* fit = new int[popSize];
	fit = sortFit(&pop);
	int numGens=1;
	while(fit[0]){
		numGens++;
		pop = newGen(pop);
		fit = sortFit(&pop);
	}
}

int main(){
	/**Main used for testing.**/
	//test list
	List i('abcd');
	i.print();
}
