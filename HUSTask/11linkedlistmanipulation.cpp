#include <bits/stdc++.h>
using namespace std;

struct Node{
    int num;
    Node* next;
};

bool checkint(Node* head, int check){ //checked
    Node* temp = head;
    while (temp != nullptr){
        if (temp->num == check)
            return true;
        temp = temp->next;
    }
    return false;
}

Node* addfirst(Node* head,int value){ //take head pointer, return new head pointer //checked
    Node* new_node = new Node();
    new_node->num = value;
    new_node->next = head;
    head = new_node;
    return head;
}

Node* addlast(Node* head,int value){ //checked
    Node* new_node = new Node();
    new_node->num = value;
    new_node->next = nullptr;
    if (head == nullptr) { //head ini alway be null
        return new_node;
    }
    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = new_node;
    return head;
}

Node* remove(Node* head,int value){ // checked
    Node* temp = head;
    if (temp->num==value){
        return temp->next;
    }
    while (temp->next->num != value){
        temp = temp->next;
    }

    temp->next = temp->next->next;
    return head;
}

Node* addafter(Node* head,int value1,int value2){ //find value2, add value1 after 
    Node* temp = head;
    while (temp->num != value2){
        temp = temp->next;
    }

    Node* new_node = new Node();
    new_node->next=temp->next;
    temp->next = new_node;
    new_node->num=value1;
    return head;
}

Node* addbefore(Node* head,int value1,int value2){ //find value2, add value1 before 
    Node* temp = head;
    while (temp->next->num != value2){
        temp = temp->next;
    }

    Node* new_node = new Node();
    new_node->next=temp->next;
    temp->next = new_node;
    new_node->num=value1;
    return head;
}

Node* reversee(Node* head){ //checked
    Node* temp = head;
    Node* next;
    Node* pre;
    next = nullptr;
    pre = nullptr;

    while (temp != nullptr){
        next = temp->next;
        temp->next = pre;
        pre = temp;
        temp = next;
    }
    head = pre;
    return head;
}

void result(Node* head){ // print result
    Node* temp = head;
    while (temp != nullptr){
        cout << temp->num <<" ";
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

    Node* head=nullptr;
    for(int i=0 ; i<n ; i++){
        head=addlast(head,arr[i]);
    }

    string sinput="";
    int iinput;
    int iiinput;
    while(sinput != "#"){
        cin >> sinput;
        if (sinput == "#"){
            result(head);
            break;
        } 
        else if (sinput=="reverse"){
            head=reversee(head);
        }
        else{
            cin >> iinput;
            if (sinput=="addfirst"){ // check iinput existance, if no then excute
                if (checkint(head,iinput)==false)
                    head=addfirst(head,iinput);
            }
            else if (sinput=="addlast"){ // check iinput existance, if no then excute
                if (checkint(head,iinput)==false)
                    head=addlast(head,iinput);
            }
            else if (sinput=="remove"){ // check iinput existance, if yes then excute
                if (checkint(head,iinput)==true)
                    head=remove(head,iinput);
            }
            else{
                cin >> iiinput;
                if (sinput=="addafter"){ // check existance, if iinput no-iiinput yes then excute
                    if (checkint(head,iinput)==false && checkint(head,iiinput)==true)
                        head=addafter(head,iinput,iiinput);
                }
                else if (sinput=="addbefore"){ // check existance, if iinput no-iiinput yes then excute
                    if (checkint(head,iinput)==false && checkint(head,iiinput)==true)
                        head=addbefore(head,iinput,iiinput);
                }
            }
        }
        sinput = "";
    }
    return 0;
}