// https://leetcode.com/problems/find-all-anagrams-in-a-string/

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int>ans;
        if(p.size()>s.size()) return ans;
        int arr[26]={0};
        int cnt=0;
        for(int i=0;i<p.size();i++){
            if(arr[p[i]-'a']==0) cnt++;
            arr[p[i]-'a']++;
        }
        for(int i=0;i<p.size();i++){
            if(arr[s[i]-'a']==0) cnt++;
            arr[s[i]-'a']--;
            if(arr[s[i]-'a']==0)cnt--;
        }
        if(cnt==0) ans.push_back(0);
        int n=p.size();
        for(int i=n;i<s.size();i++){
            if(arr[s[i]-'a']==0) cnt++;
            arr[s[i]-'a']--;
            if(arr[s[i]-'a']==0)cnt--;
            if(arr[s[i-n]-'a']==0) cnt++;
            arr[s[i-n]-'a']++;
            if(arr[s[i-n]-'a']==0) cnt--;
            if(cnt==0) ans.push_back(i-p.size()+1);
        }
        return ans;
    }
};
