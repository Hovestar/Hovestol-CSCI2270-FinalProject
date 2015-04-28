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
		//Gives it a start location 
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
		//randomly chooses where to go and updates everything else accordingly
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
	vector<int> v,v1,v2,v3,v4,v5,v6;
	v1.push_back(1);//Vectors to tell the graph what's where
	v2.push_back(2);
	v3.push_back(3);
	v4.push_back(4);
	v5.push_back(5);
	v6.push_back(6);
	
	Graph g1;
	g1.addVertex(1);
	g1.addVertex(2);
	g1.addVertex(3);
	g1.addVertex(4);
	g1.addEdge(1,3,1,v1,v1); //the vectors are bases, depots
	g1.addEdge(1,4,8,v2,v2);
	g1.addEdge(2,1,7,v3,v3);
	g1.addEdge(2,4,6,v4,v4);
	g1.addEdge(3,2,2,v5,v5);
	g1.addEdge(4,3,4,v6,v6);
	
	train t1(1,4);//Trains with unique ID, that each pick up 4 cars
	train t2(2,4);
	train t3(3,4);
	train t4(4,4);
	train t5(5,4);
	train t6(6,4);
	
	t1.startLocation(g1.vertices[1]->adj[0]); //Starting them off
	t2.startLocation(g1.vertices[1]->adj[0]);
	t3.startLocation(g1.vertices[1]->adj[0]);
	t4.startLocation(g1.vertices[1]->adj[0]);
	t5.startLocation(g1.vertices[1]->adj[0]);
	t6.startLocation(g1.vertices[1]->adj[0]);
	
	for(int i=0;i<1000;i++){
		while(t1.going||t2.going||t3.going||t4.going||t5.going||t6.going){
			t1.updateLocation();//Each updates each time
			t2.updateLocation();
			t3.updateLocation();
			t4.updateLocation();
			t5.updateLocation();
			t6.updateLocation();
		}
		t1.goal = 4;		//This here resets between runs.
		t1.going = true;
		t2.goal = 4;
		t2.going = true;
		t3.goal = 4;
		t3.going = true;
		t4.goal = 4;
		t4.going = true;
		t5.goal = 4;
		t5.going = true;
		t6.goal = 4;
		t6.going = true;
		g1.reset();
	}
	cout << "The 1 train moved over about " << t1.dist << "/1000 tiles per run." << endl; //Reporting stats
	cout << "The 2 train moved over about " << t2.dist << "/1000 tiles per run." << endl;
	cout << "The 3 train moved over about " << t3.dist << "/1000 tiles per run." << endl;
	cout << "The 4 train moved over about " << t4.dist << "/1000 tiles per run." << endl;
	cout << "The 5 train moved over about " << t5.dist << "/1000 tiles per run." << endl;
	cout << "The 6 train moved over about " << t6.dist << "/1000 tiles per run." << endl;
	
}
