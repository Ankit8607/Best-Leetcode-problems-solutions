// https://leetcode.com/problems/split-linked-list-in-parts/?envType=daily-question&envId=2023-09-06

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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*>ans(k);
        int len=0,i=0;
        ListNode *it=head;
        while(it) len++,it=it->next;
        it=head;
        while(it){
            int t=len/k+(len%k?1:0);
            k--;
            len-=t;
            ans[i++]=it;
            ListNode *tmp=it;
            while(t--) tmp=it,it=it->next;
            tmp->next=NULL;
        }
        return ans;
    }
};
