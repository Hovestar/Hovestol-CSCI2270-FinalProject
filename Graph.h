#ifndef GRAPH_H
#define GRAPH_H
#include <vector>
#include <iostream>

struct vertex;

struct adjVertex{
	vertex *v;
	int weight;
	std::vector<int> depots;//depots here
	std::vector<int> bases;//bases here
	std::vector<int> stock;//stock for the depots
};

struct vertex{
	int name;
	bool visited;
	int distance;
	vertex *previous;
	std::vector<adjVertex> adj;
};

class Graph
{
	public:
		Graph();
		~Graph();
		void addEdge(int v1, int v2, int weight,std::vector<int>,std::vector<int>);
		void addVertex(int name);
		void displayEdges();
		void findDistricts();
		void findPath(int,int);
		int index(vertex);
		int index(int);
		void printHelp(vertex*,int);
		void printHelp(vertex*);
		void BFS(int,int);
		std::vector<vertex*> vertices;
		void reset();

};

#endif // GRAPH_H
