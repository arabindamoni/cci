#include<iostream>
#include<ctime>
using namespace std;
void printarray(int arr[],int n){
	for(int i=0;i<n;i++){
		cout << arr[i] <<" ";
	}
	cout << endl;
}

void swap(int arr[],int i, int j){
	int tmp = arr[i];
	arr[i] = arr[j];
	arr[j] = tmp;
}

int find(int arr[],int n, int key){
	int left = 0;
	int right = n-1; 
	int mid;
	while(left <= right){
		mid = (left + right)/2;		
		if(arr[mid] == key)	return mid;
		if(arr[left] <= arr[mid]){
			if(key > arr[mid]) left = mid +1;
			else if(key < arr[left]) left = mid +1;			
			else right = mid-1;
		}
		else{
			if(key < arr[mid]) right = mid -1;
			else if(key <= arr[right]) left = mid +1;
			else right = mid -1;
		}
	}				
	return -1;
}

int main(){
	clock_t start = clock();
	int n = 9;	
	int arr[] = {7,8,9,1,2,3,4,5,6};

for(int i=1;i<=9;i++)  cout << i << "  :  "<<find(arr,n,i) << endl;
	
	cout << endl;
	cout << "Execution time: "<<(clock() - start)/(double)1000000 <<" seconds"<<endl;
	return 0;
}