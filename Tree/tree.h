#include <iostream> 

using namespace std ; 

struct Node{
    double value ; 
    Node* left ; 
    Node* right;    
};

struct Tree{
    Node* root ;
    void addChild(double);  
    void preOrder(Node*); 
    void inOrder(Node*); 
    void postOrder(Node*);
    void BST(Node*, Node*); 
    bool isEmpty();
    void close(Node*);
    void init();
}; 