//
// Created by farah on 14/05/2024.
//

#ifndef DATASTRUCTURES2_HEAP_H
#define DATASTRUCTURES2_HEAP_H
#include <utility>
#include <fstream>
#include <sstream>
#include <vector>
#include <functional>
#include "Item.h"
class HeapNode{
public:
    Item* item;

    explicit HeapNode(Item* item) : item(item) {}
};

using Comparator = function<bool(const Item&, const Item&)>;

class Heap {
protected:
    vector<HeapNode*> heap;
    Comparator comparator;

    virtual void heapifyUp(int index) = 0;
    virtual void heapifyDown(int index) = 0;

public:
    Heap(Comparator comp) : comparator(std::move(comp)) {}

    void insert(Item* item) {
        int i = heap.size();
        heap.emplace_back(new HeapNode(item));
        HeapNode* temp = heap[i]; // Store the newly inserted node

        while (i > 0 && comparator(*temp->item, *heap[(i - 1) / 2]->item)) {
            heap[i] = heap[(i - 1) / 2]; // Move parent down
            i = (i - 1) / 2; // Move to the parent index
        }

        heap[i] = temp;
    }

    Item* getTop() {
        if (heap.empty()) return nullptr;
        return heap[0]->item;
    }

    virtual void removeTop() {
        if (heap.empty()) return;
        delete heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);
    }

    virtual ~Heap() {
        for (auto node : heap) {
            delete node;
        }
    }
    void display(){
        while (getTop()) {
            getTop()->print();
            removeTop();
        }
    }
    friend Heap* AscHeapSort(Heap* heap);
    friend Heap* DescHeapSort(Heap* heap);
};



class MaxHeap : public Heap {
private:
    void heapifyUp(int index) override {
        int parent = (index - 1) / 2;
        while (index > 0) {
            if (comparator(*heap[index]->item, *heap[parent]->item)) {
                swap(heap[index], heap[parent]);
                index = parent;
            } else {
                break; // Stop if the parent is smaller
            }
        }
    }

    void heapifyDown(int index) override {
        int leftChild = 2 * index + 1;
        int rightChild = 2 * index + 2;
        int largest = index;

        if (leftChild < heap.size() && comparator(*heap[leftChild]->item, *heap[largest]->item)) {
            largest = leftChild;
        }
        if (rightChild < heap.size() && comparator(*heap[rightChild]->item, *heap[largest]->item)) {
            largest = rightChild;
        }

        if (largest != index) {
            swap(heap[index], heap[largest]);
            heapifyDown(largest);
        }
    }

public:
    MaxHeap(Comparator comp) : Heap(comp) {}
};

// MinHeap class derived from Heap
class MinHeap : public Heap {
private:
    void heapifyUp(int index) override {
        while (index > 0) {
            int parent = (index - 1) / 2;
            // Swap if the parent is greater than the current node
            if (comparator(*heap[index]->item, *heap[parent]->item)) {
                swap(heap[index], heap[parent]);
                index = parent;
            } else {
                break; // Stop if the parent is smaller
            }
        }
    }
    void heapifyDown(int index) override {
        int leftChild = 2 * index + 1;
        int rightChild = 2 * index + 2;
        int smallest = index;

        if (leftChild < heap.size() && comparator(*heap[leftChild]->item, *heap[smallest]->item)) {
            smallest = leftChild;
        }
        //if right child is smaller than the smallest, make smallest = right child
        if (rightChild < heap.size() && comparator(*heap[rightChild]->item, *heap[smallest]->item)) {
            smallest = rightChild;
        }

        if (smallest != index) {
            swap(heap[index], heap[smallest]);
            heapifyDown(smallest);
        }
    }


public:
    MinHeap(Comparator comp) : Heap(comp) {}
};

void readItemsFromFile(const string& filename, Heap* heap) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error: Unable to open file: " << filename << endl;
        return;
    }

    string line;
    string name, category;
    int price;

    while (getline(file, line)) {
        name = line;

        // Read category
        getline(file, category);

        // Read price
        file >> price;
        file.ignore(); // Consume newline

        // Create Item object and insert into heap
        heap->insert(new Item(name, category, price));
    }

    file.close();
}

Heap* AscHeapSort(Heap *heap) {
    // Perform heap sort directly on the provided heap
    Heap *sortedheap = new MinHeap(heap->comparator);
    // Perform heap sort
    int n = heap->heap.size()-1;

    for (int i = n; i >= 0; --i) {
        HeapNode root = HeapNode(heap->getTop());
        heap->removeTop();
        sortedheap->insert(root.item);
    }
    return sortedheap;
}


Heap* DescHeapSort(Heap *heap) {
    // Perform heap sort directly on the provided heap
    Heap *sortedheap = new MaxHeap(heap->comparator);
    // Perform heap sort
    int n = heap->heap.size()-1;

    for (int i = n; i >= 0; --i) {
        HeapNode root = HeapNode(heap->getTop());
        heap->removeTop();
        sortedheap->insert(root.item);
    }
    return sortedheap;
}

#endif //DATASTRUCTURES2_HEAP_H
