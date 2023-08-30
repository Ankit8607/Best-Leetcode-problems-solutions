// https://leetcode.com/problems/minimum-replacements-to-sort-the-array/

class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
        long long ans=0;
        int n=nums.size();
        for(int i=n-2;i>=0;i--){
            if(nums[i]<=nums[i+1]) continue;
            int k=nums[i]/nums[i+1];
            ans+=k;
            if(nums[i]%nums[i+1]==0){
                nums[i]=nums[i+1];
                ans--;
                continue;
            }
            k++;
            nums[i]=nums[i]/k;
        }
        return ans;
    }
};
