// https://leetcode.com/problems/minimum-speed-to-arrive-on-time/description/

class Solution {
public:
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int ans=-1,l=1,r=1e7;
        while(l<=r){
            int mid=(l+r)/2;
            double sum=0;
            for(int i=0;i<dist.size()-1;i++) sum+=(dist[i]+mid-1)/mid;
            sum+=(dist[dist.size()-1]*1.0/mid);
            if(sum<=hour){
                ans=mid;
                r=mid-1;
            }
            else l=mid+1;
        }
        return ans;
    }
};
