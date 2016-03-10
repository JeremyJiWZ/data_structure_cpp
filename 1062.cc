#include <iostream>
#include <algorithm>
#include <math.h>
#include <queue>
using namespace std;
int N;
int nodes[1005];
bool square[1025];
struct Node{
    int key;
    Node *left,*right;
};
typedef Node *Tree;
int pickRoot(int i, int length){
    int index=i+(length)/2;
    while (1) {
        int l = index-i;
        int r = length-l-1;
        if (r>0&&square[r+1]) {
            break;
        }
        if (l>0&&square[l+1]) {
            break;
        }
        index++;
    }
    
    return index;
}
Tree buildTree(int first,int length){
    Tree T=NULL;
    if (length==0) {
        return T;
    }
    T = new Node;
    if (length==1) {
        T->key=nodes[first];
        return T;
    }
    int root=pickRoot(first, length);
    T->key=nodes[root];
    T->left=buildTree(first,root-first);
    T->right=buildTree(root+1,length-(root-first)-1);
    return T;
}
void levelOrder(Tree T){
    queue<Tree> q;
    Tree tt;
    if (T!=NULL) {
        cout<<T->key;
        if (T->left!=NULL) {
            q.push(T->left);
        }
        if (T->right!=NULL) {
            q.push(T->right);
        }
    }
    while (!q.empty()) {
        tt=q.front();
        q.pop();
        cout<<' '<<tt->key;
        if (tt->left!=NULL) {
            q.push(tt->left);
        }
        if (tt->right!=NULL) {
            q.push(tt->right);
        }
    }
    cout<<endl;
}
int main(){
    int i=0;
    for (i=0; i<1025; i++) {
        square[i]=false;
    }
    i=2;
    square[0]=square[1]=true;
    while (i<=1024) {
        square[i]=1;
        i*=2;
    }
    cin>>N;
    for (int i=0; i<N; i++) {
        cin>>nodes[i];
    }
    sort(nodes, nodes+N);
    Tree T;
    T=buildTree(0, N);
    levelOrder(T);
    return 0;
}