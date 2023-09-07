// https://leetcode.com/problems/reverse-linked-list-ii/?envType=daily-question&envId=2023-09-07

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

    void rec(ListNode *head,int left, int right,int n,ListNode *prev,ListNode *last,ListNode *st,ListNode *(&ans)){
        if(head==NULL) return ;

        ListNode *tmp=head->next;
        if(n==left-1) last=head;
        else if(n==left) st=head,prev=head;
        else if(n==right){
            st->next=tmp;
            if(last) last->next=head;
            else ans=head;
            head->next=prev;
        }
        else if(n>=left and n<=right){
            head->next=prev;
            prev=head;
        }
        rec(tmp,left,right,n+1,prev,last,st,ans);
    }

    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode *prev,*last=NULL,*st,*ans=head;
        rec(head,left,right,1,prev,last,st,ans);
        return ans;
    }
};
