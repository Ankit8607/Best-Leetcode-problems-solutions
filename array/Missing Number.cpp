// https://leetcode.com/problems/missing-number/description/?envType=daily-question&envId=2024-02-20

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        vector<int>arr(n+1,1);
        for(auto i:nums) arr[i]=0;
        for(int i=0;i<n;i++) if(arr[i]) return i;
        return n;
    }
};
