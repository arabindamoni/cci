#include<iostream>
using namespace std;

void print_binary(unsigned n){	
	int arr[32];
	int i;
	if(n==0) cout <<0;
	for(i=0;i<32 && n;i++){
		if(n & 1) arr[i]=1;
		else arr[i]=0;
		n /=2;
	}
	for(;i>0;i--){
		cout << arr[i-1];
	}
	cout << endl;
}
int changebits(int N,int M,int i,int j){
	int tmp = ~0;	
	tmp = tmp ^ ((1<<j) -1);		
	tmp = tmp | ((1<<i) -1);
	N = N & tmp;	
	N = N | (M<<i);
	return N;
}

int main(){
	unsigned N = 9000, M = 15;
	print_binary(N);
	print_binary(M);
	N = changebits(N,M,2,6);
	print_binary(N);	
	return 0;
}