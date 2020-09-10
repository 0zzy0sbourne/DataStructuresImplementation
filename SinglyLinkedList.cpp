#include <bits/stdc++.h>
using namespace std; 
class SinglyLinkedListNode{
    public: 
    int data ; 
    SinglyLinkedListNode* next ; 
    
    SinglyLinkedListNode(int nodeData)
    {
        this->data = nodeData; 
        this->next = NULL ;
    }

}; 
class SinglyLinkedList{
    public: 
    SinglyLinkedListNode* head ; 
    SinglyLinkedListNode* tail ;
    SinglyLinkedList()
    {
        this->head = NULL ; 
        this->tail = NULL ;
    }

    void insertNode(int node_data)
    {
        SinglyLinkedListNode* newNode = new SinglyLinkedListNode(node_data);
        
        if(!this->head)
        {
            this->head = newNode; 
        }
        else  {
            this->tail->next = newNode ; 
        }
        this->tail = newNode ; 
    }
    void traverseList(SinglyLinkedListNode* head)
    {
        if(!this->head)
        {
            return ; 
        }
        else if (head != NULL) {cout<<head->data<<" "; traverseList(head->next); }
        
        
        
    }
}; 




int main()
{
    SinglyLinkedList* list = new SinglyLinkedList(); 
    list->insertNode(10); 
    list->insertNode(5); 
    list->traverseList(list->head); 
    
    
    
}
