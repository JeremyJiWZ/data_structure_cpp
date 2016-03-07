#include<iostream>
#include<math.h>
using namespace std;
int isPrime(int a){
	int dec = 2;
	int len = sqrt(a);
	if(a<2) return 0;
	for(dec=2;dec<=len;dec++){
		if(a%dec==0) return 0;
	}
	return 1;
}
int reverseNum(int num,int radix){
	int result = 0;
	int remain = 0;
	while(num>0){
		result *= radix;
		remain = num%radix;
		num /= radix;
		result += remain;
	}
	return result;
}
int main(void){
	int N,D;
	int reverse;
	while(true){
		cin>>N;
		if(N<0) break;
		cin>>D;
		reverse = reverseNum(N,D);
		if(isPrime(N))
			if(isPrime(reverse)) cout<<"Yes"<<endl;
			else cout<<"No"<<endl;
		else
			cout<<"No"<<endl;
	}
	return 0;
}
