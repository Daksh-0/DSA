#include<iostream>
#include<map>
using namespace std;

class Node{
    public:
    int data;
    Node *next;

    Node(int d){
        this->data= d;
        this->next= NULL;
    }

    ~Node(){
        int value= this->data;
        if(this->next!= NULL){
            delete next;
            this->next= NULL;
        }
        cout<<"The node deleted with value"<<value<<endl; 
    }
};



//                                       WILL DO IT LATER 





bool isCircularLL(Node* head){
    // is empty 
    if(head==NULL){
        return false;
    }

    Node *temp= head->next;
    while(temp!=NULL && temp!=head){
        temp= temp->next;
    }
    if(temp==head){
        return true;
    }
    return false;
} 


bool isLoop(Node* head){
    if (head==NULL){
        return false;
    }
    map<Node* , bool> visited;
    Node*temp = head;

    while(temp!=NULL){
        //cycle is present
        if(visited[temp]==true){
            cout<< "Present on element"<<temp->data<<endl;
            return true;
        }

        visited[temp]=true;
        temp=temp->next;
    }
    return false;
}

int main(){
    Node* node1= new Node(3);
    Node *head= node1;
    Node *tail= node1;

    tail->next = head->next;

    if(isLoop(head)) {
        cout<<"Loop is present"<<endl;
    }
    else{
        cout<<"No Loop"<<endl;
    }

}


