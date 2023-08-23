// https://leetcode.com/problems/reorganize-string/description/

class Solution {
public:
    string reorganizeString(string s) {
        priority_queue<pair<int,int>>pq;
        vector<int>cnt(26,0);
        for(auto i:s) cnt[i-'a']++;
        for(int i=0;i<26;i++) if(cnt[i]>0) pq.push({cnt[i],i});
        string ans;
        while(!pq.empty()){
            pair<int,int>a=pq.top();
            pq.pop();
            pair<int,int>b;
            if(!pq.empty()) b=pq.top();
            else if(a.first>1) return "";
            else return ans+=(a.second+'a');
            pq.pop();
            ans+=(a.second+'a');
            ans+=(b.second+'a');
            if(a.first>1) pq.push(make_pair(a.first-1,a.second));
            if(b.first>1) pq.push(make_pair(b.first-1,b.second));
        }
        return ans;
    }
};
