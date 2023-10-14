// https://leetcode.com/problems/painting-the-walls/description/?envType=daily-question&envId=2023-10-14

class Solution {
public:

    int solve(int ind, int task, vector<int> &c, vector<int> &t, vector<vector<int>> &dp){
        if(task <= 0) return 0;
        if(ind == -1) return 1e9;
        if(dp[ind][task] != -1) return dp[ind][task];
        return dp[ind][task] = min(c[ind] + solve(ind - 1, task - t[ind] - 1, c, t, dp), solve(ind - 1, task, c, t, dp));
    }

    int paintWalls(vector<int>& cost, vector<int>& time) {
        int n = cost.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        return solve(n - 1, n, cost, time, dp);
    }
};
