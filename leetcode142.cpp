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
        // unordered_set<ListNode*> s;//用于记录访问过的结点,用的是哈希，时间为O(1)
        // for(ListNode *t = head; t;t = t->next)
        // {
        // 	if(s.find(t) != s.end()) //end指的是最后一个元素之后的迭代器
        // 	{
        // 		return t;
        // 	}
        // 	s.insert(t);
        // }

        ListNode *x = head,*y = head;
        do
        {
        	if(x == 0)
        	{
        		return 0;
        	}  	
        	x = x->next;
        	if(y == 0)
        	{
        		return 0;
        	}
        	y = y->next;
        	if(y == 0)
        	{
        		return 0;
        	}
        	y = y->next;
        	if(y == 0)
        	{
        		return 0;
        	}
        } while(x != y);
        for(x = head; x != y;x = x->next,y = y->next)
      	;
        return x;
    }
};