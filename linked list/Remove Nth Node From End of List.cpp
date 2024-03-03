// https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/?envType=daily-question&envId=2024-03-03

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
        ListNode *it=head,*tmp=head,*prev=NULL;
        while(n--) it=it->next;
        while(it){
            it=it->next;
            prev=tmp;
            tmp=tmp->next;
        }
        if(prev) prev->next=tmp->next;
        else return tmp->next;
        return head;
    }
};
