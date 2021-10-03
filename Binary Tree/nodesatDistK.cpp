/*=============================================================================
#  PROBLEM:         Given a target node,  Find all Nodes at distance K from the given target node, where K is an interger
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

// 1. search kr target ko kaise? level order? 
// target search krke, level order laga target ke neeche for dist 2 
//
//

void printAtLevelk(Node* root, int k){
    if(root==NULL)
        return;
    if(k == 0){
        cout<< root->data<<" ";
    }

    printAtLevelk(root->left, k-1);
    printAtLevelk(root->right, k-1);
}

int printNodesatK(Node* root, Node* target, int k){
    if(root == NULL){
        return -1;
    }

    // reach the target node
    if(root == target){
       printAtLevelk(target, k);
        return 0;
    }

    // check where the target node is present

    int DL = printNodesatK(root->left, target, k);

    if(DL != -1){ // 

        // 2 cases - print cureent node or call on right

        // print the current node
        if(DL + 1 == k){
            cout<< root->data <<" ";
        }
        // print some nodes in the rightsubtree
        else{
            printAtLevelk(root->right, k-2-DL);
        }

        return 1+DL;

    }

    int DR = printNodesatK(root->right, target, k);
    if(DR != -1){
        // 2 cases
        if(DR + 1 == k){
            cout<< root->data <<" ";
        }
        else{
            printAtLevelk(root->left, k-2-DR);
        }

        return 1+DR;
    } 

    return -1;

}



int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right = new Node(3);
    root->right->right = new Node(6);
    root->left->right->left = new Node(7);
    root->left->right->right = new Node(8);
    root->left->right->right->left = new Node(9);
    root->left->right->right->right = new Node(10);

    Node* target = root->left->right;
    int k = 2;
    printNodesatK(root, target, k);

   return 0;
}