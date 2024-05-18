//
// Created by hp on 5/15/2024.
//

#include "BST.h"

Node::Node(string name, string cat, int p) {
    data = new Item(name, cat, p);
    left = right = NULL;
}

Node::Node(Item *item){
    data = item;
    left = right = NULL;
}

/////////////////////////////////////////////////////

BST::BST(bool sortByName) : root(NULL), sortByName(sortByName) {}

bool BST::isEmpty(){
    return root == NULL;
}

Node* BST::getRoot(){
    return root;
}


void BST::insert(Item* item){
    Node* newNode = new Node(item);
    if(root == NULL){
        root = newNode;
        return;
    }
    Node *current = root, *prev = NULL;
    while(current != NULL){
        prev = current;
        if(sortByName) {
            if (*item < *(current->data))
                current = current->left;
            else
                current = current->right;
        }
        else{
            if (item->price < current->data->price)
                current = current->left;
            else
                current = current->right;
        }
    }
    if(sortByName) {
        if(*item < *(prev->data))
            prev->left = newNode;
        else
            prev->right = newNode;
    }
    else{
        if(item->price < prev->data->price)
            prev->left = newNode;
        else
            prev->right = newNode;
    }
}

void BST::preorder(Node* r) { // root-left-right
    if(isEmpty()){
        cerr << "Tree is empty!\n";
    }
    if (r == NULL) {
        return;
    }
    r->data->print();
    inorderASC(r->left);
    inorderASC(r->right);
}

void BST::inorderASC(Node* r) { // left-root-right
    if(isEmpty()){
        cerr << "Tree is empty!\n";
    }
    if(r == NULL){
        return;
    }
    inorderASC(r->left);
    r->data->print();
    inorderASC(r->right);
}

void BST::inorderDESC(Node* r){ // right-root-left
    if(isEmpty()){
        cerr << "Tree is empty!\n";
    }
    if(r == NULL){
        return;
    }
    inorderDESC(r->right);
    r->data->print();
    inorderDESC(r->left);
}

void BST::Delete(Node* parent, Node* current){
    // first case: the node has no children
    if(current->right == NULL && current->left == NULL){
        if(parent == NULL) {
            root = NULL;
        } 
        else if(parent->left == current) {
            parent->left = NULL;
        } 
        else {
            parent->right = NULL;
        }
        return;
    }
    // second case: the node has one child
    else if(current->right == NULL){
        if(parent == NULL) {
            root = current->left;
        } 
        else if(parent->left == current) {
            parent->left = current->left;
        } 
        else {
            parent->right = current->left;
        }
    }
    else if(current->left == NULL){
        if(parent == NULL) {
            root = current->right;
        } 
        else if(parent->left == current) {
            parent->left = current->right;
        } 
        else {
            parent->right = current->right;
        }
    }
    // third case: the node has two children
    else{
        Node* temp = minNode(current->right);
        parent = parent_search(temp->data->itemName);
        current->data->itemName = temp->data->itemName;
        current->data->category = temp->data->category;
        current->data->price = temp->data->price;
        Delete(parent, temp);
    }
}

void BST::Delete(string name){
    if (root == NULL){
        cerr << "Tree is empty!\n";
        return;
    }
    Node* current = root;
    Node* parent = NULL;
    while(current != NULL && current->data->itemName != name) {
        parent = current;
        if (name < current->data->itemName)
            current = current->left;
        else
            current = current->right;
     }
    // Check if the itema exists
    if(current == NULL){
        cerr << "Item not found!\n";
        return;
    }
    // First case: the node has no children
    if(current->right == NULL && current->left == NULL){
        if(parent == NULL) {
            root = NULL;
        } 
        else if(parent->left == current) {
            parent->left = NULL;
        } 
        else {
            parent->right = NULL;
        }
    }
    // second case: the node has one child
    else if(current->right == NULL){
        if(parent == NULL) {
            root = current->left;
        } 
        else if(parent->left == current) {
            parent->left = current->left;
        } 
        else {
            parent->right = current->left;
        }
    }
    else if(current->left == NULL){
        if(parent == NULL) {
            root = current->right;
        } 
        else if(parent->left == current) {
            parent->left = current->right;
        } 
        else {
            parent->right = current->right;
        }
    }
    // third case: the node has two children
    else{
        Node* temp = minNode(current->right);
        parent = parent_search(temp->data->itemName);
        current->data->itemName = temp->data->itemName;
        current->data->category = temp->data->category;
        current->data->price = temp->data->price;
        Delete(parent, temp);
    }
}

Node* BST::search(string name) {
    Node *current = root;
    while(current != NULL && current->data->itemName != name) {
        if (name < current->data->itemName)
            current = current->left;
        else if (name > current->data->itemName)
            current = current->right;
    }
    return current;
}

Node* BST::parent_search(string name) {
    Node *current = root;
    Node *prev = NULL;
    while(current != NULL && current->data->itemName != name) {
        prev = current;
        if (name < current->data->itemName)
            current = current->left;
        else if (name > current->data->itemName)
            current = current->right;
    }
    return prev;
}

Node* BST::minNode(Node* r){
    Node* current = r;
    while(current->left != NULL){
        current = current->left;
    }
    return current;
}