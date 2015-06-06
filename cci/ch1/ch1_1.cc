#include<iostream>
#include<string>
using namespace std;

bool isUnique(string &str){
	int arr[256];
	for(int i=0;i<256;i++) arr[i] = 0;
	for(int i=0;i<str.size();i++){
		if(arr[str[i]]!=0) return false;
		else arr[str[i]]=1;
	}
	return true;
}

bool isUniqueBruteForce(string &str){
	for(int i=0;i<str.size();i++){
		for(int j=i+1;j<str.size();j++){
			if(str[j]==str[i]) return false;
		}
	}
	return true;
}

int main(){
	string s("unique");
	cout << isUnique(s) << endl;
	cout << isUniqueBruteForce(s) << endl;
	return 0;
}