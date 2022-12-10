// https://leetcode.com/problems/solving-questions-with-brainpower/description/

class Solution {
public:
    #define ll long long
    ll dp[200100];
    ll rec(int level,vector<vector<int>>& questions){
        if(level>=questions.size()) return 0;

        if(dp[level]!=-1) return dp[level];

        return dp[level]=max(rec(level+1,questions),questions[level][0]+rec(level+questions[level][1]+1,questions));

    }
    long long mostPoints(vector<vector<int>>& questions) {
        memset(dp,-1,sizeof(dp));
        return rec(0,questions);
    }
};
