// https://leetcode.com/problems/copy-list-with-random-pointer/?envType=daily-question&envId=2023-09-05

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head==NULL) return head;
        Node *it=head;
        while(it){
            Node *tmp=new Node(it->val);
            tmp->next=it->next;
            tmp->random=it->random;
            it->next=tmp;
            it=it->next->next;
        }
        Node *tmp=head->next;
        while(tmp){
            if(tmp->random) tmp->random=tmp->random->next;
            if(tmp->next) tmp=tmp->next->next; 
            else tmp=tmp->next;
        }
        it=head; tmp=head->next;
        while(it){
            Node *t=it->next;
            if(it->next) it->next=it->next->next;
            it=t;
        }
        return tmp;
    }
};
