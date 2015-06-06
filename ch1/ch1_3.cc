#include<iostream>
using namespace std;

void removeDuplicate(char str[]){	
	int length =0;
	int tail = 1;	
	while(str[length]!='\0') length++;
	for(int i=1;i<length;i++){		
		int j;
		for(j=0;j<tail;j++){
			if(str[i]==str[j]){														
				break;
			}			
		}		
		if(j == tail) {
			str[tail] = str[i];
			tail++;
		}
	}
	str[tail] = '\0';
}

int main(){
	char arr[20];
	cin >> arr;
	removeDuplicate(arr);
	cout << arr << endl;
	return 0;
}
