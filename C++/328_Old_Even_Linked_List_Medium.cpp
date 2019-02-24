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
    // ListNode* oddEvenList(ListNode* head) {
        // ListNode *head1 = 0,*tail1 = 0,*head2 = 0, *tail2 = 0;
        // for(int i = 1; head; ++i,head = head->next)
        // {
        // 	if(i & 1) //如果i是奇数
        // 	{
        // 		if(tail1)
        // 		{
        // 			tail1 = tail1->next = head;
        // 		}
        // 		else
        // 		{
        // 			head1 = tail1 = head;
        // 		}
        // 	}
        // 	else if(tail2)//偶数结点
        // 	{
        // 		tail2  =tail2->next = head;
        // 	}
        // 	else
        // 	{
        // 		head2 = tail2 = head;
        // 	}
        // }
        // if(tail1)
        // {
        // 	tail1->next = head2;
        // }
        // else
        // {
        // 	head1 = head2;
        // }
        // if(tail2)
        // {
        // 	tail2->next = 0;
        // }

    //     return head1;
    // }

    ListNode* oddEvenList(ListNode* head) {
        if (head == 0) return 0;
        ListNode *odd = head,*even = head->next,*evenHead = even;
        while (even != 0 && even->next != 0) {
            odd->next = even->next;
            odd = odd->next;
            even->next = odd->next;
            even = even->next;
        }
        odd->next = evenHead;
        return head;
    }
};