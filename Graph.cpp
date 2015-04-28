#include "Graph.h"
#include <vector>
#include <iostream>
#include <cstdlib>
#include <fstream>

using namespace std;

Graph::Graph(){
	//Doesn't need anything initalized
	;
}

Graph::~Graph(){
	//dtor
}
void Graph::addEdge(int v1, int v2, int weight,vector<int> bases,vector<int> depots){
	/**Adds an edge from v1 to v2 with weight**/
	int i = index(v1);
	int j = index(v2);
	adjVertex av;
	av.v = vertices[j];
	av.weight = weight;
	
	av.bases = bases;
	av.depots = depots;
	vector<int> stock;
	for(int i=0;i<depots.size();i++){
		stock.push_back(4);
	}
	av.stock = stock;
	
	vertices[i]->adj.push_back(av);
}
void Graph::addVertex(int n){
	/*If a vertex doesn't already exist it adds it.*/
	for(int i = 0; i < vertices.size(); i++){
		if(vertices[i]->name == n){
			cout<<vertices[i]->name<<" found."<<endl;
			return;
		}
	}
	vertex* v = new vertex;
	v->name = n;
	vertices.push_back(v);
}

void Graph::displayEdges(){
	//loop through all vertices and adjacent vertices and prints them
	for(int i = 0; i < vertices.size(); i++){
		cout<<vertices[i]->name<<"-->";
		cout << vertices[i]->adj[0].v->name;
		for(int j = 1; j < vertices[i]->adj.size(); j++){
			cout<< "***" <<vertices[i]->adj[j].v->name;
		}
		cout << endl;
	}

}
int Graph::index(vertex n){
	//gets index of vertex n
	for(int i=0;i<vertices.size();i++){
		if(n.name == vertices[i]->name)return i;
	}
	return -1;
}
int Graph::index(int n){
	//gets index of vertex with name n
	for(int i=0;i<vertices.size();i++){
		if(n == vertices[i]->name)return i;
	}
	return -1;
}
void Graph::printHelp(vertex* e,int c){
	//Used to print shortest path, for debugging
	if(e->previous == NULL) {
		cout << c << "," << e->name;
	}
	else{
		printHelp(e->previous,c+1);
		std::cout << "," << e->name;
	}	
}
void Graph::printHelp(vertex* e){
	//Used to print shortest path, for debugging
	if(e == NULL) {
		;
	}
	else{
		printHelp(e->previous);
		std::cout << "," << e->name;
	}
}
void Graph::BFS(int name1,int name2){
	//Does a Breadth first search
	int s,e,z,j;
	s = index(name1);
	e = index(name2);
	if(s==-1||e==-1){
		cout << "One or more paths don't exist" << endl;
		return;
	}
	for(int i=0;i<15;i++){
		vertices[i]->visited=false;
		vertices[i]->previous=NULL;
	}
	vector<vertex*> next;
	next.push_back(vertices[s]);
	vertices[s]->visited = true;
	for(z=0;!vertices[e]->visited;z++){
		for(j=0;j<next[z]->adj.size();j++){
			if(!next[z]->adj[j].v->visited){
				next[z]->adj[j].v->visited = true;
				next[z]->adj[j].v->previous = next[z];
				next.push_back(next[z]->adj[j].v);
			}
		}
	}	
	printHelp(vertices[e],0);
	cout << endl;
}
void Graph::reset(){
	//Resets the stock for all depots
	for(int i=0;i<vertices.size();i++)
		for(int j=0;j<vertices[i]->adj.size();j++)
			for(int k=0;k<vertices[i]->adj[j].stock.size();k++)
				vertices[i]->adj[j].stock[k]=4;
}
