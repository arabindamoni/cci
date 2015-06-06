#include<iostream>
using namespace std;

const int M=3;
const int N=4;


void makezeros(int arr[M][N]){
	bool zerorows[M];
	bool zerocols[N];
	for(int i=0;i<M;i++) zerorows[i] = false;
	for(int i=0;i<M;i++) zerocols[i] = false;	
	for(int i=0;i<M;i++){
		for(int j=0;j<N;j++){
			if(arr[i][j]==0) {
				zerorows[i]=true;
				zerocols[i] = true;
			}
		}
	}

	for(int i=0;i<M;i++){
		for(int j=0;j<N;j++){
			if(zerorows[i]==true || zerocols[j]==true) {
				arr[i][j]= 0;
			}			
		}
	}
}

void display(int arr[M][N]){
	for(int i=0;i<M;i++){
		for(int j=0;j<N;j++){
			cout<<arr[i][j] << "\t";
		}
		cout<<endl;
	}
}

int main(){
	int arr[M][N] = {1,1,3,2,1,0,2,4,2,4,0,0};
	display(arr);
	cout <<":::::::::::"<<endl;
	makezeros(arr);
	display(arr);
	return 0;
}