// https://leetcode.com/problems/jump-game-ii/

class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return 0;
        int ans=1,i=0,mx=nums[0];
        while(mx<n-1){
            int tmp=mx;
            for(;i<=mx;i++){
                tmp=max(tmp,i+nums[i]);
            }
            ans++;
            mx=tmp;
        }
        return ans;
    }
};
