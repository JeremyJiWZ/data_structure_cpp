#include <iostream>
#include <map>
#include <vector>
#include <set>
#include <cstdio>
using namespace std;

const int maxN=10001;
int N;
map<int, vector<int>> edges;
set<int> tmp;
bool isRoot[maxN],visit[maxN];
int cnt,maxd=-1,pre[maxN];

void merge(int a,int b);
int root(int a);
void init();
void DFS(int src,int step);
int main(){
    int m,n;
    cin>>N;
    init();
    for(int i=1;i<N;i++){
        cin>>m>>n;
        edges[m].push_back(n);
        edges[n].push_back(m);
        merge(m,n);
    }
    if(cnt!=1){
        printf("Error: %d components",cnt);
        return 0;
    }
    DFS(1, 1);
    for(set<int>::iterator iter=tmp.begin();iter!=tmp.end();iter++)
        isRoot[*iter]=true;
    int Root = *tmp.begin();
    DFS(Root, 1);
    for(set<int>::iterator iter=tmp.begin();iter!=tmp.end();iter++)
        isRoot[*iter]=true;
    for(int i=1;i<=N;i++)
        if(isRoot[i])
            printf("%d\n",i);
    
    
    return 0;
}

void init(){
    cnt=N;
    for(int i=1;i<=N;i++){
        visit[i]=false;
        pre[i]=i;
        isRoot[i]=false;
    }
}
int root(int a){
    if(pre[a]!=a){
        pre[a]=root(pre[a]);
    }
    return pre[a];
}
void merge(int a,int b){
    if(root(a)!=root(b)){
        pre[b]=a;
        cnt--;
    }
}
void DFS(int src,int step){
    if(step>maxd){
        tmp.clear();
        tmp.insert(src);
        maxd=step;
    }
    else if (step==maxd){
        tmp.insert(src);
    }
    visit[src]=true;
    vector<int>::iterator iter = edges[src].begin();
    for(;iter!=edges[src].end();iter++){
        if(!visit[*iter]){
            DFS(*iter, step+1);
        }
    }
    visit[src]=false;
}