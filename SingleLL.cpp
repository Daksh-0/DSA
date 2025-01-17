#include <iostream> 
using namespace std; 

//node implementation 
class Node {   
	public:
	int data;
	Node* next;
    
	//Constructor for pointing to new node 
	Node(int data){
		this-> data = data;
		this-> next = NULL;
	}
	
	//Destructor
	~Node(){
		int value= this->data;
		// To free up memory allocated 
		if(this->next!=NULL){
			delete next;
			this->next=NULL;
		}
		cout<<"memory is free for node with value"<<value<<endl;
	}
};


/*Insetion at the head of the linked list 
  simply create a new node and then point its next pointer
  to head and make the new node head 
  */  
void insertAtHead(Node *&head, int d){
	Node* temp = new Node(d);//created new node
	temp->next = head ;// pointed the next to head 
	head= temp;// made the new node as head 
}


// Insert at tail node
void insertAtTail(Node* &tail,int d){
	//create new node
    Node *temp= new Node(d);
	tail->next=temp;
	tail = tail->next;
}


//Insert at given location 
void insertAtPosition(Node* &head, int position, int d){
	Node *temp= head;
	int c=1;
    
	if (position==1){     // if the position is 1
		insertAtHead(head,d);
		return; 
	}
	while(c< position -1){   // taking temp to the position 
		temp= temp->next;
		c++;
	}
	if(temp->next== NULL){    // if the position is in the end of the LL
		insertAtTail(head,d);
		return;
	}

	Node *Nodetoinsert = new Node(d); // creating new node
	Nodetoinsert->next= temp->next;  // point the next of node to the next of temp
	temp->next= Nodetoinsert;   // point the next of temp to node to break the connection 

}


// Deleting a node in linked list 
void deleteNode(Node* &head, int position){
	// first node deletion
	if(position==1){
		Node *temp=head;
		head= head->next;
		temp->next=NULL;
		delete temp;
	}
	//deletion of rest other nodes
	else{
		Node* curr= head;
		Node* prev= NULL;

		int c=1;
		while(c<position){
			prev=curr;
			curr= curr->next;
			c++;
		}
		prev->next= curr->next;
		curr->next=NULL;
		delete curr;
	}
}

// Printing the linked list 
void printLL(Node* &head){
    Node *temp= head;  //a new node is created pointing to head 

	while(temp!=NULL){
		cout<<temp->data<<" "; //temp ka data access ho raha h 
		temp= temp->next; //temp is pointed to the next insted of the data i.e.head
	}
	cout<<endl;
}


int main(){
	//created a new node
	Node* node1= new Node(10);
    //cout<<node1 ->data<<endl;
    
	//head pointed to first node 
	Node *head= node1;
	Node *tail= node1;
    printLL(head);

	insertAtHead(head,15);
	printLL(head); 

	insertAtTail(tail,7);
	printLL(head);

	insertAtTail(tail,5);
	printLL(head);

	deleteNode(head,2);
	printLL(head);
     
	return 0;
}