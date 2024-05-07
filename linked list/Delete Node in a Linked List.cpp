// https://leetcode.com/problems/delete-node-in-a-linked-list/description/?envType=daily-question&envId=2024-05-05

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
    void deleteNode(ListNode* head) {
       while(head->next->next){
            head->val=head->next->val;
            head=head->next;
       }
       head->val=head->next->val;
       head->next=NULL;
    }
};

// In python

// # Definition for singly-linked list.
// # class ListNode:
// #     def __init__(self, x):
// #         self.val = x
// #         self.next = None

// class Solution:
//     def deleteNode(self, head):
//         while head.next.next:
//             head.val=head.next.val
//             head=head.next
//         head.val=head.next.val
//         head.next=None


// In javascript

// /**
//  * Definition for singly-linked list.
//  * function ListNode(val) {
//  *     this.val = val;
//  *     this.next = null;
//  * }
//  */
// /**
//  * @param {ListNode} node
//  * @return {void} Do not return anything, modify node in-place instead.
//  */
// var deleteNode = function(head) {
//     while(head.next.next){
//         head.val=head.next.val;
//         head=head.next;
//     }
//     head.val=head.next.val;
//     head.next=null;
// };
