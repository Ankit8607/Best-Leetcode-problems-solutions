// https://leetcode.com/problems/is-subsequence/?envType=daily-question&envId=2023-09-22

class Solution {
public:
    bool isSubsequence(string &s, string &t) {
        int n=s.size(),m=t.size();
        int i=0,j=0;
        while(i<n and j<m){
            if(s[i]==t[j]) i++;
            j++;
        }
        return i==n;
    }
};
