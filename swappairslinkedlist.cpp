#include <iostream> 
using namespace std; 
 struct List{
    struct ListNode* head = nullptr ; 
    struct ListNode* tail = nullptr ; 
    void addNode(int , struct List* );
    ListNode* swapPairs(ListNode*); 
 }; 
 struct ListNode {
    int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 

ListNode* List::swapPairs(ListNode* head)
    {
        // create new linked list. 
        if(head  == nullptr && head->next == nullptr) return head; 
        ListNode* newhead = head->next; 
        newhead->next = head ; // first two nodes are okay .
        
        ListNode* currentNode = new ListNode(); 
        currentNode = newhead->next; 
        while(1)
        {
            if(currentNode->next == nullptr && currentNode->next->next == nullptr)break; 
            ListNode* temp = new ListNode() ;
            temp = currentNode->next; 
            currentNode->next = currentNode->next->next; 
            currentNode->next->next = temp; 
            currentNode = currentNode->next->next;
        }
        return newhead; 
    }
    
    

void List::addNode(int value, struct List* listptr)
{
    struct ListNode* newnode = new ListNode(value); 
    if(listptr->head == nullptr ) 
    {
        listptr->head= newnode; 
        listptr->tail = newnode ; 
    } 
    else{
        listptr->tail = newnode ; 
    }

}
int main()
{

    struct List* mylist = new struct List(); 
    cout<<"enter t if you want to stop adding nodes:"<<endl; 
    while(1)
    {   
        int ch ; 
        cin>>ch; 
        if(ch == 116) break; 
        mylist->addNode(ch, mylist); 
    }
    ListNode* newhead = mylist->swapPairs(mylist->head);
    ListNode* currentNode = newhead;  
    while(currentNode  !=  nullptr )
    {
        cout<<currentNode->val<<" ";
        currentNode = currentNode->next;  
    }
    return 0; 
}