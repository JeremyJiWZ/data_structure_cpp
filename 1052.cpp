#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
struct Node{
	int key;
	string next;
	string address;
};
bool cmp(const Node& a,const Node &b){
	return a.key<b.key;
}
Node list[100000];
int N;
int main(){
	cin>>N;
	int head;
	cin>>head;
	for(int i=0;i<N;i++){
		cin>>list[i].address>>list[i].key>>list[i].next;
	}
	sort(list,list+N,cmp);
	cout<<N<<' '<<list[0].address<<endl;
	for(int i=0;i<N-1;i++)
		cout<<list[i].address<<' '<<list[i].key<<' '<<list[i+1].address<<endl;
	cout<<list[N-1].address<<' '<<list[N-1].key<<' '<<-1<<endl;
	return 0;
}
