// https://leetcode.com/problems/partition-list/description/

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
    ListNode* partition(ListNode* head, int x) {
        ListNode A(0),B(0);
        ListNode *a=&A,*b=&B,*root1,*root2;
        while(head){
            if(head->val<x) a=a->next=head;
            else b=b->next=head;
            head=head->next;
        }
        b->next=NULL;
        a->next=B.next;
        return A.next;
    }
};
