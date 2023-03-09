// https://leetcode.com/problems/linked-list-cycle-ii/

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
    ListNode *detectCycle(ListNode *head) {
        unordered_set<ListNode *>mp;
        ListNode *t=head;
        while(t){
            if(mp.find(t)!=mp.end()) return t;
            mp.insert(t);
            t=t->next;
        }
        return t;
    }
};
