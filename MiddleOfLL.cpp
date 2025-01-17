#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *next;

    Node(int d){
        this->data= d;
        this->next= NULL;
    }
};


int getLength(Node* head){
    int len=0;
    while(head!=NULL){
        len++;
        head=head->next;
    }
    return len;
}

Node* findMiddle(Node* head){
    int ans= getLength(head)/2;

    Node* temp= head;
    int c=0;
    while(c<ans){
        temp=temp->next;
        c++;
    }
    return temp;
}