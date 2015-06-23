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

unsigned set(unsigned n,int index,bool b){
	if(b){
		return n | (1<<index);
	}
	else{
		unsigned mask = ~(1<<index);
		return n & mask;
	}
}

unsigned nextSmallest(unsigned n){
	int length=0, ones =0;;
	while(n>>length){ 
		length++;
		if(n & (1<<length)) ones++;
	}
	n=0;	
	for(int i=length-2;i>=length-1-ones;i--){
		n = set(n,i,true);
	}
	return n;
}


int main(){
	unsigned N =12;
	print_binary(N);	
	print_binary(nextSmallest(N));
	return 0;
}