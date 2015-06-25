#include<iostream>
#include<ctime>
using namespace std;
 
void permute_paren(int lcount,int rcount,int n,int length,char arr[]){	
	if(lcount ==0){
		for(int i=0;i<length;i++){
			if(i<n) cout <<arr[i];
			else cout << ')';
		}	
		cout << endl;	
	}	
	else{
		arr[n] = '(';
		permute_paren(lcount-1,rcount,n+1,length,arr);			
		if(lcount < rcount){
			arr[n] = ')';
			permute_paren(lcount,rcount-1,n+1,length,arr);
		}
	}

}

int permute_paren(int length){
	char *arr= new char[length];
	permute_paren(length,length,0,2*length,arr);
}

int main(){
	clock_t start = clock();	
	permute_paren(4);
	cout << "Execution time: "<<(clock() - start)/(double)1000000 <<" seconds"<<endl;
	return 0;
}