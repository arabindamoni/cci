#include<iostream>
#include"binary.h"
using namespace std;

int bits(int m,int n){
	int t = m^n;
	int i=0;
	while(t){
		if(t&1) i++;
		t = t>>1;
	}
	return i;
}

int main(){
	int N,M;
	cout << "Enter two integers"<<endl;
	cin >> N >> M;
	print_binary(N);
	print_binary(M);
	cout << bits(M,N)<<endl;
	return 0;
}