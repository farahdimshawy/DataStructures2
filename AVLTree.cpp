#include"AVLTree.h"
NodeAVL* PriceAVLTree::createNodeAVL(Item item){
    NodeAVL* newNodeAVL = new NodeAVL();
    newNodeAVL->item = item;
    newNodeAVL->left = NULL;
    newNodeAVL->right =NULL;
    newNodeAVL->height = 1;
    return newNodeAVL;
}
int PriceAVLTree::height(NodeAVL* node){
    if(node==NULL){
        return 0;
    }
    return node->height;
}
int PriceAVLTree::BF(NodeAVL* node){
    return (height(node->left) - height(node->right));
}
NodeAVL* PriceAVLTree::rightRotate(NodeAVL* parent){
    NodeAVL* child = parent->left;
    NodeAVL* subchild = child->right;
    child -> right = parent;
    parent->left = subchild;
    return child;
}
NodeAVL* PriceAVLTree::leftRotate(NodeAVL* parent){
    NodeAVL* child = parent->right;
    NodeAVL* subchild = child->left;
    child->left = parent;
    parent->right = subchild;
    return child;
}
NodeAVL* PriceAVLTree::insert(NodeAVL* node,Item item){
    if(node==NULL){
        return createNodeAVL(item);
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
    if(bf > 1 and item.price <= (node->left->item).price){
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
    else if(bf < -1 and item.price <= (node->right->item).price){
        node->right = rightRotate(node->right);
        node = leftRotate(node);
    }
    
    return node;
    
}
NodeAVL* PriceAVLTree::minTreeNodeAVL(NodeAVL *node) {
    NodeAVL* current = node; 
    while (current->left != NULL){ 
        current = current->left; 
    }
    return current;
}
 
NodeAVL* PriceAVLTree::deleteNodeAVL(NodeAVL* node,Item item){
    if(node==NULL){
        return node;
    }
    
    if(item.price<(node->item).price){
        node->left = deleteNodeAVL(node->left,item);
    }
    else if(item.price>(node->item).price){
        node->right = deleteNodeAVL(node->right,item);
    }
    else if(node->item.itemName != item.itemName){
        node->left = deleteNodeAVL(node->left,item);    
    }
    else{
        if(node->left == NULL and node->right == NULL){
            node =NULL;
        }
        else if(node->left == NULL){
            NodeAVL* curr = node->right;
            node->item = curr->item;
            delete curr;
        }
        else if(node->right == NULL){
            NodeAVL* curr = node->left;
            node->item = curr->item;
            delete  curr;
        }
        else{
            NodeAVL* suc = minTreeNodeAVL(node->right);
            node->item = suc->item;
            node->right = deleteNodeAVL(node->right,suc->item);
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
void PriceAVLTree::insertNodeAVL(Item item){
    if(root==NULL){
        root = createNodeAVL(item);
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
        root = deleteNodeAVL(root, item);
    }
  }
void PriceAVLTree::Inorder(NodeAVL *p) {
    if (p){
        Inorder(p->left);
        (p->item).print();
        Inorder(p->right);
    }
}
void PriceAVLTree::InorderDesc(NodeAVL* p){
    if (p){
        InorderDesc(p->right);
        (p->item).print();
        InorderDesc(p->left);
    }
}
NodeAVL* PriceAVLTree::getRoot(){
    return root;
}
void PriceAVLTree::preorder(NodeAVL* p){
    if(p){
        (p->item).print();
        preorder(p->left);
        preorder(p->right);
    }
}


NodeAVL* NameAVLTree::createNodeAVL(Item item){
    NodeAVL* newNodeAVL = new NodeAVL();
    newNodeAVL->item = item;
    newNodeAVL->left = NULL;
    newNodeAVL->right =NULL;
    newNodeAVL->height = 1;
    return newNodeAVL;
}
int NameAVLTree::height(NodeAVL* node){
    if(node==NULL){
        return 0;
    }
    return node->height;
}
int NameAVLTree::BF(NodeAVL* node){
    return (height(node->left) - height(node->right));
}
NodeAVL* NameAVLTree::rightRotate(NodeAVL* parent){
    NodeAVL* child = parent->left;
    NodeAVL* subchild = child->right;
    child -> right = parent;
    parent->left = subchild;
    return child;
}
NodeAVL* NameAVLTree::leftRotate(NodeAVL* parent){
    NodeAVL* child = parent->right;
    NodeAVL* subchild = child->left;
    child->left = parent;
    parent->right = subchild;
    return child;
}
NodeAVL* NameAVLTree::insert(NodeAVL* node,Item item){
    if(node==NULL){
        return createNodeAVL(item);
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
NodeAVL* NameAVLTree::minTreeNodeAVL(NodeAVL *node) {
    NodeAVL* current = node; 
    while (current->left != NULL){ 
        current = current->left; 
    }
    return current;
}
 
NodeAVL* NameAVLTree::deleteNodeAVL(NodeAVL* node,Item item){
    if(node==NULL){
        return node;
    }
    
    if(item.itemName<(node->item).itemName){
        node->left = deleteNodeAVL(node->left,item);
    }
    else if(item.itemName>(node->item).itemName){
        node->right = deleteNodeAVL(node->right,item);
    }
    else{
        if(node->left == NULL and node->right == NULL){
            node =NULL;
        }
        else if(node->left == NULL){
            NodeAVL* curr = node->right;
            node->item = curr->item;
            delete curr;
        }
        else if(node->right == NULL){
            NodeAVL* curr = node->left;
            node->item = curr->item;
            delete  curr;
        }
        else{
            NodeAVL* suc = minTreeNodeAVL(node->right);
            node->item = suc->item;
            node->right = deleteNodeAVL(node->right,suc->item);
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
void NameAVLTree::insertNodeAVL(Item item){
    if(root==NULL){
        root = createNodeAVL(item);
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
        root = deleteNodeAVL(root, item);
    }
  }
void NameAVLTree::Inorder(NodeAVL *p) {
    if (p){
        Inorder(p->left);
        (p->item).print();
        Inorder(p->right);
    }
}
void NameAVLTree::InorderDesc(NodeAVL* p){
    if (p){
        InorderDesc(p->right);
        (p->item).print();
        InorderDesc(p->left);
    }
}
void NameAVLTree::preorder(NodeAVL* p){
    if(p){
        (p->item).print();
        preorder(p->left);
        preorder(p->right);
    }
}

NodeAVL* NameAVLTree::getRoot(){
    return root;
}
Item NameAVLTree::Search(string name){
    NodeAVL* curr = root;
    NodeAVL* prev = NULL;
    while(curr !=NULL){
        prev= curr;
        if(name < curr->item.itemName){
            curr = curr->left;
        }
        if(name > curr->item.itemName){
            curr = curr->right;
        }
        if(name == curr->item.itemName){
            break;
        }
    }
    if(curr == NULL){
        Item item;
        return item;
    }
    return curr->item;
}
