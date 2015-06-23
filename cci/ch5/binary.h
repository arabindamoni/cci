void print_binary(unsigned n){	
	int arr[32];
	int i;	
	for(i=0;i<32;i++){
		if(n & 1) arr[i]=1;
		else arr[i]=0;
		n /=2;
	}
	for(;i>0;i--){
		std::cout << arr[i-1];
	}
	std::cout << std::endl;
}