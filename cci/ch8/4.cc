#include<iostream>
#include<ctime>
using namespace std;

void printarray(int arr[],int n){
	for(int i=0;i<n;i++) cout <<" "<<arr[i];
	cout << endl;		
}

void swap(int arr[],int i,int j){
	int tmp=arr[i];
	arr[i]=arr[j];
	arr[j]=tmp;
}

void permute(int arr[],int first,int last){
	if(first==last) {printarray(arr,last+1);	return;}	
	for(int i=first;i<=last;i++){
		swap(arr,first,i);
		permute(arr,first+1,last);		
		swap(arr,first,i);
	}
}

void permute(int arr[],int n){
	permute(arr,0,n-1);
}

int main(){
	clock_t start = clock();
	int arr[]={1,2,3,4};
	permute(arr,4);
	cout << "Execution time: "<<(clock() - start)/(double)1000000 <<" seconds"<<endl;
	return 0;
}