#include<iostream>
#include<vector>
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


// THIS IS FOR A SORTED ARRAY
// removing duplicate elements
Node* uniqueSortedLL(Node* head){
    // empty ll
    if(head==NULL){
        return NULL;
    }
    //non empty ll
    Node *curr= head;
    while(curr!=NULL){
        if(curr!=NULL && curr->data==curr->next->data){
            Node* next_n= curr->next->next;
            Node* nodeToDelete= curr->next;
            delete(nodeToDelete);
            curr->next= next_n;
        }
        else{
            curr= curr->next;
        }
    }
    return head;
}

// THIS IS FOR UNSORTED ARRAY
// removing duplicate elements
// Only contains 0,1,2 
Node* uniqueUnsortedLL(Node* head){
    // first sort the Linked list then the same process as above
    int one=0;
    int zero=0;
    int two=0;

    Node* temp= head;
    while(temp!=NULL){
        if(temp->data== 0){
            zero++;
        }
        else if(temp->data==1){
            one++;
        }
        else(temp->data== 2){
            two++;
        }
        temp= temp->next;
    }
    temp=head;
    while(temp!=NULL){

        if(zero!=NULL){
            temp->data=0;
            zero--;
        }
        else if(one!=NULL){
            temp->data=1;
            one--;
        }
        else if(two!=NULL){
            temp->data= 2;
            two--;
        }

    }
    return head;
}

// Program to merge 2 sorted Linked Lists 

// Kar lio baad me abhi man nhi h 


//                          PALLINDROME


bool checkPalindrome(vector<int> arr){
    int n= arr.size();
    int s=0;
    int e= n-1;

    while(s<e){
        if(arr[s]!=arr[e])
            return 0;
        s++;
        e--;
    }
    return 1;

}
bool isPalindrome(Node* head){
    vector<int> arr;
    Node* temp= head;

    while(temp!= NULL){
        arr.push_back(temp->data);
        temp= temp->next;
    }
    return checkPalindrome(arr);
}


//                         MERGE SORT


Node *findMid(Node *head){
    Node *slow= head;
    Node *fast=head->next;

    while(slow!=NULL && fast!=NULL){
        slow=slow->next;
        fast= fast->next->next;
    }
    return slow;
}
Node *merge(Node *left, Node *right){
    if (left==NULL){
        return right;
    }
    if(right==NULL){
        return left;
    }
    Node *ans= new Node(-1);
    Node*temp= ans;

    while(left!=NULL && right!=NULL){
        if(left->data < right->data){
            temp->next= left;
            temp= left;
            left= left->next;
        }
        else{
            temp->next= right;
            temp= right;
            right= right->next;
        }
    }
    while(left!=NULL){
        temp->next= left;
        temp= left;
        left= left->next;
    }
    while(right!= NULL){
        temp->next= right;
        temp= right;
        right= right->next;

    }
    ans= ans->next;
    return ans;
}
Node *mergeSort(Node* head){
    if(head==NULL || head->next==NULL){
        return head;
    }
    Node *mid= findMid(head);

    Node *left= head;
    Node *right= mid->next;
    mid->next= NULL;

    left= mergeSort(left);
    right =mergeSort(right);

    Node* result= merge(left,right);

    return result;

}

int main(){
    cout<<"hello"<<endl;
}