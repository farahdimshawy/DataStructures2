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
    preorder(r->left);
    preorder(r->right);
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

void BST::Delete(Node* parent, Node* current) {
    // First case: the node has no children
    if (current->right == NULL && current->left == NULL) {
        if (parent == NULL) {
            root = NULL;
        } else if (parent->left == current) {
            parent->left = NULL;
        } else {
            parent->right = NULL;
        }
        delete current;  // Delete the node
        return;
    }
        // Second case: the node has one child
    else if (current->right == NULL) {
        if (parent == NULL) {
            root = current->left;
        } else if (parent->left == current) {
            parent->left = current->left;
        } else {
            parent->right = current->left;
        }
        delete current;  // Delete the node
    } else if (current->left == NULL) {
        if (parent == NULL) {
            root = current->right;
        } else if (parent->left == current) {
            parent->left = current->right;
        } else {
            parent->right = current->right;
        }
        delete current;  // Delete the node
    }
        // Third case: the node has two children
    else {
        Node* temp = minNode(current->right);
        parent = parent_search(temp->data->itemName);
        // Swap data
        swap(current->data, temp->data);
        // Recursively delete the node with the minimum value in the right subtree
        Delete(current, temp);
    }
}


void BST::Delete(string name) {
    if (root == NULL) {
        cerr << "Tree is empty!\n";
        return;
    }

    Node* current = root;
    Node* parent = NULL;

    // Find the node to delete
    while (current != NULL && current->data->itemName != name) {
        parent = current;
        if (name < current->data->itemName)
            current = current->left;
        else
            current = current->right;
    }

    // Check if the item exists
    if (current == NULL) {
        cerr << "Item not found!\n";
        return;
    }

    // Case 1: Node has no children
    if (current->right == NULL && current->left == NULL) {
        if (parent == NULL) {
            // Deleting the root node
            delete root;
            root = NULL;
        } else if (parent->left == current) {
            delete parent->left;
            parent->left = NULL;
        } else {
            delete parent->right;
            parent->right = NULL;
        }
    }
        // Case 2: Node has one child
    else if (current->right == NULL) {
        if (parent == NULL) {
            root = current->left;
        } else if (parent->left == current) {
            parent->left = current->left;
        } else {
            parent->right = current->left;
        }
        delete current;
    } else if (current->left == NULL) {
        if (parent == NULL) {
            root = current->right;
        } else if (parent->left == current) {
            parent->left = current->right;
        } else {
            parent->right = current->right;
        }
        delete current;
    }
        // Case 3: Node has two children
    else {
        Node* temp = minNode(current->right);
        // Swap data
        swap(current->data, temp->data);
        // Recursively delete the node with the minimum value in the right subtree
        Delete(current->data->itemName);
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