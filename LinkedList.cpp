#include "LinkedList.h"


List::List(){
	
}
Element* List::find(T i){
	for(Element* m=start;m&&m->elem!=i;m=m->next);
	return m;
}
Element* List::getIndex(int i){
	for(Element* m=start;i>0;i--){
		m = m->next;
	}
	return m;
}
int List::operator==(List other){
	//Returns 0 if they are = otherwise return the #of differnces
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

