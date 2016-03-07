#include <iostream>
#include <string>
using namespace std;
int main(){
	string in;
	cin>>in;
	int n1,n2,len=in.length();
	int maxn=0,tmp;
	int initial = len%2==0?4:3;
	for(int i=initial;i<=len;i+=2){
		tmp=(len-i)/2+1;
		if(tmp<=i&&tmp>maxn){
			maxn=tmp;
		}
	}
	n1=maxn;
	n2=len-2*maxn+2;
	for(int i=0;i<n1-1;i++){
		cout<<in[i];
		for(int j=0;j<n2-2;j++)
			cout<<' ';
		cout<<in[len-1-i]<<endl;
	}
	for(int i=0;i<n2;i++)
		cout<<in[i+n1-1];
	
	return 0;
}
