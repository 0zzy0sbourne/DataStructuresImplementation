#include <iostream> 
using namespace std ; 
struct node{
  int nodedata;
  node* next ; 
  node(int data)
  {
      nodedata = data ; 
      next = nullptr ; 
  }
  
}; 
struct graph{
  node* head ; 
  node* tail ; 

  graph(int data)
  {
    node* newnode = new node(data); 
    head = newnode; ; 
    tail = newnode ;
  }
  void printGraph();
  node* createNode(int); 
}; 
node* graph::createNode(int data){
  node* newnode = new node(data); 
  if(head->next == nullptr)
  {
    head->next = newnode ;
    tail = newnode; 
  }
  else{
    tail->next = newnode ; 
    tail = newnode; 
  }
  return newnode; 

}
void graph::printGraph()
{
  if( head == nullptr){
    cout<<"$ "<<"graph has no head"<<endl;
  }
  else{
    node* currentNode = new node(head->nodedata); 
    currentNode = head; 

    while(currentNode != nullptr) 
    {
      cout<<currentNode->nodedata<<"--"; 
      currentNode = currentNode->next; 
    }
  }
  
  
}
int main() {
  
  int veri = 10 ; 
  graph* newgraph = new graph(veri); 
  int choice = -1; 
  
  
  while(choice != 0)
  {
  cout<<endl;
     cout<<endl; 
    cout<<"MENU"<<endl; 
    cout<<"1.Add node to the list"<<endl; 
    cout<<"2.Delete node from the list"<<endl; 
    cout<<"3.Print the list"<<endl; 
    cout<<"(Press 0 to exit):"; 
    cin>>choice; 
    cout<<endl<<endl; 
  
    switch(choice)
    {
      case 1 : 
                cout<<"enter the data of the node that you want to add:"; 
                cin>>veri; 
                
                newgraph->createNode(veri); 
        break; 
      case 2 :
        break; 
      case 3 : 
                newgraph->printGraph(); 
        break;
      case 0: 
        break; 
    }
  }
  
  return 0;
}
