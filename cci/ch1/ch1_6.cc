#include<iostream>
using namespace std;

const int N =3;

void rotate90(int arr[N][N]){
	int tmp[N][N];
	for(int row=0;row<N;row++){
		for(int col=0;col<N;col++){
			tmp[col][N-row-1] = arr[row][col];
		}
	}
	for(int i=0;i<N;i++) {
		for(int j=0;j<N;j++){ 
			arr[i][j]=tmp[i][j];
		}
	}	
}

void rotate90_a(int arr[N][N]){
	for(int layer=0;layer<N/2;layer++){
		int first = layer;
		int last = N - layer - 1;
		for(int i=first;i<last;i++){
			int offset = i - first;
			int tmp = arr[first][i];
			arr[first][i] = arr[last-offset][first];
			arr[last-offset][first] = arr[last][last-offset];
			arr[last][last-offset] = arr[i][last];
			arr[i][last]=tmp;
		}
	}
}

void display(int arr[N][N]){
	for(int i=0;i<N;i++) {
		for(int j=0;j<N;j++){ 
			cout<<arr[i][j]<<"\t";
		}
		cout<<endl;
	}	
}
int main(){
	int arr[N][N]={1,2,3,4,5,6,7,8,9};
	display(arr);
	//cout<<"After right 90 rotation"<<endl;
	//rotate90(arr);
	//display(arr);
	cout<<"After right 90 rotation"<<endl;
	rotate90_a(arr);
	display(arr);
	return 0;
}
