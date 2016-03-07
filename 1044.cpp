#include <iostream>
#include <algorithm>
using namespace std;
int N,M;
int nums[100000];
int main(){
	cin>>N>>M;
	for(int i=0;i<N;i++)
		cin>>nums[i];
	int sum=0,i=0,j=0;
	while(i<N&&j<N){
		sum+=nums[j];
		if(sum==M){
			sum-=nums[i];
			cout<<i+1<<'-'<<j+1<<endl;
			i=i+1;
			j++;
		}
		else if(sum>M){
			sum-=nums[i];
			sum-=nums[j];
			i++;
		}
		else{
			j++;
		}
	}


	return 0;
}

