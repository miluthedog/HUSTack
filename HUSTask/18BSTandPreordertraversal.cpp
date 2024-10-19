#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

// binary search tree definition: right must be larger than left

struct Node{
    int id;
    Node* left;
    Node* right;
    Node(int key) : id(key), left(nullptr), right(nullptr) {}
};

Node* insert(Node* root, int key) {
    if (root == nullptr) return new Node(key);
    if (key < root->id) root->left = insert(root->left, key);
    else if (key > root->id) root->right = insert(root->right, key);
    return root;
}

void pre(Node* root) {
    if (root == nullptr) return;

    cout << root->id << " ";
    pre(root->left);
    pre(root->right);
}

int main(){
    string input = "";
    int key;

    cin >> input >> key;
    Node* head = new Node(key);

    while (input != "#"){
        cin >> input;
        if (input == "#") break;
        cin >> key;
        insert(head, key);
    }
    pre(head);
    return 0;
}