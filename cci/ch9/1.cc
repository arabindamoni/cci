#include <iostream>
using namespace std;

void merge(int arr1[], int arr2[], int n, int m){
	int k = n + m -1;
	int i = n-1;
	int j = m-1;
	while(i>=0 && j >=0){
		if(arr1[i] < arr2[j]){
			arr1[k--]=arr2[j];
			j--;
		}
		else{
			arr1[k--] = arr1[i];
			i--;
		}
	}
	while(j>=0){
		arr1[k--] = arr2[j--];
	}
}

void printarray(int arr[],int n){
	for(int i=0;i<n;i++) cout << arr[i] <<" ";
	cout << endl;
}

int main(){
	int *arr1 = new int[13];
	arr1[0] = 2; arr1[1]= 4; arr1[2]=6;arr1[3]=8; arr1[4]=10;
	int arr2[]	= {1,3,5,7,9,11,13,15};
	merge(arr1,arr2,5,8);
	printarray(arr1,13);
	return 0;
}