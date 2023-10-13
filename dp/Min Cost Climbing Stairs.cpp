// https://leetcode.com/problems/min-cost-climbing-stairs/?envType=daily-question&envId=2023-10-13

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int one=cost[0],two=cost[1],n=cost.size();
        for(int i=2;i<n;i++){
            int tmp=two;
            two=cost[i]+min(one,two);
            one=tmp;
        }
        return min(one,two);
    }
};
