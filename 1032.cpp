#include <iostream>

using namespace std;
struct List{
	char data;
	int next;
};
List node[100000];
int add1,add2,N;

int main(){
	cin>>add1>>add2>>N;
	int addr,nextAdd;
	char dat;
	for(int i=0;i<N;i++){
		cin>>addr;
		cin>>dat;
		cin>>nextAdd;
		node[addr].data=dat;
		node[addr].next=nextAdd;
	}
	int sharing=-1;
	addr=add1;
	while(addr!=-1){
		
	}

	cout<<sharing<<endl;


	return 0;
}
