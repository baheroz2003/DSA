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


    
