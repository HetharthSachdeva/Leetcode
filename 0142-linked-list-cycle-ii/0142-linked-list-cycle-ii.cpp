/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* ptr = head;
        int ind = 0;
        map<ListNode*,int> m;
        while(ptr != NULL){
            if(m.find(ptr)!=m.end()){
                return ptr;
            }
            m[ptr] = ind;
            ptr = ptr->next;
            ind++;

        }
        return NULL;
    }
};