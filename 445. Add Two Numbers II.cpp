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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        stack<int> node1;
        stack<int> node2;
        stack<int> node3;

        while(l1!=NULL)
        {
            node1.push(l1->val);
            l1 = l1->next;
        }
        while(l2!=NULL)
        {
            node2.push(l2->val);
            l2 = l2->next;
        }
        int carry = 0;
        ListNode* head=NULL;
        ListNode* prev=NULL;
        while(!node1.empty() && !node2.empty())
        {
            int temp = node1.top() + node2.top() + carry;
            carry = 0;
            node1.pop();
            node2.pop();
            if(temp>=10)
            {
                carry = 1;
                temp %= 10;
            }
            // ListNode* newnode = new ListNode();
            // newnode->val = temp;
            // newnode->next = NULL;
            node3.push(temp);

            // if(head==NULL)
            // {
            //     head = newnode;
            //     prev = newnode;
            // }
            // else
            // {
            //     prev->next = newnode;
            //     prev = newnode;
            // }

        }
        while(!node1.empty())
        {
            int temp = node1.top() + carry;
            carry = 0;
            node1.pop();
            if(temp>=10)
            {
                carry = 1;
                temp %= 10;
            }
            node3.push(temp);
        }

        while(!node2.empty())
        {
            int temp = node2.top() + carry;
            carry = 0;
            node2.pop();
            if(temp>=10)
            {
                carry = 1;
                temp %= 10;
            }
            node3.push(temp);
        }

        if(carry!=0)
        {
            node3.push(1);
        }
        while(!node3.empty())
        {
            int temp = node3.top();
            node3.pop();

            ListNode* newnode=  new ListNode();
            newnode->val = temp;
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
        }
        return head;
    }
};