#include"AVLTree.h"
Node* PriceAVLTree::createNode(Item item){
    Node* newNode = new Node();
    newNode->item = item;
    newNode->left = NULL;
    newNode->right =NULL;
    newNode->height = 1;
    return newNode;
}
int PriceAVLTree::height(Node* node){
    if(node==NULL){
        return 0;
    }
    return node->height;
}
int PriceAVLTree::BF(Node* node){
    return (height(node->left) - height(node->right));
}
Node* PriceAVLTree::rightRotate(Node* parent){
    Node* child = parent->left;
    Node* subchild = child->right;
    child -> right = parent;
    parent->left = subchild;
    return child;
}
Node* PriceAVLTree::leftRotate(Node* parent){
    Node* child = parent->right;
    Node* subchild = child->left;
    child->left = parent;
    parent->right = subchild;
    return child;
}
Node* PriceAVLTree::insert(Node* node,Item item){
    if(node==NULL){
        return createNode(item);
    }
    else if(item.price <= (node->item).price){
        node->left = insert(node->left,item);
    }
    else{
        node->right = insert(node->right,item);
    }
    node->height = max(height(node->left),height(node->right)) + 1;
    
    int bf = BF(node);
    //LL
    if(bf > 1 and item.price < (node->left->item).price){
        node = rightRotate(node);
    }
    //RR
    else if(bf < -1 and item.price > (node->right->item).price){
        node = leftRotate(node);
    }
    //LR
    else if (bf > 1 and item.price > (node->left->item).price){
        node->left = leftRotate(node->left);
        node = rightRotate(node);
    }
    //RL
    else if(bf < -1 and item.price < (node->right->item).price){
        node->right = rightRotate(node->right);
        node = leftRotate(node);
    }
    
    return node;
    
}
Node* PriceAVLTree::minTreeNode(Node *node) {
    Node* current = node; 
    while (current->left != NULL){ 
        current = current->left; 
    }
    return current;
}
 
Node* PriceAVLTree::deleteNode(Node* node,Item item){
    if(node==NULL){
        return node;
    }
    
    if(item.price<(node->item).price){
        node->left = deleteNode(node->left,item);
    }
    else if(item.price>(node->item).price){
        node->right = deleteNode(node->right,item);
    }
    else{
        if(node->left == NULL and node->right == NULL){
            node =NULL;
        }
        else if(node->left == NULL){
            Node* curr = node->right;
            node->item = curr->item;
            delete curr;
        }
        else if(node->right == NULL){
            Node* curr = node->left;
            node->item = curr->item;
            delete  curr;
        }
        else{
            Node* suc = minTreeNode(node->right);
            node->item = suc->item;
            node->right = deleteNode(node->right,suc->item);
        }
    }
    if(node==NULL){
        return node;
    }
    node->height = max(height(node->left),height(node->right)) +1;
    
    int bf = BF(node);
    //LL
    if(bf > 1 ){
        if(BF(node->left)>=0)//LL
          node = rightRotate(node);
        else{//LR
            node->left=leftRotate(node->left);
            return rightRotate(node);
        }
    }
    if(bf<-1){//RR
        if(BF(node->right)<=0)
            return leftRotate(node);
        else{
            //RL
            node->right=rightRotate(node->right);
            return leftRotate(node);
        }      
    }
    return node;
    
}

PriceAVLTree::PriceAVLTree(){
    root=NULL;
}
void PriceAVLTree::insertNode(Item item){
    if(root==NULL){
        root = createNode(item);
    }
    else{
        root = insert(root, item);
    }
}
   
void PriceAVLTree::deleteItem(Item item){
    if(root==NULL){
        cerr<<"Tree is empty\n";
        return;
    }
    else{
        root = deleteNode(root, item);
    }
  }
void PriceAVLTree::Inorder(Node *p) {
    if (p){
        Inorder(p->left);
        (p->item).print();
        Inorder(p->right);
    }
}
Node* PriceAVLTree::getRoot(){
    return root;
}





Node* NameAVLTree::createNode(Item item){
    Node* newNode = new Node();
    newNode->item = item;
    newNode->left = NULL;
    newNode->right =NULL;
    newNode->height = 1;
    return newNode;
}
int NameAVLTree::height(Node* node){
    if(node==NULL){
        return 0;
    }
    return node->height;
}
int NameAVLTree::BF(Node* node){
    return (height(node->left) - height(node->right));
}
Node* NameAVLTree::rightRotate(Node* parent){
    Node* child = parent->left;
    Node* subchild = child->right;
    child -> right = parent;
    parent->left = subchild;
    return child;
}
Node* NameAVLTree::leftRotate(Node* parent){
    Node* child = parent->right;
    Node* subchild = child->left;
    child->left = parent;
    parent->right = subchild;
    return child;
}
Node* NameAVLTree::insert(Node* node,Item item){
    if(node==NULL){
        return createNode(item);
    }
    else if(item.itemName < (node->item).itemName){
        node->left = insert(node->left,item);
    }
    else{
        node->right = insert(node->right,item);
    }
    node->height = max(height(node->left),height(node->right)) + 1;
    
    int bf = BF(node);
    //LL
    if(bf > 1 and item.itemName < (node->left->item).itemName){
        node = rightRotate(node);
    }
    //RR
    else if(bf < -1 and item.itemName > (node->right->item).itemName){
        node = leftRotate(node);
    }
    //LR
    else if (bf > 1 and item.itemName > (node->left->item).itemName){
        node->left = leftRotate(node->left);
        node = rightRotate(node);
    }
    //RL
    else if(bf < -1 and item.itemName < (node->right->item).itemName){
        node->right = rightRotate(node->right);
        node = leftRotate(node);
    }
    
    return node;
    
}
Node* NameAVLTree::minTreeNode(Node *node) {
    Node* current = node; 
    while (current->left != NULL){ 
        current = current->left; 
    }
    return current;
}
 
Node* NameAVLTree::deleteNode(Node* node,Item item){
    if(node==NULL){
        return node;
    }
    
    if(item.itemName<(node->item).itemName){
        node->left = deleteNode(node->left,item);
    }
    else if(item.itemName>(node->item).itemName){
        node->right = deleteNode(node->right,item);
    }
    else{
        if(node->left == NULL and node->right == NULL){
            node =NULL;
        }
        else if(node->left == NULL){
            Node* curr = node->right;
            node->item = curr->item;
            delete curr;
        }
        else if(node->right == NULL){
            Node* curr = node->left;
            node->item = curr->item;
            delete  curr;
        }
        else{
            Node* suc = minTreeNode(node->right);
            node->item = suc->item;
            node->right = deleteNode(node->right,suc->item);
        }
    }
    if(node==NULL){
        return node;
    }
    node->height = max(height(node->left),height(node->right)) +1;
    
    int bf = BF(node);
    //LL
    if(bf > 1 ){
        if(BF(node->left)>=0)//LL
          node = rightRotate(node);
        else{//LR
            node->left=leftRotate(node->left);
            return rightRotate(node);
        }
    }
    if(bf<-1){//RR
        if(BF(node->right)<=0)
            return leftRotate(node);
        else{
            //RL
            node->right=rightRotate(node->right);
            return leftRotate(node);
        }      
    }
    return node;
    
}

NameAVLTree::NameAVLTree(){
    root=NULL;
}
void NameAVLTree::insertNode(Item item){
    if(root==NULL){
        root = createNode(item);
    }
    else{
        root = insert(root, item);
    }
}
   
void NameAVLTree::deleteItem(Item item){
    if(root==NULL){
        cerr<<"Tree is empty\n";
        return;
    }
    else{
        root = deleteNode(root, item);
    }
  }
void NameAVLTree::Inorder(Node *p) {
    if (p){
        Inorder(p->left);
        (p->item).print();
        Inorder(p->right);
    }
}
Node* NameAVLTree::getRoot(){
    return root;
}