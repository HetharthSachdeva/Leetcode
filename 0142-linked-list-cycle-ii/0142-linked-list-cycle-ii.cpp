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
        if(!head || !head->next) return NULL;
        ListNode* ptr1 = head, *ptr2 = head;
        while(ptr2!=NULL && ptr2->next != NULL){
            
            ptr1 = ptr1->next;
            ptr2 = ptr2->next->next;
            if(ptr1==ptr2) break;

        }
        if(!(ptr2) || !ptr2->next) return NULL;
        ptr1 = head;
        while(ptr1!=ptr2){
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        return ptr1;
    }
};