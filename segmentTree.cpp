/* a min segment tree template*/
#include <stdio.h>
#include <iostream>
using namespace std;
const int maxind=256;
int segTree[maxind*4+10];
int data[maxind];

/*build segment tree,
 node is the root,
 l and r are the range of this node*/
void buildTree(int node,int l,int r){
   if (l==r) {
      segTree[node]=data[l];
   }
   else{
      int mid =(l+r)>>1;
      buildTree(2*node, l, mid);
      buildTree(2*node+1, mid+1, r);
      if (segTree[2*node]<=segTree[2*node+1]) segTree[node]=segTree[2*node];
      else segTree[node]=segTree[2*node+1];
   }
}

/*node is the current query node,
 begin and end is the range of this node,
 left and right is the query range we need to find*/
int query(int node,int begin,int end,int left,int right){
   int q1,q2;
   if (begin>=left&&end<=right) {
      return segTree[node];
   }
   if (left>=end||right<=begin) {
      return -1;
   }
   int mid=(begin+end)>>1;
   q1=query(2*node, begin, mid, left, right);
   q2=query(2*node+1, mid+1, end, left, right);
   if(q1==-1)return q2;
   if(q2==-1)return q1;
   if(q1<=q2)return q1;
   return  q2;
}

/*update one node,
 begin and end are the range of this node,
 data[index] is the data we need to updagte,
 and add is the update number*/
void update(int node,int begin,int end,int index,int add){
   if (begin==end){
      segTree[node]+=add;
      return;
   }
   int mid=(begin+end)>>1;
   if (index<=mid)
      update(2*node, begin, mid, index, add);
   else
      update(2*node+1, mid+1, end, index, add);
   segTree[node]=min(segTree[2*node],segTree[2*node+1]);
}


int main(){
   
}