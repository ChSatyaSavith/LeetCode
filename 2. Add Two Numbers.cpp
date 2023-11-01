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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode* head = NULL;
        ListNode* prev = NULL;

        while(l1!=NULL && l2!=NULL)
        {
            int add = l1->val + l2->val + carry;
            carry = add / 10;

            ListNode* newnode = new ListNode();
            newnode->val = add % 10;
            newnode->next = NULL;
            if(head==NULL)
            {
                head = newnode;
                prev = newnode;
            }
            else
            {
                prev->next = newnode;
                prev = newnode;
            }
            l1 = l1->next;
            l2 = l2->next;
        }
        while(l1!=NULL)
        {
            ListNode* newnode = new ListNode();
            int add = l1->val + carry;
            carry = add / 10;
            newnode->val = add % 10;
            newnode->next = NULL;
            if(head==NULL)
            {
                head = newnode;
                prev = newnode;
            }
            else
            {
                prev->next = newnode;
                prev = newnode;
                l1 = l1->next;
            }
        }
        while(l2!=NULL)
        {
            ListNode* newnode = new ListNode();
            int add = l2->val + carry;
            carry = add / 10;
            newnode->val = add % 10;
            newnode->next = NULL;
            if(head==NULL)
            {
                head = newnode;
                prev = newnode;
            }
            else
            {
                prev->next = newnode;
                prev = newnode;
                l2 = l2->next;
            }
        }
        if(carry!=0)
        {
            ListNode* newnode = new ListNode();
            newnode->val = carry;
            newnode->next = NULL;
            prev->next = newnode;
        }
        return head;
    }
};