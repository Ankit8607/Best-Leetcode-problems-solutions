// https://leetcode.com/problems/make-the-string-great/description/?envType=daily-question&envId=2024-04-05

class Solution {
public:
    string makeGood(string s) {
        stack<char>st;
        for(char i:s){
            if(!st.empty() and (st.top()-32==i || st.top()+32==i))
                st.pop();
            else st.push(i);
        }
        string ans;
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};


// In python

// class Solution:
//     def makeGood(self, s: str) -> str:
//         st=[]
//         for i in s:
//             if len(st)>0 and (ord(st[-1])-32==ord(i) or ord(st[-1])+32==ord(i)):
//                 st.pop()
//             else:
//                 st.append(i)
//         ans=""
//         for i in st:
//             ans+=i
//         return ans


// In javascript

// /**
//  * @param {string} s
//  * @return {string}
//  */
// var makeGood = function(s) {
//     let stack = [];
//     for (let i of s) {
//         if (stack.length && (stack[stack.length - 1].charCodeAt(0) - 32 === i.charCodeAt(0) || stack[stack.length - 1].charCodeAt(0) + 32 === i.charCodeAt(0))) {
//             stack.pop();
//         } else {
//             stack.push(i);
//         }
//     }
//     let ans="";
//     for(let i of stack)
//         ans+=i;
//     return ans;
// };
