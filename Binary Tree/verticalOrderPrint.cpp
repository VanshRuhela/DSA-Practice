/*=============================================================================
#  PROBLEM:          Given a binary tree and print it in vertical order
=============================================================================*/
#include <bits/stdc++.h> 
using namespace std;
class Node {
   public:
    int data;
    Node* left;
    Node* right;
    Node(int d) {
        data = d;
        left = NULL;
        right = NULL;
    }
};


void traverse(Node* root, map<int, vector<int>> &m, int dist){
    if(root == NULL){
        return;
    }

    m[dist].push_back(root->data);
    traverse(root->left, m, dist-1);
    traverse(root->right, m, dist+1);
}


void verticalOrderPrint(Node* root){

    map<int, vector<int>> m;

    int d = 0;

    traverse(root, m, 0);

    for(auto p: m){
        int key = p.first;
        vector<int> vl = p.second;

            for(auto e : vl){
                cout << e <<" ";
            }
            cout<< "\n";
    }
} 
 
int main() {
   return 0;
}