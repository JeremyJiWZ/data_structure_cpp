#include <iostream>
#include <cstdio>
#include <set>
using namespace std;
int N,M;
bool coin[501];
int main(){
	cin>>N>>M;
	int money;
	for(int i=1;i<=500;i++)
		coin[i]=false;
	for(int i=0;i<N;i++){
		scanf("%d",&money);
		coin[money]=true;
	}
	int flag=false;
	for(int i=1;i<=M/2;i++){
		if(coin[i]&&coin[M-i]){
			flag=true;
			cout<<i<<' '<<M-i<<endl;
            break;
		}
	}
	if(!flag)
		cout<<"No Solution"<<endl;
	return 0;
}
