// https://leetcode.com/problems/maximum-number-of-events-that-can-be-attended-ii/description/

class Solution {
public:

    int rec(int level,int k,vector<vector<int>>&events, vector<vector<int>>&dp,vector<int>&find){
        if(level==events.size() || k==0) return 0;

        if(dp[level][k]!=-1) return dp[level][k];

        int ans=rec(level+1,k,events,dp,find);
        int ind=upper_bound(find.begin(),find.end(),events[level][1])-find.begin();
        ans=max(ans,rec(ind,k-1,events,dp,find)+events[level][2]);

        return dp[level][k]=ans;
    }

    int maxValue(vector<vector<int>>& events, int k) {
        sort(events.begin(),events.end());
        vector<vector<int>>dp(events.size(),vector<int>(k+1,-1));
        vector<int>find;
        for(int i=0;i<events.size();i++){
            find.push_back(events[i][0]);
        }
        cout<<endl;
        return rec(0,k,events,dp,find);
    }
};
