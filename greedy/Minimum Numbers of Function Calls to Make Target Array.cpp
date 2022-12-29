// https://leetcode.com/problems/minimum-numbers-of-function-calls-to-make-target-array/

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int ans=0,cnt=0;
        for(auto i:nums){
            int t=0;
            while(i){
                if(i%2){
                    ans++;
                    i=i-1;
                    if(i){
                        i/=2;
                        t++;
                    }
                }
                else t++,i=i/2;
            }
            cnt=max(t,cnt);
        }
        return ans+cnt;
    }
};
