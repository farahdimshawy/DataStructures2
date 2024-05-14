#include <iostream>
#include <string>
#include "Heap.h"
#include "Item.h"

int main() {
    // Example usage
    Comparator Comparator = [](const Item& a, const Item& b) {
        return a.price > b.price;
    };

    MaxHeap maxHeap(Comparator);

    // Insert items
    readItemsFromFile("items.txt", &maxHeap);

    // Set comparator dynamically based on user choice
    // Get and print max item
    cout << "Max item according to price: ";
    maxHeap.getTop()->print();

    MinHeap minHeap(Comparator);
    readItemsFromFile("items.txt", &minHeap);

    cout << "Min item according to price: ";
    minHeap.getTop()->print();

    HeapSort(&minHeap);
    // Print the sorted heap
    cout << "\nSorted Heap:" << endl;
    while (minHeap.getTop()) {
        minHeap.getTop()->print();
        minHeap.removeTop();
    }
    return 0;
}
