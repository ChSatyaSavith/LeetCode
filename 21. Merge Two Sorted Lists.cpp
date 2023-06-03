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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* head = NULL;
        ListNode* prev = NULL;
        if(list1==NULL && list2==NULL)
        {
            return head;
        }
        while(list1!=NULL && list2!=NULL)
        {
            ListNode* newnode = new ListNode();

            if(list1->val < list2->val)
            {
                newnode->val = list1->val;
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
                list1 = list1->next;
            }
            else
            {
                newnode->val = list2->val;
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
                list2 = list2->next;
            }
        }

        if(list1==NULL && list2!=NULL)
        {
            if(prev!=NULL)
            {
                while(list2!=NULL)
                {
                    ListNode* newnode = new ListNode();
                    newnode->val = list2->val;
                    newnode->next = NULL;
                    prev->next = newnode;
                    prev = newnode;
                    list2 = list2->next;
                }
            }
            else
            {
                head = list2;
            }
        }
        else if(list1!=NULL && list2==NULL)
        {
            if(prev!=NULL)
            {
                while(list1!=NULL)
                {
                    ListNode* newnode = new ListNode();
                    newnode->val = list1->val;
                    newnode->next = NULL;
                    prev->next = newnode;
                    prev = newnode;
                    list1 = list1->next;
                }
            }
            else
            {
                head = list1;
            }
        }
        return head;
    }
};