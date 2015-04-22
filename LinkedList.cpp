#include "LinkedList.h"
#include <cstdlib>

char* chars = 'abcdefghijklmnopqrstuvwxyz ABCDEFGHIJKLMNOPQRSTUVWXYZ'
int bases=53;

List::List(){
	/*Basic inializer not useful for this program may be as a library function*/
	start = NULL;
}
List::List(char a){
	/*Initializes with just the first element*/
	start = new Element(a);
}
List::List(char* a){
	/*Takes a char* and initalizes whole list. Useful for target strand*/
	Element * tmp= start;
	start->elem = a[0];
	for(int i=1;a[i];i++){
		tmp->next = new Element(a[i]);
		tmp = tmp->next;
	}
}
Element* List::find(char i){
	//Find element in the list with value i
	for(Element* m=start;m&&m->elem!=i;m=m->next);
	return m;
}
Element* List::getIndex(int i){
	//finds the ith element
	for(Element* m=start;i>0;i--){
		m = m->next;
	}
	return m;
}
void List::addElement(char a){
	if(!start)start = new Element(a);
	else{
		Element* tmp=start;
		for(;tmp->next;tmp=tmp->next);
		tmp->next = new Element(a);
	}
}
int List::operator==(List other){
	//Returns 0 if they are = otherwise return the #of differnces
	//Upgrade: Find largerst chains of similarities without using charactors 2 times.
	// or out of order?
	Element* m,n;
	m=start;
	n = other.start;
	int out = 0
	while(n&&m){
		if(n->elem != m->elem){
			out+=1;
		}
		n=n->next;
		m->next;
	}
	for(;n;n=n->next) out+=1;
	for(;m;m=m->next) out+=1;
	return out;
}
Element* List::findLast(Element* curr){
	Element* tmp=start;
	if(tmp == curr){
		return NULL;
	}
	for(;tmp->next!=curr;tmp = tmp->next);
	return tmp;
}
void List::mutate(double rate){
	Element* tmp = start;
	for(;tmp;tmp=tmp->next){
		if(rate>((float)rand()/(float)RAND_MAX)){
			int test= rand()%10;
			if(test <=3){//Simple change, 4 out of 10 chances
				tmp->elem = chars[rand()%bases];
			}
			else if(test <=6){//Swap 3 out of 10
				Element* parent = findLast(tmp);
				if(parent==NULL){
					start = tmp->next;
					tmp->next = tmp->next->next;
					start->next = tmp;
				}else{
					parent->next = tmp->next;
					tmp->next = tmp->next->next;
					parent->next->next = tmp;
				}
			}
			else if(test <=8){//insertion 2 out of 10
				Element* child=tmp->next;
				tmp->next = new Element(chars[rand()%bases]);
				tmp->next->next = child;
			}
			else{//deletion 1 out of 10
				Element* parent = findLast(tmp);
				if(parent == NULL){
					start = tmp->next;
					delete tmp;
					tmp= start;
				}else{
					parent->next = tmp->next;
					delete tmp;
					tmp = parent;
				}
			}
		}
	}
}
