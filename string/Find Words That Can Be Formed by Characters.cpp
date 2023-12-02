// https://leetcode.com/problems/find-words-that-can-be-formed-by-characters/description/?envType=daily-question&envId=2023-12-02

class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        vector<int>cnt(26,0);
        for(auto i:chars) cnt[i-'a']++;
        int ans=0;
        for(auto i:words){
            vector<int>ch(26,0);
            int flag=1;
            for(auto j:i) ch[j-'a']++;
            for(int j=0;j<26;j++) if(cnt[j]<ch[j]) flag=0;
            if(flag) ans+=i.size();
        }
        return ans;
    }
};
