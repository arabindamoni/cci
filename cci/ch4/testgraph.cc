#include<iostream>
#include<cstdlib>
#include"graph.h"
using namespace std;

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
	g.addEdge(1,5);
	g.addEdge(1,7);
	while(true){
		int startnode=0;
		cin >> startnode;
		g.dfs(startnode);
	}
	return 0;
}