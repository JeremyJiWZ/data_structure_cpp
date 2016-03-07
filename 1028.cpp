#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
struct Student{
	string id;
	string name;
	int grade;
};
bool cmp1(const Student &a,const Student &b){
	return a.id<b.id;
}
bool cmp2(const Student &a,const Student &b){
	if(a.name<b.name)
		return 1;
	if(a.name==b.name)
		return a.id<b.id;
	return 0;
}
bool cmp3(const Student &a,const Student &b){
	if(a.grade==b.grade)
		return a.id<b.id;
	return a.grade<b.grade;
}
Student stus[100000];
int N,C;
int main(){
	cin>>N>>C;
	for(int i=0;i<N;i++){
		cin>>stus[i].id;
		cin>>stus[i].name;
		cin>>stus[i].grade;
	}
	if(C==1)
		sort(stus,stus+N,cmp1);
	else if(C==2)
		sort(stus,stus+N,cmp2);
	else if(C==3)
		sort(stus,stus+N,cmp3);
	for(int i=0;i<N;i++)
	{
		cout<<stus[i].id<<' '<<stus[i].name<<' '<<stus[i].grade<<endl;
	}
	return 0;
}
