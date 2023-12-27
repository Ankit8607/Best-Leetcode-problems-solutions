// https://leetcode.com/problems/minimum-time-to-make-rope-colorful/description/?envType=daily-question&envId=2023-12-27

class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int n=colors.size(),i=0,ans=0;
        while(i<n){
            int mx=neededTime[i],sum=neededTime[i++];
            while(colors[i]==colors[i-1]) mx=max(mx,neededTime[i]),sum+=neededTime[i++];
            ans+=sum-mx;
        }
        return ans;
    }
};
