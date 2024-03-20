// https://leetcode.com/problems/merge-in-between-linked-lists/description/?envType=daily-question&envId=2024-03-20

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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode *head=list1,*last=list2;
        while(last->next) last=last->next;
        for(int i=0;i<=b;i++){
            if(i==(a-1)){  
                ListNode *t=head;
                head=head->next;
                t->next=list2;
            }
            else head=head->next;
        }
        last->next=head;
        return list1;
    }
};
