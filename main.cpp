#include "Graph.h"
#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

class train{
	public: //because privates are for the army!
	train(int Color,int Goal){
		//initaliser self explainitory
		color = Color; //Make it special
		goal = Goal; //so it knows when it's done
		going = true;
		inv = 0;
		dist = 0;
	}
	void startLocation(adjVertex start){
		location = start;
		dist += location.weight;
		for(int i=0;i<location.depots.size();i++){
			if(location.depots[i]==color){
				if(location.stock[i]){
					inv += 1;
					location.stock[i]-=1;
				}
			}
		}
	}
	void updateLocation(){
		if(!going) return;
		int s = location.v->adj.size();
		location = location.v->adj[rand()%s];
		dist += location.weight;
		for(int i=0;i<location.bases.size();i++){
			if(location.bases[i]==color){
				if(goal==0){
					going = false;
					return;
				}
				goal -= inv;
				inv =0;
			}
		}
		for(int i=0;i<location.depots.size();i++){
			if(location.depots[i]==color){
				if(location.stock[i]){
					inv += 1;
					location.stock[i]-=1;
				}
			}
		}
	}
	bool going;
	int dist;//gives distance traveled
	int color; //special identifier
	int goal;//total cars to pick up
	int inv;//Number of cars pulled
	adjVertex location; // current path
};

int main(){
	vector<int> v;
	vector<int> v1;
	v1.push_back(1);
	Graph g1;
	g1.addVertex(1);
	g1.addVertex(2);
	g1.addVertex(3);
	g1.addVertex(4);
	g1.addEdge(1,3,1,v,v);
	g1.addEdge(1,4,8,v,v1);
	g1.addEdge(2,1,7,v1,v);
	g1.addEdge(2,4,6,v,v);
	g1.addEdge(3,2,2,v,v);
	g1.addEdge(4,3,4,v,v);
	
	train red(1,4);
	g1.displayEdges();
	red.startLocation(g1.vertices[1]->adj[0]);
	for(int i=0;i<100;i++){
		while(red.going){
			red.updateLocation();
		}
		red.goal = 4;
		red.going = true;
		g1.reset();
	}
	cout << "The red train moved over about " << red.dist << "/100 tiles per run." << endl;
	
}
