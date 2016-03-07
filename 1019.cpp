#include<iostream>
#include<vector>
using namespace std;
vector<unsigned int> getCoef(unsigned int N,unsigned int b);
bool isReverse(vector<unsigned int> coef);
int main(){
	unsigned int N,b;
	cin>>N>>b;
	vector<unsigned int> coef = getCoef(N,b);
	if(isReverse(coef))
		cout<<"Yes"<<endl;
	else
		cout<<"No"<<endl;
	cout<<coef[0];
	for(int i=1;i<coef.size();i++)
		cout<<' '<<coef[i];

	return 0;
}
bool isReverse(vector<unsigned int> coef){
	int i=0,j=coef.size()-1;
	for(;i<j;i++,j--)
		if(coef[i]!=coef[j])
			return false;
	return true;
	

}
vector<unsigned int> getCoef(unsigned int N,unsigned int b){
	vector<unsigned int> coef;
	unsigned int remain,quot;
	quot=N/b;
	remain=N%b;
	if(quot>0)
		coef = getCoef(quot,b);
	coef.push_back(remain);
	return coef;
}
