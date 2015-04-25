#include "Graph.h"
#include <iostream>

int main(){
	Graph g;
	g.addVertex("1");
	g.addVertex("2");
	g.addVertex("3");
	g.addVertex("4");
	g.addEdge("1","4",8);
	g.addEdge("1","3",1);
	g.addEdge("2","1",7);
	g.addEdge("2","4",6);
	g.addEdge("3","2",2);
	g.addEdge("4","3",4);
	
	g.displayEdges();
}
