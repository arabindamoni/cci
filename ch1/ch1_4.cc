#include<iostream>
#include<string>
using namespace std;

bool isAnagram(string &s1, string &s2){
	if(s1.size()!=s2.size()) return false;
	int arr[256];
	for(int i=0;i<256;i++) arr[i]=0;
	for(int i=0;i<s1.size();i++) arr[s1[i]]++;
	for(int i=0;i<s2.size();i++){
		if(arr[s2[i]]==0) return false;
	}		
	return true;
}

int main(){
	string str1,str2;
	cin >> str1>>str2;
	cout << isAnagram(str1,str2)<<endl;
	return 0;
}
