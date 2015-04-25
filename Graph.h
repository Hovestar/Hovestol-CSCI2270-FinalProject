#ifndef GRAPH_H
#define GRAPH_H
#include <vector>
#include <iostream>

struct vertex;

struct adjVertex{
	vertex *v;
	int weight;
};

struct vertex{
	std::string name;
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
		void addEdge(std::string v1, std::string v2, int weight);
		void addVertex(std::string name);
		void displayEdges();
		void findDistricts();
		void findPath(std::string,std::string);
		bool inDistrict(int);
		void districtHelper(int,int);
		int index(vertex);
		int index(std::string);
		void printHelp(vertex*,int);
		void printHelp(vertex*);
		void BFS();
		void Dijkstra();
	protected:
	private:
		//vector<edge> edges;
		std::vector<vertex*> vertices;

};

#endif // GRAPH_H
