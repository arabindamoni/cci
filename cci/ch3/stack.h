#include"linked_list.h"

class stack:public LinkedList{
public:
	void push(int data){
		Node *tmp = makenode(data);
		tmp->next = head;
		head = tmp;
	}

	int pop(){
		if(head == NULL){			
			throw "No more elements";			
		}			
		else{
			int data = head->data;
			head = head->next;
			return data;
		}		
	}	
};

