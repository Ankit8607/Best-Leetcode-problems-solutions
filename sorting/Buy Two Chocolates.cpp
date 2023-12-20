// https://leetcode.com/problems/buy-two-chocolates/description/?envType=daily-question&envId=2023-12-20

class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        sort(prices.begin(),prices.end());
        int ans=money-prices[0]-prices[1];
        if(ans>=0) return ans;
        return money;
    }
};
