// https://leetcode.com/problems/longest-valid-parentheses/

/*

Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.

 

Example 1:

Input: s = "(()"
Output: 2
Explanation: The longest valid parentheses substring is "()".
Example 2:

Input: s = ")()())"
Output: 4
Explanation: The longest valid parentheses substring is "()()".
Example 3:

Input: s = ""
Output: 0
 

Constraints:

0 <= s.length <= 3 * 104
s[i] is '(', or ')'.

*/


class Solution {
public:
    int longestValidParentheses(string s) {
        int op=0,cl=0;
        int ans=0;
        for(auto i:s){
            if(i=='(') op++;
            else cl++;
            if(cl==op) ans=max(ans,op+cl);
            else if(cl>op){
                op=0; cl=0;
            }
        }
        op=0; cl=0;
        for(int i=s.size()-1;i>=0;i--){
            if(s[i]=='(') op++;
            else cl++;
            if(cl==op) ans=max(ans,op+cl);
            else if(cl<op){
                op=0; cl=0;
            }
        }
        return ans;
    }
};
