/*
Following is the class structure of the Node class:

class Node
{
public:
    int data;
    Node *next,*prev;
    Node()
    {
        this->data = 0;
        next = NULL;
        prev= NULL;
    }
    Node(int data)
    {
        this->data = data; 
        this->next = NULL;
        this->prev= NULL;
    }
    Node(int data, Node* next, Node *prev)
    {
        this->data = data;
        this->next = next;
        this->prev= prev;
    }
};

*/

Node* reverseDLL(Node* head)
{   
    if(head == NULL || head->next == NULL) return head;
    Node * previous = NULL;
    Node * curr =  head;
    while(curr!=NULL){
       previous = curr->prev;
       curr->prev = curr->next;
       curr->next = previous;
       curr = curr->prev;

    }  
    return previous->prev; 
}

