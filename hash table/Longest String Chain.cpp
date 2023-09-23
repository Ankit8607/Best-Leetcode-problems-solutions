// https://leetcode.com/problems/longest-string-chain/description/?envType=daily-question&envId=2023-09-23

class Solution {
public:

    bool comp(string &a, string &b){
        if(a.size()==b.size()) return a<b;
        return a.size()<b.size();
    }

    bool check(string &a,string &b){
        int cnt=0,j=0,i=0;
        while(i<a.size() and j<b.size()){
            if(a[i]==b[j]) i++;
            else cnt++;
            j++;
        }
        if(j==(int)b.size()-1) return cnt==0;
        return cnt==1;
    }

    int rec(string node,unordered_map<int,vector<string>>&g,unordered_map<string,int>&dp){
        if(dp.count(node)) return dp[node];

        int ans=0;
        for(auto i:g[node.size()+1]){
            if(check(node,i)){
                ans=max(ans,rec(i,g,dp));
            }
        }
        return dp[node]=ans+1;
    }

    int longestStrChain(vector<string>& words) {
        unordered_map<string,int>dp;
        unordered_map<int,vector<string>>g;
        for(auto i:words) g[(int)i.size()].push_back(i);
        int ans=1;
        for(auto i:words){
            if(!dp.count(i)){
                ans=max(ans,rec(i,g,dp));
            }
        }
        return ans;
    }
};
