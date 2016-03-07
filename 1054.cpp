#include <iostream>
#include <cstdio>
#include <map>
using namespace std;
map<int,int>hist;
int main(){
	int M,N;
	int dominant,maxN=0;
	cin>>M>>N;
	for (int i=0;i<N;i++)
		for(int j=0;j<M;j++){
			int color;
			scanf("%d",&color);
			if(hist.count(color)==0) hist[color]=1;
			else hist[color]++;
//			if(hist[color]>maxN){
//				maxN++;
//				dominant=color;
//			}
		}
    for (map<int,int>::iterator iter=hist.begin(); iter!=hist.end(); iter++) {
        if (iter->second>maxN) {
            maxN=iter->second;
            dominant=iter->first;
        }
    }
    cout<<dominant<<endl;
	return 0;
}
