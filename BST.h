//
// Created by omar on 5/15/2024.
//

#ifndef BST_BST_H
#define BST_BST_H
#include "item.h"

class Node{
public:
    Item* data;
    Node* left;
    Node* right;
    Node(string name, string cat, int p);
    Node(Item* item);
};

class BST {
private:
    Node* root;
    bool sortByName;
public:
    BST(bool sortByName = true);
    bool isEmpty();
    Node* getRoot();
    void insert(Item* item);
    void preorder(Node* r);
    void inorderASC(Node* r);
    void inorderDESC(Node* r);
    void Delete(string name);
    void Delete(Node* parent, Node* current);

    Node* search(string name);
    Node* parent_search(string name);
    Node* minNode(Node* r);
};


#endif //BST_BST_H
