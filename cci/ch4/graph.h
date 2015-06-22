#include<vector>
class node{
	public:
		int data;
		std::vector<int> neighbours;
};
class graph{
protected:		
	std::vector<node*> v;

	node *newNode(int data){
		node *nd = new node();
		nd->data=data;
		nd->neighbours;
	}
	
	int *visited;
	void DFS(int inx){
		if(!visited[inx]){
			visited[inx]=1;
			std::cout << v[inx]->data << " ";
			for(int i=0;i<v[inx]->neighbours.size();i++){
				DFS(v[inx]->neighbours[i]);
			}
		}
	}
	
public:	
	std::vector<node *> getnodes(){
		return v;
	}	

	void addNode(int data){		
		v.push_back(newNode(data));
		std::cout<<"Added node: "<<v.size()<<" : "<<data<<std::endl;
	}

// node1 and node2  are index of respectively node 1 and node 2
	void addEdge(int node1, int node2){
		if(v.size() <= node1 || v.size() <= node2) 
			throw "No such node";
		std::cout<<"Added edge: (" <<node1 <<","<<node2<<")"<<std::endl;
		v[node1]->neighbours.push_back(node2);
		//v[node2]->neighbours.push_back(node1);
	}

	void dfs(int startnode){
		if(startnode >= v.size()) throw "Wrong starting node";
		visited = new int[v.size()+1];
		for(int i=0;i<v.size();i++) visited[i]=0;
		std::cout<<"DFS starting from "<<startnode <<std::endl;
		DFS(startnode);
		std::cout<<std::endl;
	}

	
};