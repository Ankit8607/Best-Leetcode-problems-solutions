// https://leetcode.com/problems/remove-nodes-from-linked-list/description/?envType=daily-question&envId=2024-05-06

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
    
    ListNode* rec(ListNode* head,int &mx){
        if(head==NULL) return NULL;
        
        ListNode *t=rec(head->next,mx);
        mx=max(mx,head->val);
        if(head->val<mx) return t;
        head->next=t;
        return head;
    }
    
    ListNode* removeNodes(ListNode* head) {
        int mx=0;
        return rec(head,mx);
    }
};


// In python

// # Definition for singly-linked list.
// # class ListNode:
// #     def __init__(self, val=0, next=None):
// #         self.val = val
// #         self.next = next
// class Solution:
//   def removeNodes(self, head: Optional[ListNode]) -> Optional[ListNode]:
//     if not head:
//       return None
//     head.next = self.removeNodes(head.next)
//     return head.next if head.next and head.val < head.next.val else head


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
// var removeNodes = function(head) {
//     if(!head)
//       return null;
//     head.next = removeNodes(head.next)
//     return (head.next && (head.val < head.next.val))? head.next:head;
// };
