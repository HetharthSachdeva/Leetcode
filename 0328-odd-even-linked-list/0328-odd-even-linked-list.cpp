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
    ListNode* oddEvenList(ListNode* head) {
        ListNode* ptr1 = head;
        if(ptr1==NULL) return head;
        ListNode* ptr2 = head->next;
        if(ptr2==NULL) return head;
        ListNode* ans = new ListNode();
        ListNode* ptr = ans;
        while(ptr1!=NULL){
            ptr->val = ptr1->val;
            ptr->next = new ListNode();
            ptr = ptr->next;
            if(ptr1->next==NULL) break;
            
           
            ptr1 = ptr1->next->next;
        }
        while(ptr2!=NULL){
            ptr->val = ptr2->val;
            if(ptr2->next==NULL || ptr2->next->next == NULL) break;
            ptr->next = new ListNode();
            ptr = ptr->next;
            ptr2 = ptr2->next->next;
        }


        return ans;
        
    }
};