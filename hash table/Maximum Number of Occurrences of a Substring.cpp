// https://leetcode.com/problems/maximum-number-of-occurrences-of-a-substring/description/

class Solution {
public:
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
        int ans=0,cnt=0;
        int pre[26];
        unordered_map<string,int>mp;
        memset(pre,0,sizeof(pre));
        for(int i=0;i<minSize;i++){
            if(pre[s[i]-'a']==0) cnt++;
            pre[s[i]-'a']++;
        }
        if(cnt<=maxLetters){
            mp[s.substr(0,minSize)]++;
            ans=1;
        }
        for(int i=minSize;i<s.size();i++){
            if(pre[s[i]-'a']==0) cnt++; pre[s[i]-'a']++;
            if(pre[s[i-minSize]-'a']==1) cnt--; pre[s[i-minSize]-'a']--;
            // cout<<"i= "<<i<<"cnt= "<<cnt<<endl;
            if(cnt<=maxLetters){
                mp[s.substr(i-minSize+1,minSize)]++;
                ans=max(ans,mp[s.substr(i-minSize+1,minSize)]);
                // cout<<"ans= "<<ans<<endl;
            }
        }
        return ans;
    }
};
