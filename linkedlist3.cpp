#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int d) {
        this->data = d;
        this->next = NULL;
    }

    ~Node() {
        int value = this->data;
        if (this->next != NULL) {
            delete next;
            next = NULL;
        }
        cout << "Memory is free for node with data " << value << endl;
    }
};

// Print circular linked list
void print(Node* tail) {
    if (tail == NULL) {
        cout << "List is empty" << endl;
        return;
    }
    Node* temp = tail->next;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != tail->next);
    cout << endl;
}

// Length
int length(Node* tail) {
    if (tail == NULL) return 0;
    int cnt = 0;
    Node* temp = tail->next;
    do {
        cnt++;
        temp = temp->next;
    } while (temp != tail->next);
    return cnt;
}

// Search
bool search(Node* tail, int key) {
    if (tail == NULL) return false;
    Node* temp = tail->next;
    do {
        if (temp->data == key) return true;
        temp = temp->next;
    } while (temp != tail->next);
    return false;
}

// Insert after a given element
void insertAfter(Node* &tail, int element, int d) {
    if (tail == NULL) {
        Node* newNode = new Node(d);
        tail = newNode;
        newNode->next = newNode;
        return;
    }
    Node* curr = tail->next;
    do {
        if (curr->data == element) {
            Node* temp = new Node(d);
            temp->next = curr->next;
            curr->next = temp;
            if (curr == tail) tail = temp; // update tail if inserted after tail
            return;
        }
        curr = curr->next;
    } while (curr != tail->next);
    cout << "Element " << element << " not found\n";
}

// Insert at head
void insertHead(Node* &tail, int d) {
    insertAfter(tail, tail->next->data, d); // insert after tail->next (head)
    tail->next = tail->next; // head updated implicitly
}

// Insert at tail
void insertTail(Node* &tail, int d) {
    insertAfter(tail, tail->data, d);
}

// Delete head
void deleteHead(Node* &tail) {
    if (tail == NULL) return;
    Node* head = tail->next;
    if (head == tail) {
        delete head;
        tail = NULL;
        return;
    }
    tail->next = head->next;
    head->next = NULL;
    delete head;
}

// Delete tail
void deleteTail(Node* &tail) {
    if (tail == NULL) return;
    if (tail->next == tail) {
        delete tail;
        tail = NULL;
        return;
    }
    Node* temp = tail->next;
    while (temp->next != tail) temp = temp->next;
    temp->next = tail->next;
    delete tail;
    tail = temp;
}

// Delete by value
void deleteByValue(Node* &tail, int val) {
    if (tail == NULL) return;
    if (tail->next->data == val) {
        deleteHead(tail);
        return;
    }
    Node* temp = tail->next;
    while (temp->next != tail->next && temp->next->data != val) {
        temp = temp->next;
    }
    if (temp->next->data == val) {
        Node* del = temp->next;
        if (del == tail) tail = temp;
        temp->next = del->next;
        del->next = NULL;
        delete del;
    }
}

// Delete at position (1-based)
void deleteAtPosition(Node* &tail, int pos) {
    if (tail == NULL || pos <= 0) return;
    if (pos == 1) {
        deleteHead(tail);
        return;
    }
    Node* temp = tail->next;
    int count = 1;
    while (count < pos - 1 && temp->next != tail->next) {
        temp = temp->next;
        count++;
    }
    if (temp->next == tail->next) return; // invalid position
    Node* del = temp->next;
    if (del == tail) tail = temp;
    temp->next = del->next;
    del->next = NULL;
    delete del;
}

// ---------------- MAIN ----------------
int main() {
    Node* tail = NULL;

    insertAfter(tail, 5, 3); // first node
    print(tail);

    insertAfter(tail, 3, 5);
    print(tail);

    insertAfter(tail, 5, 7);
    print(tail);

    insertAfter(tail, 7, 9);
    print(tail);

    insertAfter(tail, 5, 6);
    print(tail);

    insertHead(tail, 1);
    cout << "After inserting 1 at head: ";
    print(tail);

    insertTail(tail, 10);
    cout << "After inserting 10 at tail: ";
    print(tail);

    cout << "Length: " << length(tail) << endl;

    cout << "Search 7: " << (search(tail, 7) ? "Found ✅" : "Not Found ❌") << endl;

    deleteHead(tail);
    cout << "After deleting head: ";
    print(tail);

    deleteTail(tail);
    cout << "After deleting tail: ";
    print(tail);

    deleteByValue(tail, 6);
    cout << "After deleting value 6: ";
    print(tail);

    deleteAtPosition(tail, 3);
    cout << "After deleting position 3: ";
    print(tail);

    return 0;
}
