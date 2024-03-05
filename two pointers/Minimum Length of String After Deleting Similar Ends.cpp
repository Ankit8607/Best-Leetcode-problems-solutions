// https://leetcode.com/problems/minimum-length-of-string-after-deleting-similar-ends/description/?envType=daily-question&envId=2024-03-05

#include<tuple>
class Solution {
public:
    int minimumLength(string s) {
        int l=0,r=s.size()-1,i=0,j=s.size()-1;
        while(i<j){
            if(s[i]!=s[j]) break;
            char t=s[i];
            while(i<j and s[i]==t) i++;
            while(j>=i and s[j]==t) j--;
            l=i,r=j;
        }
        return r-l+1;
    }
};
