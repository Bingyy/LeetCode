#include "lib.h"
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL){}
                                   
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *head = new ListNode(0);
        ListNode *cur = head;
        // ListNode *p = l1, *q = l2;
        int carry = 0;
        // 自己处理进位
        while(l1 || l2) {
            // 如果一个为空了，就设置为0，这样无需再写两个循环
            int x = l1 ? l1->val : 0;
            int y = l2 ? l2->val : 0;
            
            int sum = carry + x + y;
            
            carry = sum / 10;
            cur->next = new ListNode(sum % 10);
            cur = cur->next;
            
            if(l1) {
                l1 = l1->next;
            } 
            
            if(l2) {
                l2 = l2->next;
            }      
        }
        
        if(carry > 0) {
            // 处理最后的进位
            cur->next = new ListNode(carry);
        }
        return head->next;
    }
    
};
