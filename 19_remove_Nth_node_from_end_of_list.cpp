// use double pointers

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *h1=new ListNode(0);
        h1->next=head;
        ListNode *h2=h1;
        head=h1;
        for(int i=0;i<n+1;i++) h1=h1->next;
        while(h1!=NULL)
        {
            h1=h1->next;
            h2=h2->next;
        }
        h2->next=h2->next->next;
        return head->next;
    }
};