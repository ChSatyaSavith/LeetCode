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
    void reorderList(ListNode* head)
    {
        ListNode* slow = head;
        ListNode* fast = head;

        if(head->next==NULL || head->next->next==NULL)
        {
            return;
        }

        while(fast!=NULL && fast->next!=NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* new_head = slow->next;
        slow->next=NULL;

        ListNode* prev = new_head;
        ListNode* curr = new_head->next;
        prev->next = NULL;

        while(curr!=NULL)
        {
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }

        new_head = prev;

        ListNode* store = head->next;
        ListNode* store1 = new_head->next;
        while(new_head!=NULL)
        {
            head->next = new_head;
            new_head->next = store;
            head = store;
            new_head = store1;
            if(head==NULL || new_head==NULL)
            {
                break;
            }
            store = head->next;
            store1 = new_head->next;
        }
    }
};