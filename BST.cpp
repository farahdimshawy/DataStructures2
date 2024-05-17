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

void BST::inorderASC(Node* r) { // left-root-right
    if(r == NULL){
        return;
    }
    inorderASC(r->left);
    r->data->print();
    inorderASC(r->right);
}

void BST::inorderDESC(Node* r){
    if(r == NULL){
        return;
    }
    inorderDESC(r->right);
    r->data->print();
    inorderDESC(r->left);
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