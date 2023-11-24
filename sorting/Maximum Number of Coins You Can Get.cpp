// https://leetcode.com/problems/maximum-number-of-coins-you-can-get/description/?envType=daily-question&envId=2023-11-24

class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.begin(),piles.end(),greater<int>());
        int n=piles.size()/3,ans=0,it=0;
        while(n-- and ++it) ans+=piles[it++];
        return ans;
    }
};
