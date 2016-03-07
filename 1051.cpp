#include <iostream>
#include <cstdio>
#include <stack>
using namespace std;
int M,N,K;
int sequences[1000];
bool checkPopSequence(){
	int last=1;
	stack<int> stk;
	for(int i=0;i<N;i++){
		while(last-1<sequences[i])
			stk.push(last++);
		if(stk.size()>M||stk.top()>sequences[i])
			return false;
		else
			stk.pop();
	}
	return true;
}
int main(){
	cin>>M>>N>>K;
	for(int i=0;i<K;i++){
		for(int j=0;j<N;j++)
			scanf("%d",&sequences[j]);
		if(checkPopSequence())
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
	}
	return 0;
}
