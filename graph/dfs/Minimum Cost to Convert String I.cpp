// https://leetcode.com/problems/minimum-cost-to-convert-string-i/description/?envType=daily-question&envId=2024-07-27

class Solution {
public:

    void rec(int node, int &par, int wt, vector<vector<int>>&g, vector<vector<int>>&dp){
        for(auto child:g[node]){
            if(dp[par][child]>=wt+dp[node][child]){
                dp[par][child]=wt+dp[node][child];
                rec(child,par,wt+dp[node][child],g,dp);
            }
        }
    }

    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        vector<vector<int>>dp(26,vector<int>(26,1e9)),g(26);
        for(int i=0;i<original.size();i++){
            dp[original[i]-'a'][changed[i]-'a']=min(cost[i],dp[original[i]-'a'][changed[i]-'a']);
        }
        for(int i=0;i<26;i++)
            for(int j=0;j<26;j++)
                if(dp[i][j]!=1e9)
                    g[i].push_back(j);

        for(int i=0;i<26;i++) rec(i,i,0,g,dp);

        long long ans=0;
        for(int i=0;i<source.size();i++){
            if(source[i]==target[i]) continue;
            if(dp[source[i]-'a'][target[i]-'a']==1e9) return -1;
            ans+=dp[source[i]-'a'][target[i]-'a'];
        }
        return ans;
    }
};
