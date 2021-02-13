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

//be careful to the carry

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *head=new ListNode((l1->val + l2->val) % 10);
        int deci=(l1->val + l2->val) / 10; 
        ListNode *fence=head;
        while (l1->next != NULL && l2->next != NULL){
            l1 = l1->next;
            l2 = l2->next;
            fence->next = new ListNode((l1->val + l2->val + deci) % 10);
            fence = fence -> next;
            deci=(l1->val + l2->val + deci) / 10;
        }
        if (l1->next != NULL) 
            fence->next = l1->next;
        else if (l2->next != NULL) 
            fence->next = l2->next;
        while (fence -> next != NULL){
            fence = fence->next;
            int num = fence -> val;
            fence -> val = (deci + fence->val) % 10;
            deci = (deci + num) / 10;
        }
        if (deci !=0 )
            fence -> next = new ListNode(deci);
        return head; 
    }
};