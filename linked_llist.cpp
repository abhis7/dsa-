/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;

class node {
    public:
    int data ; 
    node* next ;
    
    //constructor 
    node (int data ){
        this -> data = data ;
        this -> next = NULL ;
    }
    
    //desturctor
    ~node(){
        int value = this->data ; 
        //memory free
        if(this->next !=NULL){
            delete next ;
            this->next = NULL;
        }
        
        cout<<"memory is free for node with data "<<value<<endl;
    }
};

void insertAtHead(node* &head , int d ){
    node* temp = new node(d);
    temp ->next = head;
    head = temp ; 
}

void insertAtTail(node* &tail , int d){
    node*temp = new node(d);
    tail ->next = temp ;
    tail=tail->next;
}

void insertAtPosition(node* &tail , node* &head ,int position , int d){
    
    if(position == 1 ){
        insertAtHead(head, d );
        return ;
    }
    
    // if(len == position-1){
    //     insertAtTail(tail, d);
    //     return;
    // }

    node*temp = head ;
    int cnt =1;
    while(cnt<position-1){
        temp = temp->next;
        cnt++;
    }
    
    
    //inserting at last position (tail)
    if(temp->next == NULL){
        insertAtTail(tail, d);
        return ;
    }
    
    
    node* nodeToInsert = new node(d);
    nodeToInsert ->next = temp->next;
    temp->next = nodeToInsert;
}

void print (node* &head ){
    node* temp = head ;
    while(temp != NULL){
        cout<<temp->data<<" " ; 
        temp= temp->next;
    }
    cout<<endl;
}

void deleteNode(int position , node* &head){
    //deleting first or start node 
    
    if(position == 1){
        node* temp = head ;
        head = head->next ; 
        
        
        //memory free
        temp->next = NULL;
        delete temp ; 
        
    }
    
    else{
        
        node* curr = head ;
        node* prev = NULL ; 
        
        int cnt = 1 ; 
        
        while(cnt<=position){
            // delting any postion without head
            prev = curr  ; 
            curr= curr->next ; 
            cnt++  ; 
        }
        
        prev->next = curr->next ;
        curr->next=NULL;
        delete curr ;
    }
}

int main()
{
    //created a new node 
    node* node1 = new node(10); // Providing data value 42
    cout << node1->data << endl;
    cout << node1->next << endl;
    
    //head pointed to node1 
    node* head = node1 ;
    insertAtHead(head , 12);
    insertAtHead(head , 16);
    
    node* tail = node1;
    insertAtTail(tail, 20);
    insertAtTail(tail, 25);
    insertAtPosition(tail ,head, 3,33);
    
    deleteNode(2, head);

    
    print(head);
    

    delete node1; // Don't forget to free the memory allocated for the node

    return 0;
}





