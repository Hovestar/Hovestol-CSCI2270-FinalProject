#ifndef LIST_H
#define LIST_H

template<typename T>
struct Element
{
	T elem;
	Element *next;
	
	Element(){};
	Element(T e){
		elem = e;
		next = NULL;
	};
};

template<typename T>
class List{
	public:
		List();
		Element<T>* find(T);
		Element<T>* getIndex(int);
		int operator==(List);
		Element<T>* start;
		Element<T>* end;
}

#endif
