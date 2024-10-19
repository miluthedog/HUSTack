#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

struct Node{
    int id;
    vector <Node*> VectorNode;
};

unordered_map <int,Node*> memo;

Node* root(int u){
    Node* root = new Node();
    root->id = u;
    return root;
}
void insert(int u, int v){
    if (memo[u] == nullptr && memo[v] != nullptr){
        Node* mama = memo[v];
        Node* baby = new Node();
        baby->id = u;
        mama->VectorNode.push_back(baby);
        memo[u] = baby;
    }
}
void pre(Node* root) {
    if (root == nullptr) return;
    cout << root->id << " ";
    for (Node* baby : root->VectorNode) {
        pre(baby);
    }
}

void in(Node* root) {
    if (root == nullptr) return;
    int n = root->VectorNode.size();
    for (int i = 0; i < n / 2; i++) {
        in(root->VectorNode[i]);
    }
    cout << root->id << " ";
    for (int i = n / 2; i < n; i++) {
        in(root->VectorNode[i]);
    }
}

void post(Node* root) {
    if (root == nullptr) return;
    for (Node* baby : root->VectorNode) {
        post(baby);
    }
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
        if (input == "Insert"){ // v must exist, u must not
            cin >> u; // new id
            cin >> v; // exist id
            insert(u, v);
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