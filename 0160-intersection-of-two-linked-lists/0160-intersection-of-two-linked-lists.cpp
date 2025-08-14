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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* ptr = headA, *ptr2 = headB;
        while(ptr!=NULL && ptr2!=NULL){
            if(ptr==ptr2) return ptr;
            ptr = ptr->next;
            ptr2 = ptr2->next;
        }
        int len = 0;
        bool flag = true;
        while(ptr!=NULL){
            ptr = ptr->next;
            len++;
        }
        while(ptr2!=NULL){
            ptr2 = ptr2->next;
            len++;
            flag = false;
        }

        ptr = headA;
        ptr2 = headB;
        if(flag){
            while(len--) ptr = ptr->next;
        }
        else while(len--) ptr2 = ptr2->next;

        while(ptr){
            if(ptr==ptr2) return ptr;
            ptr=ptr->next;
            ptr2=ptr2->next;
        }
        return NULL;
    }
};