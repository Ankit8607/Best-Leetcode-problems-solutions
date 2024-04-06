// https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses/description/?envType=daily-question&envId=2024-04-06

class Solution {
public:
    string minRemoveToMakeValid(string s) {
        string ans;
        int cnt=0;
        for(auto i:s){
            if(i==')'){
                if(cnt>0){
                    cnt--;
                    ans+=i;
                }
            }
            else{
                if(i=='(') cnt++;
                ans+=i;
            }
        }
        if(cnt==0) return ans;
        int i=ans.size()-1;
        string res;
        while(i>=0){
            if(cnt and ans[i]=='(') cnt--;
            else res+=ans[i];
            i--;
        }
        reverse(res.begin(),res.end());
        return res;
    }
};


// In python 


// class Solution:
//     def minRemoveToMakeValid(self, s: str) -> str:
//         ans,res,cnt="","",0
//         for i in s:
//             if i==')':
//                 if cnt>0:
//                     cnt-=1
//                     ans+=i
//             else:
//                 if i=='(':
//                     cnt+=1
//                 ans+=i
//         if cnt==0:
//             return ans
//         i=len(ans)-1
//         while i>=0:
//             if cnt and ans[i]=='(':
//                 cnt-=1
//             else:
//                 res+=ans[i]
//             i-=1
//         return res[::-1]


//   In javascript

// /**
//  * @param {string} s
//  * @return {string}
//  */
// var minRemoveToMakeValid = function(s) {
//     let ans="",cnt=0;
//     for(let i of s){
//         if(i==')'){
//             if(cnt>0){
//                 cnt--;
//                 ans+=i;
//             }
//         }
//         else{
//             if(i=='(') cnt++;
//             ans+=i;
//         }
//     }
//     if(cnt==0) return ans;
//     let i=ans.length-1,res="";
//     while(i>=0){
//         if(cnt && ans[i]=='(') cnt--;
//         else res+=ans[i];
//         i--;
//     }
//     return res.split("").reverse().join("");
// };
