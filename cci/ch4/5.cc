#include<iostream>
#include<cstdlib>
using namespace std;
class bstree_5{
protected:	
	class node{
	public:
		int data;
		node *left;
		node *right;
		node *parent;
	};

	node *root;
	int size;

node *makeNode(int data){
	node *p = new node();
	p->left=NULL;
	p->right = NULL;
	p->data = data;	
	p->parent = NULL;	
	return p;
}

node *insert(int data,node *p){
	if(p==NULL){
		return makeNode(data);
	} 
	if(p->data > data){
		p->left=insert(data,p->left);
		p->left->parent = p;
	}
	else if(p->data < data){
		p->right=insert(data,p->right);
		p->right->parent = p;
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
	bstree_5(){
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

	int successor(int key){	
		node *p = search(key,root);	
		if(p==NULL) throw "no successor";
		if(p->right!=NULL){
			p=p->right;
			while(p->left) p=p->left;
			return p->data;
		}
		else{
			node *q;
			while((q=p->parent)->left!=p){
				p=q;
			}
			return q->data;
		}
	}
	
};

int main(){
	bstree_5 t;
	srand(time(NULL));
	for(int i=0;i<20;i++){
		int tmp = rand()%10;
		t.insert(tmp);	
		cout<<" "<<tmp;
	}
	cout<<endl;
	t.inorder();
	cout<<"calling successor"<<endl;
	cout << t.successor(5)<<endl;
	return 0;
}