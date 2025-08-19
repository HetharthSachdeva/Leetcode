/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        auto cmp = [](ListNode* a, ListNode* b){ return a->val > b->val; };
        priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> pq;
        for(int i = 0; i < lists.size(); i++){
            if(lists[i]) pq.push(lists[i]);
        }
        if(pq.empty()) return NULL;
        ListNode* ans = pq.top();
        pq.pop();
        if(ans->next) pq.push(ans->next);
        ListNode* ptr=ans;

        while(!pq.empty()){
            ListNode* temp = pq.top();
            pq.pop();
            if(temp->next) pq.push(temp->next);
            ptr->next = temp;
            ptr = temp;
        }

        return ans;
    }
};