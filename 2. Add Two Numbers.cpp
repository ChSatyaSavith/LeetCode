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
        
        ListNode* head = NULL;
        ListNode* prev = NULL;
        int carry = 0;
        bool flag = true;
        while(l1!=nullptr && l2!=nullptr)
        {
            int val = l1->val + l2->val + carry;
            ListNode* newnode = new ListNode();
            if(val>=10)
            {
                carry = val/10;
                val = val % 10;
            }
            else
            {
                carry = 0;
            }

            newnode->val = val;
            newnode->next = nullptr;

            if(flag)
            {
                head = newnode;
                prev = newnode;
                flag = false;
            }
            else
            {
                prev->next = newnode;
                prev = newnode;
            }

            l1 = l1->next;
            l2 = l2->next;
        }

        if(l1==nullptr && l2!=nullptr)
        {
            while(l2!=nullptr)
            {
                int val = l2->val + 0 + carry;
                ListNode* newnode = new ListNode();
                if(val>=10)
                {
                    carry = val/10;
                    val = val % 10;
                }
                else
                {
                    carry = 0;
                }
                newnode->val = val;
                newnode->next = nullptr;
                prev->next = newnode;
                prev = newnode;
                l2 = l2->next;
            }
        }

        else if(l1!=nullptr && l2==nullptr)
        {
            while(l1!=nullptr)
            {
                int val = l1->val + 0 + carry;
                ListNode* newnode = new ListNode();
                if(val>=10)
                {
                    carry = val/10;
                    val = val % 10;
                }
                else
                {
                    carry = 0;
                }
                newnode->val = val;
                newnode->next = nullptr;
                prev->next = newnode;
                prev = newnode;
                l1 = l1->next;
            }
        }

        if(carry!=0)
        {
            ListNode* newnode = new ListNode();
            newnode->val = carry;
            newnode->next = nullptr;
            prev->next = newnode;
            prev = newnode;
        }
        return head;
    }
};