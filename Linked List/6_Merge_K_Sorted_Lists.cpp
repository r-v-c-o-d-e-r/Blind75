
 #include<queue>
#include<vector>
using namespace std;
 
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode *head = new ListNode(-1);
        ListNode *curr = head;
        priority_queue<pair<int, ListNode*>, vector<pair<int,ListNode*>>,
        greater<pair<int,ListNode*>>>pq;

        for(int i=0; i<lists.size(); i++){
            if(lists[i])
                pq.push({lists[i]->val, lists[i]});
        }

        while(!pq.empty()){
            auto[value, node] = pq.top();
            pq.pop();

            curr->next = node;
            curr = node;

            if(node->next)
            pq.push({node->next->val, node->next});
        }

        return head->next;
    }
};
    