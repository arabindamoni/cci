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

void quicksort(int arr[],int left,int right){
	if(left>=right) return;
	int pivot = arr[left];
	int i=left+1, j = right;
	while(i <= j && j>left && i < right){
		if(arr[i] < pivot){ i++; }
		if(arr[j] >= pivot) {j--;}
		else if(arr[i] >=pivot){ 
			swap(arr,i,j);	
		}
	}	
	if(pivot > arr[j]){
		arr[left] = arr[j];
		arr[j]=pivot;
	}
	
	cout << left <<","<<right <<" -- "<<i << "  "<< j<<" : ";
	printarray(arr,5);
	quicksort(arr,left,j-1);
	quicksort(arr,j+1,right);	
}

int main(){
	clock_t start = clock();
	int n=5;	
	int arr[]={1,2,3,4,5};
	quicksort(arr,0,n-1);
	printarray(arr,n);
cout << endl;
	int arr1[] = {5,4,3,2,1};
	quicksort(arr1,0,n-1);
	printarray(arr1,n);
cout << endl;
	int arr2[] = {2,1,5,3,1};
	quicksort(arr2,0,n-1);
	printarray(arr2,n);
	
	cout << "Execution time: "<<(clock() - start)/(double)1000000 <<" seconds"<<endl;
	return 0;
}