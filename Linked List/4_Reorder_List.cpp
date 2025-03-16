 //Definition for singly-linked list.
 struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

class Solution {
public:
    ListNode* findMiddle(ListNode *head){
        ListNode *slow = head, *fast = head, *prev = nullptr;
        while (fast && fast->next) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        if (prev) prev->next = nullptr; 
        return slow;
    }

    ListNode* reverseList(ListNode *head){
        ListNode *curr = head, *prev = nullptr;
        while(curr){
            ListNode *temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }
    void reorderList(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return;
        ListNode *l1 = head;
        ListNode *l2 = findMiddle(head);
        l2 = reverseList(l2);
        while(l1->next){
            ListNode *temp1 = l1->next;
            ListNode *temp2 = l2->next;
            l1->next = l2;
            l2->next = temp1;
            l1 = temp1;
            l2 = temp2;
        }
        l1->next = l2;
    }
};
    