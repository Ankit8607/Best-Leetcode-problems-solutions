// https://leetcode.com/problems/reverse-linked-list/description/


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

    ListNode* rec(ListNode* head, ListNode* &ans){
        if(head->next==NULL){
            ans=head;
            return head;
        }

        ListNode* t=rec(head->next,ans);
        t->next=head;
        head->next=NULL;
        return t->next;
    }

    ListNode* reverseList(ListNode* head) {
        if(!head) return head;
        // ListNode* prev=NULL;
        // while(head->next){
        //     ListNode* tmp=head;
        //     head=head->next;
        //     tmp->next=prev;
        //     prev=tmp;
        // }
        // head->next=prev;
        // return head;

        ListNode *ans=head;
        rec(head,ans);
        return ans;
    }
};


// In python

// # Definition for singly-linked list.
// # class ListNode:
// #     def __init__(self, val=0, next=None):
// #         self.val = val
// #         self.next = next
// class Solution:
//     def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
//         if not head: return head
//         prev=None
//         while head.next:
//             tmp=head
//             head=head.next
//             tmp.next=prev
//             prev=tmp
//         head.next=prev
//         return head

// In javascript

// /**
//  * Definition for singly-linked list.
//  * function ListNode(val, next) {
//  *     this.val = (val===undefined ? 0 : val)
//  *     this.next = (next===undefined ? null : next)
//  * }
//  */
// /**
//  * @param {ListNode} head
//  * @return {ListNode}
//  */
// var reverseList = function(head) {
//     if(!head) return head;
//         let prev=null;
//         while(head.next){
//             let tmp=head;
//             head=head.next;
//             tmp.next=prev;
//             prev=tmp;
//         }
//         head.next=prev;
//         return head;
// };
