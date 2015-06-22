#include<iostream>
#include<vector>
#include<deque>
#include<cstdlib>
#include "graph.h"
using namespace std;

// uses BFS to search if there exists a path between start and end
bool isPath(graph g,int start,int end){
	vector<node *> v = g.getnodes();
	bool visited[v.size()];
	for(int i=0;i<v.size();i++) visited[i]=false;
	deque<int> queue;
	queue.push_back(start);
	while(!queue.empty()){
		int p = *queue.begin();	
		queue.pop_front();	
		if(p==end)	return true;
		if(!visited[p]){
			visited[p] = true;		
			cout << p << endl;				
			for(int i=0;i<v[p]->neighbours.size();i++){				
				queue.push_back(v[p]->neighbours[i]);			
			}
		}
	}
	return false;
}

int main(){
	graph g;
	for(int i=0;i<10;i++){
		int tmp =rand()%100;
		g.addNode(tmp);		
	}	
	g.addEdge(0,1);
	g.addEdge(1,3);
	g.addEdge(3,4);
	g.addEdge(4,1);
	g.addEdge(4,0);
	g.addEdge(1,5);
	g.addEdge(1,7);
	g.addEdge(2,6);
	cout<<endl<<isPath(g,4,7)<<endl;
	return 0;
}