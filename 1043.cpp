#include <iostream>
using namespace std;
int node[1000];
int N;
typedef Node* Tree;
struct Node{
	int key;
	Tree leftChild;
	Tree rightChild;
};
Tree buildBST(int index, int& length){
	Tree T=new Node;
	T->key=node[index];


}
int main(){
	
	return 0;
}
