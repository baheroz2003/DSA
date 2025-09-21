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
