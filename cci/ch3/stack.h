#include"linked_list.h"

class stack:public LinkedList{
public:
	void push(int data){		
		insert(0,data);		
	}	

	int pop(){
		if(head == NULL){			
			throw "No more elements";			
		}			
		else{
			int data = get(0);
			remove(0);
			return data;
		}		
	}

	bool isEmpty(){
		return size()==0 ? true:false;
	}

	int peek(int pos){
		return get(pos);
	}
};

