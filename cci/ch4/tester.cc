#include<iostream>
#include<cstdlib>
#include"bstree.h"
using namespace std;

int main(){
	bstree t;
	srand(time(NULL));
	for(int i=0;i<10;i++){
		int tmp = rand()%20;
		t.insert(tmp);	
		cout<<" "<<tmp;
	}
	cout<<endl;
	t.inorder();
	t.level_order();	
	return 0;
}