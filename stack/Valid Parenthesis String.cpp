// https://leetcode.com/problems/valid-parenthesis-string/description/?envType=daily-question&envId=2024-04-07

class Solution {
public:
/*
    bool checkValidString(string s) {
        stack<int> leftStack;
        stack<int> starStack;
        
        for(int i = 0; i < s.length(); i++) {
            if(s[i] == '(') {
                leftStack.push(i);
            } else if(s[i] == '*') {
                starStack.push(i);
            } else { // s[i] == ')'
                if(!leftStack.empty()) {
                    leftStack.pop();
                } else if(!starStack.empty()) {
                    starStack.pop();
                } else {
                    return false;
                }
            }
        }
        
        while(!leftStack.empty() && !starStack.empty()) {
            if(leftStack.top() > starStack.top()) {
                return false;
            }
            leftStack.pop();
            starStack.pop();
        }
        
        return leftStack.empty();     
    }
*/
    bool checkValidString(string s) {
        int cmin = 0;
        int cmax = 0;
        for (char c : s) {
            if (c == '(') {
                cmax++;
                cmin++;
            } else if (c == ')') {
                cmax--;
                cmin = max(cmin - 1, 0);
            } else if (c == '*') {
                cmax++;
                cmin = max(cmin - 1, 0);
            }
            if (cmax < 0) {
                return false;
            }
        }
        return cmin == 0;
    }
};


// In python

// class Solution:
//     def checkValidString(self, s: str) -> bool:
//         cmin,cmax=0,0
//         for c in s:
//             if c == '(':
//                 cmax+=1
//                 cmin+=1
//             elif c == ')':
//                 cmax-=1
//                 cmin = max(cmin - 1, 0)
//             elif c == '*':
//                 cmax+=1
//                 cmin = max(cmin - 1, 0)
//             if cmax < 0:
//                 return 0
//         return cmin == 0

// In javasript

// /**
//  * @param {string} s
//  * @return {boolean}
//  */
// var checkValidString = function(s) {
//         let cmin = 0,cmax = 0;
//         for (let c of s) {
//             if (c == '(') {
//                 cmax++;
//                 cmin++;
//             } else if (c == ')') {
//                 cmax--;
//                 cmin = Math.max(cmin - 1, 0);
//             } else if (c == '*') {
//                 cmax++;
//                 cmin = Math.max(cmin - 1, 0);
//             }
//             if (cmax < 0) {
//                 return false;
//             }
//         }
//         return cmin == 0;
// };
