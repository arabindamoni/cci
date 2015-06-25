#include<iostream>
#include<ctime>
using namespace std;

long fib(unsigned n){
	if(n==1 || n==2) return 1;
	return fib(n-1)+fib(n-2);
}

int main(){
	clock_t start = clock();
	cout << fib(40)<<endl;	
	cout << "Execution time: "<<(clock() - start)/(double)1000000 <<" seconds"<<endl;
	return 0;
}