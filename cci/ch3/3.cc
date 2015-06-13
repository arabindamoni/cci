#include<iostream>
#include"stack.h"
using namespace std;

class SetOfStack:private stack{
private:
	int N;
	int capacity;
	int curstack; 
	stack *sos;  //set of stacks

public:
	//initialize total number of stacks
	// and capacity of each stack
	SetOfStack(int n,int cap){
		N = n;
		capacity = cap;
		sos = new stack[N];
		curstack = 0;
	}

	void push(int data){
		if(sos[curstack].size() < capacity){
			sos[curstack].push(data);			
		}
		else{
			curstack++;
			if(curstack < N){
				sos[curstack].push(data);
				cout<<"\nNew stack created "<<curstack<<endl;
			}
			else{
				throw "Stack overflow";
			}
		}			
		cout<<"pushing "<<data<<endl;
	}

	int pop(){
		if(sos[curstack].size()>0){
			return sos[curstack].pop();
		}
		else{
			curstack--;
			if(curstack>=0){
				return sos[curstack].pop();
			}
			else{
				throw "stack underflow";
			}
		}
	}

	//index is index of stack
	int popAt(int index){
		if(index >=N || index < 0) throw "Wrong stack index";
		return sos[index].pop();
	}
};



int main(){
	SetOfStack st(5,4);
	for(int i=0;i<20;i++){
		st.push(i);		
	}

	cout << st.popAt(0)<<endl;

	for(int i=0;i<19;i++){
		cout<<st.pop()<<endl;
	}

	
	return 0;
}