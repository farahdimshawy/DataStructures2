#include <iostream>
#include <string>
#include "Heap.h"
#include "Item.h"

int main() {
    // Example usage
    Comparator maxComparator = [](const Item& a, const Item& b) {
        return a.itemName > b.itemName;
    };
    Comparator minComparator = [](const Item& a, const Item& b) {
        return a.itemName < b.itemName;
    };

    MaxHeap maxHeap(maxComparator);

    // Insert items
    readItemsFromFile("items.txt", &maxHeap);

    // Set comparator dynamically based on user choice
    // Get and print max item
    cout << "Max item according to name: ";
    maxHeap.getTop()->print();

    MinHeap minHeap(minComparator);
    readItemsFromFile("items.txt", &minHeap);

    cout << "Min item according to name: ";
    minHeap.getTop()->print();

    //HeapSort(&minHeap);
    // Print the sorted heap
    //cout << "\nSorted Heap:" << endl;
    minHeap.display();
    return 0;
}
