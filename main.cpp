#include <iostream>
#include <fstream>
#include "Item.h"
#include "BST.h"
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
        tree.insert(new Item(name, category, price));
    }
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
        case 1: {
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
        case 2:
            break;
        case 3:
            break;
        default:
            cout << "Invalid type\n";
    }

}
