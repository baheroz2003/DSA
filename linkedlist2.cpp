#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
    Node(int val) {
        data = val;
        prev = nullptr;
        next = nullptr;
    }
};

Node* convertToDLL(vector<int>& arr) {
    if (arr.empty()) return nullptr;
    Node* head = new Node(arr[0]);
    Node* mover = head;
    for (int i = 1; i < arr.size(); i++) {
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        temp->prev = mover;
        mover = temp;
    }
    return head;
}

void printDLL(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " <-> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int lengthDLL(Node* head) {
    int count = 0;
    Node* temp = head;
    while (temp != nullptr) {
        count++;
        temp = temp->next;
    }
    return count;
}

bool searchDLL(Node* head, int key) {
    Node* temp = head;
    while (temp != nullptr) {
        if (temp->data == key) return true;
        temp = temp->next;
    }
    return false;
}

Node* deleteHead(Node* head) {
    if (head == nullptr) return nullptr;
    Node* temp = head;
    head = head->next;
    if (head) head->prev = nullptr;
    delete temp;
    return head;
}

Node* deleteTail(Node* head) {
    if (head == nullptr) return nullptr;
    if (head->next == nullptr) {
        delete head;
        return nullptr;
    }
    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->prev->next = nullptr;
    delete temp;
    return head;
}

Node* deleteByValue(Node* head, int key) {
    if (head == nullptr) return nullptr;
    if (head->data == key) {
        Node* temp = head;
        head = head->next;
        if (head) head->prev = nullptr;
        delete temp;
        return head;
    }
    Node* temp = head;
    while (temp != nullptr && temp->data != key) {
        temp = temp->next;
    }
    if (temp == nullptr) return head;
    temp->prev->next = temp->next;
    if (temp->next) temp->next->prev = temp->prev;
    delete temp;
    return head;
}

int main() {
    vector<int> arr = {10, 20, 30, 40, 50};
    Node* head = convertToDLL(arr);

    cout << "Original DLL: ";
    printDLL(head);

    cout << "Length of DLL: " << lengthDLL(head) << endl;

    int key = 30;
    cout << "Searching " << key << ": " 
         << (searchDLL(head, key) ? "Found ✅" : "Not Found ❌") 
         << endl;

    head = deleteHead(head);
    cout << "After deleting head: ";
    printDLL(head);

    head = deleteByValue(head, 40);
    cout << "After deleting 40: ";
    printDLL(head);

    head = deleteTail(head);
    cout << "After deleting tail: ";
    printDLL(head);

    return 0;
}
