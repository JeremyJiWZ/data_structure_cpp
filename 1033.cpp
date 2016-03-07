#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
struct Node{
	double price;
	double dist;
};
Node gas[500];
double Cm,D,dist;
int N;
bool cmp(const Node &a,const Node &b){
	return a.dist<b.dist;
}
int findNext(int i,double price){
	double src=gas[i].dist;
	i++;
	double mind=gas[i].price;
	int des=i;
	while(gas[i].dist-src<=Cm*dist){
		if(gas[i].price<=price)
			return i;
		if(gas[i].price<=mind){
			des=i;
			mind=gas[i].price;
		}
	}
	return des;
}
int main(){
	cin>>Cm>>D>>dist>>N;
	for(int i=0;i<N;i++){
		cin>>gas[i].price>>gas[i].dist;
	}
	sort(gas,gas+N,cmp);
	double tank=0, Maxdist=0,currentDist=0,currentPrice=0;
	int i=0;
	while(currentDist<D){
		//to next station
		if(Cm*dist+currentDist<gas[i+1].dist){
			currentDist+=Cm*dist;
			break;
		}
		int next = findNext(i,gas[i].price);
		if(gas[next].price<=gas[i].price||gas[next].dist==D){
			double db=gas[next].dist-gas[i].dist-tank*dist;
			currentPrice+=gas[i].price*db/dist;
			currentDist=gas[next].dist;
			i=next;
			tank=0;
		}
		else{
			double db=gas[next].dist-gas[i].dist;
			currentPrice+=(Cm-tank)*gas[i].price;
			currentDist=gas[next].dist;
			tank=Cm-db/dist;
			i=next;
		}
	}
	if(currentDist<D)
		printf("The maximum travel distance = %.2lf\n",currentDist);
	else
		printf("%.2lf\n",currentPrice);
	return 0;
}
