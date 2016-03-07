#include <iostream>
#include <stdio.h>
using namespace std;

struct Table{
    int known=0;
    int dist=INT32_MAX;
    int path=-1;
    int bikeNeed=0;
    int bikeRet=0;
};
Table t[501];
int vertex[501];
int roads[501][501];
int Cmax,N,Sp,M;
void shortest(int v,int w);
void printPath(int v);
int main(){
    cin>>Cmax;
    cin>>N;
    cin>>Sp;
    cin>>M;
    int m,n;//m->n
    for(int i=0;i<501;i++)
        vertex[i]=-1;
    for(int i=0;i<501;i++)
        for(int j=0;j<501;j++)
            roads[i][j]=-1;
    for(int i=1;i<N+1;i++)
        cin>>vertex[i];
    for(int i=0;i<M;i++){
        cin>>m;
        cin>>n;
        cin>>roads[m][n];
        roads[n][m]=roads[m][n];
    }
    shortest(0,Sp);
    int bikeNum = t[Sp].bikeNeed;
    cout<<t[Sp].bikeNeed<<' ';
    printPath(Sp);
    cout<<' '<<t[Sp].bikeRet;
    return 0;
}

void shortest(int v, int w){
    t[v].dist=0;
    t[v].bikeNeed=0;
    int minDis;
    int P,Q;
    while(true){
        minDis=INT32_MAX;
        P=-1;
        Q=-1;
        for(int i=0;i<=N;i++){
            if(!t[i].known&&t[i].dist<minDis)
            {
                minDis=t[i].dist;
                P=i;
            }
        }
        t[P].known=1;
        if (P==-1||P==w)
            break;
        for(int i=0;i<=N;i++){
            if(roads[P][i]!=-1&&!t[i].known){
                int needOrRet = Cmax/2-vertex[i];
                int need = needOrRet-t[P].bikeRet;
                int retr = t[P].bikeRet-needOrRet;
                int newNeed=need>0?need+t[P].bikeNeed:t[P].bikeNeed;
                int newRetr=retr>0?retr:0;
                if(t[P].dist+roads[P][i]<t[i].dist
                   ||(t[P].dist+roads[P][i]==t[i].dist
                      &&newNeed<t[i].bikeNeed)
                   ||(t[P].dist+roads[P][i]==t[i].dist
                      &&newNeed==t[i].bikeNeed
                      &&newRetr<t[i].bikeRet))
                {
                    t[i].dist=t[P].dist+roads[P][i];
                    t[i].path=P;
                    t[i].bikeNeed=newNeed;
                    t[i].bikeRet=newRetr;
                }
            }
        }
    }
}
void printPath(int v){
    int back=t[v].path;
    if(v==0){
        cout<<0;
        return;
    }
    //else
    printPath(back);
    printf("->%d",v);
}
