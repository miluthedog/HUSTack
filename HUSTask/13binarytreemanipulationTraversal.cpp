#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

struct Node{
    int id;
    Node* left;
    Node* right;
};

unordered_map <int,Node*> memo;

Node* root(int u){
    Node* root = new Node();
    root->id = u;
    return root;
}

void left(int u, int v){
    if (memo[u] == nullptr && memo[v] != nullptr){
        Node* mama = memo[v];
        if (mama->left != nullptr) return;
        Node* baby = new Node();
        baby->id = u;
        mama->left = baby;
        memo[u] = baby;
    }
}
void right(int u, int v){
    if (memo[u] == nullptr && memo[v] != nullptr){
        Node* mama = memo[v];
        if (mama->right != nullptr) return;
        Node* baby = new Node();
        baby->id = u;
        mama->right = baby;
        memo[u] = baby;
    }
}
void pre(Node* root) {
    if (root == nullptr) return;

    cout << root->id << " ";
    pre(root->left);
    pre(root->right);
}

void in(Node* root) {
    if (root == nullptr) return;

    in(root->left);
    cout << root->id << " ";
    in(root->right);
}

void post(Node* root) {
    if (root == nullptr) return;

    post(root->left);
    post(root->right);
    cout << root->id << " ";
}
int main(){
    string input = "";
    int u;
    int v;
    Node* head;

    cin >> input;
    if (input == "MakeRoot"){
        cin >> u;
        head = root(u);
        memo[u] = head;
    }

    while (input != "*"){ 
        cin >> input;
        if (input == "AddLeft"){ // v must exist, u must not
            cin >> u; // new id
            cin >> v; // exist id
            left(u, v);
        }
        else if (input == "AddRight"){ // v must exist, u must not
            cin >> u; // new id
            cin >> v; // exist id
            right(u, v);
        }
        else if (input == "PreOrder"){ // root -> left -> right
            pre(head);
            cout << endl;
        }
        else if (input == "InOrder"){ // left (n-1) -> root -> right
            in(head);
            cout << endl;
        }
        else if (input == "PostOrder"){ // left -> right -> root
            post(head);
            cout << endl;
        }
    }
    return 0;
}