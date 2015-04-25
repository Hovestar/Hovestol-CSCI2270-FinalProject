#ifndef LIST_H
#define LIST_H
#include <cstddef>

struct Element
{
	char elem;
	Element *next;
	
	Element(){next = NULL;};
	Element(char e){
		elem = e;
		next = NULL;
	};
};

class List{
	public:
		List();
		List(char);
		List(char*);
		Element* find(char);
		Element* getIndex(int);
		int compare(List);
		void addElement(char);
		Element* start;
		void mutate(double);
		Element* findLast(Element*);
		Element* swapTail(int,Element*);
		int size();
		void print();
};

#endif
