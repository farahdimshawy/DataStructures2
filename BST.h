//
// Created by omar on 5/15/2024.
//

#ifndef BST_BST_H
#define BST_BST_H
#include "item.h"

class Tree{

};


class Node{
public:
    Item* data;
    Node* left;
    Node* right;
    Node(string name, string cat, int p);
    Node(Item* item);
};

class BST: Tree {
private:
    Node* root;
    bool sortByName;
public:
    BST(bool sortByName);
    Node* getRoot();
    void insert(Item* item);
    void inorderASC(Node* r);
    void inorderDESC(Node* r);

    Node* search(string name);
};


#endif //BST_BST_H
