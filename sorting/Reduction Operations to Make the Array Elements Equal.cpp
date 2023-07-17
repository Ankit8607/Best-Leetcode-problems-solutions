// https://leetcode.com/problems/reduction-operations-to-make-the-array-elements-equal/description/

class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        int ans=0;
        sort(nums.begin(),nums.end());
        int i=0,n=nums.size();
        while(i<n){
            while(i+1<n and nums[i]==nums[i+1]){
                i++;
            }
            ans+=n-i-1;
            i++;
        }
        return ans;
    }
};
