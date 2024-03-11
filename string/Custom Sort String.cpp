// https://leetcode.com/problems/custom-sort-string/description/?envType=daily-question&envId=2024-03-11

class Solution {
public:
    string customSortString(string order, string s) {
        int cnt[26]={0};
        for(auto i:s) cnt[i-'a']++;
        string ans;
        for(char i:order){
            while(cnt[i-'a']--)
                ans+=i;
        }
        for(int i=0;i<26;i++){
            while(cnt[i]>0){
                ans+=(i+'a');
                cnt[i]--;
            }
        }
        return ans;
    }
};
