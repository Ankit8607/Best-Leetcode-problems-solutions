// https://leetcode.com/problems/arithmetic-subarrays/

class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        vector<bool> ans;
        for(int i=0;i<l.size();i++){
            vector<int>arr;
            for(int j=l[i];j<=r[i];j++) arr.push_back(nums[j]);
            sort(arr.begin(), arr.end());
            int diff=arr[1]-arr[0];
            int flag=0;
            for(int j=1;j<arr.size();j++){
                if(arr[j]-arr[j-1]!=diff){
                    flag=1;
                    ans.push_back(0);
                    break;
                }
            }
            if(!flag) ans.push_back(1);
        }
        return ans;
    }
};
