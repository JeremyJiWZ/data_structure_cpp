#include <iostream>
#include <map>
#include <set>
#include <string>
#include <cstdio>
#include <vector>
using namespace std;

vector<set<string>>courseList(5000);
int N,K;
int main(){
    scanf("%d %d",&N,&K);
    for(int i=0;i<N;i++){
        char name[5];
        scanf("%s",name);
        int n;
        scanf("%d",&n);
        for(int j=0;j<n;j++){
            int courseNum;
            scanf("%d",&courseNum);
            courseList[courseNum].insert(name);
        }
    }
    for(int i=1;i<=K;i++){
        printf("%d %lu\n",i,courseList[i].size());
        for(set<string>::iterator it=courseList[i].begin(); it!=courseList[i].end();it++)
            printf("%s\n",(*it).c_str());
    }
    return 0;
}
