// https://leetcode.com/problems/koko-eating-bananas/

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int ans=1;
        int l=1,r=1e9;
        while(l<=r){
            int mid=(l+r)/2;
            long long cnt=0;
            for(auto &i:piles) cnt+=1LL*(i+mid-1)/mid;
            if(cnt<=h){
                ans=mid;
                r=mid-1;
            }
            else l=mid+1;
        } 
        return ans;
    }
};
