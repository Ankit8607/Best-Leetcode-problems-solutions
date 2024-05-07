// https://leetcode.com/problems/double-a-number-represented-as-a-linked-list/description/?envType=daily-question&envId=2024-05-07

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

    int rec(ListNode* head){
        if(head==NULL) return 0;

        int carry=rec(head->next);
        
        carry+=head->val*2;
        head->val=carry%10;
        return carry/=10;
    }

    ListNode* doubleIt(ListNode* head) {
        int carry=rec(head);
        if(carry){
            ListNode *t=new ListNode(carry);
            t->next=head;
            return t;
        }
        return head;
    }
};


// In python

// # Definition for singly-linked list.
// # class ListNode:
// #     def __init__(self, val=0, next=None):
// #         self.val = val
// #         self.next = next
// class Solution:
//     def doubleIt(self, head: Optional[ListNode]) -> Optional[ListNode]:
//         def rec(head):
//             if head==None: return 0

//             carry=rec(head.next)
            
//             carry+=head.val*2
//             head.val=carry%10
//             carry/=10
//             return int(carry)

//         carry=rec(head)

//         if carry:
//             t=ListNode(carry)
//             t.next=head
//             return t
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
// var doubleIt = function(head) {
//     var carry=rec(head);
//     if(carry){
//         var t=new ListNode(carry);
//         t.next=head;
//         return t;
//     }
//     return head;
// };
// var rec=(head)=>{
//     if(head==null) return 0;

//     var carry=rec(head.next);
    
//     carry+=head.val*2;
//     head.val=carry%10;
//     carry/=10;
//     console.log(carry);
//     return Math.floor(carry);
// };
