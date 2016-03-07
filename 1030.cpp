#include <iostream>
#include <cstdio>
using namespace std;
struct Table{
	int dist=-1;
	int cost=-1;
};
Table table[500][500];
bool Visited[500];
int cost[500];
int path[500];
int dist[500];
int N,M,S,D;
void SPS();
void printPath(int P);
int main(){
	cin>>N>>M>>S>>D;
	memset(Visited,false,N*sizeof(bool));
	int srt,des,dist,cost;
	for(int i=0;i<M;i++){
		cin>>srt>>des>>dist>>cost;
		table[srt][des].dist=table[des][srt].dist=dist;
		table[srt][des].cost=table[des][srt].cost=cost;
	}
	SPS();
	printPath(D);
	cout<<' '<<dist[D]<<' '<<cost[D];

	return 0;
}
void SPS(){
	memset(dist,INT_MAX,sizeof(int));
	memset(cost,INT_MAX,sizeof(int));
	dist[S]=0;
	path[S]=S;
	int P=S;
	while(P!=D){
		Visited[P]=true;
		for(int i=0;i<N;i++)
			if(table[P][i].dist!=-1){
				if(dist[P]+table[P][i].dist<dist[i]||
					dist[P]+table[P][i].dist==dist[i]&&cost[P]+table[P][i].cost<cost[i]){
					dist[i]=dist[P]+table[P][i].dist;
					cost[i]=cost[P]+table[P][i].cost;
					path[i]=P;

				}
			}
		int mind=INT_MAX;
		for(int i=0;i<N;i++)
			if(!Visited[i]&&dist[i]<mind){
				P=i;
				mind=dist[i];
			}
	}




}
void printPath(int P){
	if(path[P]!=S){
		printPath(path[P]);
		cout<<' '<<P;
	}
	else
		cout<<S;
}
