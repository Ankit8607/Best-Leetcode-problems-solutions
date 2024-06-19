// https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/description/?envType=daily-question&envId=2024-06-19

class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        if(1LL*m*k>bloomDay.size()) return -1;
        int ans=0, l=0, r=1e9;
        while(l<=r){
            int mid=(l+r)/2;
            int cnt=0,streak=0;
            for(int i=0;i<bloomDay.size();i++){
                if(bloomDay[i]<=mid) streak++;
                else streak=0;
                if(streak==k){
                    cnt++; 
                    streak=0;
                }
            }
            if(cnt>=m){
                ans=mid;
                r=mid-1;
            }
            else l=mid+1;
        }
        return ans;
    }
};
