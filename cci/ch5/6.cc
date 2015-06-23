#include<iostream>
#include"binary.h"
using namespace std;

int swapbits(int n){
	int tmp=0;
	if(n & (1<<1)) tmp = 1;
	n = n<<1;
	n= n|tmp;
	return n;
}

int main(){
	int N;
	cout << "Enter an integers"<<endl;
	cin >> N ;
	print_binary(N);	
	print_binary(swapbits(N));
	return 0;
}