#include<iostream>
#include<string>
using namespace std;

string replaceSpace(const string &str){
	string res;	
	for(int i=0;i<str.size();i++){
		if(str[i]==' '){
			res+='%';
			res+='2';
			res+='0';
		}
		else{
			res+=str[i];
		}
	}
	return res;
}

int main(){
	string s = "apple is a fruit";
	cout << replaceSpace(s)<<endl;
	return 0;
}
