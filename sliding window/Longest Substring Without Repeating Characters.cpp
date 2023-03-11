// https://leetcode.com/problems/longest-substring-without-repeating-characters/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int>arr(256,0);
        int l=0,r=0,ans=0;
        int n=s.size();
        while(r<n){
            while(r<n and arr[s[r]]==0){
                arr[s[r]]=1;
                r++;
            }
            ans=max(ans,r-l);
            if(r==n) break;
            while(s[l]!=s[r]) arr[s[l]]--,l++;
            arr[s[l]]--;
            l++;
        }
        return ans;
    }
};
