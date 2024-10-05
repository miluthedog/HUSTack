#include <bits/stdc++.h>
using namespace std;

struct Node{
    int num;
    Node* next;
};

Node* addfirst(Node* head,int value){ //take head pointer, return new head pointer
    Node* new_node = new Node();
    new_node->num = value;
    new_node->next = head;
    head = new_node;
    return head;
}

void result(Node* head){ // print result
    Node* temp = head;
    while (temp != nullptr){
        cout << temp->num;
        temp = temp->next;
    }
}

int main(){
    int n;
    cin >> n;    
    int arr[n];
    for(int i=0 ; i<n ; i++){
        cin >> arr[i];
    }

    Node* head;
    for (int i=n-1 ; i>=0 ; i--){
        head=addfirst(head,arr[i]); // head is pointer
    }
    result(head);

}