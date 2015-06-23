#include<iostream>
using namespace std;

void print_binary(double num){		
	int n = (int) num;  //integer part
	double f = num - n;	// fraction part
	int arr[32];
	int i;

	//convert integer part;
	if(n==0) cout <<0;
	for(i=0;i<32 && n;i++){
		if(n & 1) arr[i]=1;
		else arr[i]=0;
		n /=2;
	}
	for(;i>0;i--){
		cout << arr[i-1];
	}
	cout <<".";
	//convert fraction part
	for(i=0;i<32;i++){
		f*=2;
		if(f==1){ cout<<1; break;}
		if(f > 1){ cout <<1; f = f-1;}
		else{ cout << 0;}
	}
	cout << endl;
}

int main(){
	double num;
	cout << "enter a double number"<<endl;
	cin >> num;
	print_binary(num);
	return 0;
}