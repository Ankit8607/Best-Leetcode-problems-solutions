// https://leetcode.com/problems/linked-list-cycle/?envType=daily-question&envId=2023-09-04

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *a=head;
        while(a and a->next){
            a=a->next->next;
            head=head->next;
            if(a==head) return 1;
        }
        return 0;
    }
};
