// https://leetcode.com/problems/last-stone-weight-ii/description/

class Solution{
public:
    int dp[31][3001],sum=0;

    int rec(int level,int pos,vector<int> &stones){
        if(level==stones.size()) return ((pos-(sum-pos))>=0?2*pos-sum:1e9);

        if(dp[level][pos]!=-1) return dp[level][pos];

        return dp[level][pos]=min(rec(level+1,pos,stones),rec(level+1,pos+stones[level],stones));
    }
    int lastStoneWeightII(vector<int>& stones) {
        memset(dp,-1,sizeof(dp));
        for(int &i:stones) sum+=i;
        return rec(0,0,stones);
    }
};
