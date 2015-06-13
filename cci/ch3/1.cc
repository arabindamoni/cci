#include<iostream>
using namespace std;

class stacks3{
private:
	int N ;
	int *arr;	
	int top1;
	int top2;
	int top3;
public:
	stacks3(){
		N = 300;
		arr = new int(N);	
		top1=0;
		top2=N/3;
		top3=2*N/3;
	}
	//stack=1,2 or 3 for respectively
	// first,second and third stack
	void push(int data,int stack){
		switch(stack){
			case 1: 
			if(top1==N/3) throw "Stack 1 is full";
			arr[top1++]=data;
			break;
			case 2:
			if(top2==2*N/3) throw "Stack 2 is full";
			arr[top2++]=data;
			break;
			case 3:
			if(top3==N-1) throw "Stack 3 is full";
			arr[top3++]=data;			
		}		
	}

	int pop(int stack){
		switch(stack){
			case 1:
			if(top1==0)  throw "Stack 1 is empty";
			return arr[--top1];
			case 2:
			if(top2==0)  throw "Stack 2 is empty";
			return arr[--top2];
			case 3:
			if(top3==0)  throw "Stack 3 is empty";
			return arr[--top3];
		}
	}

};

int main(){
	stacks3 stk;
	for(int i=1;i<6;i++){
		stk.push(i,1);
		stk.push(2*i,2);
		stk.push(3*i,3);
	}

	for(int i=0;i<6;i++){
		try{
			cout << stk.pop(1) <<"  :  "<<stk.pop(2) << "  :  "<<stk.pop(3)<<endl;			
		}
		catch(const char *ex){
			cout << ex << endl;
		}		
	}
} 