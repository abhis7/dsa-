class solution
{
     private:
    void insertAtTail(Node* &head, Node* &tail, int d) {
        Node* newNode = new Node(d);
        if(head == NULL) {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail -> next = newNode;
            tail = newNode;
        }
    }
    
    void print(Node* head) {
        while(head != NULL) {
            cout << head -> data << " ";
            head = head -> next;
        }cout << endl;
    }

    void printRandom(Node* head) {
        while(head != NULL) {
            cout << " head data: " << head->data <<" ";
            if(head ->arb != NULL) {
                cout << " head random data" << head -> arb ->data;
            }
            else
            {
                cout << " head random data: NULL";
            }
            head = head -> next;
            cout << endl;
        }
    }

    public:
    Node *copyList(Node *head)
    {
        //step 1: Create a Clone List
        Node* cloneHead = NULL;
        Node* cloneTail = NULL;
        
        Node* temp = head;
        while(temp != NULL) {
            insertAtTail(cloneHead, cloneTail, temp->data);
            temp = temp -> next;
        }
        
        // step 2: insert nodes of Clone List in between originalList
        unordered_map<Node* , Node*> oldToNewNode;
        Node* originalNode = head;
        Node* cloneNode = cloneHead;
        
        while(originalNode != NULL && cloneNode != NULL) {
            oldToNewNode[originalNode]= cloneNode ; 
            
            originalNode=originalNode->next ; 
            cloneNode = cloneNode->next ; 
        }
        
        originalNode = head;
        cloneNode = cloneHead;
        
        while(originalNode!=NULL){
            cloneNode->arb = oldToNewNode[originalNode->arb];
            originalNode=originalNode->next ; 
            cloneNode = cloneNode->next ; 
        }
       

        // step 5 answer return
        return cloneHead;
    }
    
};