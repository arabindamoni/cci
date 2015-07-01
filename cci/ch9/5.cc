#include<iostream>
#include<string>
#include<ctime>
using namespace std;

int find(string arr[],string key,int n){
	int left=0;
	int right = n-1;	
	while(left <= right){
		while(arr[left]=="" && left <= right) left++;
		while(arr[right]=="" && right >= left) right--;
		int mid = (left + right)/2;
		while(arr[mid]=="" && mid <=right) mid++;
		if(key == arr[mid]) return mid;
		else if(key <arr[mid]) right = mid -1;
		else left = mid +1;
	}

}

int main(){
	clock_t start = clock();
	int n = 9;	
	string arr[] = {"","at","","","bat","cat","","",""};

for(int i=0;i<9;i++)  cout << i << "  :  "<<find(arr,arr[i],n) << endl;
	
	cout << endl;
	cout << "Execution time: "<<(clock() - start)/(double)1000000 <<" seconds"<<endl;
	return 0;
}