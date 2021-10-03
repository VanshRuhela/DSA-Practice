/*=============================================================================
#  PROBLEM:          Find the inorder successor of a given target node.
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

// look for the right subtree -> if you go to ext left = ans(i.e is the smallest in right subtree)
// if no right subtree -> everytime I see a node a node whose data is greater then target then i will update my suceesor

Node* inorderSuccor(Node* root, Node* target){
    // if right subtree
    if(target->right != NULL){
        Node* temp = target->right;
        while(temp->left!= NULL){
            temp = temp->left;
        }
        return temp;
    }

    // if no right subtree
    // find root to target path
    Node* temp = root;
    Node* succ = NULL;

    while(temp != NULL){

        if(temp->data > target->data){
            succ = temp;
            temp = temp->left;
        }

        if(temp->data < target->data){
            temp = temp->right;
        }
        else{
            break;
        }
    }

    return succ;
}

 
int main() {
   return 0;
}