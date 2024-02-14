// https://leetcode.com/problems/rearrange-array-elements-by-sign/description/?envType=daily-question&envId=2024-02-14

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int pos=0,neg=1;
        vector<int>ans(nums.size());
        for(auto i:nums){
            if(i>0) ans[pos]=i,pos+=2;
            else ans[neg]=i,neg+=2;
        }
        return ans;
    }
};
