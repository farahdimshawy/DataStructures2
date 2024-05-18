//
// Created by farah on 14/05/2024.
//

#ifndef DATASTRUCTURES2_ITEM_H
#define DATASTRUCTURES2_ITEM_H

#include <string>
#include <iostream>
#include <utility>
using namespace std;

class Item {
public:
    string itemName;
    string category;
    double price;

    Item(){
        itemName = "Item";
        category = "category";
        price = 0;
    }
    Item(string name, string cat, double p) : itemName(std::move(name)), category(std::move(cat)), price(p) {}

    bool operator<(const Item& otherItem) const {
        return this->itemName < otherItem.itemName;
    }
    bool operator>=(const Item& otherItem) const{
        return this->itemName >= otherItem.itemName;
    }

    void print() const {
        cout << "\nItem: " << itemName << "\nCategory: " << category << "\nPrice: " << price << endl;
    }
};



#endif //DATASTRUCTURES2_ITEM_H
