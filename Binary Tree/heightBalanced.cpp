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

/*=============================================================================
#  PROBLEM:      Height Balanced or not
                 left subtree and right subtree both should be balanced 
                 | H1 - H2 | <= 1 property of height balanced tree
=============================================================================*/
// we need the height of both sides
// along with it we will also return whether its balanced or not

//height, balanced or not
pair<int, bool> isHeightBalanced(Node* root) {
    pair<int, bool> p, L, R;

    if(root == NULL){
        p.first = 0; // height
        p.second = true; // balanced
        return p;
    }

    L = isHeightBalanced(root->left);
    R = isHeightBalanced(root->right);

    int height = 1 + max(L.first, R.first);

    if(abs (L.first - R.first) <= 1 and L.second and R.second){
        return make_pair(height, true);
    }

    return make_pair(height, false);
}