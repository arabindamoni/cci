#include<cstdlib>
#include<vector>
#include<limits>
class bstree{
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

int isBalanced(node *p){
	if(p==NULL) return 0;
	int lheight = isBalanced(p->left);
	int rheight = isBalanced(p->right);
	if(lheight == -1 || rheight == -1 || abs(lheight-rheight)>1){
		return -1;
	}
	return (lheight > rheight)? (lheight+1) : (rheight+1);
}

public:
	bstree(){
		root = NULL;
		size = 0;
	}		

	bool isBalanced(){
		return isBalanced(root)>=0;
	}

	void insert(int data){
		root = insert(data,root);
	}

	void inorder(){
		std::cout<<"Printing tree in inorder traversal"<<std::endl;
		inorder(root,0);
	}

	void level_order(){
		std::cout<<"Level order traversal " << std::endl;
		std::vector<node *> queue;
		queue.push_back(root);
		node *p = makeNode(std::numeric_limits<int>::max());
		queue.push_back(p);
		while(!queue.empty()){
			node *tmp = *queue.begin();
			queue.erase(queue.begin());			
			if(tmp->left) queue.push_back(tmp->left);
			if(tmp->right) queue.push_back(tmp->right);
			if(tmp->data==std::numeric_limits<int>::max()){
				std::cout<<std::endl;
				if(!queue.empty()){
					node *p = makeNode(std::numeric_limits<int>::max());
					queue.push_back(p);
				}
			}
			else{
				std::cout<<tmp->data<<"  ";
			}
		}
	}
};