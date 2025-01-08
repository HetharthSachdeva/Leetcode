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
    ListNode* sortList(ListNode* head) {
        ListNode *ptr = head;
        vector<int> v;
        while(ptr){
            v.push_back(ptr->val);
            ptr = ptr->next;
        }
        sort(v.begin(),v.end());
        ptr = head;
        for(int i: v){
            ptr->val = i;
            ptr = ptr->next;
        }
        return head;
    }
};