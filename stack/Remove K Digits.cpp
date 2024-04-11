// https://leetcode.com/problems/remove-k-digits/

class Solution {
public:
    string removeKdigits(string num, int k) {
        string s="";
        for(char c:num){
            while(s.size() && s.back()>c && k)
            {
                k--;
                s.pop_back();
            }
            if(s.size()||c!='0') s.push_back(c);
        }
        while(s.size() && k--)
            s.pop_back();
        return (s.size()==0)?"0":s;
    }
};


// In python

// class Solution:
//     def removeKdigits(self, num: str, k: int) -> str:
//         s=[]
//         for c in num:
//             while len(s) and s[-1]>c and k:
//                 k-=1
//                 s.pop()
//             if len(s) or c!='0':
//                 s+=c
//         while len(s) and k:
//             s.pop()
//             k-=1
//         return "0" if len(s)==0 else "".join(s)


// In javascript

// /**
//  * @param {string} num
//  * @param {number} k
//  * @return {string}
//  */
// var removeKdigits = function(num, k) {
//     const s=[];
//     for(let c of num){
//         while(s.length && s.at(-1)>c && k)
//         {
//             k--;
//             s.pop();
//         }
//         if(s.length||c!='0') s.push(c);
//     }
//     while(s.length && k--)
//         s.pop();
//     return (s.length==0)?"0":s.join('');
// };
