// https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/

class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int sum=0;
        for(auto &i:weights) sum+=i;
        int l=*max_element(weights.begin(),weights.end()),r=sum,ans=1;
        while(l<=r){
            int mid=(r+l)/2;
            int sum=0,cnt=0;
            for(auto &i:weights){
                sum+=i;
                if(sum>mid){
                    cnt++;
                    sum=i;
                }
            }
            cnt+=(sum?1:0);
            if(cnt<=days){
                ans=mid;
                r=mid-1;
            }
            else l=mid+1;
        }
        return ans;
    }
};
