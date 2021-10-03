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

Node* takeInput() {
    int d;
    cin >> d;
    if (d == -1)
        return;

    Node* n = new Node(d);
    n->left = takeInput();
    n->right = takeInput();
}

void levelOrderPrint(Node* root) {
    queue<Node*> rem;
    rem.push(root);

    while (!rem.empty()) {
        Node* t = rem.front();
        rem.pop();

        cout << t->data;

        if (t->left != NULL)
            rem.push(t->left);
        if (t->right != NULL)
            rem.push(t->right);
    }
}

Node* levelOrderInp() {
    int d;
    cin >> d;
    Node* root = new Node(d);

    queue<Node*> rem;
    rem.push(root);

    while (!rem.empty()) {
        Node* t = rem.front();
        rem.pop();

        int c1, c2;
        cin >> c1 >> c2;

        if (c1 != -1) {
            t->left = new Node(c1);
            rem.push(t->left);
        }

        if (c2 != -1) {
            t->right = new Node(c2);
            rem.push(t->right);
        }
    }

    return root;
}

void preOrderprintRecur(Node* root) {
    if (root == NULL)
        return;

    cout << root->data;

    preOrderprintRecur(root->left);
    preOrderprintRecur(root->right);
}

void preOrderIter(Node* root) {
    if (root == NULL)
        return;

    stack<Node*> s;
    s.push(root);

    while (!s.empty()) {
        Node* t = s.top();
        s.pop();
        cout << t->data;

        if (t->right != NULL)
            s.push(t->right);
        if (t->left != NULL)
            s.push(t->left);
    }
}

void postOrderRecur(Node* root) {
    if (root == NULL)
        return;
    postOrderRecur(root->left);
    postOrderRecur(root->right);
    cout << root->data;
}

void postOrderIter(Node* root) {
    if (root == NULL)
        return;

    stack<Node*> s;
    stack<int> ans;

    s.push(root);

    while (!s.empty()) {
        Node* curr = s.top();
        s.pop();
        ans.push(curr->data);

        if (curr->left)
            s.push(curr->left);
        if (curr->right)
            s.push(curr->right);
    }

    while (!s.empty()) {
        cout << s.top();
        s.pop();
    }
}

void inOrderRecur(Node* root) {
    if (root == NULL)
        return;

    inOrderRecur(root->left);
    cout << root << "\n";
    inOrderRecur(root->right);
}

void inOrderIter(Node* root) {
    if (root == NULL)
        return;

    stack<Node*> s;
    stack<int> ans;

    while (!s.empty() or root != NULL) {
        if (root != NULL) {
            s.push(root);
            root = root->left;
        } else {
            root = s.top();
            s.pop();
            cout << root->data;
            root = root->right;
        }
    }
}

int height(Node* root) {
    if (root == nullptr)
        return 0;

    return 1 + max(height(root->left), height(root->right));
}

int diameter(Node* root) {
    if (root == nullptr)
        return;

    int d1 = height(root->left) + height(root->right);
    int d2 = diameter(root->left);
    int d3 = diameter(root->right);

    return max(d1, max(d2, d3));
}

class HDpair {
   public:
    int height;
    int diameter;
};

HDpair optDiamter(Node* root) {
    HDpair p;

    if (root == NULL) {
        p.diameter = 0;
        p.height = 0;
        return p;
    }

    HDpair left = optDiamter(root->left);
    HDpair right = optDiamter(root->right);

    p.height = max(left.height , right.height) + 1;

    int d1 = left.height + right.height;
    int d2 = left.diameter ;
    int d3 = right.diameter;

    p.diameter = max(d1, max(d2, d3));

    return p;
}

int height_opt(Node* root){
    HDpair ans = optDiamter(root);

    return ans.diameter;
}




int main() {
}