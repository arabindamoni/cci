#include<iostream>
#include"stack.h"
using namespace std;

class queue:private stack{
private:
	stack st;
	stack tmp;	
public:	
	void push(int data){
		while(!st.isEmpty()){
			tmp.push(st.pop());
		}
		st.push(data);
		while(!tmp.isEmpty()){
			st.push(tmp.pop());
		}
	}

	int pop(){
		if(st.isEmpty()) throw "queue underflow";
		return st.pop();
	}
};

int main(){
	queue q;
	for(int i=0;i<5;i++){
		q.push(i);
	}
	for(int i=0;i<5;i++){
		cout<<q.pop()<<endl;
	}
	return 0;	
}

