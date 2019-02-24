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
    ListNode* sortList(ListNode* head) {
        if((head == 0) ||(head->next == 0))
        {
        	return head;
        }
        ListNode *a = head, *b = head;
        for(;b->next && b->next->next; b = b->next->next, a = a->next)
        ;
        b = sortList(a->next);
        a->next = 0;
        a = sortList(head);
        head = 0;

        ListNode *tail = 0;
        while(a && b)
        {
        	if(a->val < b->val)
        	{
        		if(tail)
        		{
        			tail = tail->next = a;
        		}
        		else{
        			head = tail = a;
        		}
        		a = a->next;
        	}
        	else
        	{
        		if(tail)
        		{
        			tail = tail->next = b;
        		}
        		else
        		{
        			head = tail = b;
        		}
        		b = b->next;
        	}
        }
        if(a)
        {
        	if(tail)
        	{
        		tail->next = a;
        	}
        	else{
        		head = a;
        	}
        }
        else if(tail)
        {
        	tail->next = b;
        }
        else{
        	head = b;
        }
        return head;

    }
};