#include<iostream>
#include<vector>
#include<cstdlib>
#include"bstree.h"
using namespace std;

class bstree_8:public bstree{
private:
	void findPathSum(int sum,node *p,vector<int> path){
		if(p==NULL) return;
		path.push_back(p->data);
		int tmp = sum;
		for(int i=path.size()-1;i>=0;i--){
			tmp-=path[i];
			if(tmp == 0){
				cout<<"Path found: ";
				while(i++ < path.size()){
					cout<<path[i-1]<<" ";
				}
				cout<<endl;
				break;
			}
		}
		vector<int> v1(path);
		vector<int> v2(path);
		findPathSum(sum,p->left,v1);
		findPathSum(sum,p->right,v2);
	}
public:
	void findPathSum(int sum){
		vector<int> v;
		findPathSum(sum,root,v);
	}
};

int main(){
	bstree_8 t;
	srand(time(NULL));
	for(int i=0;i<30;i++){
		int tmp = rand()%30;
		t.insert(tmp);			
	}
	cout<<endl;
	t.inorder();
	t.findPathSum(20);
	return 0;
}
