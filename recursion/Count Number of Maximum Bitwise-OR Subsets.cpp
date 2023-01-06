// https://leetcode.com/problems/count-number-of-maximum-bitwise-or-subsets/

class Solution {
public:
    int ans=0;
    void rec(int level,int x,vector<int>& nums,int mx){
        if(level==nums.size()){
            if(x==mx) ans++;
            return;
        }

        rec(level+1,x,nums,mx);
        rec(level+1,x|nums[level],nums,mx);
    }
    int countMaxOrSubsets(vector<int>& nums) {
        int mx=0;
        for(auto &i:nums) mx|=i;
        rec(0,0,nums,mx);
        return ans;
    }
};
