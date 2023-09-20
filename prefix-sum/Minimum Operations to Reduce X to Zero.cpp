// https://leetcode.com/problems/minimum-operations-to-reduce-x-to-zero/?envType=daily-question&envId=2023-09-20

class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n=nums.size();
        vector<int>last(n);
        last[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--) last[i]=nums[i]+last[i+1];
        if(x>last[0]) return -1;
        int l=-1,r=0,sum=0,ans=1e9;
        while(l<n-1){
            while(r<n and last[r]+sum>x) r++;
            if(sum+(r==n?0:last[r])==x and ans>n-r+l+1) ans=n-r+l+1;
            l++;
            sum+=nums[l];
        }
        return ans==1e9?-1:ans;
    }
};
