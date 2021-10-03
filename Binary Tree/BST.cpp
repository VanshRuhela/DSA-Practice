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

Node* insert(Node* root, int key){
    if(root == NULL){
        return new Node(key);
    }

    if(key < root->data)
        insert(root->left, key);
    else
        insert(root->right, key);
}

int findClosest(Node* root, int target){
    int closest;
    int diff = INT_MAX;
    Node* temp = root;

    while(temp!= NULL){
        int curr_diff = abs(temp->data - target);

        if(curr_diff == 0)
            return temp->data;
        
        if(curr_diff < diff){
            diff = curr_diff;
            closest = temp->data;
        }

        // right or left
        if(temp->data < target)
            temp = temp->right;
        
        else 
            temp = temp->left;
    }

    return closest;
}

