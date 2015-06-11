#include<iostream>
#include"linked_list.h"
using namespace std;

class p2:public LinkedList{
public:
	int nth_last(int n){
		Node *p = head;
		Node *q = head;			
		if(n==0){
			cerr<<"wrong vaue of n"<<endl;
			return -1;
		}
		while(q!=NULL && n--){
			q=q->next;
		}
		if(q==NULL && n) {
			cerr<<"wrong vaue of n"<<endl;
			return -1;
		}
		while(q){
			p=p->next;
			q=q->next;
		}
		return p->data;
	}
};

int main(){
	p2 p;
	int data=0;
	cout << "Enter integer data,( -1 as end of entry)"<<endl;
	cin >> data;
	while(data!=-1){	
		p.append(data);
		cin >> data;
	}
	p.display();
	cout<<p.nth_last(1)<<endl;
	cout<<p.nth_last(3)<<endl;
	cout<<p.nth_last(p.size())<<endl;
	return 0;
}