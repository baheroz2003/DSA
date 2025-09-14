#include <bits/stdc++.h>
using namespace std;
struct Node {
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = nullptr;
    }
};
Node* convertToLL(vector<int>& arr) {
    if (arr.empty()) return nullptr;
    Node* head = new Node(arr[0]);
    Node* mover = head;
    for (int i = 1; i < arr.size(); i++) {
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}

void printLL(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int lengthLL(Node* head) {
    int count = 0;
    Node* temp = head;
    while (temp != nullptr) {
        count++;
        temp = temp->next;
    }
    return count;
}

bool searchLL(Node* head, int key) {
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
    delete temp;
    return head;
}

Node* deleteByValue(Node* head, int key) {
    if (head == nullptr) return nullptr;
    if (head->data == key) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return head;
    }
    Node* prev = nullptr;
    Node* curr = head;
    while (curr != nullptr && curr->data != key) {
        prev = curr;
        curr = curr->next;
    }
    if (curr == nullptr) return head;
    prev->next = curr->next;
    delete curr;
    return head;
}

Node* deleteTail(Node* head) {
    if (head == nullptr) return nullptr;
    if (head->next == nullptr) {
        delete head;
        return nullptr;
    }
    Node* temp = head;
    while (temp->next->next != nullptr) {
        temp = temp->next;
    }
    delete temp->next;
    temp->next = nullptr;
    return head;
}

int main() {
    vector<int> arr = {10, 20, 30, 40, 50};
    Node* head = convertToLL(arr);

    cout << "Original List: ";
    printLL(head);

    cout << "Length of LL: " << lengthLL(head) << endl;

    int key = 30;
    cout << "Searching " << key << ": " 
         << (searchLL(head, key) ? "Found ✅" : "Not Found ❌") 
         << endl;

    head = deleteHead(head);
    cout << "After deleting head: ";
    printLL(head);

    head = deleteByValue(head, 40);
    cout << "After deleting 40: ";
    printLL(head);

    head = deleteTail(head);
    cout << "After deleting tail: ";
    printLL(head);

    return 0;
}
