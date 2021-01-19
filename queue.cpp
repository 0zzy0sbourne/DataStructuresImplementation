#include <iostream> 


using namespace std; 


typedef int QueueDataType ; 
struct  node {
    QueueDataType data; 
    node* next;
}; 

struct queue{
    public: 
    // declare functions 
    void create() ; // ok
    void close() ; // 
    bool push_back(QueueDataType) ; // ok 
    void front() ; // ok  
    bool empty() ; // ok
    void pop_front(); // ok 
    void size() ; 
    void back(); 
    private:
        node* head ; 
        node* tail ;        
        
}; 

void queue::create() {
    head = nullptr ; 
    tail = nullptr ; 
}
bool queue::push_back(QueueDataType data){
    node* newnode = new node;
    newnode->data = data; 
    newnode->next = nullptr ; 
    if(head == nullptr && tail == nullptr){
        head = newnode;
        tail = newnode ; 
        return true;  
    }
    tail->next = newnode; 
    tail = newnode ; 
    return true ;  

}

void queue::front() {
    if(head == nullptr && tail == nullptr){
        cout<<"queue is empty"<<endl;
        return ; 
        }
    cout<<head->data<<endl;
}

bool queue::empty(){
    return (head == nullptr && tail == nullptr ) ;
}

void queue::pop_front(){
    // check if queue is empty or not : 
    if(!empty()){
        if(head == tail && head != nullptr && tail != nullptr){ // check if queue has one element| can be done like if(head == tail)
           
            head = nullptr ; 
            tail = nullptr; 
           
        }
        else if(head == nullptr && tail == nullptr) {
            // queue is empty 
            cout<<"queue is empty"<<endl;
             
        }
        else {
            head = head->next ;
        }
    }
   
}

void queue::close(){
    if(head != nullptr && tail != nullptr)
    {
        node* currentNode = new node ;
        currentNode = head ; 
        while(currentNode)
        {
            node* temp = currentNode ; 
            currentNode = currentNode->next; 
            delete temp ; 
        }
    }

 
}
void queue::size(){
    int counter = 0 ; 
    if(head == nullptr && tail == nullptr){
        cout<<counter<<endl;
         return ;
          }
    node* traverse = head ; 
    while(traverse){
        counter++; 
        traverse = traverse->next;
    }
    cout<<counter<<endl; 
    return;

}
void queue::back(){
    if(!empty()){
        cout<< tail->data<<endl; 
        return ; 
    }
    cout<<"queue is empty"<<endl; 
    return;
}

int main(){
    int get ; 
    queue Queue ; 
    Queue.create() ; 
    while(true){
         cout << "MENU" <<endl; 
         cout<<"1.insert element"<<endl; 
         cout<<"2.pop from front"<<endl; 
         cout<<"3.see the front element"<<endl; 
         cout<<"4.see the back element"<<endl; 
         cout<<"5.see the size of the element" <<endl; 
        cin>>get; 
        if(get == 0 ){break; }
         switch(get){
             case 1 :
                QueueDataType data ; 
                cout<<"enter the element you wanna insert:"; 
                cin>>data ; 
                Queue.push_back(data) ;
                break;
            case 2 : 
                Queue.pop_front() ; 
                break; 
            case 3: 
                Queue.front();
                break;  
            case 4: 
                Queue.back();
                break;  
            case 5 :  
                Queue.size();
                break;  
                
         }
         

    }
    Queue.close();
    return 0; 

}