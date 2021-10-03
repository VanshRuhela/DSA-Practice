// // Algo
// 1) Perform the normal BST insertion.
// 2) The current node must be one of the ancestors of the newly inserted node. Update the height of the current node.
// 3) Get the balance factor (left subtree height – right subtree height) of the current node.
// 4) If balance factor is greater than 1, then the current node is unbalanced && we are either in Left Left case or left Right case.
// To check whether it is left left case or not, compare the newly inserted key with the key in left subtree root.
// 5) If balance factor is less than -1, then the current node is unbalanced && we are either in Right Right case or Right-Left case.
// To check whether it is Right Right case or not, compare the newly inserted key with the key in right subtree root.

#include <bits/stdc++.h>
using namespace std;

class Node {
   public:
    int key;
    Node* left;
    Node* right;
    int height;
};

int height(Node* n) {
    if (n == NULL)
        return 0;
    return n->height;
}

Node* newNode(int key) {
    Node* node = new Node();
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;  // new node is added at leaf

    return (node);
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

// to get BF
int getBalance(Node* root) {
    if (root == NULL)
        return 0;
    return height(root->left) - height(root->right);
}

// Right rotate
/* 

T1, T2 && T3 are subtrees of the tree rooted with y (on the left side) or x (on the right side)           
     y                               x
    / \     Right Rotation          /  \
   x   T3   - - - - - - - >        T1   y 
  / \       < - - - - - - -            / \
 T1  T2     Left Rotation            T2  T3

Keys in both of the above trees follow the 
following order 
 keys(T1) < key(x) < keys(T2) < key(y) < keys(T3)
So BST property is not violated anywhere.
*/

Node* rightRotate(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;

    // rotate
    x->right = y;
    y->left = T2;

    // update heights
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    // return the new root
    return x;
}

// left rotate
Node* leftRotate(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;

    // rotate
    y->left = x;
    x->right = T2;

    // update height
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    // return new root
    return y;
}

Node* insert(Node* node, int key) {
    // normal bst insert

    if (node == NULL)
        return (newNode(key));
    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else  // no equal keys allowed
        return node;

    // update height of the ancestor node
    node->height = 1 + max(height(node->left), height(node->right));

    // get the balance factor for imbalance / checking if this node become unbabalnced
    int balance = getBalance(node);

    // if node is unbalanced then 4 cases
    // if bf > 1 -> LL case or LR case {to check for LL compare newly inserted key to the left subtree root}
    // if bf <-1 -> RR case or RL case {to check for RR compare newly inserted key to the right subtree root}

    // 1. LL imbalace
    if (balance > 1 && key < node->left->key) {
        return rightRotate(node);
    }

    // 2. LR imbalance
    if (balance > 1 && key > node->left->key) {
        // 2 step rotation
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // 3. RR imbalance
    if (balance < -1 && key > node->right->key) {
        return leftRotate(node);
    }

    // 4. RL imbalance
    if (balance < -1 && key < node->right->key) {
        // 2 step rotation
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    // returning the unchanged pointer (node)
    return node;
}

Node* minValNode(Node* root) {
    Node* curr = root;
    while (curr->left != NULL) {
        curr = curr->left;
    }

    return curr;
}

Node* deleteNode(Node* root, int key) {
    // std bst delete
    if (root == NULL)
        return root;
    // If the key to be deleted is smaller than the root's key, then it lies in left subtree
    if (key < root->key)
        root->left = deleteNode(root->left, key);
    else if (key > root->key)
        root->right = deleteNode(root->right, key);
    else {
        // with only one child or no child
        if ((root->left == NULL) || (root->right == NULL)) {
            Node* temp = root->left ? root->left : root->right;

            // no child
            if (temp == NULL) {
                temp = root;
                root = NULL;
            } else  // one child case
            {
                *root = *temp;
            }

            free(temp);
        } else {
            // node with 2 childern
            Node* temp = minValNode(root->right);
            root->key = temp->key;
            root->right = deleteNode(root->right, key);
        }
    }

        // if the tree had only one node
        if (root == NULL)
            return root;

        // 2) Update height of the curr node
        root->height = 1 + max(height(root->right), height(root->left));

        int balance = getBalance(root);

        if (balance > 1 && getBalance(root->left) >= 0)
            return rightRotate(root);

        // Left Right Case
        if (balance > 1 && getBalance(root->left) < 0) {
            root->left = leftRotate(root->left);
            return rightRotate(root);
        }

        // Right Right Case
        if (balance < -1 && getBalance(root->right) <= 0)
            return leftRotate(root);

        // Right Left Case
        if (balance < -1 && getBalance(root->right) > 0) {
            root->right = rightRotate(root->right);
            return leftRotate(root);
        }

    return root;

}

void preorder(Node* root) {
    if (root != NULL) {
        cout << root->key << "  ";
        preorder(root->left);
        preorder(root->right);
    }
}

int main() {
    Node* root = NULL;

    for (int i = 0; i < 10; i++) {
        root = insert(root, 10 * rand());
        preorder(root);
        cout << "\n";
    }

    return 0;

    // root = insert(root, 10);
    //  preorder(root);
    // root = insert(root, 20);
    //  preorder(root);
    // root = insert(root, 30);
    //  preorder(root);
    // root = insert(root, 40);
    //  preorder(root);
    // root = insert(root, 50);
    //  preorder(root);
    // root = insert(root, 25);

    // /* The constructed AVL Tree would be
    //         30
    //         / \
    //         20 40
    //         / \ \
    //         10 25 50
    // */

    // cout << "Preorder of AVL tree :\n";
    // preorder(root);

    // cout << "Preorder 2\n";
    // root = insert(root, 14);
    // preorder(root);
}
