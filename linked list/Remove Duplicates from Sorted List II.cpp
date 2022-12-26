// https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/

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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *it=head,*ans=NULL,*prev=NULL;
        while(it){
            if(it->next and it->next->val==it->val){
                int t=it->val;
                while(it and it->val==t) it=it->next;
            }
            else{
                if(prev==NULL) ans=it;
                else prev->next=it;
                prev=it;
                it=it->next;
            }
        }
        if(prev) prev->next=NULL;
        return ans;
    }
};
