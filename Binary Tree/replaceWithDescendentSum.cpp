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

int replace(Node* root){

    // base
    if(root == NULL)
        return 0;
    if(root ->left == NULL and root ->right == NULL)
        return root->data;

    int temp = root->data;
    root-> data = (replace(root -> left) + replace(root -> right));

    return temp + root->data;
}