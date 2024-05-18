#include <iostream>
#include <fstream>
#include<vector>
#include<string>
#include "Item.h"
#include "BST.h"
#include "AVLTree.h"
#include "Heap.h"
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
void clearScreen() {
    // ANSI escape code to clear the screen
    cout << "\033[2J\033[H";
}
void displayHeapMenu(){
    cout << "\nMenu:" << endl;
    cout << "----------------------------------------" << endl;
    cout << "1. Add item" << endl;
    cout << "2. Add items from a file" << endl;
    cout << "3. Remove item at the top" << endl;
    cout << "4. Display item at the top" << endl;
    cout << "5. Heap Sort" << endl;
    cout << "0. Exit" << endl;
    cout << "----------------------------------------" << endl;
}
void displaySubMenu() {
    cout << "\nOrder by: " << endl;
    cout << "1. Price" << endl;
    cout << "2. Name" << endl;
}

void maxHeapMenu() {
    displaySubMenu();
    int choice;
    Comparator maxComparator;
    cout << "Enter your choice: ";
    cin >> choice;
    switch(choice){
        case 1:
            maxComparator = [](const Item& a, const Item& b) {
                return a.price > b.price;
            };
            break;
        case 2:
            maxComparator = [](const Item &a, const Item &b) {
                return a.itemName > b.itemName;
            };
            break;
        case 0:
            clearScreen();
            cout << "Exiting max Heap menu" << endl;
            break;
        default:
            clearScreen();
            cout << "Wrong choice, please choose from the menu" << endl;
    }
    displayHeapMenu();
    MaxHeap maxHeap(maxComparator);
    do {
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1: {//add item
                clearScreen();
                string name, category;
                double price;
                cout << "Enter name: ";
                cin.ignore();
                getline(cin, name);
                cout << "Enter category: ";
                cin >> category;
                cout << "Enter price: ";
                cin >> price;
                maxHeap.insert(new Item(name, category, price));
                clearScreen();
                break;
            }
            case 2:{
                clearScreen();
                cout << "\nEnter file name: ";
                string file;
                cin >> file;
                readItemsFromFile(file, &maxHeap);
                break;
            }
            case 3: {//remove
                clearScreen();
                cout << "\nRemoving Top...";
                maxHeap.removeTop();
                // Your Max Heap remove function
                clearScreen();
                break;
            }
            case 4: {//display
                clearScreen();
                if(maxHeap.getTop()){
                    cout << "\nTop Item:";
                    maxHeap.getTop()->print();
                }
                else
                    cout << "Empty Heap\n";
                break;
            }
            case 5: {//heapsort
                clearScreen();
                cout << "\nHeap Sort (in descending order):\n";
                Heap* sortedHeap = HeapSort(&maxHeap);
                sortedHeap->display();
                break;
            }

            case 0:
                clearScreen();
                cout << "Exiting Max Heap menu" << endl;
                break;
            default:
                clearScreen();
                cout << "Wrong choice, please choose from the menu" << endl;
        }
    } while (choice != 0);
}

void minHeapMenu() {
    Comparator minComparator;
    int choice;
    displaySubMenu();
    cout << "Enter your choice: ";
    cin >> choice;
    switch (choice) {
        case 1:
            minComparator = [](const Item &a, const Item &b) {
                return a.price < b.price;
            };
            break;
        case 2:
            minComparator = [](const Item &a, const Item &b) {
                return a.itemName < b.itemName;
            };
            break;
        case 0:
            clearScreen();
            cout << "Exiting Min Heap menu" << endl;
            break;
        default:
            clearScreen();
            cout << "Wrong choice, please choose from the menu" << endl;
    }

    displayHeapMenu();
    MinHeap minHeap(minComparator);
    do {
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1: {//add item
                clearScreen();
                string name, category;
                double price;
                cout << "Enter name: ";
                cin.ignore();
                getline(cin, name);
                cout << "Enter category: ";
                cin >> category;
                cout << "Enter price: ";
                cin >> price;
                minHeap.insert(new Item(name, category, price));
                clearScreen();
                break;
            }
            case 2:{
                clearScreen();
                cout << "\nEnter file name: ";
                string file;
                cin >> file;
                readItemsFromFile(file, &minHeap);
                break;
            }
            case 3: {//remove
                clearScreen();
                cout << "\nRemoving Top...";
                minHeap.removeTop();
                // Your Max Heap remove function
                clearScreen();
                break;
            }
            case 4: {//display
                clearScreen();
                cout << "\nTop Item:\n";
                minHeap.getTop()->print();
                break;
            }
            case 5: {//heapsort
                clearScreen();
                cout << "\nHeap Sort (in ascending order):\n";
                Heap* sortedHeap = HeapSort(&minHeap);
                sortedHeap->display();
                break;
            }

            case 0:
                clearScreen();
                cout << "Exiting Min Heap menu" << endl;
                break;
            default:
                clearScreen();
                cout << "Wrong choice, please choose from the menu" << endl;
        }
    } while (choice != 0);
}
int main() {   
    cout << "Choose a non-linear data structure..\n";
    cout << "1. Binary Search Tree\n";
    cout << "2. AVL Tree\n";
    cout << "4. Max Heap\n";
    cout << "5. Min Heap\n";
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
        case 4:
            maxHeapMenu();
            break;
        case 5:
            minHeapMenu();
            break;
        default:
            cout << "Invalid type\n";
    }

}
