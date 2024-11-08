#pragma once
#include <string>
#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;



struct Node {
    int data;
    Node* nextPtr;
    int ID;
};
template<typename Item_Type>
class SingleLinkList {
private:
	Node* headPtr;
	Node* tailPtr;
	int NumOfIndexs = -1;
public:
    SingleLinkList() {
        headPtr = nullptr;
        tailPtr = nullptr;
    }
    SingleLinkList(Item_Type d) {
        Node* tempPtr = new Node;
        tempPtr->data = d;
        tempPtr->nextPtr = nullptr;
        tempPtr->ID = NumOfIndexs + 1;
        headPtr = tempPtr;
        tailPtr = tempPtr;
        NumOfIndexs++;
    }
    SingleLinkList(vector<Item_Type> d) {
        headPtr = nullptr;
        tailPtr = nullptr;
        for (int i = 0; i < d.size(); i++) {
            push_back(d[i]);
        }
    }

    Item_Type getData(int id) {
        Node* tempPtr = headPtr;
        while (tempPtr->ID != id) {
            tempPtr = tempPtr->nextPtr;
        }
        return tempPtr->data;
    }

    Node* getNode(int id) {
        Node* tempPtr = headPtr;
        while (tempPtr->ID != id) {
            tempPtr = tempPtr->nextPtr;
        }
        return tempPtr;
    }

    Node* front() {
        return headPtr;
    }

    Node* back() {
        return tailPtr;

    }

    bool empty() {
        if (headPtr == nullptr) {
            return true;
        }
        return false;
    }

    int size() {
        return NumOfIndexs + 1;
    }

    int find(Item_Type d) {

        Node* tempPtr = headPtr;
        while (tempPtr->data != d) {
            if (tempPtr == nullptr) {
                return size();
            }
            tempPtr = tempPtr->nextPtr;
        }

        return tempPtr->ID;
    }

    void  printNode(int id) {
        Node* tempPtr = headPtr;
        while (tempPtr->ID != id) {
            tempPtr = tempPtr->nextPtr;
        }
        cout << tempPtr->data << " -> " << tempPtr->nextPtr->data;
    }

    void  push_back(Item_Type d) {
        // create a new node and putting in the data
        Node* newNode = new Node;
        newNode->data = d;
        newNode->nextPtr = nullptr;
        newNode->ID = NumOfIndexs + 1;

        // if list is empty, the new node is top of list
        if (headPtr == nullptr) {
            headPtr = newNode;
            tailPtr = newNode;
        }

        else {
            Node* tempPtr = headPtr;
            while (tempPtr != nullptr && tempPtr->nextPtr != nullptr) {
                tempPtr = tempPtr->nextPtr;
            }
            //adjust the pointers
            newNode->nextPtr = tempPtr->nextPtr;
            tempPtr->nextPtr = newNode;
            tailPtr = newNode;
        }
        NumOfIndexs++;
    }

    void  push_front(Item_Type d) {
        // create a new node and putting in the data
        Node* newNode = new Node;
        newNode->data = d;
        newNode->nextPtr = nullptr;
        newNode->ID = -1;

        // if list is empty, the new node is top of list
        if (headPtr == nullptr) {
            headPtr = newNode;
            tailPtr = newNode;
        }
        else {
            Node* tempPtr = headPtr;
            //adjust the pointers
            newNode->nextPtr = tempPtr;
            headPtr = newNode;
        }
        NumOfIndexs++;
        Node* tempPtr = headPtr;
        while (tempPtr != nullptr) {
            tempPtr->ID++;
            tempPtr = tempPtr->nextPtr;
        }
    }

    bool  pop_back() {
        if (headPtr == nullptr) {
            return false;
        }
        Node* delNode = tailPtr;
        Node* tempPtr = headPtr;
        while (tempPtr->nextPtr != tailPtr) {
            tempPtr = tempPtr->nextPtr;
        }
        tailPtr = tempPtr;
        tempPtr->nextPtr = nullptr;
        delete delNode;
        delNode = nullptr;
        NumOfIndexs--;
        return true;
    }

    bool  pop_front() {
        if (headPtr == nullptr) {
            return false;
        }
        Node* delNode = headPtr;
        headPtr = headPtr->nextPtr;
        delete delNode;
        delNode = nullptr;
        NumOfIndexs--;
        Node* tempPtr = headPtr;
        while (tempPtr != nullptr) {
            tempPtr->ID--;
            tempPtr = tempPtr->nextPtr;
        }
        return true;
    }

    void  insert(int id, Item_Type d) {
        if (headPtr == nullptr) {
            push_back(d);
            return;
        }

        Node* tempPtr = headPtr;
        while (tempPtr->ID != id - 1) {
            tempPtr = tempPtr->nextPtr;
        }

        Node* newNode = new Node;
        newNode->data = d;
        newNode->nextPtr = tempPtr->nextPtr;
        newNode->ID = id;
        tempPtr->nextPtr = newNode;

        tempPtr = tempPtr->nextPtr->nextPtr;
        while (tempPtr != nullptr) {
            tempPtr->ID++;
            tempPtr = tempPtr->nextPtr;
        }
        NumOfIndexs++;

    }

    bool  remove(int id) {
        if (headPtr == nullptr) {
            return false;
        }

        if (id > NumOfIndexs) { return false; }

        if (headPtr->ID == id) {
            Node* delNode = headPtr;
            headPtr = headPtr->nextPtr;
            delete delNode;
            delNode = nullptr;
            NumOfIndexs--;
            Node* tempPtr = headPtr;
            while (tempPtr != nullptr) {
                tempPtr->ID--;
                tempPtr = tempPtr->nextPtr;
            }
            return true;
        }

        Node* tempPtr = headPtr;
        while (tempPtr != nullptr) {
            if (tempPtr->nextPtr->ID == id) {
                if (id == NumOfIndexs) {
                    tailPtr = tempPtr;
                }
                Node* delNode = tempPtr->nextPtr;
                tempPtr->nextPtr = tempPtr->nextPtr->nextPtr;
                delete delNode;
                delNode = nullptr;
                NumOfIndexs--;
                tempPtr = tempPtr->nextPtr;
                while (tempPtr != nullptr) {
                    tempPtr->ID--;
                    tempPtr = tempPtr->nextPtr;
                }
                return true;
            }
            tempPtr = tempPtr->nextPtr;
        }
        return false;
    }




    void  printList() {
        Node* tempPtr = headPtr;
        while (tempPtr != nullptr) {
            cout << "(" + to_string(tempPtr->data) + ", " << tempPtr->ID << ") -> ";
            tempPtr = tempPtr->nextPtr;
        }
        cout << "null" << endl;
    }
};



