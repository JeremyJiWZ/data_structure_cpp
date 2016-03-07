#include "stdio.h"
#include <iostream>
#include <stack>
using namespace std;
const int length=100005;
struct BinaryIndexTree{
   int tree[length];
   void add(int num,int k){
      while(k<length){
         tree[k]+=num;
         k+=k&-k;
      }
   }
   int read(int k){
      int sum=0;
      while(k>0){
         sum+=tree[k];
         k-=k&-k;
      }
      return sum;
   }
};
BinaryIndexTree bit;
int getmid(int size){
   int index=(size+1)/2;
   int left=1,right=length,mid=(left+right)/2;
   while (left<right) {
      if (bit.read(mid)<index)
         left=mid+1;
      else
         right=mid;
      mid=(left+right)/2;
   }
   return mid;
}
int main(){
   int N;
   int num;
   stack<int> S;
   cin>>N;
   for (int i=0; i<N; i++) {
      char cmd[20];
      scanf("%s",cmd);
      switch (cmd[1]) {
         case 'o':
            if (S.size()<1) {
               printf("Invalid\n");
            }
            else{
               num=S.top();
               S.pop();
               bit.add(-1, num);
               printf("%d\n",num);
            }
            break;
         case 'e':
            if (S.size()<1) {
               printf("Invalid\n");
            }
            else{
               printf("%d\n",getmid(S.size()));
            }
            break;
         case 'u':
            scanf("%d",&num);
            S.push(num);
            bit.add(1, num);
            break;
         default:
            break;
      }
   }
   
   
}