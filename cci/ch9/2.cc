#include <iostream>
#include <ctime>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
void printvector(vector<string> arr,int n){
	for(int i=0;i<n;i++){
		cout << arr[i] <<" ";
	}
	cout << endl;
}

void anagram_sort(vector<string> &str){
	struct{
		bool operator ()(string s1,string s2){
		    sort(s1.begin(),s1.end());
			sort(s2.begin(),s2.end());
			return s1<s2;
		}
	}comp;
	sort(str.begin(),str.end(),comp);
}

int main(){
	clock_t start = clock();
	vector<string> arr{"apple","cccbb","ab","aa","smsk","pplea"};	
	anagram_sort(arr);
	printvector(arr,arr.size());
	cout << "Execution time: "<<(clock() - start)/(double)1000000 <<" seconds"<<endl;
	return 0;
}