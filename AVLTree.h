#ifndef AVLTREE_H
#define AVLTREE_H
#include "Item.h"
struct NodeAVL{
    NodeAVL* left;
    Item item;
    NodeAVL* right;
    int height;
    };

class PriceAVLTree{
private:
    NodeAVL* root;
    NodeAVL* createNodeAVL(Item item);
    int height(NodeAVL* node);
    int BF(NodeAVL* node);
    NodeAVL* rightRotate(NodeAVL* parent);
    NodeAVL* leftRotate(NodeAVL* parent);
    NodeAVL* insert(NodeAVL* node,Item item);
    NodeAVL* minTreeNodeAVL(NodeAVL *node);
    NodeAVL* deleteNodeAVL(NodeAVL* node,Item item);
public:

    PriceAVLTree();
    void insertNodeAVL(Item item);
    void deleteItem(Item item);
    void Inorder(NodeAVL *p);
    void InorderDesc(NodeAVL* p);
    void preorder(NodeAVL* p);
    NodeAVL* getRoot();
    
};
class NameAVLTree{
    NodeAVL* root;
private:
    NodeAVL* createNodeAVL(Item item);
    int height(NodeAVL* node);
    int BF(NodeAVL* node);
    NodeAVL* rightRotate(NodeAVL* parent);
    NodeAVL* leftRotate(NodeAVL* parent);
    NodeAVL* insert(NodeAVL* node,Item item);
    NodeAVL* minTreeNodeAVL(NodeAVL *node);
    NodeAVL* deleteNodeAVL(NodeAVL* node,Item item);
public:
    NameAVLTree();
    void insertNodeAVL(Item item);
    void deleteItem(Item item);
    void Inorder(NodeAVL *p);
    void InorderDesc(NodeAVL* p);
    void preorder(NodeAVL* p);
    NodeAVL* getRoot();
    Item Search(string name);
    
};
#endif
