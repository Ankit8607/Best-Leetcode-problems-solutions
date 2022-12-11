// https://leetcode.com/problems/global-and-local-inversions/description/

class Solution {
public:
    bool isIdealPermutation(vector<int>& nums) {
        int n=nums.size();
        if(n<=2) return 1;
        int tar=0;
        for(int i=0;i<n-1;i++){
            if(nums[i]>nums[i+1]){
                if(nums[i+1]!=i) return 0;
                if(nums[i]!=i+1) return 0;
                i++;
            }
            else if(nums[i]!=i) return 0;
        }
        return 1;
    }
};
