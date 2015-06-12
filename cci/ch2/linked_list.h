class LinkedList{

private:
	int length;

protected:
	class Node{	
	public:
		int data;
		Node * next = NULL;
	};

	Node * head = NULL;		

	Node *makenode(int data){
		Node* newnode = new Node();
		newnode->data=data;
		newnode->next = NULL;
		return newnode;
	}

public:
	LinkedList(){
		length=0;
	}

	int size(){
		return length;
	}

	//get data of node at index pos
	int get(int pos){
		if(pos>=length) return -1;
		Node *p = head;
		while(pos--){
			p=p->next;
		}
		return p->data;
	}

	void append(int data){		
		insert(length,data);
	}	

	void insert(int pos,int data){
		if(pos == 0){
			Node *tmp = makenode(data);
			tmp->next = head;
			head = tmp;
		}
		else{
			Node *p=head;
			for(int i=0;i<pos-1;i++){
				p=p->next;
			}
			Node *tmp = makenode(data);
			tmp->next = p->next;
			p->next = tmp;
		}
		length++;
	}

	void remove(int pos){
		if(pos >= length) return;
		Node *p = head;
		if(pos == 0) head = head->next; return;
		for(int i=1;i<pos;i++){
			p = p->next;
		}
		p->next = p->next->next;
		length--;
	}

	void display(){
		Node *p = head;
		while(p!=NULL){
			std::cout << p->data <<"\t";
			p=p->next;
		}
		std::cout<<std::endl;
	}	
};
