#include <iostream>

using namespace std;

class node{
    public:
        int data ;
        node* prev ;
        node* next ;
        
        //constructor 
        node(int d){
            this->data = d;
            this->prev= NULL ; 
            this->next=NULL ;
        }
};

void print (node* head){
    node* temp =head ;
    
    while(temp != NULL){
        cout<<temp -> data<<" " ;
        temp = temp->next ;
    }
} 

void insertAtHead(node* &head , int d  ){
    node* temp = new node(d);
    temp->next = head ;
    head->prev = temp ;
    head =temp ;
}

void getLength (node* head){
    int len=0;
    node* temp =head ;
    
    while(temp != NULL){
        len++;
        temp = temp->next ;
    }
    cout<<len;
}

int main()
{
    node* node1 = new node(5);
    node* head = node1 ;
    print( head );
    cout<<endl;
    getLength(head);
    cout<<endl;
    insertAtHead(head , 14);
    print(head);

    return 0;
}

