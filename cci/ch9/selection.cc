#include<iostream>
#include<ctime>
using namespace std;

void selectionsort(int arr[],int n){
	int min;
	for(int i=0;i<n-1;i++){
		min = i;
		for(int j=i+1;j<n;j++){
			if(arr[min]>arr[j]) min =j;
		}
		int tmp = arr[i];
		arr[i] = arr[min];
		arr[min] = tmp;
	}
}

int main(){
	clock_t start = clock();
	int n;	
	cout << "Enter number of elements in array"<<endl;
	cin >> n;	
	int *arr = new int[n];
	cout <<"Enter elements" <<endl;
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	selectionsort(arr,n);
	for(int i=0;i<n;i++){
		cout << arr[i] <<" ";
	}
	cout << endl;
	cout << "Execution time: "<<(clock() - start)/(double)1000000 <<" seconds"<<endl;
	return 0;
}