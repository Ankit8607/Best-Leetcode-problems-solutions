// https://leetcode.com/problems/filling-bookcase-shelves/description/?envType=daily-question&envId=2024-07-31

class Solution {
public:

    int rec(int level, vector<vector<int>>& books, int &shelfWidth, vector<int>&dp){
        if(level==books.size()) return 0;

        if(dp[level]!=-1) return dp[level];

        int ans=1e9,sum=0,mx=0,i=level;
        while(i<books.size() and sum+books[i][0]<=shelfWidth){
            sum+=books[i][0];
            mx=max(mx,books[i][1]);
            ans=min(ans,mx+rec(i+1,books,shelfWidth,dp));
            i++;
        }
        
        return dp[level]=ans;
    }

    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        int n=books.size();
        vector<int>dp(n,-1);
        return rec(0,books,shelfWidth,dp);
    }
};
