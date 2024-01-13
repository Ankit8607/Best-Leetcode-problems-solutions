// https://leetcode.com/problems/minimum-number-of-steps-to-make-two-strings-anagram/?envType=daily-question&envId=2024-01-13

class Solution {
public:
    int minSteps(string s, string t) {
        int cnt[26]={0};
        for(auto i:s) cnt[i-'a']++;
        for(auto i:t) cnt[i-'a']--;
        int ans=0;
        for(auto i:cnt) if(i>0) ans+=i;
        return ans;
    }
};
