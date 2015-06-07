#include<iostream>
#include<set>
#include"linked_list.h"
using namespace std;

class p1:public LinkedList{
public:
	void removeDuplicates(){
		Node *p = head;
		set<int> s;
		int pos=0;
		while(p){			
			if(s.find(p->data)!=s.end()){
				remove(pos);	
//after each removal size of list decreases									
				pos--; 
			}
			else{
				s.insert(p->data);			
			}
			p = p->next;
			pos++;
		}		
	}

	void removeDuplicatesNO_BUFFER(){
		Node *p= head;
		int pos = 0;
		while(p){			
			Node *q = p->next;			
			int i = pos+1;
			while(q){
				if(q->data == p->data){
					remove(i);					
					i--;					
				}
				q=q->next;
				i++;
			}
			p=p->next;
			pos++;
		}
	}
};

int main(){		
	p1 p;
	int data=0;
	cout << "Enter integer data,( -1 as end of entry)"<<endl;
	cin >> data;
	while(data!=-1){	
		p.append(data);
		cin >> data;
	}
	p.display();
	p.removeDuplicatesNO_BUFFER();
	p.display();	
	return 0;
}