// https://leetcode.com/problems/populating-next-right-pointers-in-each-node/

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        stack<Node*>st;
        if(root!=NULL)st.push(root);
        while(!st.empty()){
            stack<Node*>tmp;
            while(!st.empty()){
                Node *head=st.top();
                st.pop();
                if(head->left!=NULL){
                    tmp.push(head->left);
                    tmp.push(head->right);
                }
                if(!st.empty()) head->next=st.top();
                else head->next=NULL;
            }
            while(!tmp.empty()){
                st.push(tmp.top());
                tmp.pop();
            }
        }
        return root;
    }
};
