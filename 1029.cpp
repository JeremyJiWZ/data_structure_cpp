#include <iostream>
#include <stdio.h>
using namespace std;
int N1,N2;
long a[1000000],b[1000000],result[2000000];
void merge(long a[],long b[]);
int main (){
    cin>>N1;
    for(int i=0;i<N1;i++)
        scanf("%ld",&a[i]);
    cin>>N2;
    for(int i=0;i<N2;i++)
        scanf("%ld",&b[i]);
    merge(a,b);
	if((N1+N2)%2==0){
		int median = (N1+N2)/2-1;
		cout<<result[median]<<endl;
	}
	else{
		int median = (N1+N2)/2;
    	cout<<result[median]<<endl;
	}
    
    return 0;
}
void merge(long a[],long b[]){
    int i=0,j=0,k=0;
    for(;i<N1&&j<N2;){
        if(a[i]<=b[j])
            result[k++]=a[i++];
        else
            result[k++]=b[j++];
    }
    while(i<N1)
        result[k++]=a[i++];
    while(j<N2)
        result[k++]=b[j++];
}
