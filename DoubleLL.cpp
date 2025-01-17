#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *prev;
    Node *next;

    Node(int d){
        this->data= d;
        this->prev=NULL;
        this->next=NULL;
    }
};

// Printing elements of the linked list 
void print(Node *head){
    Node *temp= head;

    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp= temp->next;
    }
    cout<<endl;
}

// Length of the Linked list 
int getLength(Node* head){
    Node *temp= head;
    int c=0;
    while(temp!=NULL){
        c++;
        temp= temp->next;
    }
    return c;
}


// Insert at head 
void insertAtHead(Node* &head, int d){
    Node *temp= new Node(d);
    temp->next= head;
    head->prev= temp;
    head= temp;
}


// Insert at tail
void insertAtTail(Node* &tail, int d){
    Node *temp= new Node(d);
    tail->next= temp;
    temp->prev= tail;
    tail= temp; 
}


// Insert at position
void insertAtPosition(Node* head, int Position, int d){
    
    if(Position==1){
        insertAtHead(head,d);
        return;
    }

    Node *temp= head;
    int c=1;
    while(c<Position){
        temp= temp->next;
        c++;
    }

    if(temp->next== NULL){
        insertAtTail(head,d);
        return;
    }

    Node *nodeToInsert= new Node(d);
    nodeToInsert->next= temp->next;
    temp->next->prev= nodeToInsert;
    temp->next=nodeToInsert;
    nodeToInsert->prev=temp;
}


//Deletion of a node
void deleteNode(Node *head, int Position){
    if(Position== 1){
        Node* temp= head;
        temp->next->prev =NULL;
        head= temp->next;
        temp->next = NULL;
        delete temp;
    }

    else{
        Node *curr= head;
        Node *prev= NULL;

        int c=1;
        while(c<Position){
            prev= curr;
            curr= curr->next;
            c++;
        }
        curr->prev= NULL;
        prev->next= curr->next;
        curr->next= NULL;
        delete curr;
    }
}

int main(){

    Node *node1= new Node(10);
    Node *head= node1;
    Node *tail= node1;

    print(head);
    cout<< getLength(head)<<endl;

    insertAtTail(tail, 12);
    print(head);

    insertAtHead(head,6);
    insertAtHead(head, 9);
    insertAtTail(tail, 16);
    print(head);

    insertAtPosition(head, 2, 5);
    print(head);
}