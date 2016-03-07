#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

class Customer{
public:
    int arriveTime;
    int procTime;
    int serveTime=-1;//not served
};
Customer customers[10000];
int windowDue[100];
int cmp(const Customer &a, const Customer &b){
    return a.arriveTime<b.arriveTime;
}
int main(){
    int N,K;
    cin>>N;
    cin>>K;
    int currentTime=8*60*60;
    int hour,min,sec;
    int proc;
    
    for (int i =0; i<N; i++) {
        scanf("%d:%d:%d %d",&hour,&min,&sec,&proc);
        customers[i].arriveTime=hour*60*60+min*60+sec;
        customers[i].procTime=proc;
    }
    sort(customers, customers+N, cmp);
    for(int i=0;i<K;i++) windowDue[i]=8*60*60;
    int m=0;
    while (m<N) {
        int window,Due;
        window=0;
        Due=windowDue[0];
        for (int i=0; i<K;i++){
            if(windowDue[i]<currentTime)
                windowDue[i]=currentTime;
            if(windowDue[i]<Due) {
                Due=windowDue[i];
                window=i;
            }
        }
        if(customers[m].arriveTime>17*60*60) break;
        if(Due<customers[m].arriveTime){
            currentTime=customers[m].arriveTime;
        }
        else{
            customers[m].serveTime=Due;
            windowDue[window]+=customers[m].procTime*60;
            m++;
            currentTime=Due;
        }
    }
    int total=0,count=0;
    for(int i =0;i<N;i++)
        if(customers[i].serveTime!=-1){
            int time=customers[i].serveTime-customers[i].arriveTime;
            //            cout<<time<<endl;
            total+=customers[i].serveTime-customers[i].arriveTime;
            count++;
        }
    double average=count!=0?((double)total/count/60):0;
    printf("%.1lf\n",average);
    return 0;
}
