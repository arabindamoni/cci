#include<iostream>
#include<cstdlib>
using namespace std;
class bstree_6{
protected:	
	class node{
	public:
		int data;
		node *left;
		node *right;
	};

	node *root;
	int size;

node *makeNode(int data){
	node *p = new node();
	p->left=NULL;
	p->right = NULL;
	p->data = data;		
	return p;
}

node *insert(int data,node *p){
	if(p==NULL){
		return makeNode(data);
	} 
	if(p->data > data){
		p->left=insert(data,p->left);	
	}
	else if(p->data < data){
		p->right=insert(data,p->right);		
	}	
	return p;
}

void inorder(node *p,int level){			
	if(p!=NULL){
		inorder(p->left,level+1);	
		for(int i=0;i<level;i++) std::cout<<" - ";	
		std::cout<<p->data<<std::endl;
		inorder(p->right,level+1);
	}		
}

public:
	bstree_6(){
		root = NULL;
		size = 0;
	}			

	void insert(int data){
		root = insert(data,root);
	}

	void inorder(){
		std::cout<<"Printing tree in inorder traversal"<<std::endl;
		inorder(root,0);
	}

	node *search(int key,node *p){
		if(p==NULL) return NULL;
		if(p->data == key) return p;
		if(p->data < key) return search(key,p->right);
		return search(key,p->left);
	}

	int lcancestor(int key1,int key2){				
		node *p=root;
		if(!(search(key1,root) && search(key2,root))) throw "wrong input";
		while(p){
			if(p->data >key1){
				if(p->data <=key2) {return p->data;}
				else {p=p->left;}
			}
			else{
				if(p->data >= key2 || p->data == key1) {return p->data;}
				else{ p = p->right;}
			}
		}
	}
	
};

int main(){
	bstree_6 t;
	srand(time(NULL));
	for(int i=0;i<100;i++){
		int tmp = rand()%20;
		t.insert(tmp);	
		cout<<" "<<tmp;
	}
	cout<<endl;
	t.inorder();
	cout<<"calling successor"<<endl;
	cout << t.lcancestor(3,8)<<endl;	
	return 0;
}