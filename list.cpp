#include<bits/stdc++.h>

using namespace std;

struct Node{
    int val;
    Node* next;
    Node(int x){
        val = x;
        next = NULL;
    }
};

void append(int v,Node* head){
    Node* temp = new Node(v);
    Node* curr = head;
    while(curr->next!=NULL){
        curr = curr->next;
    }
    curr->next = temp;
    return;
}

int main(){ 
    Node* head = new Node(1);
    append(2,head);
    append(3,head);
    append(4,head);
    Node* curr = head;
    while(curr!=NULL){
        cout<<curr->val<<" ";
        curr = curr->next;
    }
    cout<<(0x0F & 0xED)<<1;
    cout<<hex<<(0x0F & 0xED)<<1;
    // cout<<endl;
    system("pause");
    return 0;
}