// https://leetcode.com/problems/middle-of-the-linked-list/description/?envType=daily-question&envId=2024-03-07

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
    ListNode* middleNode(ListNode* head) {
        ListNode *it=head;
        while(it and it->next){
            it=it->next->next;
            head=head->next;
        }
        return head;
    }
};
