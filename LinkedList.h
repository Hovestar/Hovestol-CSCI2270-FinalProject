#ifndef LIST_H
#define LIST_H

struct Element
{
	char elem;
	Element *next;
	
	Element(){};
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
		int operator==(List);
		void addElement(char);
		Element* start;
		void mutate(double);
		Element* findLast(Element*);
}

#endif
