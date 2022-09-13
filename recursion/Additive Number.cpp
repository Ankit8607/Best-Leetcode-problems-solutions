// https://leetcode.com/problems/additive-number/

/*

An additive number is a string whose digits can form an additive sequence.

A valid additive sequence should contain at least three numbers. Except for the first two numbers, each subsequent number in the sequence must be the sum of the preceding two.

Given a string containing only digits, return true if it is an additive number or false otherwise.

Note: Numbers in the additive sequence cannot have leading zeros, so sequence 1, 2, 03 or 1, 02, 3 is invalid.

 

Example 1:

Input: "112358"
Output: true
Explanation: 
The digits can form an additive sequence: 1, 1, 2, 3, 5, 8. 
1 + 1 = 2, 1 + 2 = 3, 2 + 3 = 5, 3 + 5 = 8
Example 2:

Input: "199100199"
Output: true
Explanation: 
The additive sequence is: 1, 99, 100, 199. 
1 + 99 = 100, 99 + 100 = 199
 

Constraints:

1 <= num.length <= 35
num consists only of digits.


*/


class Solution {
public:
    #define int long long
    bool rec(int level,int a,int b,string s){
        
        int n=s.size();
        if(b==-1){
            if(a==-1){
                for(int i=0;i<n-1;i++){
                    if(rec(i+1,stol(s.substr(0,i+1)),-1,s)){ 
                        if(s[0]=='0' and i>0) return 0;
                        return 1;
                    }
                }
            }
            else{
                for(int i=level;i<n-1;i++){
                    if(rec(i+1,a,stol(s.substr(level,i+1-level)),s)){
                        if(i+1-level>1 and s[level]=='0') return 0;
                        return 1;
                    }
                }
            }
        }
        else{
            int t=0;
            while(level<n and t<a+b){
                t=t*10+(s[level++]-'0');
                if(t==(a+b)){
                    if(level==n) return 1;
                    return rec(level,b,t,s);
                }
                if(t==0) return 0;
            }
        }
        return 0;
    }
    
    bool isAdditiveNumber(string num) {
        if(num.size()<3) return 0;
        int n=num.size();
        int flag=0;
        for(int i=0;i<n;i++){
            if(num[i]!='0') flag=1;
        }
        if(flag==0) return 1;
        #undef int
        return rec(0,-1,-1,num);
    }
    
};
