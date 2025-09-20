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

Node* insertHead(Node* head, int val) {
    Node* newNode = new Node(val);
    if (head != nullptr) {
        newNode->next = head;
        head->prev = newNode;
    }
    return newNode;
}

Node* insertTail(Node* head, int val) {
    Node* newNode = new Node(val);
    if (head == nullptr) return newNode;
    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
    return head;
}

Node* insertAtPosition(Node* head, int pos, int val) {
    if (pos <= 1 || head == nullptr) {
        return insertHead(head, val);
    }
    Node* temp = head;
    int count = 1;
    while (temp != nullptr && count < pos - 1) {
        temp = temp->next;
        count++;
    }
    if (temp == nullptr || temp->next == nullptr) {
        return insertTail(head, val);
    }
    Node* newNode = new Node(val);
    newNode->next = temp->next;
    newNode->prev = temp;
    temp->next->prev = newNode;
    temp->next = newNode;
    return head;
}

Node* insertBeforeValue(Node* head, int target, int val) {
    if (head == nullptr) return nullptr;
    if (head->data == target) {
        return insertHead(head, val);
    }
    Node* temp = head;
    while (temp != nullptr && temp->data != target) {
        temp = temp->next;
    }
    if (temp == nullptr) return head;
    Node* newNode = new Node(val);
    newNode->prev = temp->prev;
    newNode->next = temp;
    temp->prev->next = newNode;
    temp->prev = newNode;
    return head;
}

Node* deleteHead(Node* head) {
    if (head == nullptr) return nullptr;
    Node* temp = head;
    head = head->next;
    if (head != nullptr) head->prev = nullptr;
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
        return deleteHead(head);
    }
    Node* temp = head;
    while (temp != nullptr && temp->data != key) {
        temp = temp->next;
    }
    if (temp == nullptr) return head;
    if (temp->next != nullptr) temp->next->prev = temp->prev;
    if (temp->prev != nullptr) temp->prev->next = temp->next;
    delete temp;
    return head;
}

Node* deleteAtPosition(Node* head, int pos) {
    if (head == nullptr) return nullptr;
    if (pos <= 1) {
        return deleteHead(head);
    }
    Node* temp = head;
    int count = 1;
    while (temp != nullptr && count < pos) {
        temp = temp->next;
        count++;
    }
    if (temp == nullptr) return head;
    if (temp->prev != nullptr) temp->prev->next = temp->next;
    if (temp->next != nullptr) temp->next->prev = temp->prev;
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
         << (searchDLL(head, key) ? "Found ✅" : "Not Found ❌") << endl;

    head = insertHead(head, 5);
    cout << "After inserting 5 at head: ";
    printDLL(head);

    head = insertTail(head, 60);
    cout << "After inserting 60 at tail: ";
    printDLL(head);

    head = insertAtPosition(head, 3, 15);
    cout << "After inserting 15 at position 3: ";
    printDLL(head);

    head = insertBeforeValue(head, 40, 35);
    cout << "After inserting 35 before 40: ";
    printDLL(head);

    head = deleteHead(head);
    cout << "After deleting head: ";
    printDLL(head);

    head = deleteByValue(head, 20);
    cout << "After deleting value 20: ";
    printDLL(head);

    head = deleteTail(head);
    cout << "After deleting tail: ";
    printDLL(head);

    head = deleteAtPosition(head, 3);
    cout << "After deleting node at position 3: ";
    printDLL(head);

    return 0;
}
