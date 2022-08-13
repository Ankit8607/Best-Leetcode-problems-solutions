// https://leetcode.com/problems/different-ways-to-add-parentheses/submissions/

/*

Given a string expression of numbers and operators, return all possible results from computing all the different possible ways to group numbers and operators. You may return the answer in any order.

The test cases are generated such that the output values fit in a 32-bit integer and the number of different results does not exceed 104.

 

Example 1:

Input: expression = "2-1-1"
Output: [0,2]
Explanation:
((2-1)-1) = 0 
(2-(1-1)) = 2
Example 2:

Input: expression = "2*3-4*5"
Output: [-34,-14,-10,-10,10]
Explanation:
(2*(3-(4*5))) = -34 
((2*3)-(4*5)) = -14 
((2*(3-4))*5) = -10 
(2*((3-4)*5)) = -10 
(((2*3)-4)*5) = 10
 

Constraints:

1 <= expression.length <= 20
expression consists of digits and the operator '+', '-', and '*'.
All the integer values in the input expression are in the range [0, 99].

*/


class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        stack<int>intst;
        stack<char>opst;
        vector<int>ans;
        rec(0,expression,intst,opst,ans);
        return ans;
    }
    void rec(int level,string &s,stack<int>intst,stack<char>opst,vector<int>&ans){
        if(level==s.size()){
            if(intst.size()==1)
                ans.push_back(intst.top());
            return;
        }
            
        if(s[level]=='+' || s[level]=='-' || s[level]=='*'){
            opst.push(s[level]);
            rec(level+1,s,intst,opst,ans);
        }
        else{
            int t=0;
            while(level<s.size() and s[level]>='0' and s[level]<='9'){
                t=t*10+(s[level]-'0');
                level++;
            }
            intst.push(t);
            rec(level,s,intst,opst,ans);
            while(!opst.empty()){
                int b=intst.top(); intst.pop();
                char op=opst.top(); opst.pop();
                int a=intst.top(); intst.pop();
                int res=0;
                if(op=='+') res=a+b;
                else if(op=='-') res=a-b;
                else res=a*b;
                intst.push(res);
                rec(level,s,intst,opst,ans);
            }
        }
    }
};
