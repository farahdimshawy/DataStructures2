#ifndef AVLTREE_H
#define AVLTREE_H
#include "Item.h"
struct Node{
    Node* left;
    Item item;
    Node* right;
    int height;
};

class PriceAVLTree{

    Node* root;
private:
    Node* createNode(Item item);
    int height(Node* node);
    int BF(Node* node);
    Node* rightRotate(Node* parent);
    Node* leftRotate(Node* parent);
    Node* insert(Node* node,Item item);
    Node* minTreeNode(Node *node);
    Node* deleteNode(Node* node,Item item);
public:
    PriceAVLTree();
    void insertNode(Item item);
   
    void deleteItem(Item item);
    void Inorder(Node *p);
    Node* getRoot();
    
};
class NameAVLTree{

    Node* root;
private:
    Node* createNode(Item item);
    int height(Node* node);
    int BF(Node* node);
    Node* rightRotate(Node* parent);
    Node* leftRotate(Node* parent);
    Node* insert(Node* node,Item item);
    Node* minTreeNode(Node *node);
    Node* deleteNode(Node* node,Item item);
public:
    NameAVLTree();
    void insertNode(Item item);
   
    void deleteItem(Item item);
    void Inorder(Node *p);
    Node* getRoot();
    
};
#endif