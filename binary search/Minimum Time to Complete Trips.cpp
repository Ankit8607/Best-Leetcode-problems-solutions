// https://leetcode.com/problems/minimum-time-to-complete-trips/

class Solution {
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long ans=0, l=0,r=1;
        while(1){
            long long cnt=0;
            for(auto &i:time) cnt+=r/i;
            if(cnt>=totalTrips) break;
            r*=2;
        }
        while(l<=r){
            long long mid=(r+l)/2;
            long long cnt=0;
            for(auto &i:time) cnt+=mid/i;
            if(cnt>=totalTrips){
                ans=mid;
                r=mid-1;
            }
            else l=mid+1;
        }
        return ans;
    }
};
