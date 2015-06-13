#include<iostream>
#include"stack.h"
using namespace std;

class stack2:private stack{
private:
	LinkedList minlist;	
public:
	void push2(int data){
		push(data);
		if(minlist.size()==0 || data < minlist.get(0)){
			try{
				minlist.insert(0,data);
			}catch(const char* ex){
				cout<<ex<<endl;
			}
		}
	}

	int pop2(){		
		int data = pop();		
		if(data == minlist.get(0)){
			try{
				minlist.remove(0);					
			}catch(const char* ex){
				cout<<ex<<endl;
			}
		}
		return data;
	}
	int getmin(){
		try{
	 		return minlist.get(0);
		}catch(const char* ex){
				cout<<ex<<endl;
		}
	}
};

int main(){
	stack2 st;
	for(int i=0;i<5;i++){
		st.push2(10-i);	
		cout << st.getmin()<<"\t";		
	}
	cout<<endl;
	for(int i=0;i<4;i++){		
		st.pop2();					
		cout << st.getmin()<<"\t";
	}
	cout<<endl;
	
	return 0;
}