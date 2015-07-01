#include<iostream>
#include<ctime>
using namespace std;

bool find(int *arr,int m,int n,int i,int j,int key){
	if(m<=i || n <=j) return false;
	if(key ==  *(arr+m*i+j)) return true;
	else if(key < *(arr+m*i+j)) return find(arr,m,n,i-1,j,key) || find(arr,m,n,i,j-1,key);
	else return find(arr,m,n,i+1,j,key) || find(arr,m,n,i,j+1,key);
}


int main(){
	clock_t start = clock();
	int m =4, n=4;
	int *arr = new int[m*n];
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			*(arr+m*i+j) = i+j;
		}
	}
	cout << find(arr,m,n,0,0,0);
	cout << endl;
	cout << "Execution time: "<<(clock() - start)/(double)1000000 <<" seconds"<<endl;
	return 0;
}