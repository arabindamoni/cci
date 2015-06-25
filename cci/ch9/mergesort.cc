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

void merge(int arr[],int left,int mid,int right){
	int k =left;
	int i = mid +1;
	int j = 0;
	int size = (right-k+1);
	int *res = new int[size];
	while(k <= mid && i<=right){
		if(arr[k] > arr[i]) res[j++] = arr[i++];
		else res[j++] = arr[k++];		
	}
	while(k <= mid){
		res[j] = arr[k];
		j++; k++;
	}
	while(i <= right){
		res[j] = arr[i];
		j++; i++;
	}
	i=0;
	while(left<=right){
		arr[left++]=res[i++];
	}
}

void mergesort(int arr[],int left, int right){
	if(left < right){
		int mid = (right + left)/2;
		mergesort(arr,left,mid);
		mergesort(arr,mid+1,right);
		merge(arr,left,mid,right);		
	}	
}

int main(){
	clock_t start = clock();
	int n=5;	
	int arr[]={1,2,3,4,5};
	mergesort(arr,0,n-1);
	printarray(arr,n);
cout << endl;
	int arr1[] = {5,4,3,2,1};
	mergesort(arr1,0,n-1);
	printarray(arr1,n);
cout << endl;
	int arr2[] = {2,4,5,3,1};
	mergesort(arr2,0,n-1);
	printarray(arr2,n);
	
	cout << "Execution time: "<<(clock() - start)/(double)1000000 <<" seconds"<<endl;
	return 0;
}