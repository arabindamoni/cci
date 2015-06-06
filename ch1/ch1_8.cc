#include<iostream>
#include<string>
using namespace std;

bool isSubstring(string &str1,string &str2){
	return str1.find(str2)!=string::npos?true:false;
}

bool isRotation(string &str1, string &str2){		
	return (str1.size()==str2.size()) && isSubstring(str1+=str1,str2);
}

int main(){
	string str1,str2;
	cin >> str1 >>str2;
	cout << isRotation(str1,str2) << endl;	
	return 0;
}