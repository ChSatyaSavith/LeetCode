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
    ListNode* removeNthFromEnd(ListNode* head, int n)
    {
        ListNode* fast = new ListNode();
        ListNode* slow = new ListNode();
        fast->next = head;
        slow->next = head;
        slow->val = -1;

        for(int i = 0;i<n+1;i++)
        {
            fast = fast->next;
        }
        
        while(fast!=NULL)
        {
            fast = fast->next;
            slow = slow->next;
        }

        slow->next = slow->next->next;
        
        if(slow->val == -1)
        {
            return slow->next;
        }
        return head;
        
    }
};