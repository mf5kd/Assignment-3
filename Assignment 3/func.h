#pragma once
#include <iostream>
#include <iomanip>
#include <vector>
#include <typeinfo>
#include <type_traits>
#include "SingleLinkList.h"

using namespace std;

void print(string input = "") {
	cout << input << endl;
}
void print(int input) {
	cout << input << endl;
}

template<typename Item_Type>
int linear_search(vector<Item_Type>& items, Item_Type& target, size_t pos) {
	// Base case: if position is out of range, target not found
	if (pos < 0)
		return -1;

	// Check if current position has the target
	if (items[pos] == target)
		return pos;

	// Recursive call to check the previous position
	return linear_search(items, target, pos - 1);
}


void insertion_sort(SingleLinkList<int>& list) {
    int i, j;
    bool insertionNeeded = false;

    for (j = 1; j < list.size(); j++) {
        int key = list.getData(j);  // get key from position j
        insertionNeeded = false;

        for (i = j - 1; i >= 0; i--) {  // move elements greater than key right
            if (key < list.getData(i)) {
                // Move data at i to i+1
                list.getNode(i + 1)->data = list.getData(i);
                insertionNeeded = true;
            }
            else {
                break;
            }
        }

        if (insertionNeeded) {
            // Place key into its correct position
            list.getNode(i + 1)->data = key;
        }
    }
}




template<typename Item_Type>
void printVector(vector<Item_Type> data) {
	for (int x = 0; x < data.size(); x++) {
		print(to_string(data[x]));
	}
}