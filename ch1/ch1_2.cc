#include<iostream>
using namespace std;

void reverse(char arr[]){
	int size=0;
	while(arr[size]!='\0'){
		size++;
	}

	for(int i=0;i<=(size-1)/2;i++){
		char tmp = arr[i];
		arr[i]=arr[size-i-1];
		arr[size-i-1] = tmp;
	}

}

int main(){
	char arr[]={'a','\0'};
	//char arr[10];
	//cin >> arr;
	cout << arr << endl;
	reverse(arr);
	cout << arr << endl;
	return 0;
}