/*=============================================================================
#  PROBLEM:          Given BST, convert it to a sorted linked list, right pointer should behave as next pointer for the linked list.
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
// BST to linked list
class LinkedList {
   public:
    Node* head;
    Node* tail;
};

LinkedList tree2LL(Node* root) {
    LinkedList l;
    if (root == NULL) {
        l.head = l.tail = NULL;
        return l;
    }

    // 4 cases
    if (root->left == NULL and root->right == NULL) {
        l.head = l.tail = root;
    }

    else if (root->left != NULL and root->right == NULL) {
        LinkedList leftLL = tree2LL(root->left);
        leftLL.tail->right = root;

        l.head = leftLL.head;
        l.tail = root;
    }

    else if (root->left == NULL and root->right != NULL) {
        LinkedList rightLL = tree2LL(root->right);
        root->right = rightLL.head;

        l.head = root;
        l.tail = rightLL.tail;
    } else {
        LinkedList leftLL = tree2LL(root->left);
        LinkedList rightLL = tree2LL(root->right);
        leftLL.tail->right = root;
        root->right = rightLL.head;

        l.head = leftLL.head;
        l.tail = rightLL.tail;
    }

    return l;
}

int main() {
    return 0;
}