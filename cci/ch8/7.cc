#include<iostream>
#include<ctime>
using namespace std;

long cent(int n,int denom[],int curdenom){
	if(curdenom == 3) return 1;
	long sum =0;
	for(int i=0;i*denom[curdenom]<=n;i++){
		sum+= cent(n-i*denom[curdenom],denom,curdenom+1);
	}	
	return sum;
}

int main(){
	clock_t start = clock();
	int denom[] = {25,10,5,1};	
	int n;
	cin >> n;
	cout << cent(n,denom,0)<<endl;;	
	cout << "Execution time: "<<(clock() - start)/(double)1000000 <<" seconds"<<endl;
	return 0;
}