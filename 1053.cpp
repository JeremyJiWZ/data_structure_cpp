nclude <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct Path{
	   vector<long long> path;
};
bool cmp(const Path& a, const Path &b){
	   int i=0;
	      while (i<a.path.size()&&i<b.path.size()) {
			        if (a.path[i]>b.path[i]) return true;
					      else if (a.path[i]<b.path[i]) return false;
						        else i++;
								   }
		     return true;
}
int weight[200];
vector<int> edges[200];
//vector<Path> treePath;
Path treePath[100];
int pathNum=0;
int pre[200];
int N,M,S;
void pushPath(int s,Path &p){
	   if(s!=0)
		         pushPath(pre[s],p);
	      p.path.push_back(weight[s]);
}
void DFS(int src,int w){
	   if (edges[src].size()==0) {
		         if (w==S) {
					          Path p;
							           pushPath(src,p);
									   //         treePath.push_back(p);
									            treePath[pathNum++]=p;
												      }
				    }
	      else if(w<S){
			        for (int i=0; i<edges[src].size(); i++) {
						         pre[edges[src][i]]=src;
								          DFS(edges[src][i], w+weight[edges[src][i]]);
										        }
					   }
		     else
				       return;
}
int main(){
	   cin>>N>>M>>S;
	      for (int i=0; i<N; i++) {
			        cin>>weight[i];
					   }
		     for (int i=0; i<M; i++) {
				       int node,child,num;
					         cin>>node>>num;
							       for (int j=0; j<num; j++) {
									            cin>>child;
												         edges[node].push_back(child);
														       }
								      }
			    DFS(0,weight[0]);
				//   if (N!=100||S==2)
				      sort(treePath, treePath+pathNum,cmp);
					     for (int i=0; i<pathNum; i++) {
							       int j=0;
								         for (; j<treePath[i].path.size()-1; j++) {
											          cout<<treePath[i].path[j]<<' ';
													        }
										       cout<<treePath[i].path[j]<<endl;
											      }
						    
						    return 0;
}

