#include <iostream>
#include <fstream>
#include<vector>
#include<string>
#include "Item.h"
#include "BST.h"
#include "AVLTree.h"
using namespace std;

void readItems(istream& is, BST& tree) {
    int numItems;
    is >> numItems;
    is.ignore();

    for (int i = 0; i < numItems; ++i) {
        std::string name;
        std::string category;
        double price;
        std::getline(is, name);
        std::getline(is, category);
        is >> price;
        is.ignore();
        is.ignore();
        tree.insert(new Item(name, category, price));
    }
}
vector<Item> readFile(string filename){
    vector<Item> items;
    ifstream file(filename);
    string nS;
    getline(file,nS);
    int n = stoi(nS);
    for(int i =0; i<n; i++){
        string name;
        string category;
        string price;
        getline(file,name);
        getline(file,category);
        getline(file,price);
        Item item(name,category,stod(price));
        items.push_back(item);
        string dummy;
        getline(file,dummy);
    }
    return items;
}

void miniMenu(){
    cout << "\n1. Add item data\n";
    cout << "2. Add items data from a file\n";
    cout << "3. Remove item data\n";
    cout << "4. Display the item data normally\n";
    cout << "5. Display all the items sorted by their name ascending\n";
    cout << "6. Display all the items sorted by their name descending\n";
    cout << "7. Display all the items sorted by their prices ascending\n";
    cout << "8. Display all the items sorted by their prices descending\n";
    cout << "0. Exit\n\n";
}

int main() {   
    cout << "Choose a non-linear data structure..\n";
    cout << "1. Binary Search Tree\n";
    cout << "2. AVL Tree\n";
    cout << "3. Heap Tree\n";
    int type;
    cin >> type;
    switch (type) {
        case 1:{ 
            BST nameTree, priceTree(false);
            cout << "Choose one of the following choices..\n";
            miniMenu();
            int choice;
            while (cin >> choice, choice != 0) {
                switch (choice) {
                    case 1: {
                        string name, category;
                        double price;
                        cout << "Enter item name, category, price (space separated)\n";
                        cin >> name >> category >> price;
                        nameTree.insert(new Item(name, category, price));
                        priceTree.insert(new Item(name, category, price));
                        break;
                    }
                    case 2: {
                        ifstream inputFile("items.txt");
                        if(!inputFile){
                            cerr << "Error opening file\n";
                        }
                        readItems(inputFile, nameTree);
                        inputFile.close();
                        inputFile.open("items.txt");
                        readItems(inputFile, priceTree);
                        break;
                    }
                    case 3: {
                        cout << "Enter name of the item you want to delete\n";
                        string name;
                        cin >> name;
                        nameTree.Delete(name);
                        priceTree.Delete(name);
                        break;
                    }
                    case 4:
                        nameTree.preorder(nameTree.getRoot());
                        break;
                    case 5:
                        nameTree.inorderASC(nameTree.getRoot());
                        break;
                    case 6:
                        nameTree.inorderDESC(nameTree.getRoot());
                        break;
                    case 7:
                        priceTree.inorderASC(priceTree.getRoot());
                        break;
                    case 8:
                        priceTree.inorderDESC(priceTree.getRoot());
                        break;
                    default:
                        cout << "Invalid choice\n";
                }
                miniMenu();
            }
            break;
        }
        case 2:{
            PriceAVLTree priceTree;
            NameAVLTree nameTree;
            cout << "Choose one of the following choices..\n";
            miniMenu();
            int choice;
            while (cin >> choice, choice != 0) {
                switch (choice) {
                    case 1: {
                        string name, category;
                        double price;
                        cout << "Enter item name, category, price (space separated)\n";
                        cin >> name >> category >> price;
                        Item item(name, category, price);
                        nameTree.insertNodeAVL(item);
                        priceTree.insertNodeAVL(item);
                        break;
                    }
                    case 2: {
                        vector<Item> items = readFile("items.txt");
                        for(auto item : items){
                            nameTree.insertNodeAVL(item);
                            priceTree.insertNodeAVL(item);
                        }
                        break;
                    }
                    case 3: {
                        cout << "Enter name of the item you want to delete\n";
                        string name;
                        cin >> name;
                        Item item = nameTree.Search(name);
                        nameTree.deleteItem(item);
                        priceTree.deleteItem(item);
                        break;
                    }
                    case 4:
                        nameTree.preorder(nameTree.getRoot());
                        break;
                    case 5:
                        nameTree.Inorder(nameTree.getRoot());
                        break;
                    case 6:
                        nameTree.InorderDesc(nameTree.getRoot());
                        break;
                    case 7:
                        priceTree.Inorder(priceTree.getRoot());
                        break;
                    case 8:
                        priceTree.InorderDesc(priceTree.getRoot());
                        break;
                    default:
                        cout << "Invalid choice\n";
                }
                miniMenu();
            }
            break;
        }
        case 3:
            break;
        default:
            cout << "Invalid type\n";
    }

}
