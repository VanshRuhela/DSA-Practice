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
//////////////////////////////////LEFT VIEW
// queue solution
void leftView(Node* root) {
    queue<Node*> q;
    if (root != NULL)
        q.push(root);

    while (!q.empty()) {
        int n = q.size();  // elements in the current level

        for (int i = 1; i <= n; i++) {
            Node* temp = q.front();
            q.pop();

            if (i == 1) {
                cout << temp->data << " ";
            }

            if (temp->left) {
                q.push(temp->left);
            }

            if (temp->right)
                q.push(temp->right);
        }
    }
}

void leftViewHelper(Node* root, int level, int* max_level) {
    if (root == NULL) {
        return;
    }
    if (*max_level < level) {
        cout << root->data << " ";
        *max_level = level;
    }

    leftViewHelper(root->left, level + 1, max_level);
    leftViewHelper(root->right, level + 1, max_level);
}

void leftViewRecursive(Node* root) {
    int max_level = 0;
    leftViewHelper(root, 1, &max_level);
}

///////////////////// RIGHT VIEW

void rightViewHelper(Node* root, int level, int* max_level) {
    if (root == NULL)
        return;

    if (*max_level < level) {
        cout << root->data << " ";
        *max_level = level;
    }

    rightViewHelper(root->right, level + 1, max_level);
    rightViewHelper(root->left, level + 1, max_level);
}

void rightViewRecursive(Node* root) {
    int max_level = 0;
    rightViewHelper(root, 1, &max_level);
}

void rightViewIter(Node* root) {  // using queue
    queue<Node*> q;
    q.push(root);

    while (!q.empty()){
        int n = q.size();
        for(int i =1; i<=n; i++){
            Node* curr = q.front();
            q.pop();

            if(i==1){
                cout<< curr->data <<" ";

            }

            if(curr->right){
                q.push(curr->right);
            }
            if(curr->left){
                q.push(curr->left);
            }
        }
    }
}

///////////////// TOP VIEW

void printTop(Node* root, int dist, int level , map<int, pair<int,int>>& map){
    //base
    if(root == NULL)
        return;
    
    if(map.find(dist) == map.end() || level < map[dist].second){
        map[dist] = {root->data, level};
    }

    printTop(root, dist-1, level+1, map);
    printTop(root, dist+1, level+1, map);

}


void topViewRecursive(Node* root){
    
    map<int, pair<int, int>> m; // key -> horizontal dist(from the root) , value -> pair(Node's value, its level)
    
    printTop(root, 0, 0, m); // pre order traversal and fill the map

    for( auto it : m){
        cout << it.second.first<<" ";
    }
}

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right = new Node(3);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->right->left->right = new Node(8);

    cout << "left view \n";
     leftViewRecursive(root);
     cout<<endl;
     leftView(root);

    cout <<"\n\n\nright view\n";
     rightViewIter(root);
     cout << endl;
     rightViewRecursive(root);

    cout <<"\n\n\n top view\n";
     topViewRecursive(root);
}