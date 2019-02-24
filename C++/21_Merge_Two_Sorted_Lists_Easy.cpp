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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *p = l1, *q = l2;
        ListNode *res = new ListNode(0); // dummy head
        ListNode *cur = res;
        
        while(p && q) {
            if(p->val > q->val) {
                ListNode *temp = new ListNode(q->val);
                cur->next = temp;
                cur = cur->next;
                q = q->next;  
            }
            else {
                ListNode *temp = new ListNode(p->val);
                cur->next = temp;
                cur = cur->next;
                p = p->next;
            }
        }
        
        if(p) {
            // 如果第一个列表还没走完
           cur->next = p; 
        }
        if(q) {
            cur->next = q;
        }
        
        return res->next;
    }
};
