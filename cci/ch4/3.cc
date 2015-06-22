#include<iostream>
#include"bstree.h"
using namespace std;

//creates a balanced bstree from a sorted array
void makeTree(bstree *t,int arr[],int start, int end){	
	if(start > end) return;
	int mid=(start+end)/2;
	t->insert(arr[mid]);	
	makeTree(t,arr,start,mid-1);
	makeTree(t,arr,mid+1,end);
}

int main(){
	int arr[]={1,2,3,4,5,6,7};
	bstree *t = new bstree;
	makeTree(t,arr,0,7);
	t->inorder();
	return 0;
}