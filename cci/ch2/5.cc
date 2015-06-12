#include<iostream>
#include"linked_list.h"
using namespace std;

class p5:public LinkedList{

public:

	//points tail->next to node at index pos
	void makeLoop(int pos){
		Node *p = head;
		Node *q = head;
		while(pos--) p=p->next;						
		q=p;
		while(q->next) q = q->next;
		q->next=p;
	}

	//finds the first element of the loop
	int findLoop(){
		Node *p=head;
		Node *q=head->next->next;
		int count = 0;
		while(p!=q){
			p=p->next;
			q=q->next->next;
			count++;
		}		
		while(--count) p=p->next;
		return p->data;		
	}
};
int main(){
	p5 list;
	for(int i=0;i<10;i++) list.append(i);
	list.display();
	list.makeLoop(5);
	cout << list.findLoop()<<endl;
	return 0;
}