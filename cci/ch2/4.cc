#include<iostream>
#include"linked_list.h"
using namespace std;

void add(LinkedList l1,LinkedList l2,LinkedList *res){	
	int carry=0;
	int i;
	for(i=0; i<l1.size() && i < l2.size(); i++){
		int a = l1.get(i);
		int b = l2.get(i);
		int data = (a+b+carry)%10;
		carry = (a+b+carry)/10;
		res->append(data);
	}		
	while(i < l1.size()){
		int a = l1.get(i);		
		int data = (a+carry)%10;
		carry = (a+carry)/10;
		res->append(data);
		i++;
	}	
	while(i < l2.size()){
		int b = l2.get(i);		
		int data = (b+carry)%10;
		carry = (b+carry)/10;
		res->append(data);
		i++;
	}
	if(carry!=0) res->append(carry);	
}

int main(){
	LinkedList list1;
	list1.append(9);
	list1.append(6);
	list1.append(9);
	list1.display();

	LinkedList list2;
	list2.append(5);
	list2.append(3);
	list2.append(6);
	list2.append(4);
	list2.display();

	LinkedList res;
	add(list1,list2,&res);
	res.display();
	return 0;
}