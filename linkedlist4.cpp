#reverse linkedlist using iteration
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev=nullptr;
        ListNode* temp=head;
        while(temp)
        {
            ListNode* curr=temp->next;
            temp->next=prev;
            prev=temp;
            temp=curr;     
        }
       return prev; 
    }
};
#reverse linkedlist using recursion
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        //edge case only one node
        if(!head || !head->next)
        {
            return head;
        }
        ListNode *newHead=reverseList(head->next);
        head->next->next=head;
        head->next=nullptr;
        return newHead;
    }
};
#middle of the linked list
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast!=nullptr && fast->next!=nullptr)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
       return slow; 
    }
};
#starting point of linkedlist
Node* getStartingNode(Node* head){
    if(!head)return NULL;
    Node* slow=head;
    Node* fast=head;
    while(fast && fast->next){
    slow=slow->next;
    fast=fast->next->next;
    if(slow==fast){
    Node* slow=head;
    while(slow!=fast){
    slow=slow->next;
    fast=fast->next;
    }
return slow;
    }
#remove the loops
if(!head)return NULL;
Node* startofloop=getStartingNode(head);
Node* temp=startOfLoop;
while(temp->next!=startofLoop){
temp=temp->next;
}
temp->next=NULL;
return head; 
#remove duplicates from the sorted list
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head)return NULL;
        ListNode* curr=head;
        while(curr!=NULL){
            if((curr->next!=nullptr) &&curr->val==curr->next->val){
                ListNode* next=curr->next->next;
                ListNode* to_del=curr->next;
                delete(to_del);
                curr->next=next;
            }
            else{
                curr=curr->next;
            }
        }
        return head; 
    }
};
#remove duplicated from unsorted list
#method-1:
class Solution {
  public:
    Node *removeDuplicates(Node *head) {
    if (!head) return nullptr;
    unordered_set<int> st;
    Node* temp = head;
    Node* prev = nullptr;
    while (temp != nullptr) {
        if (!st.count(temp->data)) {
             st.insert(temp->data);
            prev = temp;
            temp = temp->next;
        } else {
            prev->next = temp->next;
            Node* toDelete = temp;
            temp = temp->next;
            delete toDelete;
        }
    }
    return head;
    }
};
#method-2
class Solution {
  public:
    Node *removeDuplicates(Node *head) {
     if(!head)return NULL;
        Node* curr=head;
        while(curr->next!=NULL){
            Node* temp=curr;
            while(temp->next){
            if(curr->data==temp->next->data){
                Node* next=temp->next->next;
                Node* to_del=temp->next;
                delete(to_del);
                temp->next=next;
            }
            else{
                temp=temp->next;
            }
            }
            curr=curr->next;
            
        }
        return head; 
    }
};
#reverse in k groups
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head) return nullptr;
        
        ListNode* temp = head;
        int count = 0;
        while (temp && count < k) {
            temp = temp->next;
            count++;
        }
        if (count < k) return head;

        ListNode* prev = nullptr;
        ListNode* current = head;
        ListNode* next = nullptr;
        int cnt = 0;

        while (current && cnt < k) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
            cnt++;
        }

        if (next) {
            head->next = reverseKGroup(next, k);
        }

        return prev;
    }
};

    
