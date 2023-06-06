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
    ListNode* deleteDuplicates(ListNode* head) 
    {
        if(head==NULL)
        {
            return head;
        }
        ListNode* prev = NULL;
        ListNode* new_head = new ListNode();
        new_head->val = head->val;
        new_head->next = NULL;
        prev = new_head;
        while(head->next!=NULL)
        {
            if(head->val!=head->next->val)
            {
                ListNode* newnode = new ListNode();
                newnode->val = head->next->val;
                newnode->next = NULL;
                prev->next = newnode;
                prev = newnode;
            }
            head = head->next;
        }

        return new_head;
    }
};