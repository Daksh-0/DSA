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

Node* reverseLL(Node *head){
    // if there is only one or no element then return that 
    if( head == NULL || head->next == NULL){ // one or zero
        return head;
    }

    Node* prev= NULL; // prev is pointing to Null so that first element can become last by pointing to Null
    Node* curr= head;  //curr is the head element starting from that 
    Node* forward= NULL; //It is made so that before breaking the existing connection to next node we can point it to that value

    while(curr!=NULL){
        forward= curr->next; // in first iteration 2nd element is pointed to forward
        curr->next= prev; //pointing first element to null in first case
        prev=curr; //curr is made to be prev
        curr= forward; // 2nd is made to be the curr
    }  
    return prev;
/* Now this will basically point every element to the prev element the head will be pointing the 
last element and the first element initially will be pointing to NULL which makes it the tail*/
}



//                               REVERSE IN K ORDER 



// Going to do it in a recursive manner 
Node* kReverse(Node* head, int k ){
    // base case
    if(head==NULL){
        return NULL;
    }
    // first step
    Node *next= NULL;
    Node *curr= head;
    Node*prev= NULL;
    int c=0;

    while(curr!=NULL && c<k){
        next= curr->next;// Dobara dekhio video 51 samajh nhi aaya yaha hua kya ):
        curr->next= prev;
        prev= curr;
        curr= next;
    }
    // by recursion the following iterations will take place 
    if(next!=NULL){
        head->next= kReverse(next, k);
    }

    // return head of reversed list 
    return prev;
}




int main(){
    Node* node1= new Node(4);
    Node* head= node1;
    Node* a= reverseLL(head);
    cout<<a;
}