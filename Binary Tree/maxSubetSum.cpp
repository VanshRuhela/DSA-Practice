/*=============================================================================
#  PROBLEM:      Find the largest sum of a subset of nodes in a binary tree, such that if a node
is inluded in the sum then its parents and children must not be included in the subset sum. 
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
 
class Pair{
    public:
    int inc;
    int exc;
};

Pair maxSubsetSum(Node* root){
    Pair p;
    if(root == NULL){
        p.inc = p.exc = 0;
    }

    Pair Left = maxSubsetSum(root->left);
    Pair Right = maxSubsetSum(root->right);

    p.inc = root->data + Left.exc + Right.exc;
    p.exc = max(Left.exc, Left.inc) + max(Right.inc, Right.exc);

    return p;
    
}

int main() {
   return 0;
}