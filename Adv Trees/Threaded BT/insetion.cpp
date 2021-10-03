#include <bits/stdc++.h>
using namespace std;

struct Node {
    struct Node *left, *right;
    int info;
    bool lthread, rthread;
};

struct Node* insert(struct Node* root, int ikey) {
    Node* ptr = root;  // searching for a node with given val
    Node* par = NULL;  // parent

    while (ptr != NULL) {
        // if key exist return
        if (ikey == (ptr->info)) {
            return root;
        }

        par = ptr;  // update parent

        // l sub tree
        if (ikey < ptr->info) {
            if (par->lthread == false)
                ptr = ptr->left;
            else
                break;
        }

        else {
            if (ptr->right == false)
                ptr = ptr->right;
            else
                break;
        }
    }

    // create a node
    Node* temp = new Node;
    temp->info = ikey;
    temp->lthread = true;
    temp->rthread = true;

    if (par == NULL) {
        root = temp;
        temp->left = NULL;
        temp->right = NULL;
    }
    else if (ikey < (par->info)) {
        temp->left = par->left;
        temp->right = par;
        par->lthread = false;
        par->left = temp;
    }
    else {
        temp->left = par;
        temp->right = par->right;
        par->rthread = false;
        par -> right = temp;
    }
    
    return root;
    
}

int main() {
    return 0;
}