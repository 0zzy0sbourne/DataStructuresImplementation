#include <iostream> 
#include "tree.h"
using namespace std; 
void Tree::init(){
    root = nullptr;     
}
void Tree::close(Node* node ){ // deletion must be in postorder !!!
    if(node == nullptr) return ; 
    close(node->left); 
    close(node->right); 
    delete node ; 
}
bool Tree::isEmpty(){
    return root==nullptr;  
}
void Tree::addChild(double child){
    Node* newnode = new Node; 
    newnode->value = child ; 
    newnode->left = nullptr; 
    newnode->right = nullptr; 
    if(isEmpty()){root = newnode;}
    else {
        // tree is not empty
        BST(root, newnode);
    }
}

void Tree::BST(Node* temproot,Node* nptr){
    if(nptr->value > temproot->value){
        if(temproot->right == nullptr){
            temproot->right = nptr ; 
        }
        else {
            BST(temproot->right, nptr);
        }
    }
    else if(nptr->value < temproot->value){
        if(temproot->left == nullptr){temproot->left = nptr;
        }
        else {
            BST(temproot->left, nptr); 
        }
    }
}
void Tree::preOrder(Node* temproot){
    if(temproot == root && temproot == nullptr){
        cout<<"Tree is empty"<<endl; 
    }
    else {
        cout<<temproot->value<<endl;
        if(temproot->left != nullptr) 
            preOrder(temproot->left);
        if(temproot->right != nullptr)
            preOrder(temproot->right);
        
    }
}
void Tree::inOrder(Node* temproot){
    if(temproot == root && temproot == nullptr){
        cout<<"Tree is empty"<<endl; 
    }
    else {
        if(temproot->left != nullptr)
            inOrder(temproot->left) ;
        cout<<temproot->value<<endl; 
        if(temproot->right != nullptr)
            inOrder(temproot->right);         
    }
}
void Tree::postOrder(Node* temproot){
    if(temproot == root && temproot == nullptr){
        cout<<"Tree is empty"<<endl; 
    }
    else {
        if(temproot->left != nullptr) 
            postOrder(temproot->left);
        if(temproot->right != nullptr)
            postOrder(temproot->right);
        cout<<temproot->value<<endl; 
    }
}


int main(){
    Tree* tree = new Tree ; 
    tree->addChild(30); 
    tree->addChild(20);
    tree->inOrder(tree->root);
    return 0; 
}