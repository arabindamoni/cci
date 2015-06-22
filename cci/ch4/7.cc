#include<iostream>
#include<cstdlib>
using namespace std;
class node{
	public:
		int data;
		node *left;
		node *right;
};
class bstree_7{
public:	
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

	bstree_7(){
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

};

bool isSubtree(node *p, node *q){
	if(q == NULL && p == NULL) return true;
	if((p == NULL | q== NULL) || p->data!=q->data) return false;
	return (isSubtree(p->left,q->left) && isSubtree(p->right,q->right));
}

bool isSubtree(bstree_7 t1, bstree_7 t2){
	node *p = t1.search(t2.root->data,t1.root);
	if(p== NULL) return true;
	return isSubtree(p,t2.root);
}

int main(){
	bstree_7 t1;
	srand(time(NULL));
	for(int i=0;i<30;i++){
		int tmp = rand()%10;
		t1.insert(tmp);			
	}
	bstree_7 t2;
	srand(time(NULL));
	for(int i=0;i<2;i++){
		int tmp = rand()%3;
		t2.insert(tmp);			
	}

	t1.inorder();
	t2.inorder();
	cout << isSubtree(t1,t2)<<endl;
	return 0;
}