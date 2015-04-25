#include "Graph.h"
#include <vector>
#include <iostream>
#include <cstdlib>
#include <fstream>

using namespace std;

Graph::Graph(){
	;
}

Graph::~Graph(){
	//dtor
}
void Graph::addEdge(string v1, string v2, int weight){

	for(int i = 0; i < vertices.size(); i++){
		if(vertices[i]->name == v1){
			for(int j = 0; j < vertices.size(); j++){
				if(vertices[j]->name == v2 && i != j){
					adjVertex av;
					av.v = vertices[j];
					av.weight = weight;
					vertices[i]->adj.push_back(av);
					//another vertex for edge in other direction
					adjVertex av2;
					av2.v = vertices[i];
					av2.weight = weight;
					vertices[j]->adj.push_back(av2);
				}
			}
		}
	}
}
void Graph::addVertex(string n){
	bool found = false;
	for(int i = 0; i < vertices.size(); i++){
		if(vertices[i]->name == n){
			found = true;
			cout<<vertices[i]->name<<" found."<<endl;
		}
	}
	if(found == false){
		vertex* v = new vertex;
		v->name = n;
		vertices.push_back(v);
	
	}
}

void Graph::displayEdges(){
	//loop through all vertices and adjacent vertices
	for(int i = 0; i < vertices.size(); i++){
		cout<<vertices[i]->district<<":";
		cout<<vertices[i]->name<<"-->";
		cout << vertices[i]->adj[0].v->name;
		for(int j = 1; j < vertices[i]->adj.size(); j++){
			cout<< "***" <<vertices[i]->adj[j].v->name;
		}
		cout << endl;
	}

}
int Graph::index(vertex n){
	for(int i=0;i<vertices.size();i++){
		if(n.name == vertices[i]->name)return i;
	}
	return -1;
}
int Graph::index(string n){
	for(int i=0;i<vertices.size();i++){
		if(n == vertices[i]->name)return i;
	}
	return -1;
}
void Graph::printHelp(vertex* e,int c){
	if(e->previous == NULL) {
		cout << c << "," << e->name;
	}
	else{
		printHelp(e->previous,c+1);
		std::cout << "," << e->name;
	}	
}
void Graph::printHelp(vertex* e){
	if(e == NULL) {
		;
	}
	else{
		printHelp(e->previous);
		std::cout << "," << e->name;
	}
}
void Graph::BFS(){
	char hoe[100];
	int s,e,z,j;
	string name;
	cout << "Enter a starting city:" << endl;
	cin >> name;
	cin.getline(hoe,100);
	name += string(hoe);
	s = index(name);
	cout << "Enter an ending city:" << endl;
	cin >> name;
	cin.getline(hoe,100);
	name += string(hoe);
	e = index(name);
	if(vertices[0]->district==-1){
		cout << "Please identify the districts before checking distances" << endl;
		return;
	}
	if(s==-1||e==-1){
		cout << "One or more cities doesn't exist" << endl;
		return;
	}
	if(vertices[s]->district!=vertices[e]->district){
		cout << "No safe path between cities" << endl;
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
void Graph::Dijkstra(){
	char hoe[100];
	int s,e,z,j;
	string name;
	cout << "Enter a starting city:" << endl;
	cin >> name;
	cin.getline(hoe,100);
	name += string(hoe);
	s = index(name);
	cout << "Enter an ending city:" << endl;
	cin >> name;
	cin.getline(hoe,100);
	name += string(hoe);
	e = index(name);
	if(vertices[0]->district==-1){
		cout << "Please identify the districts before checking distances" << endl;
		return;
	}
	if(s==-1||e==-1){
		cout << "One or more cities doesn't exist" << endl;
		return;
	}
	if(vertices[s]->district!=vertices[e]->district){
		cout << "No safe path between cities" << endl;
		return;
	}
	for(int i=0;i<vertices.size();i++){
		vertices[i]->visited=false;
		vertices[i]->distance=-1;
		vertices[i]->previous=NULL;
	}
	vertices[s]->distance=0;
	while(!vertices[e]->visited){
		int curr =-1;
		for(int i=0;i<vertices.size();i++){
			if(	 (curr == -1 || vertices[i]->distance < vertices[curr]->distance) 
					&& vertices[i]->distance != -1
					&& vertices[i]->visited == false){
				curr = i;
			}
		}
		vertices[curr]->visited = true;
		for(int j=0;j<vertices[curr]->adj.size();j++){
			if( vertices[curr]->adj[j].weight+vertices[curr]->distance < vertices[curr]->adj[j].v->distance
				|| vertices[curr]->adj[j].v->distance == -1){
				vertices[curr]->adj[j].v->distance = vertices[curr]->adj[j].weight+vertices[curr]->distance;
				 vertices[curr]->adj[j].v->previous = vertices[curr];
			}
		}
	}
	cout << vertices[e]->distance;
	printHelp(vertices[e]);
	cout << endl;
}

/*
void printHelp(vertex s,vertex e){
	if(e.name == s.name) std::cout << s.name;
	else{
		printHelp(s,*(e.previous));
		std::cout << " - " << e.name;
	}
	
}

void Graph::Dijkstra(string start, string end){
	std::cout << "Shortest Path" << std::endl;
   int s,e;
	for(s=0;s<vertices.size();s++){
		if(start == vertices[s].name){
			break;
		}
	}
	for(e=0;e<vertices.size();e++){
		if(end == vertices[e].name){
			break;
		}
	}
	for(int i=0;i<vertices.size();i++){
		vertices[i].visited=false;
		vertices[i].distance=-1;
		vertices[i].previous=NULL;
	}
	vertices[s].distance =0;
	while(!vertices[e].visited){
		int curr =-1;
		for(int i=0;i<vertices.size();i++){
			if(	 (curr == -1 || vertices[i].distance < vertices[curr].distance || true) 
					&& vertices[i].distance != -1
					&& vertices[i].visited == false){
				curr = i;
			}
			vertices[curr].visited = true;
			for(int j=0;j<vertices[curr].adj.size();j++){
				if( vertices[curr].adj[j].weight+vertices[curr].distance < vertices[curr].adj[j].v->distance
					|| vertices[curr].adj[j].v->distance == -1){
					vertices[curr].adj[j].v->distance = vertices[curr].adj[j].weight+vertices[curr].distance;
					 vertices[curr].adj[j].v->previous = & vertices[curr];
				}
			}
			
		}
	}
	printHelp(vertices[s], vertices[e]);
	std::cout << std::endl << "Minimum Distance: " <<vertices[e].distance << std::endl;
}
* */
