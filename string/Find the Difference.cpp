// https://leetcode.com/problems/find-the-difference/?envType=daily-question&envId=2023-09-25

class Solution {
public:
    char findTheDifference(string s, string t) {
        vector<int>cnt(26,0);
        for(auto i:s) cnt[i-'a']++;
        for(auto i:t) cnt[i-'a']--;
        for(int i=0;i<26;i++)
            if(cnt[i]) return ('a'+i);
        return 'a'; 
    }
};
