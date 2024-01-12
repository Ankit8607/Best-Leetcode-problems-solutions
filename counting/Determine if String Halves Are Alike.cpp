// https://leetcode.com/problems/determine-if-string-halves-are-alike/description/?envType=daily-question&envId=2024-01-12

class Solution {
public:
    bool halvesAreAlike(string s) {
        int n=s.size(),arr[128]={0},cnt=0;
        for(int i=0;i<n/2;i++) arr[s[i]]++;
        for(int i=n/2;i<n;i++) arr[s[i]]--;
        for(char i:{'a','e','i','o','u'}) cnt+=arr[i];
        for(char i:{'A','E','I','O','U'}) cnt+=arr[i];
        return cnt==0;
    }
};
