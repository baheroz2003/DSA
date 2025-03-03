#include <bits/stdc++.h>
using namespace std;
//24 dec 2023 6:40pm downers at dusk

class node{
    public:
    int data;
    node* next;

    //constructor
    node(int data, node* next){
        this->data = data;
        this->next = next;
    }
    node(int data){
        this->data = data;
        this->next = nullptr;
    }
};

node* arrToLL(vector<int>& arr){

    node* head = new node(arr[0]);
    node* mover = head;

    for(int i=1 ; i<arr.size() ; i++){
        node* temp = new node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}

int lengthOfLL(node* head){
    int count=0;
    node* temp = head;

    while(temp){
        count++;
        temp = temp->next;
    }
    return count;
}

bool isPresent(node* head, int key){
    node* temp = head;
    while(temp){
        if(temp->data == key) return 1;
        temp = temp->next;
    }
    return 0;
}

void printLinky(node* head){
    node* temp = head;

    while(temp != NULL){
        cout << temp->data << ' ';
        temp = temp->next;
    }
    cout << endl;
}

node* deleteHead(node* head){

    //edge case
    if(head == NULL || head->next == NULL) return NULL;

    node* temp = head;
    head = head->next;
    delete temp;
    return head;
}

void deleteTail(node* head){

    //edge case
    if(head == NULL || head->next == NULL) delete head;

    node* temp = head;
    while(temp->next->next){
        temp = temp->next;
    }
    delete temp->next;
    temp->next = NULL;
}

node* deleteIndex(node* head, int k){

    //edge case
    if(head == NULL) return head;
    if(k==1){
        node* temp = head;
        head = head->next;
        delete temp;
        return head;
    }

    node* temp = head;
    node* prev = NULL;
    int count = 1;

    while(temp){
        if(count == k){
            prev->next = temp->next;
            delete temp;
            break;
        }
        count++;
        prev = temp;
        temp = temp->next;
    }
    return head;
}

node* deleteElement(node* head, int val){

    //edge case
    if(head == NULL) return head;
    if(head->data == val){
        node* temp = head;
        head = head->next;
        delete temp;
        return head;
    }

    node* temp = head;
    node* prev = NULL;

    while(temp){
        if(temp->data == val){
            prev->next = temp->next;
            delete temp;
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    return head;
}

node* insertHead(node* head, int el){
    node* temp = new node(el, head);
    return temp;
}

node* insertTail(node* head, int el){

    //edge case
    if(head == NULL) return new node(el);

    node* tail = new node(el);
    node* temp = head;
    while(temp->next){
        temp = temp->next;
    }
    temp->next = tail;
    return head;
}

node* insertAtIndex(node* head, int el, int k){

    //edge case
    if(head == NULL){
        if(k==1) return new node(el);
        else return NULL;
    }
    if(k==1){
        return new node(el, head);
    }

    node* temp = head;
    int count = 1;

    while(temp){
        if(count == k-1){
            node* x = new node(el, temp->next); 
            temp->next = x;  
            break;
        }
        temp = temp->next;
        count ++;
    }
    return head;
}

node* insertBeforeValue(node* head, int el, int val){

    //edge case
    if(head == NULL) return NULL;
    if(head->data == val){
        return new node(el, head);
    }

    node* temp = head;
    while(temp->next){
        if(temp->next->data == val){
            node* x = new node(el, temp->next); 
            temp->next = x;  
            break;
        }
        temp = temp->next;
    }
    return head;
}

//Function to remove a loop in the linked list.
    void removeLoop(node* head) {
        node* tort = head;
        node* hare = head;
    
        while(hare && hare->next){
            tort = tort->next;
            hare = hare->next->next;
            
            if(tort == hare){
                tort = head;
                while(tort != hare){
                    tort = tort->next;
                    hare = hare->next;
                }
                
                while(hare->next != tort){
                    hare = hare->next;
                }
                hare->next = NULL;
            }
        }
    }

int main(){
    //we refer about head when talking about LL
    vector<int> arr = {2,5,4,8,9,1,6,7,3};
    node* head = arrToLL(arr);

    //traverse through Linky
    printLinky(head);

    int size = lengthOfLL(head);
    cout << "size of linky is :" << size << endl;

    cout << head << endl;

    //search an element in the Linky
    /*
    if(isPresent(head, 8)) cout << "element is present" << endl;
    else  cout << "element is not present" << endl;
    */

    //delete head
    head = deleteHead(head);
    printLinky(head);
    
    //delete tail
    deleteTail(head);
    printLinky(head);

    //delete Kth element
    //1 indexing followed
    head = deleteIndex(head, 3);
    printLinky(head);

    //delete given element
    head = deleteElement(head, 1);
    printLinky(head);

    //insert at head
    head = insertHead(head, 23);
    printLinky(head);

    //insert at tail
    head = insertTail(head, 34);
    printLinky(head);

    //insert at kth index
    //1 indexing followed
    head = insertAtIndex(head, 56, 4);
    printLinky(head);

    //insert before the given value
    head = insertBeforeValue(head, 67, 34);
    printLinky(head);

    /*
    node x= node(arr[0]);
    cout << x.data << endl;
    cout << x.next << endl;

    cout << "pehle static ab dynamic" << endl;

    node* y= new node(arr[1], nullptr);
    cout << y << endl;
    cout << y->data << endl;
    cout << y->next << endl;
    */
}