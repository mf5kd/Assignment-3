// Assignment 3.cpp : This file contains the 'main' function. Program execution begins and ends there.


#include <iostream>
#include <fstream>
#include <vector>
#include "SingleLinkList.h"
#include "Queues.h"
#include "func.h"

using namespace std;
using namespace CQ;

int main() {
    vector<int> items = { 1, 2, 3, 4, 3, 5, 3 };
    vector<int> data = { 5, 3, 6, 7, 9, 1, 2, 4, 8, 0 };
    Queue<int> queue;
    SingleLinkList<int> list(data);

    print("Q1---------------------------------------");
    print();
    for (int x = 1; x <= 10; x++) {
        queue.push(x);
    }
    for (int x = 1; x <= 10; x++) {
        print(to_string(queue.front()) + " ");
        queue.pop();
    }
    for (int x = 1; x <= 10; x++) {
        queue.push(x);
    }
    queue.move_to_rear();
    print();
    for (int x = 1; x <= 10; x++) {
        print(to_string(queue.front()) + " ");
        queue.pop();
    }
    print();

    print("Q2----------------------------------------");
    print();
    int target = 3;
    int pos = linear_search(items, target, items.size() - 1);

    if (pos != -1) {
        std::cout << "Last occurrence of " << target << " is at index " << pos << std::endl;
    }
    else {
        std::cout << target << " not found in the vector." << std::endl;
    }
    print();
    
    print("Q3----------------------------------------");
    print();
    list.printList();
    insertion_sort(list);
    list.printList();
    

}