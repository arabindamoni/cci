#include<iostream>
#include<cstdlib>
#include"bstree.h"
using namespace std;

int main(){
	bstree t;
	srand(time(NULL));
	for(int i=0;i<5;i++){
		int tmp = rand()%20;
		t.insert(tmp);	
		cout<<" "<<tmp;
	}
	cout<<endl;
	t.inorder();
	cout<<t.isBalanced()<<endl;
	return 0;
}