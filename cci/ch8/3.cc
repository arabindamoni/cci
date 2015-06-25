#include<iostream>
#include<ctime>
using namespace std;

void power_set(int arr[],int n){
	long max = (1 << n);
	for(long i=0;i<max;i++){
		cout<<endl<<i;
		for(int j=0;j<n;j++){
			if((i>>j)&1) cout<<" "<<arr[j];			
		}		
	}
}

int main(){
	clock_t start = clock();
	int arr[]={1,2,3,4,5,6,7,8,9,10};
	power_set(arr,10);
	cout << endl<<"Execution time: "<<(clock() - start)/(double)1000000 <<" seconds"<<endl;
	return 0;
}