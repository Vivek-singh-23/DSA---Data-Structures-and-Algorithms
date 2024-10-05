#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list node
template <typename T>
class Node {
public:
    T data;
    Node* next;

    Node(T val) {
        data = val;
        next = nullptr;
    }
};

// Custom comparator class
class compare {
public:
    bool operator()(Node<int>* a, Node<int>* b) {
        return a->data > b->data;
    }
};

// Function to merge k sorted linked lists
Node<int>* mergeKLists(vector<Node<int>*>& listArrays) {
    // Priority queue with custom comparator
    priority_queue<Node<int>*, vector<Node<int>*>, compare> pq;

    int k = listArrays.size();

    if (k == 0) {
        return nullptr;
    }

    // Push the head of each list into the priority queue
    for (int i = 0; i < k; i++) {
        if (listArrays[i] != nullptr) {
            pq.push(listArrays[i]);
        }
    }

    Node<int>* head = nullptr;
    Node<int>* tail = nullptr;

    // Process the priority queue
    while (!pq.empty()) {
        Node<int>* top = pq.top();
        pq.pop();

        if (top->next != nullptr) {
            pq.push(top->next);
        }

        if (head == nullptr) {
            head = top;
            tail = top;
        } else {
            tail->next = top;
            tail = top;
        }
    }

    return head;
}

// Helper function to print the linked list
template <typename T>
void printList(Node<T>* node) {
    while (node != nullptr) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

// Main function to test the mergeKLists function
int main() {
    // Create sample linked lists
    Node<int>* list1 = new Node<int>(1);
    list1->next = new Node<int>(4);
    list1->next->next = new Node<int>(5);

    Node<int>* list2 = new Node<int>(1);
    list2->next = new Node<int>(3);
    list2->next->next = new Node<int>(4);

    Node<int>* list3 = new Node<int>(2);
    list3->next = new Node<int>(6);

    vector<Node<int>*> listArrays = {list1, list2, list3};

    // Merge the k sorted linked lists
    Node<int>* mergedList = mergeKLists(listArrays);

    // Print the merged linked list
    printList(mergedList);

    return 0;
}
