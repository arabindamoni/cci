#include<iostream>
#include"stack.h"
using namespace std;

stack *sortStack(stack *st){
	stack *tmp = new stack();
	while(!st->isEmpty()){
		int data = st->pop();		
		int tmp_top;	
		int count=0;		
		while(!tmp->isEmpty() && (tmp_top=tmp->pop())<data){	
				st->push(tmp_top);			
				count++;		   		
		}				
	    if(tmp_top >= data)	tmp->push(tmp_top);
		while(count--){
			tmp->push(st->pop());
		}		
		tmp->push(data);						
	}		
	return tmp;
}

int main(){
	stack stk;
	for(int i=5;i>0;i--){
		stk.push(i);
	}
	stk.display();
	stack *tmp=sortStack(&stk);
	tmp->display();
	return 0;
}
